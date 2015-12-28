#include <cmath>
#include "terminal.hpp"
#include "../defs.h"
#include "../face.h"
#include "vlCore/GLSLmath.hpp"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using namespace std;

void GrammarObject::buildModelMatrix()
{
    modelMatrix.clear();
    vl::mat4 i;
    modelMatrix.push_back(i);
}

vl::mat4 GrammarObject::getModelMatrix() const
{
	std::list<vl::mat4>::const_iterator i = modelMatrix.begin();
	vl::mat4 m;
	if (i==modelMatrix.end())
		m.setIdentity();
	else
	{
		m = *i++;
		for (;i!=modelMatrix.end(); i++)
			m = (*i) * m;
	}
    return m;
}

GrammarObject::GrammarObject()
{
    //buildModelMatrix();
}

GrammarObject::~GrammarObject()
{
}

void GrammarObject::scale(float x, float y, float z)
{
    modelMatrix.push_back(vl::mat4::getScaling(x, y, z));
}

void GrammarObject::translate(float x, float y, float z)
{
    modelMatrix.push_back(vl::mat4::getTranslation(x, y, z));
}

void GrammarObject::rotate(float p, float y, float r)
{
    modelMatrix.push_back(vl::mat4::getRotationXYZ(vl::fRAD_TO_DEG * p, vl::fRAD_TO_DEG * y, vl::fRAD_TO_DEG * r));
}

void GrammarObject::rotateDeg(float p, float y, float r)
{
    modelMatrix.push_back(vl::mat4::getRotationXYZ(p, y, r));
}

void GrammarObject::prepare()
{
    /*if (has_parent())
    {
        node_ptr p = parent.lock();
        tmpMatrix = dynamic_cast<GrammarObject*>(p)->tmpMatrix*getModelMatrix();
    }
    else*/
        tmpMatrix = getModelMatrix();
    tmpMatrixInv = tmpMatrix.getInverse();

    for (t_child_list::iterator i = childs.begin(); i!=childs.end(); i++)
       dynamic_cast<GrammarObject*>(*i)->prepare();
}

bool GrammarObject::hit(vl::vec4& p, vl::vec4& v, set& s)
{
    return false;
}

bool GrammarObject::hit(vl::vec4& p)
{
    return false;
}

bool GrammarObject::rayTrace(vl::vec4& p, vl::vec4& v, set& s)
{
    if (!has_child())
    {
        vl::vec4 pp = tmpMatrixInv * p;
        vl::vec4 vv = tmpMatrixInv * v;
        return hit(pp, vv, s);
    }
    else
    {
        bool tmp = false;
        vl::vec4 pp = tmpMatrixInv * p;
        vl::vec4 vv = tmpMatrixInv * v;

        // usredniamy dzieciaki
        for (t_child_list::iterator i = childs.begin(); i!=childs.end(); i++)
        {
            vl::vec4 ppp = pp;
            vl::vec4 vvv = vv;
            set ss;
            tmp |= dynamic_cast<GrammarObject*>(*i)->rayTrace(ppp, vvv, ss);
            s += s;
        }

        return tmp;
    }

    return false;
}

bool GrammarObject::rayTrace(vl::vec4& p)
{
    if (!has_child())
    {
        vl::vec4 pp = tmpMatrixInv * p;
        return hit(pp);
    }
    else
    {
        bool tmp = false;
        vl::vec4 pp = tmpMatrixInv * p;

        // usredniamy dzieciaki
        for (t_child_list::iterator i = childs.begin(); i!=childs.end(); i++)
        {
            vl::vec4 ppp = pp;
            set ss;
            tmp |= dynamic_cast<GrammarObject*>(*i)->rayTrace(ppp);
        }

        return tmp;
    }

    return false;
}

Node::node_ptr GrammarObject::clone()
{
    node_ptr n(new GrammarObject);
    Node::clone(n);

    dynamic_cast<GrammarObject*>(n)->modelMatrix  = modelMatrix;
    dynamic_cast<GrammarObject*>(n)->tmpMatrix    = tmpMatrix;
    dynamic_cast<GrammarObject*>(n)->tmpMatrixInv = tmpMatrixInv;

    return n;
}

Node::node_ptr GrammarObject::clone(Node::node_ptr n)
{
    Node::clone(n);

    dynamic_cast<GrammarObject*>(n)->modelMatrix  = modelMatrix;
    dynamic_cast<GrammarObject*>(n)->tmpMatrix    = tmpMatrix;
    dynamic_cast<GrammarObject*>(n)->tmpMatrixInv = tmpMatrixInv;

    return n;
}

Sphere::Sphere()
{
}

Sphere::~Sphere()
{
}

bool Sphere::hit(vl::vec4& p, vl::vec4& v, set& s)
{
    vl::vec3 v_tmp = v.xyz();
    vl::vec3 p_tmp = p.xyz();

    float a = vl::dot(v_tmp, v_tmp);
    float b = vl::dot(v_tmp, p_tmp) * 2;
    float c = vl::dot(p_tmp, p_tmp) - 1;

    float d = b*b - 4*a*c;

    if (d > 0)
    {
        float sq = sqrt(d);
        float t1 = (-b-sq)/(2*a);
        float t2 = (-b+sq)/(2*a);

        vl::vec3 n1 = p_tmp + t1 * v_tmp;
        n1.normalize();

        vl::vec3 n2 = p_tmp + t2 * v_tmp;
        n2.normalize();

        if (t1 < t2)
            s.add(t1, n1, t2, n2);
        else
            s.add(t2, n2, t1, n1);

        return true;
    }

    return false;
}

bool Sphere::hit(vl::vec4& p)
{
    return p.xyz().length() < 1;
}

Node::node_ptr Sphere::clone()
{
    node_ptr n(new Sphere);
    GrammarObject::clone(n);

    return n;
}

Cylinder::Cylinder()
{
    r = 1.0;
    h = 2.0;
    rdir = vl::vec3(1.0f, 0.0f, 0.0f);
    hdir = vl::vec3(0.0f, 1.0f, 0.0f);
    center = vl::vec3(0.0f, 0.0f, 0.0f);
}

Cylinder::~Cylinder()
{
}

bool Cylinder::hit(vl::vec4& p, vl::vec4& v, set& s)
{
    /*vl::vec3 v_tmp = v.xyz();
    vl::vec3 p_tmp = p.xyz();

    float a = vl::dot(v_tmp, v_tmp);
    float b = vl::dot(v_tmp, p_tmp) * 2;
    float c = vl::dot(p_tmp, p_tmp) - 1;

    float d = b*b - 4*a*c;

    if (d > 0)
    {
        float sq = sqrt(d);
        float t1 = (-b-sq)/(2*a);
        float t2 = (-b+sq)/(2*a);

        vl::vec3 n1 = p_tmp + t1 * v_tmp;
        n1.normalize();

        vl::vec3 n2 = p_tmp + t2 * v_tmp;
        n2.normalize();

        if (t1 < t2)
            s.add(t1, n1, t2, n2);
        else
            s.add(t2, n2, t1, n1);

        return true;
    }*/

    return false;
}

bool Cylinder::hit(vl::vec4& p)
{
    vl::vec3 p3 = p.xyz();
    vl::vec3 newPr = p3-hdir*vl::dot(hdir, p3-center);
    float dr = newPr.length();
    float dh = vl::abs(vl::dot(hdir, p3-center));
    if (dr <= r && dh <= h*0.5f)
        return true;
    else
        return false;
}

Node::node_ptr Cylinder::clone()
{
    node_ptr n(new Cylinder);
    GrammarObject::clone(n);

    return n;
}

Cube::Cube()
{
}

Cube::~Cube()
{
}

bool Cube::hit(vl::vec4& p, vl::vec4& v, set& s)
{
    return false;
}

bool Cube::hit(vl::vec4& p)
{
	return fabs(p.x()) <= 1 && fabs(p.y()) <= 1 && fabs(p.z()) <= 1;
}

Node::node_ptr Cube::clone()
{
    node_ptr n(new Cube);
    GrammarObject::clone(n);

    return n;
}


Cone::Cone()
{
    r = 1.0;
    h = 1.0;
}

Cone::~Cone()
{
}

bool Cone::hit(vl::vec4& p, vl::vec4& v, set& s)
{
    return false;
}

bool Cone::hit(vl::vec4& p)
{
	vl::vec3 p3(p.x(), p.y(), p.z());
	vl::vec3 pnorm(p3);
	pnorm.normalize();
	vl::vec3 yvec(0, 1, 0);
	float dotpy = vl::dot(pnorm, yvec);
	if (dotpy < 0 || dotpy > h)
		return false;

	float alpha = acos(dotpy);
	
	float a = p3.length();
	float b = a * cos(alpha);

	float beta = vl::atan(r / h);
	float y = (h - b) * tan(beta);

	float x = a * sin(alpha);
	return x <= y;
}

Node::node_ptr Cone::clone()
{
    node_ptr n(new Cone);
    GrammarObject::clone(n);

    return n;
}

Torus::Torus()
{
	R = 1.0f;
	r = 0.66f;
}

Torus::Torus(float _R, float _r)
{
	R = _R;
	r = _r;
}

Torus::~Torus()
{
}

bool Torus::hit(vl::vec4& p, vl::vec4& v, set& s)
{
    return false;
}

bool Torus::hit(vl::vec4& p)
{
	float a = R - sqrt(p.x()*p.x() + p.z()*p.z());
	float tmp = sqrt(a*a + p.y()*p.y());

    return tmp <= r;
}

Node::node_ptr Torus::clone()
{
    node_ptr n(new Torus(R, r));
    GrammarObject::clone(n);

    return n;
}

Coscos::Coscos()
{
}

Coscos::~Coscos()
{
}

bool Coscos::hit(vl::vec4& p, vl::vec4& v, set& s)
{
    return false;
}

bool Coscos::hit(vl::vec4& p)
{
	if (p.y() < 0)
		return false;
	vl::vec4 tmp = p * M_PI;
	if (tmp.x() < -M_PI || tmp.x() > M_PI || tmp.z() < -M_PI || tmp.z() > M_PI)
		return false;
	return p.y() <= ((cos(tmp.x()) + 1) * (cos(tmp.z()) + 1)) / 4.0;
}

Node::node_ptr Coscos::clone()
{
    node_ptr n(new Coscos);
    GrammarObject::clone(n);

    return n;
}


And::And(GrammarObject& t1, GrammarObject& t2)
{
    node_ptr tt1(&t1);
    node_ptr tt2(&t2);
    Node::attach(tt1);
    Node::attach(tt2);
}

And::And(GrammarObject& t1, GrammarObject& t2, GrammarObject& t3)
{
    node_ptr tt1(&t1);
    node_ptr tt2(&t2);
    node_ptr tt3(&t3);
    Node::attach(tt1);
    Node::attach(tt2);
    Node::attach(tt3);
}

And::And(GrammarObject& t1, GrammarObject& t2, GrammarObject& t3, GrammarObject& t4)
{
    node_ptr tt1(&t1);
    node_ptr tt2(&t2);
    node_ptr tt3(&t3);
    node_ptr tt4(&t4);
    Node::attach(tt1);
    Node::attach(tt2);
    Node::attach(tt3);
    Node::attach(tt4);
}

And::And(GrammarObject& t1, GrammarObject& t2, GrammarObject& t3, GrammarObject& t4, GrammarObject& t5)
{
    node_ptr tt1(&t1);
    node_ptr tt2(&t2);
    node_ptr tt3(&t3);
    node_ptr tt4(&t4);
    node_ptr tt5(&t5);
    Node::attach(tt1);
    Node::attach(tt2);
    Node::attach(tt3);
    Node::attach(tt4);
    Node::attach(tt5);
}

And::~And()
{
}

bool And::rayTrace(vl::vec4& p, vl::vec4& v, set& s)
{
    t_child_list::iterator i = childs.begin();
    bool h;
    set ss;
    vl::vec4 ppt = tmpMatrixInv * p;
    vl::vec4 vvt = tmpMatrixInv * v;

    for (;i!=childs.end(); i++)
    {
        vl::vec4 pp = ppt;
        vl::vec4 vv = vvt;

        if (i == childs.begin())
        {
            h  = dynamic_cast<GrammarObject*>(*i)->rayTrace(pp, vv, ss);
        }
        else
        {
            set sss;
            h &= dynamic_cast<GrammarObject*>(*i)->rayTrace(pp, vv, sss);
            ss *= sss;
        }
    }

    if (h)
    {
        s = ss;
        return true;
    }

    return false;
}

bool And::rayTrace(vl::vec4& p)
{
    t_child_list::iterator i = childs.begin();
    bool h;
    vl::vec4 ppt = tmpMatrixInv * p;

    for (;i!=childs.end(); i++)
    {
        vl::vec4 pp = ppt;

        if (i == childs.begin())
        {
            h  = dynamic_cast<GrammarObject*>(*i)->rayTrace(pp);
        }
        else
        {
            h &= dynamic_cast<GrammarObject*>(*i)->rayTrace(pp);
        }
    }

    return h;
}

Node::node_ptr And::clone()
{
    node_ptr n(new And);
    GrammarObject::clone(n);

    return n;
}

Or::Or(GrammarObject& t1, GrammarObject& t2)
{
    node_ptr tt1(&t1);
    node_ptr tt2(&t2);
    Node::attach(tt1);
    Node::attach(tt2);
}

Or::Or(GrammarObject& t1, GrammarObject& t2, GrammarObject& t3)
{
    node_ptr tt1(&t1);
    node_ptr tt2(&t2);
    node_ptr tt3(&t3);
    Node::attach(tt1);
    Node::attach(tt2);
    Node::attach(tt3);
}

Or::Or(GrammarObject& t1, GrammarObject& t2, GrammarObject& t3, GrammarObject& t4)
{
    node_ptr tt1(&t1);
    node_ptr tt2(&t2);
    node_ptr tt3(&t3);
    node_ptr tt4(&t4);
    Node::attach(tt1);
    Node::attach(tt2);
    Node::attach(tt3);
    Node::attach(tt4);
}

Or::Or(GrammarObject& t1, GrammarObject& t2, GrammarObject& t3, GrammarObject& t4, GrammarObject& t5)
{
    node_ptr tt1(&t1);
    node_ptr tt2(&t2);
    node_ptr tt3(&t3);
    node_ptr tt4(&t4);
    node_ptr tt5(&t5);
    Node::attach(tt1);
    Node::attach(tt2);
    Node::attach(tt3);
    Node::attach(tt4);
    Node::attach(tt5);
}

Or::~Or()
{
}

bool Or::rayTrace(vl::vec4& p, vl::vec4& v, set& s)
{
    t_child_list::iterator i = childs.begin();
    bool h;
    set ss;
    vl::vec4 ppt = tmpMatrixInv * p;
    vl::vec4 vvt = tmpMatrixInv * v;

    for (;i!=childs.end(); i++)
    {
        vl::vec4 pp = ppt;
        vl::vec4 vv = vvt;

        if (i == childs.begin())
        {
            h  = dynamic_cast<GrammarObject*>(*i)->rayTrace(pp, vv, ss);
        }
        else
        {
            set sss;
            h |= dynamic_cast<GrammarObject*>(*i)->rayTrace(pp, vv, sss);
            ss += sss;
        }
    }

    if (h)
    {
        s = ss;
        return true;
    }

    return false;
}

bool Or::rayTrace(vl::vec4& p)
{
    t_child_list::iterator i = childs.begin();
    bool h;
    vl::vec4 ppt = tmpMatrixInv * p;

    for (;i!=childs.end(); i++)
    {
        vl::vec4 pp = ppt;

        if (i == childs.begin())
        {
            h  = dynamic_cast<GrammarObject*>(*i)->rayTrace(pp);
        }
        else
        {
            h |= dynamic_cast<GrammarObject*>(*i)->rayTrace(pp);
        }
    }

    return h;
}

Node::node_ptr Or::clone()
{
    node_ptr n(new Or);
    GrammarObject::clone(n);

    return n;
}

Diff::Diff(GrammarObject& t1, GrammarObject& t2)
{
    node_ptr tt1(&t1);
    node_ptr tt2(&t2);
    Node::attach(tt1);
    Node::attach(tt2);
}

Diff::Diff(GrammarObject& t1, GrammarObject& t2, GrammarObject& t3)
{
    node_ptr tt1(&t1);
    node_ptr tt2(&t2);
    node_ptr tt3(&t3);
    Node::attach(tt1);
    Node::attach(tt2);
    Node::attach(tt3);
}

Diff::Diff(GrammarObject& t1, GrammarObject& t2, GrammarObject& t3, GrammarObject& t4)
{
    node_ptr tt1(&t1);
    node_ptr tt2(&t2);
    node_ptr tt3(&t3);
    node_ptr tt4(&t4);
    Node::attach(tt1);
    Node::attach(tt2);
    Node::attach(tt3);
    Node::attach(tt4);
}

Diff::Diff(GrammarObject& t1, GrammarObject& t2, GrammarObject& t3, GrammarObject& t4, GrammarObject& t5)
{
    node_ptr tt1(&t1);
    node_ptr tt2(&t2);
    node_ptr tt3(&t3);
    node_ptr tt4(&t4);
    node_ptr tt5(&t5);
    Node::attach(tt1);
    Node::attach(tt2);
    Node::attach(tt3);
    Node::attach(tt4);
    Node::attach(tt5);
}

Diff::~Diff()
{
}

bool Diff::rayTrace(vl::vec4& p, vl::vec4& v, set& s)
{
    t_child_list::iterator i = childs.begin();
    bool h;
    set ss;
    vl::vec4 ppt = tmpMatrixInv * p;
    vl::vec4 vvt = tmpMatrixInv * v;

    for (;i!=childs.end(); i++)
    {
        vl::vec4 pp = ppt;
        vl::vec4 vv = vvt;

        if (i == childs.begin())
        {
            h  = dynamic_cast<GrammarObject*>(*i)->rayTrace(pp, vv, ss);
        }
        else
        {
            set sss;
            h &= !dynamic_cast<GrammarObject*>(*i)->rayTrace(pp, vv, sss);
            ss -= sss;
        }
    }

    if (h)
    {
        s = ss;
        return true;
    }

    return false;
}

bool Diff::rayTrace(vl::vec4& p)
{
    t_child_list::iterator i = childs.begin();
    bool h;
    vl::vec4 ppt = tmpMatrixInv * p;

    for (;i!=childs.end(); i++)
    {
        vl::vec4 pp = ppt;

        if (i == childs.begin())
        {
            h  = dynamic_cast<GrammarObject*>(*i)->rayTrace(pp);
        }
        else
        {
            h &= !dynamic_cast<GrammarObject*>(*i)->rayTrace(pp);
        }
    }

    return h;
}

Node::node_ptr Diff::clone()
{
    node_ptr n(new Diff);
    GrammarObject::clone(n);

    return n;
}

Xor::Xor(GrammarObject& f, GrammarObject& s)
{
    node_ptr ff(&f);
    node_ptr ss(&s);
    Node::attach(ff);
    Node::attach(ss);
}

Xor::~Xor()
{
}

bool Xor::rayTrace(vl::vec4& p, vl::vec4& v, set& s)
{
    set s1;
    set s2;
    vl::vec4 ppt = tmpMatrixInv * p;
    vl::vec4 vvt = tmpMatrixInv * v;
    vl::vec4 p1 = ppt;
    vl::vec4 p2 = ppt;
    vl::vec4 v1 = vvt;
    vl::vec4 v2 = vvt;
    t_child_list::iterator i = childs.begin();

    bool h1 = dynamic_cast<GrammarObject*>(*i)->rayTrace(p1, v1, s1);
    i++;
    bool h2 = dynamic_cast<GrammarObject*>(*i)->rayTrace(p2, v2, s2);

    s = s1 / s2;

    if (h1 ^ h2)
        return true;

    return false;
}

bool Xor::rayTrace(vl::vec4& p)
{
    vl::vec4 ppt = tmpMatrixInv * p;
    vl::vec4 p1 = ppt;
    vl::vec4 p2 = ppt;
    t_child_list::iterator i = childs.begin();

    bool h1 = dynamic_cast<GrammarObject*>(*i)->rayTrace(p1);
    i++;
    bool h2 = dynamic_cast<GrammarObject*>(*i)->rayTrace(p2);

    if (h1 ^ h2)
        return true;

    return false;
}

Node::node_ptr Xor::clone()
{
    node_ptr n(new Xor);
    GrammarObject::clone(n);

    return n;
}

Mirror::Mirror(GrammarObject& t, char type)
{
    Node::node_ptr n = dynamic_cast<GrammarObject*>(&t)->clone();
    attach(n);

    if (type == 0)
        modelMatrix.push_back(vl::mat4::getScaling(-1, 1, 1));
    else if (type == 1)
        modelMatrix.push_back(vl::mat4::getScaling( 1,-1, 1));
    else if (type == 2)
        modelMatrix.push_back(vl::mat4::getScaling( 1, 1,-1));
}

Mirror::~Mirror()
{
}

/*
bool Mirror::rayTrace(vl::vec4& p, vl::vec4& v, set& s)
{
    set s1;
    vl::vec4 p1 = p;
	if (mtype == 0)
		p1.x() = -p1.x();
	else if (mtype == 0)
		p1.y() = -p1.y();
	else if (mtype == 0)
		p1.z() = -p1.z();
    vl::vec4 v1 = v;
    //t_child_list::iterator i = childs.begin();

    //bool h = dynamic_cast<GrammarObject*>(*i)->rayTrace(p1, v1, s1);
	bool h = term->rayTrace(p1, v1, s1);
    return h;
}
*/

Node::node_ptr Mirror::clone()
{
    node_ptr n(new Mirror);
    GrammarObject::clone(n);

    return n;
}

Plane::Plane()
{
}

Plane::~Plane()
{
}

bool Plane::hit(vl::vec4& p, vl::vec4& v, set& s)
{
    return false;
}

bool Plane::hit(vl::vec4& p)
{
	return p.x() <= 0;
}


Node::node_ptr Plane::clone()
{
    node_ptr n(new Plane);
    GrammarObject::clone(n);

    return n;
}

PlaneProp::PlaneProp(float _max, float _power)
{
	max = _max;
	power = _power;
}

PlaneProp::PlaneProp(GrammarObject& t1, float _max, float _power)
{
	max = _max;
	power = _power;
	node_ptr tt1(&t1);
    Node::attach(tt1);
}

PlaneProp::~PlaneProp()
{
}

void PlaneProp::prepare()
{
	GrammarObject::prepare();
    myTmpMatrix = getMyModelMatrix();
	myTmpMatrix3 = myTmpMatrix.get3x3();
    myTmpMatrixInv = myTmpMatrix.getInverse();
	myTmpMatrixInv3 = myTmpMatrixInv.get3x3();
}

vl::mat4 PlaneProp::getMyModelMatrix() const
{
    std::list<vl::mat4>::const_iterator i = myModelMatrix.begin();
	vl::mat4 m;
	if (i==myModelMatrix.end())
		m.setIdentity();
	else
	{
		m = *i++;
		for (;i!=myModelMatrix.end(); i++)
			m = (*i) * m;
	}
    return m;
}

void PlaneProp::p_scale(float x, float y, float z)
{
    myModelMatrix.push_back(vl::mat4::getScaling(x, y, z));
}

void PlaneProp::p_translate(float x, float y, float z)
{
    myModelMatrix.push_back(vl::mat4::getTranslation(x, y, z));
}

void PlaneProp::p_rotate(float p, float y, float r)
{
    myModelMatrix.push_back(vl::mat4::getRotationXYZ(vl::fRAD_TO_DEG * p, vl::fRAD_TO_DEG * y, vl::fRAD_TO_DEG * r));
}

void PlaneProp::p_rotateDeg(float p, float y, float r)
{
    myModelMatrix.push_back(vl::mat4::getRotationXYZ(p, y, r));
}

bool PlaneProp::rayTrace(vl::vec4& p, vl::vec4& v, set& s)
{
    return false;
}

bool PlaneProp::rayTrace(vl::vec4& p)
{
    t_child_list::iterator i = childs.begin();
    bool h = false;
	vl::vec4 pptOrg = tmpMatrixInv * p;
    vl::vec4 ppt = pptOrg;
	ppt = myTmpMatrixInv * ppt;

	vl::vec3 pt3(ppt.x(), ppt.y(), ppt.z());
	vl::vec3 normal(1, 0, 0);
	float dist = vl::dot(normal, pt3);
	if (dist > 0 && dist < max)
	{
		float movepower = (((max-dist) / max) * power);
		ppt = pptOrg - vl::vec4(myTmpMatrix3 * (normal * movepower), 0);
	}
	else
	{
		ppt = pptOrg;
	}
    if (i != childs.end())
    {
        h = dynamic_cast<GrammarObject*>(*i)->rayTrace(ppt);
		//if (!h)
		//	h = dynamic_cast<GrammarObject*>(*i)->rayTrace(pptOrg);
    }
    return h;
}


Node::node_ptr PlaneProp::clone()
{
    node_ptr n(new PlaneProp(max, power));
    GrammarObject::clone(n);

    return n;
}



void draw(GrammarObject& t)
{
    if (sface.is_raytracing())
    {
        // RayTrace
        float z = 1;

        vl::vec3 eye    = sface.eye();
        vl::vec3 center = sface.center();
        vl::vec3 up     = sface.up();

        // front
        vl::vec3 n      = center - eye;
        n.normalize();

        // up
        vl::vec3 u      = up;
        u.normalize();

        // right
        vl::vec3 v      = cross(n, u);
        v.normalize();

        vl::vec4 p(eye, 1);

        int width  = sface.window_width();
        int height = sface.window_height();

        float fovx      = M_PI/29.0f;
        float fovy      = ((float)height / (float)width) * fovx;

        float dx        = fovx / ((float)width  * 0.5f);
        float dy        = fovy / ((float)height * 0.5f);

        vl::vec3 utmp, vtmp;

        unsigned char* pixels = sface.get_pixels(width, height);
        t.prepare();

        for (int y=0; y<height; y++)
        {
            utmp = u*(dy *((float)(y - (height * 0.5f))));

            for (int x=0; x<width; x++)
            {
                vtmp = v*(dx * ((float)(x - (width * 0.5f))));

                vl::vec3 r(vtmp);
                r += utmp;
                r += n*z;

                r.normalize();

                set s;

                vl::vec4 rr(r, 0.0);

                bool hit = t.rayTrace(p, rr, s);
                int pos = x + y*width;
                if (hit)
                {
                    vl::vec3 dd = eye + z*n;
                    s.cut_under(dd.length());

                    set::dn dis_norm = s.find_min();

                    float phong = 0.3f + 0.7f*dot(-r, dis_norm.n)*fabs(60.0f/(dis_norm.d+70.0f));

                    pixels[pos] = phong*255 > 255 ? 255 : phong*255;
                }
                else
                    pixels[pos] = 0;
            }
        }
    }
    else
    {
        t.prepare();
        // standard
        for (int z=0; z<sface.get_depth(); z++)
        {
            float zz = ((float)z/(float)sface.get_depth())*2 - 1;
            for (int y=0; y<sface.get_height(); y++)
            {
                float yy = ((float)y/(float)sface.get_height())*2 - 1;
                for (int x=0; x<sface.get_width(); x++)
                {
                    float xx = ((float)x/(float)sface.get_width())*2 - 1;

                    vl::vec4 p(xx, yy, zz, 1);

                    bool hit = t.rayTrace(p);

                    int pos = x + y*sface.get_width() + z*sface.get_width()*sface.get_height();

                    sface.get_voxels()[pos] = hit ? 1 : 0;
                }
            }
        }

		/*int n = 2;
		int min = -n, max = n;
		int row = max - min + 1;
		int cmin = row*row*row/2.0-2;
		for (int z=n; z<sface.get_depth()-n; z++)
        {
            for (int y=n; y<sface.get_height()-n; y++)
            {
                for (int x=n; x<sface.get_width()-n; x++)
                {
					int j,k,l;
					int count = 0;
					for (j = min; j < max+1; j++)
						for (k = min; k < max+1; k++)
							for (l = min; l < max+1; l++)
							{
								int jj = x + j;
								int kk = y + k;
								int ll = z + l;
								int pos = jj + kk*sface.get_width() + ll*sface.get_width()*sface.get_height();
								if (sface.get_voxels()[pos])
									count++;
							}
					
					int pos = x + y*sface.get_width() + z*sface.get_width()*sface.get_height();
                    sface.get_voxels()[pos] = count >= cmin ? 1 : 0;
                }
            }
        }*/
    }

    sface.set_update();
	//delete t;
}

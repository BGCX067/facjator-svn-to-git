#pragma once

#include <vector>
#include <list>
#include <utility>
#include  <algorithm>
#include "vlCore/Vector3.hpp"
#include "vlCore/Matrix4.hpp"
#include "../math/vector.hpp"
#include "node.hpp"

class set
{
    public:
        // odleglosc i normalna
        struct dn
        {
            float d;
            vl::vec3 n;

            dn() {}
            dn(float _d, vl::vec3& _n) : d(_d), n(_n) {}
            dn(float _d, vl::vec3  _n) : d(_d), n(_n) {}

            dn& operator=(const dn& b)
            {
                d = b.d;
                n = b.n;
                return *this;
            }

            bool operator> (const dn& b)
            {
                return d > b.d;
            }

            bool operator< (const dn& b)
            {
                return d < b.d;
            }

            dn operator-()
            {
                return dn(d, -n);
            }
        };

    private:
        typedef std::pair<dn, dn> t_pair;
        typedef std::list<t_pair> t_set_list;
        t_set_list set_list;

        int overlap_add(t_pair& p1, t_pair& p2, t_pair& p3)
        {
            if ((p1.first < p2.first) && (p1.second > p2.first))
            {
                p3.first  = p1.first;
                p3.second = p1.second < p2.second ? p2.second : p1.second;

                return 1;
            }
            else if ((p1.first > p2.first) && (p1.first < p2.second))
            {
                p3.first  = p2.first;
                p3.second = p1.second > p2.second ? p1.second : p2.second;

                return 1;
            }

            return 0;
        }

        int overlap_mul(t_pair& p1, t_pair& p2, t_pair& p3)
        {
            if ((p1.first < p2.first) && (p1.second > p2.first))
            {
                p3.first  = p2.first;
                p3.second = p1.second < p2.second ? p1.second : p2.second;

                return 1;
            }
            else if ((p1.first > p2.first) && (p1.first < p2.second))
            {
                p3.first  = p1.first;
                p3.second = p1.second > p2.second ? p2.second : p1.second;

                return 1;
            }

            return 0;
        }

        int overlap_sub(t_pair& p1, t_pair& p2, t_pair& p3, t_pair& p4)
        {
            if ((p1.first < p2.first) && (p1.second > p2.first))
            {
                if (p1.second < p2.second)
                {
                    p3.first    = p1.first;
                    p3.second   =-p2.first;

                    return 1;
                }
                else
                {
                    p3.first    = p1.first;
                    p3.second   =-p2.first;

                    p4.first    =-p2.second;
                    p4.second   = p1.second;

                    return 2;
                }
            }
            else if ((p1.first > p2.first) && (p1.first < p2.second))
            {
                if (p2.second < p1.second)
                {
                    //p3.first    = p2.first;
                    //p3.second   =-p1.first;
                    p3.first    =-p2.second;
                    p3.second   = p1.second;

                    return 1;
                }
                else
                {
                    //p3.first    = p2.first;
                    //p3.second   =-p1.first;

                    //p4.first    =-p1.second;
                    //p4.second   = p2.second;

                    return -1;
                }
            }

            return 0;
        }

        int overlap_xor(t_pair& p1, t_pair& p2, t_pair& p3, t_pair& p4)
        {
            if ((p1.first < p2.first) && (p1.second > p2.first))
            {
                if (p1.second < p2.second)
                {
                    p3.first    = p1.first;
                    p3.second   =-p2.first;

                    p4.first    =-p1.second;
                    p4.second   = p2.second;

                    return 2;
                }
                else
                {
                    p3.first    = p1.first;
                    p3.second   =-p2.first;

                    p4.first    =-p2.second;
                    p4.second   = p1.second;

                    return 2;
                }
            }
            else if ((p1.first > p2.first) && (p1.first < p2.second))
            {
                if (p2.second < p1.second)
                {
                    p3.first    = p2.first;
                    p3.second   =-p1.first;

                    p4.first    =-p2.second;
                    p4.second   = p1.second;

                    return 2;
                }
                else
                {
                    p3.first    = p2.first;
                    p3.second   =-p1.first;

                    p4.first    =-p1.second;
                    p4.second   = p2.second;

                    return 2;
                }
            }

            return 0;
        }

        void add_to_list(t_set_list& s, t_pair& p)
        {
            bool found = false;

		    for (t_set_list::iterator i=s.begin(); i!=s.end(); i++)
		    {
		        t_pair tmp;
		        if (overlap_add(*i, p, tmp))
		        {
		            i = s.erase(i);
		            s.insert(i, tmp);
		            found = true;
		            break;
		        }
		    }

		    if (!found)
		    {
		        // in future - sort
		        s.push_back(p);
		    }
        }

    public:
        set() {}
        ~set() {}

        inline set &operator += (set &s)
		{
		    t_set_list tmp_set_list;
		    for (t_set_list::iterator i=set_list.begin(); i!=set_list.end(); i++)
		    {
		        bool found = false;
		        for (t_set_list::iterator j=s.set_list.begin(); j!=s.set_list.end();)
		        {
		            t_pair tmp;
		            if (overlap_add(*i, *j, tmp))
		            {
		                add_to_list(tmp_set_list, tmp);
		                j = s.set_list.erase(j);
		                found = true;
		            }
		            else
                        j++;
		        }

		        if (!found)
                    add_to_list(tmp_set_list, *i);
		    }

            for (t_set_list::iterator i=s.set_list.begin(); i!=s.set_list.end(); i++)
                add_to_list(tmp_set_list, *i);

		    set_list.swap(tmp_set_list);

   			return *this;
		}

       	inline set &operator -= (set &s)
		{
		    t_set_list tmp_set_list;
		    for (t_set_list::iterator i=set_list.begin(); i!=set_list.end(); i++)
		    {
		        bool found = false;
		        for (t_set_list::iterator j=s.set_list.begin(); j!=s.set_list.end(); j++)
		        {
		            t_pair tmp1, tmp2;
		            int ss;
		            if ((ss = overlap_sub(*i, *j, tmp1, tmp2)) > 0)
		            {
		                add_to_list(tmp_set_list, tmp1);
		                if (ss == 2)
                            add_to_list(tmp_set_list, tmp2);

		                found = true;
		            }
		            else if (ss == -1)
                        found = true;
		        }

		        if (!found)
                    add_to_list(tmp_set_list, *i);
		    }

		    set_list.swap(tmp_set_list);

   			return *this;
		}

       	inline set &operator *= (set &s)
		{
		    t_set_list tmp_set_list;
		    for (t_set_list::iterator i=set_list.begin(); i!=set_list.end(); i++)
		    {
		        for (t_set_list::iterator j=s.set_list.begin(); j!=s.set_list.end(); j++)
		        {
		            t_pair tmp;
		            if (overlap_mul(*i, *j, tmp))
		            {
		                add_to_list(tmp_set_list, tmp);
		            }
		        }
		    }

		    set_list.swap(tmp_set_list);

   			return *this;
		}

       	inline set &operator /= (set &s)
		{
		    t_set_list tmp_set_list;
		    for (t_set_list::iterator i=set_list.begin(); i!=set_list.end(); i++)
		    {
		        bool found = false;
		        for (t_set_list::iterator j=s.set_list.begin(); j!=s.set_list.end();)
		        {
		            t_pair tmp1;
		            t_pair tmp2;
		            int ss;
		            if ((ss = overlap_xor(*i, *j, tmp1, tmp2)) > 0)
		            {
		                add_to_list(tmp_set_list, tmp1);
		                if (ss == 2)
                            add_to_list(tmp_set_list, tmp2);

                        j = s.set_list.erase(j);

		                found = true;
		            }
		            else
                        j++;
		        }

		        if (!found)
                    add_to_list(tmp_set_list, *i);
		    }

            for (t_set_list::iterator i=s.set_list.begin(); i!=s.set_list.end(); i++)
                add_to_list(tmp_set_list, *i);

		    set_list.swap(tmp_set_list);

   			return *this;
		}

        inline set operator + (set &s)
		{
		    set tmp_set;
		    for (t_set_list::iterator i=set_list.begin(); i!=set_list.end(); i++)
		    {
		        bool found = false;
		        for (t_set_list::iterator j=s.set_list.begin(); j!=s.set_list.end();)
		        {
		            t_pair tmp;
		            if (overlap_add(*i, *j, tmp))
		            {
		                add_to_list(tmp_set.set_list, tmp);
		                j = s.set_list.erase(j);
		                found = true;
		            }
		            else
                        j++;
		        }

		        if (!found)
                    add_to_list(tmp_set.set_list, *i);
		    }

            for (t_set_list::iterator i=s.set_list.begin(); i!=s.set_list.end(); i++)
                add_to_list(tmp_set.set_list, *i);

		    return tmp_set;
		}

       	inline set operator - (set &s)
		{
		    set tmp_set;
		    for (t_set_list::iterator i=set_list.begin(); i!=set_list.end(); i++)
		    {
		        bool found = false;
		        for (t_set_list::iterator j=s.set_list.begin(); j!=s.set_list.end(); j++)
		        {
		            t_pair tmp1, tmp2;
		            int ss;
		            if ((ss = overlap_sub(*i, *j, tmp1, tmp2)) > 0)
		            {
		                add_to_list(tmp_set.set_list, tmp1);
		                if (ss == 2)
                            add_to_list(tmp_set.set_list, tmp2);

		                found = true;
		            }
		        }

		        if (!found)
                    add_to_list(tmp_set.set_list, *i);
		    }

   			return tmp_set;
		}

       	inline set operator * (set &s)
		{
		    set tmp_set;
		    for (t_set_list::iterator i=set_list.begin(); i!=set_list.end(); i++)
		    {
		        for (t_set_list::iterator j=s.set_list.begin(); j!=s.set_list.end(); j++)
		        {
		            t_pair tmp;
		            if (overlap_mul(*i, *j, tmp))
		            {
		                add_to_list(tmp_set.set_list, tmp);
		            }
		        }
		    }

   			return tmp_set;
		}

       	inline set operator / (set &s)
		{
		    set tmp_set;
		    for (t_set_list::iterator i=set_list.begin(); i!=set_list.end(); i++)
		    {
		        bool found = false;
		        for (t_set_list::iterator j=s.set_list.begin(); j!=s.set_list.end();)
		        {
		            t_pair tmp1;
		            t_pair tmp2;
		            int ss;
		            if ((ss = overlap_xor(*i, *j, tmp1, tmp2)) > 0)
		            {
		                add_to_list(tmp_set.set_list, tmp1);
		                if (ss == 2)
                            add_to_list(tmp_set.set_list, tmp2);

                        j = s.set_list.erase(j);

		                found = true;
		            }
		            else
                        j++;
		        }

		        if (!found)
                    add_to_list(tmp_set.set_list, *i);
		    }

            for (t_set_list::iterator i=s.set_list.begin(); i!=s.set_list.end(); i++)
                add_to_list(tmp_set.set_list, *i);

   			return tmp_set;
		}

		void add(float t1, vl::vec3& n1, float t2, vl::vec3& n2)
		{
		    dn dn1;
		    dn dn2;

		    dn1.d = t1;
		    dn1.n = n1;
		    dn2.d = t2;
		    dn2.n = n2;

		    t_pair ptmp = std::make_pair(dn1, dn2);
		    add_to_list(set_list, ptmp);
		}

		void add(dn& dn1, dn& dn2)
		{
		    t_pair ptmp = std::make_pair(dn1, dn2);
		    add_to_list(set_list, ptmp);
		}

		void add(t_pair& p)
		{
            add_to_list(set_list, p);
		}

		bool is_empty()
		{
		    return set_list.size() == 0 ? true : false;
		}

		void cut_under(float f)
		{
		    for (t_set_list::iterator i=set_list.begin(); i!=set_list.end(); i++)
		        if (i->first.d < f)
		            if (i->second.d < f)
		            {
                        i = set_list.erase(i);
                        i--;
		            }
                    else
                    {
                        i->first.d = f;
                        i->first.n = vl::vec3(0, 0, 0);
                    }
		}

		void cut_over(float f)
		{
		    for (t_set_list::iterator i=set_list.begin(); i!=set_list.end(); i++)
		        if (i->second.d > f)
		            if (i->first.d > f)
		            {
                        i = set_list.erase(i);
                        i--;
		            }
                    else
                    {
                        i->second.d = f;
                        i->first.n = vl::vec3(0, 0, 0);
                    }
		}

		dn find_min()
		{
            dn min;

            if (set_list.size())
               min = set_list.begin()->first;

		    for (t_set_list::iterator i=set_list.begin(); i!=set_list.end(); i++)
		        if (i->first.d < min.d)
		            min = i->first;

            return min;
		}

		dn find_max()
		{
            dn max;

            if (set_list.size())
               max = set_list.begin()->second;

		    for (t_set_list::iterator i=set_list.begin(); i!=set_list.end(); i++)
		        if (i->second.d > max.d)
		            max = i->second;

            return max;
		}
};

//Klasa bazowa dla terminali i nieterminali
//Typ obiektu jest określany przez to czy ma węzły podrzędne
class GrammarObject // tolua_export
: public Node
{ // tolua_export
    protected:
        vl::mat4 tmpMatrix;
        vl::mat4 tmpMatrixInv;
        std::list<vl::mat4> modelMatrix;

    private:
        void buildModelMatrix();

    public:
        vl::mat4 getModelMatrix() const;

    public:
        // tolua_begin
        GrammarObject();
        virtual ~GrammarObject();

        void scale(float x, float y, float z);
        void translate(float x, float y, float z);
        void rotate(float p, float y, float r);
		void rotateDeg(float p, float y, float r);
        // tolua_end

        virtual void prepare();
        virtual bool hit(vl::vec4& p, vl::vec4& v, set& s);
        virtual bool hit(vl::vec4& p);
        virtual bool rayTrace(vl::vec4& p, vl::vec4& v, set& s);
        virtual bool rayTrace(vl::vec4& p);
        virtual Node::node_ptr clone();
        virtual Node::node_ptr clone(Node::node_ptr);
}; // tolua_export

// kazdy koncowy terminal - taki co nie bedzie mial nic pod sobą

class Sphere : public GrammarObject { // tolua_export
    public:
    // tolua_begin
        Sphere();
        ~Sphere();
    //tolua_end
        virtual bool hit(vl::vec4& p, vl::vec4& v, set& s);
        virtual bool hit(vl::vec4& p);
        virtual Node::node_ptr clone();
}; // tolua_export

class Cylinder : public GrammarObject { // tolua_export
    public:
    // tolua_begin
        Cylinder();
        ~Cylinder();
    //tolua_end
        virtual bool hit(vl::vec4& p, vl::vec4& v, set& s);
        virtual bool hit(vl::vec4& p);
        virtual Node::node_ptr clone();
    private:
        float r;
        float h;
        vl::vec3 rdir;
        vl::vec3 hdir;
        vl::vec3 center;
}; // tolua_export

class Cube : public GrammarObject { // tolua_export
    public:
    // tolua_begin
        Cube();
        ~Cube();
    //tolua_end
        virtual bool hit(vl::vec4& p, vl::vec4& v, set& s);
        virtual bool hit(vl::vec4& p);
        virtual Node::node_ptr clone();
}; // tolua_export


class Cone : public GrammarObject { // tolua_export
    public:
    // tolua_begin
        Cone();
        ~Cone();
    //tolua_end
        virtual bool hit(vl::vec4& p, vl::vec4& v, set& s);
        virtual bool hit(vl::vec4& p);
        virtual Node::node_ptr clone();
    private:
        float r;
        float h;
}; // tolua_export


class Torus : public GrammarObject { // tolua_export
    public:
    // tolua_begin
		Torus();
        Torus(float _R, float _r);
        ~Torus();
    //tolua_end
        virtual bool hit(vl::vec4& p, vl::vec4& v, set& s);
        virtual bool hit(vl::vec4& p);
        virtual Node::node_ptr clone();
	private:
		float R; //promien torusa
		float r; //promien okregu
}; // tolua_export

class Coscos : public GrammarObject { // tolua_export
    public:
    // tolua_begin
		Coscos();
        ~Coscos();
    //tolua_end
        virtual bool hit(vl::vec4& p, vl::vec4& v, set& s);
        virtual bool hit(vl::vec4& p);
        virtual Node::node_ptr clone();
}; // tolua_export

class And : public GrammarObject { // tolua_export
    public:
        And() {}
    // tolua_begin
        And(GrammarObject& t1, GrammarObject& t2);
        And(GrammarObject& t1, GrammarObject& t2, GrammarObject& t3);
        And(GrammarObject& t1, GrammarObject& t2, GrammarObject& t3, GrammarObject& t4);
        And(GrammarObject& t1, GrammarObject& t2, GrammarObject& t3, GrammarObject& t4, GrammarObject& t5);
        ~And();
    //tolua_end
        virtual bool rayTrace(vl::vec4& p, vl::vec4& v, set& s);
        virtual bool rayTrace(vl::vec4& p);
        virtual Node::node_ptr clone();
}; // tolua_export

class Or : public GrammarObject { // tolua_export
    public:
        Or() {}
    // tolua_begin
        Or(GrammarObject& t1, GrammarObject& t2);
        Or(GrammarObject& t1, GrammarObject& t2, GrammarObject& t3);
        Or(GrammarObject& t1, GrammarObject& t2, GrammarObject& t3, GrammarObject& t4);
        Or(GrammarObject& t1, GrammarObject& t2, GrammarObject& t3, GrammarObject& t4, GrammarObject& t5);
        ~Or();
    //tolua_end
        virtual bool rayTrace(vl::vec4& p, vl::vec4& v, set& s);
        virtual bool rayTrace(vl::vec4& p);
        virtual Node::node_ptr clone();
}; // tolua_export

class Diff : public GrammarObject { // tolua_export
    public:
        Diff() {}
    // tolua_begin
        Diff(GrammarObject& t1, GrammarObject& t2);
        Diff(GrammarObject& t1, GrammarObject& t2, GrammarObject& t3);
        Diff(GrammarObject& t1, GrammarObject& t2, GrammarObject& t3, GrammarObject& t4);
        Diff(GrammarObject& t1, GrammarObject& t2, GrammarObject& t3, GrammarObject& t4, GrammarObject& t5);
        ~Diff();
    //tolua_end
        virtual bool rayTrace(vl::vec4& p, vl::vec4& v, set& s);
        virtual bool rayTrace(vl::vec4& p);
        virtual Node::node_ptr clone();
}; // tolua_export

class Xor : public GrammarObject { // tolua_export
    public:
        Xor() {}
    // tolua_begin
        Xor(GrammarObject& f, GrammarObject& s);
        ~Xor();
    //tolua_end
        virtual bool rayTrace(vl::vec4& p, vl::vec4& v, set& s);
        virtual bool rayTrace(vl::vec4& p);
        virtual Node::node_ptr clone();
}; // tolua_export

class Mirror : public GrammarObject { // tolua_export
    public:
        Mirror() {}
    // tolua_begin
        Mirror(GrammarObject& t, char type);
        ~Mirror();
    //tolua_end
        virtual Node::node_ptr clone();
}; // tolua_export
class Plane : public GrammarObject { // tolua_export
    public:
    // tolua_begin
        Plane();
        ~Plane();
    //tolua_end
		virtual bool hit(vl::vec4& p, vl::vec4& v, set& s);
        virtual bool hit(vl::vec4& p);
        virtual Node::node_ptr clone();
}; // tolua_export
class PlaneProp : public GrammarObject { // tolua_export
    public:
    // tolua_begin
		PlaneProp(float _max, float _power);
        PlaneProp(GrammarObject& t1, float _max, float _power);
        ~PlaneProp();

		void p_scale(float x, float y, float z);
        void p_translate(float x, float y, float z);
        void p_rotate(float p, float y, float r);
		void p_rotateDeg(float p, float y, float r);
    //tolua_end
		virtual bool rayTrace(vl::vec4& p, vl::vec4& v, set& s);
        virtual bool rayTrace(vl::vec4& p);
        virtual Node::node_ptr clone();
	private:
		vl::mat4 PlaneProp::getMyModelMatrix() const;
		virtual void prepare();

		float max;
		float power;
		std::list<vl::mat4> myModelMatrix;
		vl::mat4 myTmpMatrix;
        vl::mat4 myTmpMatrixInv;
		vl::mat3 myTmpMatrix3;
		vl::mat3 myTmpMatrixInv3;
}; // tolua_export

void draw(GrammarObject& t); // tolua_export

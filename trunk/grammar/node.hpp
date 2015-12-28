#include <list>

class Node
{
    protected:
        typedef Node* node_ptr;
        typedef const Node* const_node_ptr;
        typedef Node* parent_ptr;
        typedef const Node* const_parent_ptr;
        typedef std::list<node_ptr> t_child_list;

        const_node_ptr _this;
        parent_ptr parent;
        t_child_list childs;

        struct null_deleter {
            void operator()(void const *) const {}
        };

    public:
        Node() : _this(this), parent(), childs() {}

        virtual ~Node()
		{
			//obiekty sa zarzadzane przez lua
			childs.clear();
		}

        bool has_parent()
		{
		    node_ptr p = parent;
			return p;
		}

        bool has_child()
		{
			return childs.size();
		}

		void attach(node_ptr new_child)
        {
            if (new_child->has_parent())
                new_child->detach();

            new_child->parent = (node_ptr)_this;

            childs.push_back(new_child);
        }

		void attach(node_ptr new_child, t_child_list::iterator it)
        {
            if (new_child->has_parent())
                new_child->detach();

            new_child->parent = (node_ptr)_this;

            childs.insert(it, new_child);
        }

		void attach_to(node_ptr p)
        {
            if (has_parent())
                detach();

            parent = p;

            p->childs.push_back((node_ptr)_this);
        }

		void attach_to(node_ptr p, t_child_list::iterator it)
        {
            if (has_parent())
                detach();

            parent = p;

            p->childs.insert(it, (node_ptr)_this);
        }

		t_child_list::iterator detach()
		{
            t_child_list::iterator it;
            node_ptr p = parent;

            if (p && p->childs.size())
            {
                it = std::find(p->childs.begin(), p->childs.end(), _this);
				if (it != p->childs.end())
					it = p->childs.erase(it);
            }

            return it;
		}

		virtual node_ptr clone()
		{
		    node_ptr n(new Node);

		    if (has_parent())
            {
                node_ptr p = parent;
                p->attach(n);
            }

            for (t_child_list::iterator i = childs.begin(); i!=childs.end(); i++)
            {
                n->attach((*i)->clone());
            }

            return n;
		}

		virtual node_ptr clone(node_ptr n)
		{
		    if (has_parent())
            {
                node_ptr p = parent;
                p->attach(n);
            }

            for (t_child_list::iterator i = childs.begin(); i!=childs.end(); i++)
            {
                n->attach((*i)->clone());
            }

            return n;
		}
};

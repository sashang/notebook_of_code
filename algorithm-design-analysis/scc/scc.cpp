#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <fstream>
#include <map>
#include <memory>
#include <list>
#include <sstream>

using namespace std;

class Edge;
typedef shared_ptr<Edge> EdgePtr;

class Vertex
{
    private:
        uint32_t _label;
        std::list<EdgePtr> _edges;
        bool _explored;
        uint32_t _leader;
        uint32_t _ft;

    public:
        Vertex(uint32_t label) :
            _label(label), _explored(false), _leader(0), _ft(0) {}

        Vertex(const Vertex& v) :
            _label(v._label), _edges(v._edges), _leader(v._leader), _ft(v._ft) {}

        bool operator==(const Vertex& rhs) const
        {
            return _label == rhs._label;
        }

        bool operator<(const Vertex& rhs) const
        {
             return _label < rhs._label;
        }

        void add_edge(EdgePtr m)
        {
            _edges.push_back(m);
        }

        uint32_t leader() const { return _leader; }

        uint32_t& leader() { return _leader; }

        uint32_t label() const { return _label; }
        uint32_t& label() { return _label; }

        uint32_t ft() const { return _ft; }
        uint32_t& ft() { return _ft; }

        std::list<EdgePtr> edges() {return _edges;}
        
        bool is_explored() const { return _explored; }

        void explore() {_explored = true;}

        void unexplore() {_explored = false;}

        void print() const;
};

typedef shared_ptr<Vertex> VertexPtr;

class Edge
{
    private:
        VertexPtr _u;
        VertexPtr _v;

    public:
        Edge(VertexPtr u, VertexPtr v) : 
            _u(u), _v(v) {}

        void print() const
        {
            cout << "(" << _u->label() << ", " << _v->label() << ")";
        }

        VertexPtr u() const { return _u; }

        VertexPtr v() const { return _v; }

};

typedef shared_ptr<Edge> EdgePtr;

void Vertex::print() const
{
    cout << _label << ": ";
    if (_explored)
    {
        cout << " explored: ";
    }
    else
    {
        cout << " not explored: ";
    }
    cout << "leader: " << _leader << " ";
    cout << "ft: " << _ft << " ";
    for_each(_edges.begin(), _edges.end(), [](EdgePtr m) { m->print(); });
}

void print_graph(std::list<EdgePtr>& edges, std::map<uint32_t, VertexPtr>& vertices)
{
    for_each(vertices.begin(), vertices.end(),
            [](auto n)
            {
                n.second->print();
                cout << endl;
            });
    cout << endl;
    for_each(edges.begin(), edges.end(), [](EdgePtr m){m->print();});
}

void dfs_helper(std::map<uint32_t, VertexPtr>& vertices, VertexPtr& n, uint32_t leader, uint32_t& t, map<uint32_t, VertexPtr>& ft_ordering)
{
    n->explore();
    n->leader() = leader;
    for (auto&& m : n->edges())
    {
        //go in reverse
        if (n->label() == m->v()->label())
        {
            //we can use this edge so find the target vertex
            auto search = vertices.find(m->u()->label());
            assert(search != vertices.end());
            VertexPtr target(search->second);
            if (!target->is_explored())
            {
                dfs_helper(vertices, target, leader, t, ft_ordering);
            }
        }
    }
    t++;
    n->ft() = t;
    ft_ordering.insert(make_pair(t, n));
}

void dfs(std::map<uint32_t, VertexPtr>& vertices, map<uint32_t, VertexPtr>& ft_ordering)
{
    uint32_t t = 0; //finishing time
    uint32_t leader = 0;
    for(auto it = vertices.rbegin(); it != vertices.rend(); ++it)
    {
        VertexPtr n(it->second);
        if (!n->is_explored())
        {
            leader = n->label();
            dfs_helper(vertices, n, leader, t, ft_ordering);
        }
    }
}

void dfs2_helper(map<uint32_t, VertexPtr>& ft_ordering, VertexPtr& n, uint32_t& count)
{
    n->explore();
    count++;
    for (auto&& m : n->edges())
    {
        if (n->ft() == m->u()->ft())
        {
            //we can use this edge so find the target vertex
            auto search = ft_ordering.find(m->v()->ft());
            if (search == ft_ordering.end())
            {
                cout << "Failed to find " << m->v()->ft() << endl;
                m->v()->print();
                cout << endl;
                m->u()->print();
                cout << endl;
                m->print();
                cout << endl;
                assert(false);
            }
            VertexPtr target(search->second);
            if (!target->is_explored())
            {
                dfs2_helper(ft_ordering, target, count);
            }
        }
    }
}

void dfs2(map<uint32_t, VertexPtr>& ft_ordering, vector<uint32_t>& scc_sizes)
{
    uint32_t count = 0;
    for(auto it = ft_ordering.rbegin(); it != ft_ordering.rend(); ++it)
    {
        VertexPtr n(it->second);
        if (!n->is_explored())
        {
            count = 0;
            dfs2_helper(ft_ordering, n, count);
            scc_sizes.push_back(count);
        }
    }
}

void clear_explored(map<uint32_t, VertexPtr>& vertices)
{
    for (auto&& n : vertices)
    {
        n.second->unexplore();
    }
}

void check_explored(std::map<uint32_t, VertexPtr>& vertices)
{
    for_each(vertices.begin(), vertices.end(), 
            [](auto p)
            {
                VertexPtr n(p.second);
                if (!n->is_explored())
                {
                    cout << n->label() << " not explored\n" << endl;
                }
            });
}

void check_ft(map<uint32_t, VertexPtr>& vertices)
{
    for_each(vertices.begin(), vertices.end(),
            [](auto p)
            {
                VertexPtr n(p.second);
                if (n->ft() == 0)
                {
                    cout << "vertex " << n->label() << " has 0 ft!\n" << endl;
                    assert(false);
                }
                
            });
}

int main(int argc, char* argv[])
{
    std::list<EdgePtr> edges;
    std::map<uint32_t, VertexPtr> vertices;
    std::map<uint32_t, VertexPtr> ft_ordering; //finishing time ordering of vertices in the graph.
    if (argc < 2)
    {
        printf("Usage: ./scc <filename>\n");
        return 1;
    }
    fstream f(argv[1]);
    string line;
    while (getline(f, line))
    {
        uint32_t u, v;
        stringstream ss(line);
        ss >> u >> v;
        if (u == v)
        {
            auto search = vertices.find(u);
            VertexPtr v1 = nullptr;
            if (search == vertices.end())
            {
                //make a new vertex
                v1 = make_shared<Vertex>(u);
            }
            else
            {

                v1 = search->second;
            }
            EdgePtr m(new Edge(v1, v1));
            edges.push_back(m);
            v1->add_edge(m);
            vertices.insert(make_pair(u, v1));
        }
        else
        {
            auto search_u = vertices.find(u);
            auto search_v = vertices.find(v);
            VertexPtr v1 = nullptr;
            VertexPtr v2 = nullptr;
            if (search_u == vertices.end())
            {
                //make a new vertex
                v1 = make_shared<Vertex>(u);
            }
            else
            {

                v1 = search_u->second;
            }

            if (search_v == vertices.end())
            {
                //make a new vertex
                v2 = make_shared<Vertex>(v);
            }
            else
            {
                v2 = search_v->second;
            }
            //by now both vertices have been found or created
            EdgePtr m(new Edge(v1, v2));
            edges.push_back(m);
            v1->add_edge(m);
            v2->add_edge(m);
            vertices.insert(make_pair(u, v1));
            vertices.insert(make_pair(v, v2));
        }
    }
    dfs(vertices, ft_ordering);
    check_explored(vertices);
    clear_explored(vertices);
    check_ft(vertices);
    vector<uint32_t> scc_sizes;
    dfs2(ft_ordering, scc_sizes);
    sort(scc_sizes.begin(), scc_sizes.end());
    cout << "Top 5 SCCs: ";
    uint32_t i = 0;
    for (auto it = scc_sizes.rbegin(); i < 5 && it != scc_sizes.rend(); ++it, ++i)
    {
        cout << *it << ",";
    }
    cout << endl;
    return 0;
}

#include <iostream>
#include <set>
#include <sstream>
#include <queue>
#include <memory>
#include <array>
#include <vector>
#include <list>
#include <fstream>
#include <algorithm>
#include <map>

using namespace std;

class Edge;
typedef shared_ptr<Edge> EdgePtr;

class Vertex
{
    private:
        uint32_t _label;
        std::list<EdgePtr> _edges;
        uint32_t _dist;

    public:
        Vertex(uint32_t label) :
            _label(label), _dist(1000000) {}

        Vertex(const Vertex& v) :
            _label(v._label) {}

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

        uint32_t label() const { return _label; }
        uint32_t& label() { return _label; }
        uint32_t dist() const { return _dist; }
        uint32_t& dist() { return _dist; }

        std::list<EdgePtr> edges() {return _edges;}
        
        void print() const;
};

typedef shared_ptr<Vertex> VertexPtr;

class Edge
{
    private:
        VertexPtr _u;
        VertexPtr _v;
        uint32_t _weight;

    public:
        Edge(VertexPtr u, VertexPtr v, uint32_t weight) : 
            _u(u), _v(v), _weight(weight) {}

        void print() const
        {
            cout << "(" << _u->label() << ", " << _weight << ", " << _v->label() << ")";
        }

        VertexPtr u() const { return _u; }

        VertexPtr v() const { return _v; }

        uint32_t weight() const { return _weight; }

};

typedef shared_ptr<Edge> EdgePtr;


void Vertex::print() const
{
    cout << _label << ": " << "dist: " << _dist << " ";
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

struct Compare
{
    bool operator()(VertexPtr v, VertexPtr u)
    {
        u->dist() > v->dist();
    }
};

void dijkstra_shortest_path(map<uint32_t, VertexPtr>& vertices)
{
    VertexPtr start(vertices[1]);
    start->dist() = 0;
    priority_queue<VertexPtr, vector<VertexPtr>, Compare> min_heap;
    for (auto&& it : vertices)
    {
        min_heap.push(it.second);
    }
    set<uint32_t> visited;
    while (!min_heap.empty())
    {
        VertexPtr u(min_heap.top());
        min_heap.pop();
        //we haven't visited it then process it.
        if (visited.find(u->label()) == visited.end())
        {
            for (auto m : u->edges())
            {
                if (m->u()->label() == u->label())
                {
                    VertexPtr v(m->v());
                    uint32_t temp = u->dist() + m->weight();
                    if (temp < v->dist())
                    {
                        v->dist() = temp;
                        min_heap.push(v);
                    }
                }
                else
                {
                    VertexPtr v(m->u());
                    uint32_t temp = u->dist() + m->weight();
                    if (temp < v->dist())
                    {
                        v->dist() = temp;
                        min_heap.push(v);
                    }
                }
            }
        }
        else
        {
            visited.insert(u->label());
        }
    }
}

void read(const std::string& filename, map<uint32_t, VertexPtr>& vertices, list<EdgePtr>& edges)
{
    fstream f(filename);
    string line;
    while (getline(f, line))
    {
        uint32_t u, v, weight;
        char t;
        stringstream ss(line);
        ss >> u;
        auto search_u = vertices.find(u);
        VertexPtr v1 = nullptr;
        if (search_u == vertices.end())
        {
            v1 = make_shared<Vertex>(u);
            vertices.insert(make_pair(u, v1));
        }
        else
        {
            v1 = search_u->second;
        }
        while (ss.good())
        {
            ss >> v >> t >> weight;
            if (u == v)
            {
                EdgePtr m(new Edge(v1, v1, weight));
                edges.push_back(m);
                v1->add_edge(m);
            }
            else
            {
                VertexPtr v2 = nullptr;
                if (u < v)
                {
                    auto search_v = vertices.find(v);
                    if (search_v == vertices.end())
                    {
                        v2 = make_shared<Vertex>(v);
                    }
                    else
                    {
                        v2 = search_v->second;
                    }
                    EdgePtr e(new Edge(v1, v2, weight));
                    v1->add_edge(e);
                    v2->add_edge(e);
                    edges.push_back(e);
                    vertices.insert(make_pair(v, v2));
                }
            }
        }
    }
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cout << "usage: ./dijkstra <filename>" << endl;
        return -1;
    }
    string filename(argv[1]);
    map<uint32_t, VertexPtr> vertices;
    list<EdgePtr> edges;
    read(filename, vertices, edges);
    print_graph(edges, vertices);
    dijkstra_shortest_path(vertices);
    cout << endl;
    print_graph(edges, vertices);
}


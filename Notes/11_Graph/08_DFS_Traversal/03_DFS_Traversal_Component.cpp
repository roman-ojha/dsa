#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <stack>
using namespace std;

class Edge
{
public:
    int src;
    int dest;
    Edge(int s, int d) : src(s), dest(d) {}
};

class Graph
{
public:
    // for dfs recursive
    vector<bool> *visited;
    int vertex;

    Graph(int vertex)
    {
        this->vertex = vertex;
        this->visited = new vector<bool>(this->vertex, false);
    }

    void createGraph(vector<vector<Edge>> *graph)
    {
        for (int i = 0; i < this->vertex; i++)
        {
            vector<Edge> vec;
            graph->push_back(vec);
        }

        // Created Graph with Disconnected component
        // Graph created according to '../09_BFS_Traversal/Docs/23_BFS_on_Disconnected_Component.png'
        graph->at(0).push_back({0, 1});

        graph->at(1).push_back({1, 0});
        graph->at(1).push_back({1, 2});

        graph->at(2).push_back({2, 1});

        graph->at(3).push_back({3, 4});

        graph->at(4).push_back({4, 3});
    }

    void dfs(vector<vector<Edge>> *graph)
    {
        stack<int> s;
        vector<bool> *visited = new vector<bool>(this->vertex, false);

        s.push(0);
        (*visited)[0] = true;
        while (!s.empty())
        {
            int v = s.top();
            cout << v << " ";
            s.pop();
            for (int i = 0; i < (int)graph->at(v).size(); i++)
            {
                int av = graph->at(v)[i].dest;
                if (!(*visited)[av])
                {
                    s.push(av);
                    (*visited)[av] = true;
                }
            }
        }
    }

    void dfsRecursive(vector<vector<Edge>> *graph, int curr)
    {
        int v = curr;
        (*this->visited)[v] = true;
        cout << curr << " ";
        for (int i = 0; i < (int)graph->at(v).size(); i++)
        {
            int av = graph->at(v)[i].dest;
            if (!(*this->visited)[av])
            {
                dfsRecursive(graph, av);
            }
        }
    }
};

int main()
{
    // Number of vertex
    int V = 7;

    vector<vector<Edge>> *graph = new vector<vector<Edge>>;

    Graph g(V);
    g.createGraph(graph);

    // if we have to visit the disconnected component graph
    // then we will loop for all the vertices to check is that visited
    // if that is visited than we don't have to performing BFS from that vertex
    for (int i = 0; i < V; i++)
    {
        if (!g.visited->at(i))
        {
            g.dfsRecursive(graph, i);
        }
    }

    return 0;
}
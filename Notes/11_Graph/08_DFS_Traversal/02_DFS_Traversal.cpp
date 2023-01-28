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

        /*
            1 ---   3
            /       | \
            0       |   5 -- 6
            \       | /
            2 ---- 4
        */
        // Graph created according to './Docs/21_DFS.png'
        graph->at(0).push_back({0, 1});
        graph->at(0).push_back({0, 2});

        graph->at(1).push_back({1, 0});
        graph->at(1).push_back({1, 3});

        graph->at(2).push_back({2, 0});
        graph->at(2).push_back({2, 4});

        graph->at(3).push_back({3, 1});
        graph->at(3).push_back({3, 4});
        graph->at(3).push_back({3, 5});

        graph->at(4).push_back({4, 2});
        graph->at(4).push_back({4, 3});
        graph->at(4).push_back({4, 5});

        graph->at(5).push_back({5, 3});
        graph->at(5).push_back({5, 4});
        graph->at(5).push_back({5, 6});

        graph->at(6).push_back({6, 5});
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
    g.dfs(graph);
    // 0 2 4 5 6 3 1

    cout << endl;

    // g.dfsRecursive(<graph>, <start>)
    g.dfsRecursive(graph, 0);
    // 0 1 3 4 2 5 6

    return 0;
}
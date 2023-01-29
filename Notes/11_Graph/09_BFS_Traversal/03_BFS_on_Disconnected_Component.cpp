#include <iostream>
#include <vector>
#include <queue>
#include <array>
using namespace std;

class Edge
{
public:
    int src;
    int dest;
    Edge(int s, int d) : src(s), dest(d) {}
};

void createGraph(vector<vector<Edge>> *graph, int vertex)
{
    for (int i = 0; i < vertex; i++)
    {
        vector<Edge> vec;
        graph->push_back(vec);
    }

    // Graph created according to './Docs/23_BFS_on_Disconnected_Component.png'
    // Created Graph with Disconnected component
    graph->at(0).push_back({0, 1});

    graph->at(1).push_back({1, 0});
    graph->at(1).push_back({1, 2});

    graph->at(2).push_back({2, 1});

    graph->at(3).push_back({3, 4});

    graph->at(4).push_back({4, 3});
}

void bfs(vector<vector<Edge>> *graph, int V, vector<bool> *visited, int start)
{
    // V: total number of vertex
    // visited: array containing the visited array
    // start: given the start pos to start he BFS
    queue<int> q;
    q.push(start);
    visited->at(start) = true;
    while (!q.empty())
    {
        int vertex = q.front();
        cout << vertex << " ";
        q.pop();
        for (int i = 0; i < (int)graph->at(vertex).size(); i++)
        {
            int av = graph->at(vertex).at(i).dest;
            if (!visited->at(av))
            {
                q.push(av);
                visited->at(av) = true;
            }
        }
    }
}

int main()
{
    // Number of vertex
    int V = 7;

    vector<vector<Edge>> *graph = new vector<vector<Edge>>;
    createGraph(graph, V);

    // we will use one visited array
    vector<bool> *visited = new vector<bool>(V, false);
    // if we have to visit the disconnected component graph
    // then we will loop for all the vertices to check is that visited
    // if that is visited than we don't have to performing BFS from that vertex
    for (int i = 0; i < V; i++)
    {
        if (!visited->at(i))
        {
            bfs(graph, V, visited, i);
        }
    }

    return 0;
}
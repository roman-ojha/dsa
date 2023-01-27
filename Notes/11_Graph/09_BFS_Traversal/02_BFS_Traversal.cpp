#include <iostream>
#include <vector>
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

    /*
        1 ---   3
        /       | \
        0       |   5 -- 6
        \       | /
        2 ---- 4
    */
    // Graph created according to './Docs/01_BFS.png'
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

int main()
{
    // Number of vertex
    int V = 7;

    vector<vector<Edge>> *graph = new vector<vector<Edge>>;
    createGraph(graph, V);

    return 0;
}
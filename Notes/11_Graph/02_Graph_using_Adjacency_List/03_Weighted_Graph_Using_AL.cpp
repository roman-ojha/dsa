/*
    => Undirected weighted graph
*/
#include <iostream>
#include <vector>
#include <array>
using namespace std;

class Edge
{
public:
    int src;
    int dest;
    int wt; // weight
    Edge(int s, int d, int w) : src(s), dest(d), wt(w) {}
};

void createGraph(vector<vector<Edge>> *graph, int vertex)
{
    for (int i = 0; i < vertex; i++)
    {
        vector<Edge> vec;
        graph->push_back(vec);
    }
    // Created graph according to the './Docs/03_Adjacency_List_with_Weighted.png'
    graph->at(0).push_back({0, 2, 2});

    graph->at(1).push_back({1, 2, 10});
    graph->at(1).push_back({1, 3, 0});

    graph->at(2).push_back({2, 0, 2});
    graph->at(2).push_back({2, 1, 10});
    graph->at(2).push_back({2, 3, -1});

    graph->at(3).push_back({3, 1, 0});
    graph->at(3).push_back({3, 2, -1});
}

int main()
{
    int V = 4;

    vector<vector<Edge>> *graph = new vector<vector<Edge>>;
    createGraph(graph, V);

    // print 2's neighbour & its weight
    int vertex = 2;
    for (int i = 0; i < (int)graph->at(vertex).size(); i++)
    {
        Edge e = graph->at(2)[i];
        cout << e.dest << ", " << e.wt << " " << endl;
    }

    return 0;
}
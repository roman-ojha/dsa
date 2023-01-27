/*
    => We can represent Adjacency list in the form of:
        1. Array of Array list
            -> V : total vertex
            -> int Array[]
            -> ArrayList<Edge> Graph[V]
        2. Hashmap

    => Edge:
        -> class Edge{
            int src;
            int dest;
        }
    => Or for edge we can use C++ STL std::pair
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
    Edge(int s, int d) : src(s), dest(d) {}
};

void createGraph(vector<vector<Edge>> *graph, int vertex)
{
    for (int i = 0; i < vertex; i++)
    {
        // pushing vec instance into graph to store list of Edges
        vector<Edge> vec;
        graph->push_back(vec);
    }

    // // graph->at(<for_vertex>)->push_back({<from>, <to>});
    graph->at(0).push_back({0, 2});

    graph->at(1).push_back({1, 2});
    graph->at(1).push_back({1, 3});

    graph->at(2).push_back({2, 0});
    graph->at(2).push_back({2, 1});
    graph->at(2).push_back({2, 3});

    graph->at(3).push_back({3, 1});
    graph->at(3).push_back({3, 2});

    // NOTE: most of the case we will use adjacency list for graph because
    // If we have to find the neighbour of given vertex
    // EX: for vertex 2
    // all the destination from the vertex 2 are the neighbour of the given vertex
    // here we are not taking extra space
    // and it will be fast to calculate the neighbour of the vertex
}

int main()
{
    // Number of vertex
    int V = 4;

    // vector<Edge *> *graph = new vector<Edge *>(4, NULL);
    vector<vector<Edge>> *graph = new vector<vector<Edge>>;
    createGraph(graph, V);

    // print 2's neighbour
    int vertex = 2;
    for (int i = 0; i < (int)graph->at(vertex).size(); i++)
    {
        Edge e = graph->at(2)[i];
        cout << e.dest << " ";
    }

    return 0;
}
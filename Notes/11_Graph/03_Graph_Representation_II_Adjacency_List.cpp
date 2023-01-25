/*
    # Adjacency List
        => an adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a vertex in the graph
        => and the size of the List will be equal to the number of the vertex
        => Advantages:
            *) Saves Spaces O(|V|+|E|) -> No. of vertices + No. of Edges
            *) Adding an edge takes O(1) time
            *) Adding an Vertex takes O(1) time
        => Disadvantages:
            *) Queries like whether there is and edge from vertex u to vertex v are not efficient and can be done O(V)
            *) Time taken to remove an edge takes O(E) time
            *) Time taken to remove a vertex O(V+E) time
*/

#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
// #define V 5;
int V = 5;
void displayUnweightedGraph(vector<int> graph[])
{
    for (int i = 0; i < V; i++)
    {
        cout << i;
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << " -> " << graph[i][j];
        }
        cout << endl;
    }
}

void displayWeightedGraph(vector<pair<int, int>> graph[])
{
    for (int i = 0; i < V; i++)
    {
        cout << i;
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << " -> |" << graph[i][j].first << "|" << graph[i][j].second << "|";
        }
        cout << endl;
    }
}

void addEdge(vector<int> graph[], int u, int v)
{
    graph[u].emplace_back(v);
}

void addWeightedEdge(vector<pair<int, int>> graph[], int u, int v, int weight)
{
    graph[u].emplace_back(make_pair(v, weight));
}

int main()
{
    // Here we create a Array of vectors,
    // every vector represents adjacency list of a vertex

    vector<int> unweightedGraph[V];
    addEdge(unweightedGraph, 0, 1);
    // addEdge(<array>,<vertex>,<adjacent>)
    addEdge(unweightedGraph, 0, 4);
    addEdge(unweightedGraph, 1, 1);
    addEdge(unweightedGraph, 1, 2);
    addEdge(unweightedGraph, 1, 3);
    addEdge(unweightedGraph, 1, 4);
    addEdge(unweightedGraph, 3, 2);
    addEdge(unweightedGraph, 3, 4);
    displayUnweightedGraph(unweightedGraph);

    vector<pair<int, int>> weightedGraph[V];
    cout << "For Weighted graph: " << endl;
    addWeightedEdge(weightedGraph, 0, 1, 1);
    // addEdge(<array>,<vertex>,<adjacent>,<weight>)
    addWeightedEdge(weightedGraph, 0, 4, 5);
    addWeightedEdge(weightedGraph, 1, 1, 2);
    addWeightedEdge(weightedGraph, 1, 2, 3);
    addWeightedEdge(weightedGraph, 1, 3, 4);
    addWeightedEdge(weightedGraph, 1, 4, 2);
    addWeightedEdge(weightedGraph, 3, 2, 2);
    addWeightedEdge(weightedGraph, 3, 4, 3);
    displayWeightedGraph(weightedGraph);
    return 0;
}
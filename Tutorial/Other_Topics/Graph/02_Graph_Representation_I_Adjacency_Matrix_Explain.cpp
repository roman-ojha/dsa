/*
    # 
        =>Following are the most commonly used representation of a graph:
            *) Adjacency Matrix
            *) Adjacency List
            *) Incidence Matrix/Incidence List
        => The choice of graph representation depends on the type of operations to be performed and ease of use.

    # Adjacency Matrix
        => An Adjacency Matrix A[v][v] is a 2D array of size V*V where V is the number of vertices in a graph.
        => In this matrix, both rows and columns represent vertices. this matrix is filled with either 1 (or weight) of 0.
        => 1(or weight) represents that there is an edge from row vertex to column vertex
        => 0 represents that there is no edge form row vertex to column vertex.
        => Advantages:
            1) Easy to understand and implement.
            2) Adding/ removing an edge takes O(1) time.
            3) Queries like whether there is and edge form vertes 'u' to vetes 'v' are efficient and canbe done 
        => Disadvantages:
            1) Consumes more space O(V^2).Even if the graph is spares, it consumes the same space. 
            2) Adding/Removing a vetex is O(V^2) times
*/

#include <iostream>
#include <stdio.h>
#define V 5
using namespace std;

void displayGraph(int graph[][V])
{
    cout << "Adjacency matrix:";
    cout << "\t";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << graph[i][j] << "  ";
        }
        cout << endl;
        cout << "\t\t\t";
    }
}

void addEdge(int graph[][V], int u, int v)
{
    graph[u][v] = 1;
}

int main()
{
    int graph[V][V] = {0};
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 3, 2);
    addEdge(graph, 3, 2);
    addEdge(graph, 3, 4);
    displayGraph(graph);
    return 0;
}
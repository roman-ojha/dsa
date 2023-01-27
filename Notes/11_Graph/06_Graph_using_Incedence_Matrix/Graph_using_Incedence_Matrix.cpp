/*
    # Inclidence Matrix
        => an incidence matrix is a matrix where each column represents an edge connected to two vertices.
        => In this representation, the graph is represented using a matrix of V*E.
        => Possible values for undirected graph: 0,1
        => Possible values for directed graph: 0,1,-1
        => Disadvantages:
            *) It uses O(VE) space as opposed to O(V^2) for the adjacency matrix
            *) Checking if a node is related to some other node is O(E), so it's worse than an adjacency matrix for this.
            *) Traversing a node's adjacencies is O(E), so it's worse than an adjacency list for this.
*/

#include <iostream>
#include <stdio.h>
#define V 5
#define E 5
#include <vector>
using namespace std;

void displayIncidenceMatrixGraph(int graph[][E])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < E; j++)
        {
            if (graph[i][j] == -1)
            {
                // to display to properly
                cout << graph[i][j] << "  ";
            }
            else
            {
                cout << " " << graph[i][j] << "  ";
            }
        }
        cout << endl;
    }
}

void addIncidenceMatrixEdge(int graph[][E], int u, int v, int e)
{
    graph[u][e] = 1;
    if (u != v)
    {
        graph[v][e] = -1;
    }
}

int main()
{
    // For incidence matrix:
    // 2d array of V*E
    int incidenceMatrixGraph[V][E] = {0};

    addIncidenceMatrixEdge(incidenceMatrixGraph, 0, 1, 0);
    // addIncidenceMatrixEdge(<incidenceMatrixGraph>, <start>, <end>, <edge>)
    addIncidenceMatrixEdge(incidenceMatrixGraph, 0, 4, 1);
    addIncidenceMatrixEdge(incidenceMatrixGraph, 1, 4, 2);
    addIncidenceMatrixEdge(incidenceMatrixGraph, 1, 3, 3);
    addIncidenceMatrixEdge(incidenceMatrixGraph, 1, 1, 5);
    addIncidenceMatrixEdge(incidenceMatrixGraph, 1, 2, 6);
    addIncidenceMatrixEdge(incidenceMatrixGraph, 0, 1, 0);
    addIncidenceMatrixEdge(incidenceMatrixGraph, 0, 4, 4);
    addIncidenceMatrixEdge(incidenceMatrixGraph, 0, 2, 7);
    displayIncidenceMatrixGraph(incidenceMatrixGraph);

    return 0;
}
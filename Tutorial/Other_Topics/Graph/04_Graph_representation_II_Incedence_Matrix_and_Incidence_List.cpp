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
    # Incidence List:
        => A list which stores for each vertex a list of objects representing the edges incident to that vertex.
        => To complete the structure, each edge must point back to the two vertices forming its endpoints.
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

void displayIncidenceListGraph(vector<pair<int, int>> graph[])
{
    for (int i = 0; i < V; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < graph[i].size(); j++)
        {
            cout << "|" << graph[i][j].first << "|" << graph[i][j].second << "|"
                 << " -> ";
        }
        cout << endl;
    }
}

void addIncidenceListEdge(vector<pair<int, int>> graph[], int u, int v, int e)
{
    graph[u].emplace_back(make_pair(e, v));
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

    // For incidence List:
    vector<pair<int, int>> incidenceListGraph[V];
    addIncidenceListEdge(incidenceListGraph, 0, 4, 1);
    addIncidenceListEdge(incidenceListGraph, 1, 4, 2);
    addIncidenceListEdge(incidenceListGraph, 1, 3, 3);
    addIncidenceListEdge(incidenceListGraph, 1, 1, 5);
    addIncidenceListEdge(incidenceListGraph, 1, 2, 6);
    addIncidenceListEdge(incidenceListGraph, 3, 4, 4);
    addIncidenceListEdge(incidenceListGraph, 3, 2, 7);
    displayIncidenceListGraph(incidenceListGraph);
    return 0;
}
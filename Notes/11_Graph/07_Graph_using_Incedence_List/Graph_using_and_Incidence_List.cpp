/*
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
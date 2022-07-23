#include <iostream>
#include <stdio.h>
using namespace std;
#define V 5

void displayGraph(int graph[][V], int u, int v)
{
    for (int row = 0; row < u; row++)
    {
        for (int colm = 0; colm < v; colm++)
        {
            cout << graph[row][colm] << "   ";
        }
        cout << endl;
    }
}

void addEdges(int graph[][V], int u, int v)
{
    graph[u][v] = 1;
}

int main()
{
    int graph[V][V] = {0};
    addEdges(graph, 0, 1);
    addEdges(graph, 0, 4);
    addEdges(graph, 1, 0);
    addEdges(graph, 1, 1);
    addEdges(graph, 1, 2);
    addEdges(graph, 1, 3);
    addEdges(graph, 1, 4);
    addEdges(graph, 2, 1);
    addEdges(graph, 2, 3);
    addEdges(graph, 3, 1);
    addEdges(graph, 3, 2);
    addEdges(graph, 3, 4);
    addEdges(graph, 4, 0);
    addEdges(graph, 4, 1);
    addEdges(graph, 4, 3);
    displayGraph(graph, V, V);
    return 0;
}
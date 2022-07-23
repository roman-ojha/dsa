#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct AdjListNode
{
    // A structure to represent an adjacency list node
    int dest;
    struct AdjListNode *next;
};

struct AdjList
{
    // A structure to represent an adjacency list
    struct AdjListNode *head;
};

// A structure to represent a graph. A graph
// is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
struct Graph
{
    int V;
    struct AdjList *arry;
};
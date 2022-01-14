#include <stdio.h>
#include <stdlib.h>

int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int A[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}};

/*
    NOTE: we don't have to make our own stack data structure because in programming language function already use stack as the data structre and we will use it as recursively
*/
void DFS(int i)
{
    // i is the not that we are visiting
    printf("%d ", i);
    visited[i] = 1;
    // mark node as visited
    for (int j = 0; j < 7; j++)
    {
        if (A[i][j] == 1 && !visited[j])
        {
            // if adjacent vertices if the node is not visited then we will implement ths
            DFS(j);
        }
    }
}

int main()
{
    // DFS Implementation
    DFS(0);
    // starting node is 0
    return 0;
}

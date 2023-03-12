#include <iostream>
#define V 5
#define INF 999

void floyd_warshall(int D[][V])
{
    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (i == k || j == k)
                    D[i][j] = D[i][j];
                else
                    D[i][j] = std::min(D[i][k] + D[k][j], D[i][j]);
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            std::cout << D[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int graph[V][V] = {
        {0, 3, 8, INF, -4},
        {INF, 0, INF, 1, 7},
        {INF, 4, 0, INF, INF},
        {2, INF, -5, 0, INF},
        {INF, INF, INF, 6, 0},
    };
    floyd_warshall(graph);
    return 0;
}
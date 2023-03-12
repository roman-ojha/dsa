#include <iostream>
using namespace std;

int zero_1_knapsack(int profit[], int weight[], int W, int N)
{
    int K[N + 1][W + 1];
    for (int n = 0; n <= N; n++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (n == 0 || w == 0)
                K[n][w] = 0;
            else if (weight[n - 1] <= w)
            {
                K[n][w] = std::max(K[n - 1][w - weight[n - 1]] + profit[n - 1], K[n - 1][w]);
            }
            else
            {
                K[n][w] = K[n - 1][w];
            }
        }
    }
    for (int n = 0; n <= N; n++)
    {
        for (int w = 0; w <= W; w++)
        {
            std::cout << K[n][w] << " ";
        }
        std::cout << std::endl;
    }

    return K[N][W];
}

int main()
{
    int profit[] = {2, 3, 1, 4};
    int weight[] = {3, 4, 6, 5};
    int capacity = 8;
    int n = 4;
    zero_1_knapsack(profit, weight, capacity, n);
    return 0;
}
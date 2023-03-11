#include <iostream>

int matrix_chain_multiplication(int p[], int n)
{
    int **m = new int *[n];
    int **s = new int *[n];
    int L, i, j, k, temp;
    for (i = 0; i < n; i++)
    {
        m[i] = new int[n];
        s[i] = new int[n];
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            m[i][j] = 0;
            s[i][j] = 0;
        }
    }
    for (i = 0; i < n; i++)
    {
        m[i][i] = 0;
        s[i][i] = 0;
    }
    for (L = 2; L < n; L++)
    {
        for (i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                temp = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (temp < m[i][j])
                    m[i][j] = temp;
            }
        }
    }
    for (i = 1; i < n; i++)
    {
        for (j = 1; j < n; j++)
        {
            std::cout << m[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    return m[1][n - 1];
}

int main()
{
    int p[5] = {3, 4, 5, 2, 3};
    int n = 5;
    std::cout << matrix_chain_multiplication(p, n);
    return 0;
}
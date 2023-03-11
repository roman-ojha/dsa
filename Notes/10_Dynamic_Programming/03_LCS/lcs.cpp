#include <iostream>

int lcs(std::string S1, std::string S2, int m, int n)
{
    int c[m + 1][n + 1];
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (j == 0 || i == 0)
                c[i][j] = 0;
            else if (S1[i - 1] == S2[j - 1])
                c[i][j] = c[i - 1][j - 1] + 1;
            else
                c[i][j] = std::max(c[i - 1][j], c[i][j - 1]);
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << c[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return c[m][n];
}

int main()
{
    std::string S1 = "QPQRR";
    std::string S2 = "PQPRQRP";
    int result = lcs(S1, S2, 5, 7);
    std::cout << "LCS: " << result << std::endl;
    return 0;
}
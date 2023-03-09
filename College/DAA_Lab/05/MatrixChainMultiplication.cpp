#include <iostream>
using namespace std;

int matrix_multiplication(int p[], int n, int *steps)
{
   int **m = new int *[n];
   int **s = new int *[n];
   for (int i = 0; i < n; i++)
   {
      m[i] = new int[n];
      s[i] = new int[n];
      (*steps) += 2;
   }
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < n; j++)
      {
         m[i][j] = 0;
         s[i][j] = 0;
         (*steps) += 2;
      }
   }

   for (int i = 1; i < n; i++)
   {
      m[i][i] = 0;
      (*steps)++;
   }

   for (int l = 2; l < n; l++)
   {
      for (int i = 1; i < n - l + 1; i++)
      {
         int j = i + l - 1;
         m[i][j] = 2147483647;
         (*steps) += 2;
         for (int k = i; k <= j - 1; k++)
         {
            int c = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
            (*steps)++;
            if (c < m[i][j])
            {
               m[i][j] = c;
               s[i][j] = k;
               (*steps) += 2;
            }
         }
      }
   }
   cout << "M table:" << endl;
   for (int i = 1; i < n; i++)
   {
      for (int j = 1; j < n; j++)
      {
         cout << m[i][j] << "\t";
      }
      cout << endl;
   }

   cout << "\nS table:" << endl;
   for (int i = 1; i < n; i++)
   {
      for (int j = 1; j < n; j++)
      {
         cout << s[i][j] << "\t";
      }
      cout << endl;
   }
   return m[1][n - 1];
}

int main()
{
   int p[] = {3, 4, 5, 2, 3};
   int n = 5;
   int steps = 2;
   int min = matrix_multiplication(p, n, &steps);
   steps++;
   cout << "minimum number of matrix multiplications: " << min << endl;
   cout << "Steps: " << steps << endl;
   cout << "Name: Roman Ojha" << endl;
   cout << "Roll: 25" << endl;
   return 0;
}

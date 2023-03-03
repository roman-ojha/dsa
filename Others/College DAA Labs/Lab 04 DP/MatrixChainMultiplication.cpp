#include<iostream>
using namespace std;

int matrix_multiplication(int p[], int n,int *steps) {
   int m[n][n];
   int s[n][n];

   for (int i=1; i<n; i++){
      m[i][i] = 0;
      (*steps)++;
   }

   for (int l=2; l<n; l++) {
      for (int i=1; i<n-l+1; i++) {
         int j = i+l-1;
         m[i][j] = 2147483647;
         (*steps) += 2;
         for (int k=i; k<=j-1; k++) {
            int c = m[i][k] + m[k+1][j] + p[i- 1]*p[k]*p[j];
            (*steps)++;
            if (c < m[i][j]){
               m[i][j] = c;
               s[i][j] = k;
               (*steps) += 2;
            }
         }
      }
   }
   return m[1][n-1];
}

int main() {
   int p[] = {5, 4, 6, 2, 7};
   int n = 5;
   int steps = 2;
   int min = matrix_multiplication(p, n,&steps);
   steps++;
   cout << "minimum number of matrix multiplications: " << min<<endl;
   cout<<"Steps: "<<steps<<endl;
   return 0;
}

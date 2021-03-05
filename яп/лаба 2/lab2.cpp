#include <iostream>
#include <iomanip>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
int GetN();
void NewMatr(double**& M, int n, int m);
void DelMatr(double**& M, int n, int m);
void PrintMatr(double** M, int n, int m, const char* namematr);
void PrintVect(double* x, int n, const char* namematr);
bool minor(double**& M, int n, int m);
void reshuffle(double**& M, int n, int m, int k);
bool Solve(double **&M, double *x, int n, int m);
double det(double** M, int n, int m);
void test(double**& M, int n, int m);
void clone(double**& M, int n, int m, double** M1);
double check(double** M1, int n, int m, double *x);
int main()
{
  int n;
  cout << "Enter size matrix: "; n = GetN();
  int m = n + 1;
  double **A;
  double **A1;
  double *x = new double [n];
  NewMatr(A, n, m);
  test(A, n, m);
  NewMatr(A1, n, m);
  clone(A, n, m, A1);
  PrintMatr(A, n, m, "A");
  if (Solve(A, x, n, m))
  {
    PrintVect(x, n, "x");
    cout << "epsilon = " << check(A1, n, m, x) << endl;
  }
  cout << "det = " << det(A, n, m) << endl;
  DelMatr(A, n, m);
  DelMatr(A1, n, m);
  delete [] x;
  x = NULL;
  return 0;
}
int GetN()
{
  float n;
  do
  {
    cout << "Enter (int) number: ";
    cin >> n;
    if (n <= 0 || (n - (int)n))
      cout << " ---Error, try again..." << endl;
  } while(n <= 0 || (n - (int)n));
  return n;
}
void NewMatr(double**& M, int n, int m)
{
  //cout << "\t-New int matr-" << endl;
  M = new double*[n];
  for(int i = 0; i < n; i++)
    M[i] = new double [m];
}
void DelMatr(double**& M, int n, int m)
{
  //cout << "\t-Delete int matr-"<< endl;
  for(int i = 0; i < n; i++)
    delete [] M[i];
  delete [] M;
}
void PrintMatr(double** M, int n, int m, const char* namematr)
{
  cout << endl << " " << namematr << ":" << endl;
  for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < m; j++)
        cout << setw(10) << M[i][j];
      cout << endl;
    }
    cout << endl;
}
void PrintVect(double* x, int n, const char* namematr)
{
  cout << endl << " " << namematr << ":" << endl;
  for(int i = 0; i < n; i++)
    {
      cout << setw(5) << x[i];
      cout << endl;
    }
    cout << endl;
}
void reshuffle(double**& M, int n, int m, int k)
{
  bool metka = 0;
  for (int i = k + 1; i < n; i++)
  {
    if (M[i][k] != 0)
    {
      metka = true;
      double temp;
      for (int i1 = 0; i1 < m; i1++)
      {
        temp = M[k][i1];
        M[k][i1] = M[i][i1];
        M[i][i1] = temp;
      }
      break;
    }
  }
  if (!metka)
  {
    for (int i = k + 1; i < n; i++)
    {
      if (M[k][i] != 0)
      {
        double temp;
        for (int i1 = 0; i1 < n; i1++)
        {
          temp = M[i1][k];
          M[i1][k] = M[i1][i];
          M[i1][i] = temp;
        }
        break;
      }
    }
  }
}
bool minor(double**& M, int n, int m)
{
  for (int  i = 0; i < n ; i++)
  {
    if (M[i][i] == 0) reshuffle(M, n, m, i);
    if (M[i][i] == 0) return false;
    for (int i1 = i + 1; i1 < n; i1++)
      for (int i2 = i + 1; i2 < m; i2++)
        M[i1][i2] = M[i][i] * M[i1][i2] - M[i][i2] * M[i1][i];
    for (int j = i + 1; j < n; j++)
    {
      M[j][i] = 0;
    }
  }
  PrintMatr(M, n, m, "M");
  return true;
}
bool Solve(double **&M, double *x, int n, int m)
{
  double res = 0;
  if (!minor(M, n, m)) return false;
  for(int i = n - 1; i >= 0; i--)
  {
    res = 0;
    for(int j = i + 1; j <= n - 1; j++)
      res = res - x[j] * M[i][j];
    res += M[i][n];
    x[i] = res / M[i][i];
  }
  return true;
}
double det(double** M, int n, int m)
{
  double det = 1;
  for(int i = 0; i < n; i++)
  {
    det *= M[i][i] / pow(M[i][i], n - 1 - i);
  }
  return det;
}
void test(double**& M, int n, int m)
{
  int k;
  cout << "Enter number test: "; cin >> k;
  switch (k)
  {
    case 1:
    {
      fstream A("data_array.txt", ios::in);
      for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
          A >> M[i][j];
      A.close();
      break;
    }
    case 2:
    {
      double a,b;
      srand(time(0));
      a = -10;
      b = 10;
      for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
          {
            M[i][j] = a + ((double) rand() / RAND_MAX) * (b - a);
          }
      break;
    }
    case 3:
    {
      for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
          if (i == j) M[i][j] = 1;
          else M[i][j] = 0;
      break;
    }
    case 4:
    {
      for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
          M[i][j] = 0;
      break;
    }
    case 5:
    {
      for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
          M[i][j] = 1. / (i + j + 1);
      break;
    }
  }
}
void clone (double**& M, int n, int m, double** M1)
{
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      M1[i][j] = M[i][j];
}
double check(double** M1, int n, int m, double *x)
{
  double epsilon = 0;
  double s;
  for (int i = 0; i < n; i++)
  {
    s = 0;
    for (int j = 0; j < m - 1; j++)
      s += M1[i][j] * x[i];
    if (fabs(s - M1[i][m]) > epsilon) epsilon = fabs(s - M1[i][m]);
  }
  return epsilon;
}

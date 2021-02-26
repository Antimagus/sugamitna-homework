#include <iostream>
#include <iomanip>
using namespace std;
int GetN(); // получение размера
void NewMatr(double**& M, int n, int m); // выделение памяти
void DelMatr(double**& M, int n, int m); // освобождение памяти
void GetMatr(double** M, int n, int m); // считывание с экрана
void PrintMatr(double** M, int n, int m, const char* namematr); // вывод на экран
int main()
{
  int n;
  cout << "Enter size matrix: "; n = GetN();
  double **A;
  NewMatr(A, n, n + 1);
  GetMatr(A, n, n + 1);
  PrintMatr(A, n, n + 1, "A");
  DelMatr(A, n, n + 1);
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
  cout << "\t-New int matr-" << endl;
  M = new double*[n];
  for(int i = 0; i < n; i++)
    M[i] = new double [m];
}
void DelMatr(double**& M, int n, int m)
{
  cout << "\t-Delete int matr-"<< endl;
  for(int i = 0; i < n; i++)
    delete [] M[i];
  delete [] M;
}
void GetMatr(double** M, int n, int m)
{
  cout << "Enter matrix, sized " << n <<" x "<< m << " : " << endl;
  for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
      cin >> M[i][j];
}
void PrintMatr(double** M, int n, int m, const char* namematr)
{
  cout << endl << " " << namematr << ":" << endl;
  for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < m; j++)
        cout << setw(5) << M[i][j];
      cout << endl;
    }
    cout << endl;
}

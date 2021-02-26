#include <iostream>
using namespace std;
int GetN(); // получение размера
void NewMatr(int**& M, int n, int m); // выделение памяти
int main()
{
  
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
void NewMatr(int**& M, int n, int m)
{
  cout << "\t-New int matr-" << endl;
  M = new int*[n];
  for(int i = 0; i < n; i++)
    M[i] = new int [m];
}

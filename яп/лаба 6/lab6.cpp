#include <iostream>
#include "Tree.h"
using namespace std;
int main()
{
  int n = 5;
  int mas[] = {2,5,3,4,1};
  Tree* T = NULL;
  for(int i = 0; i < n; i++) Add(&T, mas[i]);
  PrintLRR(T);
  cout << endl;
  cout << "tree size = " << GetTreeSize(T) << endl;
  system("pause");
  return 0;
}

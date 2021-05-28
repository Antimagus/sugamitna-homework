#include <iostream>
#include "Tree.h"
using namespace std;
int GetTreeSize(Tree* T)
{
  if(!T) return 0;
  if(!T->left & !T->right) return 1;
  int left = 0, right = 0;
  if(T->left) left = GetTreeSize(T->left);
  if(T->right) right = GetTreeSize(T->right);
  return left + right + 1;
}
void Add(Tree*& T, int data)
{
  if(!T)
  {
    T = new Tree;
    T->data = data;
    T->left = NULL;
    T-> right = NULL;
    return;
  }
  if(data < T->data) Add(T->left, data);
  else Add(T->right, data);
}
void PrintLRR(Tree* T)
{
  if(!T) return;
  PrintLRR(T->left);
  cout << T->data << " ";
  PrintLRR(T->right);
}
Tree* Search(Tree*& T, int data)
{
  if(!T) return NULL;
  while(T->data != data)
  {
    if(data < T->data) T = T->left;
    else T = T->right;
    if(!T) break;
  }
  return T;
}
void Delete(Tree*& T)
{
  if(T)
  {
    if(T->left) Delete(T->left);
    if(T->right) Delete(T->right);
    delete T;
    T = NULL;
  }
  else cout << "Tree is empty" << endl;
}

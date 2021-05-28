#include <iostream>
#ifndef Tree_h
#define Tree_h
struct Tree
{
  int data;
  Tree* left;
  Tree* right;
};
int GetTreeSize(Tree*);
void Add(Tree*&, int);
void PrintLRR(Tree*);
Tree* Search(Tree*&, int);
void Delete(Tree*& T);
#endif

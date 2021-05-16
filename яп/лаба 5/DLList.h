#include <iostream>
using namespace std;
#ifndef DLList_h
#define DLList_h
struct DLList
{
  struct Node
  {
    int data;
    Node* next;
    Node* prev;
  };
  Node* F = NULL;
  Node* L = NULL;
  Node* C = NULL;
  int Count;
  void Out();
  void Info();
  void Clear();
  bool MoveNext();
  bool MovePrev();
  bool MoveFirst();
  bool MoveLast();
  bool Init(int);
  bool AddNext(int);
  bool AddPrev(int);
  bool AddFirst(int);
  bool AddLast(int);
  bool Del(int&);
  bool DelNext(int&);
  bool DelPrev(int&);
  bool DelFirst(int&);
  bool DelLast(int&);
};
#endif

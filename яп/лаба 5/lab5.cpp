#include <iostream>
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
void DLList::Out()
{
  if(!F)
  {
    cout << "List is empty" << endl;
    return;
  }
  Node* temp = F;
  cout << "List: ";
  do
  {
      cout << temp->data << " ";
      temp = temp->next;
  }
  while(temp);
  cout << endl;
}
void DLList::Info()
{
  if(Count) cout << "List node count: " << Count << endl;
  else cout << "List is empty" << endl;
  if(C) cout << "Current node data = " << C->data << endl;
}
bool DLList::MoveFirst()
{
  if(!F) return false;
  C = F;
  return true;
}
bool DLList::MoveLast()
{
  if(!L) return false;
  C = L;
  return true;
}
bool DLList::MoveNext()
{
  if(!F) return false;
  if(!C)
  {
    C = F;
    return true;
  }
  if(!C->next) return false;
  C = C->next;
  return true;
}
bool DLList::MovePrev()
{
  if(!F) return false;
  if(!C)
  {
    C = F;
    return true;
  }
  if(!C->prev) return false;
  C = C->prev;
  return true;
}
bool DLList::Init(int data)
{
  if(!F)
  {
    F = new Node;
    L = F;
    C = F;
    F->prev = NULL;
    F->next = NULL;
    F->data = data;
    Count = 1;
    return true;
  }
  else return false;
}
bool DLList::AddNext(int data)
{
  if(!F) return Init(data);
  Node* temp = C->next;
  C->next = new Node;
  C->next->next = temp;
  C->next->prev = C;
  if(!temp) L = C->next;
  else temp->prev = C->next;
  
}

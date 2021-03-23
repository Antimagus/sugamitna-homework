#include <iostream>
using namespace std;
struct MyQueue
{
  struct Node
  {
    int data;
    Node* next;
  };
  Node* First = NULL;
  int Count = 0;
  bool Push(int);
  bool Pop(int&);
  void Info();
};
bool MyQueue::Push(int data)
{
  if(!First)
  {
    First = new Node;
    First -> next = NULL;
    First -> data = data;
    Count = 1;
  }
  else
  {
    Node *temp;
    temp = First;
    while(temp -> next != NULL) temp = temp -> next;
    temp -> next = new Node;
    temp -> next -> data = data;
    temp -> next -> next = NULL;
    Count++;
  }
  return true;
}
bool MyQueue::Pop(int& data)
{
  if(!First) return false;
  Node* temp = First -> next;
  data = First -> data;
  delete First;
  First = temp;
  Count--;
  return true;
}
void MyQueue::Info()
{
  if(!First) cout << "Queue is empty" << endl;
  else
  {
    cout << endl << "Queue info: " << endl;
    cout << "\tQueue size = " << Count << endl;
    cout << "\tFirst data = " << First -> data << endl << endl;
  }
}
int main()
{
  int n = 10, k;
  MyQueue Q;
  Q.Info();
  for(int i = 1; i<= n;i++) Q.Push(i);
  Q.Info();
  while(Q.Pop(k)) cout << " " << k;
  cout << endl;
  Q.Info();
}

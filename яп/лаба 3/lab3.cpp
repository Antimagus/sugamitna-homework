#include <iostream>
using namespace std;
struct MyStack
{
  struct Node
  {
    int data;
    Node *prev;
  };
  Node *Top = NULL;
  int Count;
  bool Push(int);
  bool Pop(int&);
  void Info();
};
bool MyStack::Push(int data)
{
  if(!Top)
  {
    Top = new Node;
    Top -> prev = NULL;
    Count = 1;
  }
  else
  {
    Node *temp;
    temp = new Node;
    temp -> prev = Top;
    Top = temp;
    Count++;
  }
  Top -> data = data;
  return true;
}
bool MyStack::Pop(int &data)
{
  if(!Top) return false;
  Node *temp = Top -> prev;
  data = Top -> data;
  delete Top;
  Top = temp;
  Count--;
  return true;
}
void MyStack::Info()
{
  if(!Top) cout << "Stack is empty" << endl;
  else
  {
    cout << endl << "Stack info: " << endl;
    cout << "\tStack size = " << Count << endl;
    cout <<"\tTop data = " << Top -> data << endl << endl;
  }
}
int main()
{
  int n = 10, k;
  MyStack S;
  S.Info();
  for(int i = 1; i <= n; i++)
    S.Push(i);
  S.Info();
  while(S.Pop(k))
    cout << " " << k;
  cout << endl;
  S.Info();
}

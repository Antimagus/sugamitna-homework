#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct laptop
{
  int memory;
  int RAM;
  string model;
  string color;
};
struct MyQueue
{
  struct Node
  {
    char* data;
    Node* next;
  };
  Node* First = NULL;
  int Count = 0;
  bool Push(laptop);
  bool Pop(laptop&);
};
bool MyQueue::Push(laptop A)
{
  char* d1 = reinterpret_cast<char*>(&A.memory);
  char* d2 = reinterpret_cast<char*>(&A.RAM);
  char* d3 = const_cast<char*>(A.model.c_str());
  char* d4 = const_cast<char*>(A.color.c_str());
  char* data = new char[72];
  for(int i = 0; i < 4; i++) data[i] = d1[i];
  for(int i = 0; i < 4; i++) data[i + 4] = d2[i];
  for(int i = 0; i < 32; i++) data[i + 4 + 4] = d3[i];
  for(int i = 0; i < 32; i++) data[i + 4 + 4 + 32] = d4[i];
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
bool MyQueue::Pop(laptop& A)
{
  char* data;
  if(!First) return false;
  Node* temp = First -> next;
  data = First -> data;
  delete First;
  First = temp;
  Count--;
  A.memory = *(int*) data;
  A.RAM = *(int*) (data + 4);
  A.model = (string) (data + 4 + 4);
  A.color = (string) (data + 4 + 4 + 32);
  delete[] data;
  return true;
}
int main()
{
  MyQueue Q;
  laptop A;
  int m = 1;
  char* data = new char[72];
  fstream f_in("out.dat", ios::in | ios::binary);
  if(f_in)
  {
    while(f_in.read(data, 72))
    {
      A.memory = *(int*) data;
      A.RAM = *(int*) (data + 4);
      A.model = (string) (data + 4 + 4);
      A.color = (string) (data + 4 + 4 + 32);
      Q.Push(A);
    }
  }
  f_in.close();
  delete[] data;
  while(m)
  {
    cout << "1. Add an item to the queue" << endl;
    cout << "2. Pull out an item" << endl;
    cout << "3. Clear the queue" << endl;
    cout << "0. Exit" << endl;
    cin >> m;
    switch(m)
    {
      case 1:
      {
        system("cls");
        cout << "Enter product specifications:" << endl;
        cout << "Memory = "; cin >> A.memory;
        cout << "RAM = "; cin >> A.RAM;
        cout << "Model = "; cin >> A.model;
        cout << "Color = "; cin >> A.color;
        Q.Push(A);
        system("cls");
        break;
      }
      case 2:
      {
        system("cls");
        laptop A_x;
        bool metka = false;
        cout << "Enter product specifications:" << endl;
        cout << "Memory = "; cin >> A_x.memory;
        cout << "RAM = "; cin >> A_x.RAM;
        cout << "Model = "; cin >> A_x.model;
        cout << "Color = "; cin >> A_x.color;
        int Y = Q.Count;
        for(int i = 0; i <= Y; i++)
        {
          Q.Pop(A);
          if(A.memory != A_x.memory || A.RAM != A_x.RAM || A.model != A_x.model || A.color != A_x.color)
          {
            Q.Push(A);
          }
          else
          {
            metka = true;
            break;
          }
        }
        if(!metka) cout << "Product not found" << endl;
        system("pause");
        system("cls");
        break;
      }
      case 3:
      {
        while(Q.Count)
        {
          Q.Pop(A);
          cout << "Memory = " << A.memory << endl;
          cout << "RAM = " << A.RAM << endl;
          cout << "Model = " << A.model << endl;
          cout << "Color = " << A.color << endl << endl;
        }
        system("pause");
        system("cls");
        break;
      }
    }
  }
  while(Q.Count)
  {
    Q.Pop(A);
  }
}

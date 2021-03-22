#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
struct phone
{
  string Model;
  int RAM;
  int Memory;
  int Battery;
};
struct MyStack
{
  struct Node
  {
    phone data;
    Node *prev;
  };
  Node *Top = NULL;
  int Count;
  bool Push(string, int, int, int);
  bool Pop(string&, int&, int&, int&);
  void Info();
};
bool MyStack::Push(string Model, int RAM, int Memory, int Battery)
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
  Top -> data.Model = Model;
  Top -> data.RAM = RAM;
  Top -> data.Memory = Memory;
  Top -> data.Battery = Battery;
  return true;
}
bool MyStack::Pop(string &Model, int &RAM, int &Memory, int &Battery)
{
  if(!Top) return false;
  Node *temp = Top -> prev;
  Model = Top -> data.Model;
  RAM = Top -> data.RAM;
  Memory = Top -> data.Memory;
  Battery = Top -> data.Battery;
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
    cout <<"\tTop Model = " << Top -> data.Model << endl;
    cout <<"\tTop RAM = " << Top -> data.RAM << endl;
    cout <<"\tTop Memory = " << Top -> data.Memory << endl;
    cout <<"\tTop Battery = " << Top -> data.Battery << endl << endl;
  }
}
int main()
{
  MyStack S;
  MyStack V;
  V.Count = 0;
  string Model;
  int RAM, Memory, Battery;
  ifstream file("phone.txt");
  string line;
  while(getline(file, line))
  {
    istringstream line_F(line);
    line_F >> Model >> RAM >> Memory >> Battery;
    S.Push(Model, RAM, Memory, Battery);
  }
  file.close();
  int m = 1;
  while(m)
  {
    S.Info();
    cout << "1. Add product to basket" << endl;
    cout << "2. Pull an item from the basket" << endl;
    cout << "3. Clear the basket" << endl;
    cout << "0. Exit" << endl;
    cin >> m;
    switch(m)
    {
      case 1:
      {
        system("cls");
        cout << "Enter product specifications:" << endl;
        cout << "Model = "; cin >> Model;
        cout << "RAM = "; cin >> RAM;
        cout << "Memory = "; cin >> Memory;
        cout << "Battery = "; cin >> Battery;
        S.Push(Model, RAM, Memory, Battery);
        system("cls");
        break;
      }
      case 2:
      {
        system("cls");
        string Model_x;
        int RAM_x, Memory_x, Battery_x;
        bool metka = false;
        cout << "Enter product specifications:" << endl;
        cout << "Model = "; cin >> Model_x;
        cout << "RAM = "; cin >> RAM_x;
        cout << "Memory = "; cin >> Memory_x;
        cout << "Battery = "; cin >> Battery_x;
        while(S.Count)
        {
          S.Pop(Model, RAM, Memory, Battery);
          if(Model != Model_x || RAM != RAM_x || Memory != Memory_x || Battery != Battery_x)
          {
            V.Push(Model, RAM, Memory, Battery);
          }
          else
          {
            metka = true;
            break;
          }
        }
        if(!metka) cout << "Product not found" << endl;
        while(V.Count)
        {
          V.Pop(Model, RAM, Memory, Battery);
          S.Push(Model, RAM, Memory, Battery);
        }
        system("pause");
        system("cls");
        break;
      }
      case 3:
      {
        system("cls");
        while(S.Count)
        {
          S.Pop(Model, RAM, Memory, Battery);
        }
        break;
      }
    }
  }
}

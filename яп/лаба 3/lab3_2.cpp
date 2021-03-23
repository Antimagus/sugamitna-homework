#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
struct product_group
{
  int quantity;
  double price;
};
struct MyQueue
{
  struct Node
  {
    product_group data;
    Node* next;
  };
  Node* First = NULL;
  int Count = 0;
  double full_cost = 0;
  double income = 0;
  bool Push(product_group);
  bool Pop(product_group&);
  void Info();
};
bool MyQueue::Push(product_group dt)
{
  if(!First)
  {
    First = new Node;
    First -> next = NULL;
    First -> data.quantity = dt.quantity;
    First -> data.price = dt.price;
    Count = 1;
    full_cost += dt.price * dt.quantity;
  }
  else
  {
    Node *temp;
    temp = First;
    while(temp -> next != NULL) temp = temp -> next;
    temp -> next = new Node;
    temp -> next -> data.quantity = dt.quantity;
    temp -> next -> data.price = dt.price;
    temp -> next -> next = NULL;
    Count++;
    full_cost += dt.price * dt.quantity;
  }
  return true;
}
bool MyQueue::Pop(product_group& dt)
{
  if(!First) return false;
  Node* temp = First -> next;
  dt.quantity = First -> data.quantity;
  dt.price = First -> data.price;
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
    cout << "\tFirst quantity = " << First -> data.quantity << endl;
    cout << "\tFirst price = " << First -> data.price << endl << endl;
  }
}
int main()
{
  MyQueue Q;
  product_group dt;
  product_group dt_x;
  ifstream file("warehouse.txt");
  string line;
  while(getline(file, line))
  {
    istringstream line_F(line);
    line_F >> dt.quantity >> dt.price;
    Q.Push(dt);
  }
  file.close();
  int m = 1;
  while(m)
  {
    //Q.Info();
    cout << "1. Receipt of goods" << endl;
    cout << "2. Sale of goods" << endl;
    cout << "3. Report" << endl;
    cout << "0. Exit" << endl;
    cin >> m;
    switch (m)
    {
      case 1:
      {
        system("cls");
        cout << "Enter the price and quantity of the product:" << endl;
        cout << "Quantity = "; cin >> dt.quantity;
        cout << "Price = "; cin >> dt.price;
        Q.Push(dt);
        system("cls");
        break;
      }
      case 2:
      {
        system("cls");
        cout << "Enter the price and quantity of the product:" << endl;
        cout << "Quantity = "; cin >> dt_x.quantity;
        cout << "Price = "; cin >> dt_x.price;
        //
        //
        //
        system("pause");
        system("cls");
        break;
      }
      case 3:
      {
        system("cls");
        cout << "Count = " << Q.Count << endl;
        cout << "Price = " << Q.full_cost << endl;
        cout << "Income = " << Q.income << endl;
        system("pause");
        system("cls");
        break;
      }
    }
  }
}

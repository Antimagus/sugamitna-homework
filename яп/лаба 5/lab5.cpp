#include <iostream>
#include "DLList.h"
using namespace std;
struct Cup
{
  double volume;
  double height;
  double diameter;
  string material;
};
void* Cup_init()
{
  Cup* A = new Cup;
  cout << "Enter your data:" << endl;
  cout << "Volume = "; cin >> A->volume;
  cout << "Height = "; cin >> A->height;
  cout << "Diameter = "; cin >> A->diameter;
  cout << "Material = "; cin >> A->material;
  void* S = (void*) A;
  return S;
}
void Cup_del(void* S)
{
  delete (Cup*) S;
}
void Cup_cup(void* S, Cup& A)
{
  A = *((Cup*) S);
}
void Cup_out(DLList List)
{
  Cup A;
  List.MoveFirst();
  system("cls");
  if(!List.Count)
  {
    cout << "List is empty" << endl;
    return;
  }
  for(int i = 0; i < List.Count; i++)
  {
    Cup_cup(List.C->data, A);
    cout << "Volume = " << A.volume << endl;
    cout << "Height = " << A.height << endl;
    cout << "Diameter = " << A.diameter << endl;
    cout << "Material = " << A.material << endl << endl;
    List.MoveNext();
  }
}
int main()
{
  DLList List;
  void* S;
  Cup A;
  int m = 1;
  while(m)
  {
    system("cls");
    cout << "Add element:" << endl;
    cout << "1 in the beginning" << endl;
    cout << "2 in the end" << endl;
    cout << "3 in the k-position" << endl;
    cout << "Delete element:" << endl;
    cout << "4 the first" << endl;
    cout << "5 the last" << endl;
    cout << "6 the k position" << endl;
    cin >> m;
    switch(m)
    {
      case 1:
      {
        system("cls");
        S = Cup_init();
        List.AddFirst(S);
        Cup_out(List);
        system("pause");
        break;
      }
      case 2:
      {
        system("cls");
        S = Cup_init();
        List.AddLast(S);
        Cup_out(List);
        system("pause");
        break;
      }
      case 3:
      {
        system("cls");
        int k;
        cout << "Enter the position number from " << 1 << " to " << List.Count + 1 << endl;
        cout << "k = "; cin >> k;
        k--;
        if(k >= 0 & k <= List.Count)
        {
          S = Cup_init();
          if(k == 0)
          {
            List.AddFirst(S);
          }
          else
          {
            if(k == List.Count)
            {
              List.AddLast(S);
            }
            else
            {
              List.Move_k(k - 1);
              List.AddNext(S);
            }
          }
          Cup_out(List);
        }
        else cout << "error" << endl;
        system("pause");
        break;
      }
      case 4:
      {
        system("cls");
        if(List.DelFirst(S))
        {
          Cup_del(S);
          Cup_out(List);
        }
        else
        {
          cout << "error" << endl;
        }
        system("pause");
        break;
      }
      case 5:
      {
        system("cls");
        if(List.DelLast(S))
        {
          Cup_del(S);
          Cup_out(List);
        }
        else
        {
          cout << "error" << endl;
        }
        system("pause");
        break;
      }
      case 6:
      {
        system("cls");
        int k;
        if(!List.Count)
        {
          cout << "error" << endl;
          system("pause");
          break;
        }
        cout << "Enter the position number from " << 1 << " to " << List.Count << endl;
        cout << "k = "; cin >> k;
        k--;
        if(k >= 0 & k <= List.Count)
        {
          if(k == 0)
          {
            List.DelFirst(S);
          }
          else
          {
            if(k == (List.Count - 1))
            {
              List.DelLast(S);
            }
            else
            {
              List.Move_k(k);
              List.Del(S);
            }
          }
          Cup_out(List);
        }
        else cout << "error" << endl;
        system("pause");
        break;
      }
      case 9:
      {
        List.MoveFirst();
        while(List.Count)
        {
          List.Del(S);
          Cup_del(S);
        }
        Cup_out(List);
        system("pause");
        break;
      }
    }
  }
  List.MoveFirst();
  while(List.Count)
  {
    List.Del(S);
    Cup_del(S);
  }
  system("pause");
  return 0;
}

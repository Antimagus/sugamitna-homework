#include <iostream>
#include "DLList.h"
using namespace std;
int main()
{
  DLList MyList;
  MyList.Out();
  for(int i = 1; i < 10; i++) MyList.AddNext(i);
  MyList.Out();
  cout << endl << "---------------------------------------" << endl;
  MyList.AddFirst(0);
  MyList.AddLast(10);
  MyList.Out();
  MyList.Info();
  cout << endl << "---------------------------------------" << endl;
  if (MyList.MoveFirst()) cout << "First node: " << MyList.C->data << endl;
  if (MyList.MoveNext()) cout << "Second node: " << MyList.C->data << endl;
  if (MyList.MoveLast()) cout << "Last node: " << MyList.C->data << endl;
  if (MyList.MovePrev()) cout << "Previous last node: " << MyList.C->data << endl;
  cout << endl << " ------------------------- " << endl;
  int k;
  MyList.DelFirst(k);
  if (MyList.MoveFirst()) cout << "First node: " << MyList.C->data << endl;
  if (MyList.DelNext(k)) MyList.Out();
  cout << " ------------------------- " << endl;
  MyList.DelLast(k);
  if (MyList.MoveLast()) cout << "Last node: " << MyList.C->data << endl;
  if (MyList.DelPrev(k)) MyList.Out();
  cout << " ------------------------- " << endl;
  MyList.Clear();
  MyList.Out();
  MyList.Info();
  system("pause");
  return 0;
}

#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
int** read_matrix(string, int&, int&);
void delete_matrix(int**&, int);
int* dijkstra(int**, int, int);
void dijkstra_route(int**, int, int, int, int*, stack <int>&);
int main()
{
  ofstream out;
  out.open("out.txt");
  int n, m;
  stack <int> route;
  int** A = read_matrix("data2.txt", n, m);
  if(A == NULL | n != m)
  {
    cout << "error";
    out << "error";
    return 0;
  }
  int start;
  cout << "Enter the vertex number (starting from 1): "; cin >> start;
  start--;
  int* distance = dijkstra(A, n, start);
  for(int i = 0; i < n; i++)
  {
    cout << "Distance from the vertex " << start + 1 << " to vertex " << i + 1 << " = " << distance[i] << endl;
    out << "Distance from the vertex " << start + 1 << " to vertex " << i + 1 << " = " << distance[i] << endl;
  }
  int end;
  cout << "Enter the number of the final vertex for which you want to build the route: "; cin >> end;
  end--;
  dijkstra_route(A, n, start, end, distance, route);
  cout << "Route: " << endl;
  out << "Route: " << endl;
  while(!route.empty())
  {
    cout << " -> " << route.top();
    out << " -> " << route.top();
    route.pop();
  }
  out.close();
  delete_matrix(A, n);
  delete[] distance;
  return 0;
}
int** read_matrix(string file_name, int& n, int& m)
{
  ifstream in(file_name);
  if(in.is_open())
  {
    int count = 0;
    int temp;
    while(!in.eof())
    {
      in >> temp;
      count++;
    }
    in.seekg(0, ios::beg);
    in.clear();
    int count_space = 0;
    char symbol;
    while(!in.eof())
    {
      in.get(symbol);
      if(symbol == ' ') count_space++;
      if(symbol == '\n') break;
    }
    in.seekg(0, ios::beg);
    in.clear();
    n = count / (count_space + 1);
    m = count_space + 1;
    int **x;
    x = new int*[n];
    for(int i = 0; i < n; i++) x[i] = new int[m];
    for(int i = 0; i < n; i++)
    {
      for(int j = 0; j < m; j++)
      {
        in >> x[i][j];
      }
    }
    in.close();
    return x;
  }
  in.close();
  return NULL;
}
void delete_matrix(int**& x, int n)
{
  for (int i = 0; i < n; i++) delete[] x[i];
  delete[] x;
}
int* dijkstra(int** A, int n, int start)
{
  const int inf = INT_MAX;
  int* distance = new int[n];
  bool* visited = new bool[n];
  int index, u;
  for(int i = 0; i < n; i++)
  {
    distance[i] = inf;
    visited[i] = false;
  }
  distance[start] = 0;
  for(int count = 0; count < n - 1; count++)
  {
    int min = inf;
    for(int i = 0; i < n; i++)
    if(!visited[i] && distance[i] <= min)
    {
      min = distance[i];
      index = i;
    }
    u = index;
    visited[u] = true;
    for(int i = 0; i < n; i++)
      if(!visited[i] && A[u][i] && distance[u] != inf && distance[u] + A[u][i] < distance[i]) distance[i] = distance[u] + A[u][i];
  }
  delete[] visited;
  return distance;
}
void dijkstra_route(int** A, int n, int start, int end, int* distance, stack <int>& route)
{
  route.push(end + 1);
  int weight = distance[end];
  while (end != start)
  {
    for (int i = 0; i < n; i++)
      if (A[i][end] != 0)
      {
        int temp = weight - A[i][end];
        if (temp == distance[i])
        {
          weight = temp;
          end = i;
          route.push(i + 1);
        }
      }
  }
}

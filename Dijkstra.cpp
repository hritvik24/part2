#include <iostream>
#include <limits.h>
#define VERTEX 9
using namespace std;
int minimumDistance(int distanceArr[], bool shortestPathTreeSet[])
{
  
int minm = INT_MAX, minimumIndex;
  
for (int v = 0; v < VERTEX; v++)
if (shortestPathTreeSet[v] == false && distanceArr[v] <= minm)
minm = distanceArr[v], minimumIndex = v;
  
return minimumIndex;
}
void Display(int distanceArr[])
{
printf("Vertex \t\t Distance from Source\n");
for (int i = 0; i < VERTEX; i++)
cout<<i<< "\t\t"<< distanceArr[i]<<"\n";
}
void djks(int gphArr[VERTEX][VERTEX], int source)
{
int distanceArr[VERTEX]; // The output array. distanceArr[i] will hold the shortest
  
bool shortestPathTreeSet[VERTEX]; // shortestPathTreeSet[i] will be true if vertex i is included in shortest
for (int i = 0; i < VERTEX; i++)
distanceArr[i] = INT_MAX, shortestPathTreeSet[i] = false;
distanceArr[source] = 0;
  
  
for (int count = 0; count < VERTEX - 1; count++) {
int u = minimumDistance(distanceArr, shortestPathTreeSet);
  
shortestPathTreeSet[u] = true;
  
for (int v = 0; v < VERTEX; v++)
  

if (!shortestPathTreeSet[v] && gphArr[u][v] && distanceArr[u] != INT_MAX
&& distanceArr[u] + gphArr[u][v] < distanceArr[v])
distanceArr[v] = distanceArr[u] + gphArr[u][v];
}
  
Display(distanceArr);
}
int main()
{
int gphArr[VERTEX][VERTEX] = { { 0, 3, 0, 0, 0, 0, 0, 7, 0 },
{ 3, 0, 7, 0, 0, 0, 0, 10, 0 },
{ 0, 7, 0, 7, 0, 3, 0, 0, 2 },
{ 0, 0, 7, 0, 9, 14, 0, 0, 0 },
{ 0, 0, 0, 9, 0, 10, 0, 0, 0 },
{ 0, 0, 3, 14, 10, 0, 2, 0, 0 },
{ 0, 0, 0, 0, 0, 2, 0, 1, 6 },
{ 7, 10, 0, 0, 0, 0, 1, 0, 7 },
{ 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
  
djks(gphArr, 0);

return 0;
}

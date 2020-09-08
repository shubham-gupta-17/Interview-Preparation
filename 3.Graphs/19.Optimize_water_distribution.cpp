#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n=3;
  int wells[3]={1,2,2};
  vector<vector<int>> pipes={{1,2,1},{2,3,1}};
  cout<<optimize_cost(n,wells,pipes);
  return 0;

}

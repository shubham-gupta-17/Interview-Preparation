#include<bits/stdc++.h>
using namespace std;
int fastSpeed = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
}();
vector<vector<int>> arr;
// take input
void input()
{
   int n,m,k;
   cin>>n>>m>>k;
   // n= cities , m=roads, k= min maintenance cost
   for(int i=0;i<m;i++)
    {
      int a,b,c;
      cin>>a>>b>>c;
      arr.push_back({a,b,c});
    }
}

int main()
{
   input();
}

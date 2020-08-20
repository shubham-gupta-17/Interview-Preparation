#include<iostream>
#include<vector>
using namespace std;
int main()
{
  vector<int>nums={3,0,1};
  int n=nums.size();
       if(n==0) return 0;
       int ans=0,i=0;
       for(;i<n;i++){
           ans=(ans^i^nums[i]);
       }

       cout<<(ans^i);
       return 0;
}

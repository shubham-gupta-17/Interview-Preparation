#include<bits/stdc++.h>
using namespace std;
int main()
{
    int nums[8]={4,3,2,7,8,2,3,1};
    int n=8;
       if(n==0) return ans;
       for(int i=0;i<n;i++)
       {
           int m=nums[i];
           while(nums[m-1]!=m) {
               swap(nums[i],nums[m-1]);
                m=nums[i];
           }

       }

       for(int i=0;i<n;i++)
       {
           if(nums[i]!=i+1) cout<<nums[i];
       }
    return 0;
}

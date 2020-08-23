#include<bits/stdc++.h>
using namespace std;
// Question link :https://leetcode.com/problems/first-missing-positive/submissions/
int find_1(int *nums,int n)
{
  if(n==0) return 1;
    int m=1000000;
    int *a=new int[m]();
    for(int i=0;i<n;i++)
    {
        if(nums[i]>=0 && nums[i]<m-1) a[nums[i]]=1;
    }

    for(int i=1;i<m;i++)
    {
        if(a[i]==0) return i;
    }
    return m;
}
int find_2(int *a,int n)
{
    for(int  i=0;i<n;i++)
    {
       if(a[i]==i+1 || a[i]<=0 ||a[i]>n) continue;

       int idx=a[i]-1;
       while(idx>=0 && idx<n && a[idx]!=a[i])
       {
           swap(a[i],a[idx]);
           idx=a[i]-1;
       }
    }

    for(int i=0;i<n;i++)
     {
       if(a[i]!=i+1) return i+1;
     }

     return n+1;
}
int main()
{
    int a={2,2,4};
    int n=3;
    //cout<<find_1(a,n);  // bruteforce O(n) space
    cout<<find_2(a,n);

}

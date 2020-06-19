#include<iostream>
#include<climits>
using namespace std;
//Question link:https://leetcode.com/problems/arithmetic-slices/
int find(int*a,int n)
{
	int result=0;
        int *dp=new int[n]();
        for(int i=2;i<n;i++)
        {
            if(A[i]-A[i-1]==A[i-1]-A[i-2])
                dp[i]=dp[i-1]+1;
            result+=dp[i]!=0?dp[i]:0;
        }
        return result;
}
int find_opti(int*a,int n)
{
        int result=0;
        int prev=0;
        int curr=0;
        for(int i=2;i<n;i++)
        {
            if(A[i]-A[i-1]==A[i-1]-A[i-2])
                curr=prev+1;
            else curr=0;
            result+=curr;
            prev=curr;
        }
        return result;
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<find(a,n);
	cout<<find_opti(a,n);
	return 0;
}
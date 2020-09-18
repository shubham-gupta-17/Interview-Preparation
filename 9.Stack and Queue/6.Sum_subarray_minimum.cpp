#include<bits/stdc++.h>
using namespace std;
// leetcode 907

int sumSubarrayMins(int *arr,int n) {
    
        if(n==0) return 0;
        int mod=(int)1e9+7;
        stack<int> st;
    int *left=new int[n]();
    int *right=new int[n]();
    
    // initialise
    for(int i=0;i<n;i++){
        right[i]=n-i;
        left[i]=i+1;
    }

    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && arr[i]<=arr[st.top()])
        {
            int idx=st.top();
            st.pop();
            left[idx]=idx-i;
        }
        st.push(i);
    }

    stack<int>st1;
     for(int i=0;i<n;i++)
    {
        while(!st1.empty() && arr[i]<arr[st1.top()])  // here = is removed to handle duplicacy eg[71,55,86,55]
        {
            int idx=st1.top();
            st1.pop();
            right[idx]=i-idx;
        }
        st1.push(i);
    }

    int ans=0;
    for(int i=0;i<n;i++)
    {   
       cout<<left[i]<<" "<<right[i]<<endl;
       ans=(ans+arr[i]*left[i]*right[i])%mod;
       
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<sumSubarrayMins(arr,n);
    return 0;
}
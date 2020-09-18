#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    stack<int> st;
    int *left=new int[n]();
    
    // initialise
    for(int i=0;i<n;i++) left[i]=-1;

    for(int i=n-1;i>=0;i--)
    {
        while(!st.empty() && arr[i]<=arr[st.top()])
        {
            int idx=st.top();
            st.pop();
            left[idx]=i;
        }
        st.push(i);
    }

    for(int i=0;i<n;i++)
    {
        if(left[i]==-1) cout<<arr[i]<<" "<<"-1"<<endl;
        else cout<<arr[i]<<" "<<arr[left[i]]<<endl;
    }
    return 0;


}
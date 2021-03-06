#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    stack<int> st;
    int *right=new int[n]();

    // initialise 
    for(int i=0;i<n;i++) right[i]=-1;
    
    // find greatest on right
    for(int i=0;i<n-1;i++)
    {
        while(!st.empty() && arr[i]>=arr[st.top()])
        {
            int idx=st.top();
            st.pop();
            right[idx]=i;
        }
        st.push(i);
    }

    for(int i=0;i<n;i++) {

        if(right[i]==-1) cout<<arr[i]<<" "<<"-1"<<endl;
        else cout<<arr[i]<<" "<<arr[right[i]]<<endl;
    }
    return 0;

}
#include <bits/stdc++.h>
using namespace std;
// leetcode 962
//Resource link:https://leetcode.com/problems/maximum-width-ramp/discuss/265765/Detailed-Explaination-of-all-the-three-approaches

// =======================================================
int maxWidthRamp(vector<int>& A) {
        int n=A.size();
        if(n==0) return 0;
        int ans=0;
        for(int i=0; i<n; i++)
        {
                for(int j=n-1; j>i; j--)
                {
                        if(A[i]<=A[j]) {
                                ans=max(ans,j-i);
                                break;
                        }
                }
        }
        return ans;
}
//============================================================
int maxWidthRamp_sort(vector<int>&a)
{
        int n=a.size();
        if(n==0) return 0;
        vector<vector<int> > idx(n,vector<int>(2,0));
        for(int i=0; i<n; i++)
        {
                idx[i][0]=a[i];
                idx[i][1]=i;
        }

        sort(idx.begin(),idx.end());
        int mn=n-1;
        int ans=0;
        for(int i=0; i<n; i++)
        {
                mn=min(mn,idx[i][1]);
                ans=max(ans,idx[i][1]-mn);
        }
        return ans;
}

//=================================================================
int maxWidthRamp_stack(vector<int>&A)
{
        int n=A.size();
        if(n==0) return 0;
        stack<int> st;
        for(int i=0; i<n; i++)
        {
                if(st.empty() || A[i]<A[st.top()])
                        st.push(i);
        }

        int ans=0;
        for(int i=n-1; i>=0; i--)
        {
                while(!st.empty() && A[i]>=A[st.top()])
                {
                        ans=max(ans,i-st.top());
                        st.pop();
                }
        }
        return ans;
}
int main()
{
        vector<int> a={9,8,1,0,1,9,4,0,4,1};
        // bruteforce will give TLE O(n^2)
        cout<<maxWidthRamp(a)<<endl;

        // using index and sort O(nlogn)

        cout<< maxWidthRamp_sort(a)<<endl;

        // best using stack O(n)
        cout<<maxWidthRamp_stack(a);

        return 0;
}

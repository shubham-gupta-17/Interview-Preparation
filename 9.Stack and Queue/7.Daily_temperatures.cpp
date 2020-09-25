#include <bits/stdc++.h>
using namespace std;
// leetcode 739
vector<int> dailyTemperatures(vector<int>& T) {
        int n=T.size();
        vector<int> ans(n,0);
        if(n==0) return ans;
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && T[i]>T[st.top()])
            {
                int idx=st.top();
                st.pop();
                ans[idx]=i-idx;
            }
            st.push(i);
        }
        return ans;
}
int main()
{
  vector<int> t={73, 74, 75, 71, 69, 72, 76, 73};
  dailyTemperatures();
  return 0;
}

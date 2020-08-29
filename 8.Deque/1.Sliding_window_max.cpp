#include<bits/stdc++.h>
using namespace std;

  // leetcode 239
vector<int> maxSlidingWindow(vector<int>& a, int k) {
        int n=a.size();
        vector<int> ans;
        if(n==0) return ans;
        deque<int> que;
        //process on 1st k elements
        for(int i=0;i<k;i++) {
            while(!que.empty() && a[i]>=a[que.back()]) que.pop_back();
            que.push_back(i);
        }

        for(int i=k;i<n;i++)
        {
            ans.push_back(a[que.front()]);
            // remove elements which are not part of window
            if(!que.empty() && que.front()<=(i-k)) que.pop_front();

            // remove elements which are not useful
            while(!que.empty() && a[i]>=a[que.back()]) que.pop_back();

            // push the next elements;
            que.push_back(i);

        }
        ans.push_back(a[que.front()]);
        return ans;
}
int main()
{
    vector<int> a={1,3,-1,-3,5,3,6,7};
    int k=3;
    maxSlidingWindow(a,k);
    return 0;


}

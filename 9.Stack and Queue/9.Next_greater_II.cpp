// leetcode 503
vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        if(n==0) return ans;
        stack<int> st;
        int *vis=new int[n]();
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && nums[i]>nums[st.top()])
            {
                int idx=st.top();
                st.pop();
                ans[idx]=nums[i];
                vis[idx]=1;
            }
            st.push(i);
        }

        if(st.empty()) return ans;
        for(int i=0;i<n;i++)
        {
             while(!st.empty() && i< st.top() && nums[i]>nums[st.top()])
            {
                int idx=st.top();
                st.pop();
                ans[idx]=nums[i];
                vis[idx]=1;
            }
            if(!vis[i])st.push(i);
        }
        return ans;
}
int main()
{
  vector<int> arr={-1,-2,-1,2,2,1,1};
  nextGreaterElements(arr);
  return 0;
}

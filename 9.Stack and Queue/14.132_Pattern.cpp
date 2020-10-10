#include<bits/stdc++.h>
using namespace std;
bool find132pattern(vector<int>& nums) {
       int n=nums.size();
        stack<int> st;
        int s2=INT_MIN;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<s2) return true;
            
            else while(!st.empty() && nums[i]>nums[st.top()]){
                s2=nums[st.top()];
                st.pop();
            }
            st.push(i);
        }
        return false;
    }
int main()
{
    vector<int>arr={3,5,0,3,4};
    find132pattern(arr);
    return 0;

}
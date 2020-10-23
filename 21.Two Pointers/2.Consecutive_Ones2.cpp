#include<bits/stdc++.h>
using namespace std;
// leetcode 1004
 int longestOnes(vector<int>& A, int K) {
        int start=0;
        int n=A.size();
        int end=0;
        int ans=INT_MIN;
        int zeroCount=0;
        while(end<n){
            if(A[end]==0) zeroCount++;
            while(start <n && zeroCount>K){
                if(A[start]==0) zeroCount--;
                start++;
            }
            ans=max(ans,end-start+1);
            end++;
        }
        return ans;
}
int main(){
    vector<int> nums={0,0,0,1,1,1,1,1,1,1};
    cout<<findMaxConsecutiveOnes(nums);
    return 0;
}
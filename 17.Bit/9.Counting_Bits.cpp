#include<bits/stdc++.h>
using namespace std;
// leetcode 338
 vector<int> countBits(int num) {
        vector<int> ans(num+1,0);
        for(int i=1;i<=num;i++){
            ans[i]=ans[i>>1] + (i&1);
        }
        return ans;
}
int main(){
    countBits(100);
    return 0;
}
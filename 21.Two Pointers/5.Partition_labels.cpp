#include<bits/stdc++.h>
using namespace std;
// leetcode 763
vector<int> partitionLabels(string S) {
        int n=S.length();
        int*vis=new int[26]();
        for(int i=0;i<n;i++) vis[S[i]-'a']=i;
        int max_idx=-1;
        vector<int> ans;
        int last_idx=0;
        for(int i=0;i<n;i++){
            max_idx=max(max_idx,vis[S[i]-'a']);
            if(i==max_idx){
                ans.push_back(i-last_idx+1);
                last_idx=i+1;
                max_idx=-1;
            }
        }
        return ans;
}
int main(){
    partitionLabels("abababababdefdef");
    return 0;
}
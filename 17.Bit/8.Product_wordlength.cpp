#include<bits/stdc++.h>
using namespace std;
// leetcode 318
int maxProduct(vector<string>& words) {
        int n=words.size();
        if(n==0) return 0;
        int *len=new int[n]();
        for(int i=0;i<n;i++){
            string s=words[i];
            int mask=0;
            for(char &ch:s){
                mask |=(1<<(ch-'a'));
            }
            len[i]=mask;
        }
        
        int ans=0;
        int mlen=0;
        for(int i=0;i<n;i++){
            int n1=words[i].length();
            for(int j=i+1;j<n;j++){
                int n2=words[j].length();
                
                if((len[i]&len[j])==0){
                    ans=max(ans,n1*n2);
                }
            }
        }
        return ans;
}
int main(){
    
}
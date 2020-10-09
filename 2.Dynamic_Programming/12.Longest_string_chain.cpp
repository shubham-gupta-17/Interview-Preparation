 #include<bits/stdc++.h>
using namespace std;
// leetcode  1048

 //approach is same as LIS just sort the wordson length
int longestStrChain(vector<string>& words) {
    int n=words.size();
    if(n==0) return 0;
    unordered_map<string,int>dp[n];
    sort(words.begin(),words.end(),[](string a,string b){
       return a.length()<b.length(); 
    });
    
    int ans=0;
    dp[0][words[0]]=1;
    for(int i=1;i<n;i++)
    {
        dp[i][words[i]]=1;
        for(int j=0;j<i;j++){
            
            for(int k=0;k<words[i].length();k++){
                string newstr= words[i].substr(0,k)+words[i].substr(k+1);
                dp[i][words[i]]=max(dp[i][words[i]], dp[j][newstr]+1);
            }
            ans=max(ans,dp[i][words[i]]);
        }
    }
    
    return ans;
}

int longestStrChain_OPTI(vector<string>& words) {
        int n=words.size();
        if(n==0) return 0;
        unordered_map<string,int>dp;
        sort(words.begin(),words.end(),[](string a,string b){
           return a.length()<b.length(); 
        });
        
        int ans=0;
        for(string w: words){
            
            for(int i=0;i<w.length();i++){
                string str= w.substr(0,i)+w.substr(i+1);
                dp[w]=max(dp[w],dp[str]+1);
            }
            ans=max(ans,dp[w]);
        }
        
        return ans;
}
int main()
{

    vector<string> words={"a","b","ba","bca","bda","bdca","bdcae","bdcaf"};
    cout<<longestStrChain(words)<<endl;
     cout<<longestStrChain_OPTI(words)<<endl;
}
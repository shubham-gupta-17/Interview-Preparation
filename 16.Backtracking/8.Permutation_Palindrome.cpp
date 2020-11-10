#include <bits/stdc++.h>
using namespace std;
// find all permutations of string 

void generate_permutation(int i,int len,char odd,string path,unordered_map<char,int> &mp){
    if(i==len){
        string ans=path;
        reverse(path.begin(),path.end());
        if(odd!='1') ans+=odd;
        ans+=path;
        cout<<ans<<" ";
        return ;
    }

    for(auto it:mp){
        char ch=it.first;

        if(mp[ch]<=0) continue;

        int count=it.second;
        mp[ch]--;
        generate_permutation(i+1,len,odd,path+ch,mp);
        mp[ch]++;
    }
    return ;
}
void palindrome(string &s){
    vector<string> ans;
    int n=s.length();

    // make frequency map
    unordered_map<char,int> mp;
    for(char ch:s) mp[ch]++;

    // choose character half of their count and check no of odd characters
    string permute="";
    int odd=0;
    char odd_ch='1';
    int len=0;
    for(auto it: mp){
        if(it.second%2) {
            odd_ch=it.first;
            odd++;
        }
        mp[it.first] /=2;  // decrease their frequency by 2
        len+=mp[it.first];
    }

    generate_permutation(0,len,odd_ch,"",mp);
    mp.clear();
    return ;
}
int main(){
    int t;
    cin>>t;
    while(t--){
    string s;
    cin>>s;
    cout<<"{ ";
    palindrome(s);
    cout<<"}";
    }
    return 0;
}
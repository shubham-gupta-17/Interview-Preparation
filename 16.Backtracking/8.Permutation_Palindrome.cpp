#include <bits/stdc++.h>
using namespace std;
vector<string> palindrome(string &s){
    vector<int> ans;
    int n=s.length();
    // make frequency map
    unordered_map<char,int> mp;
    for(char ch:s) mp[s]++;

    // choose character half of their count and check no of odd characters
    string permute="";
    int odd=0;
    for(auto it: mp){
        if(it.second%2) odd++;
        it.second/=2;  // decrease their frequency by 2
    }

    for(auto it:mp)
    cout<<it.second<<" ";

    return ans;

}
int main(){
    string s="aabbcccbbaa";
    palindrome(s);
    return 0;
}
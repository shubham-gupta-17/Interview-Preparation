#include<bits/stdc++.h>
using namespace std;
// leetcode 1234
int balancedString(string s) {
       int n=s.length();
       int m=n/4;
       unordered_map<char,int> map;
       for(char ch:s)
           map[ch]+=1;
        int start=0;
        int end=0;
        int len=n;
        for(;end<n;end++){
            map[s[end]]--;
            while(start<n && map['Q']<=m && map['W']<=m && map['E']<=m && map['R']<=m){
                len=min(len,end-start+1);
                map[s[start]]++;
                start++;
            }
        }
        return len;
        
}
int main()
{
    string s="WWEQERQWQWWRWWERQWEQ";
    cout<<balancedString(s);
}
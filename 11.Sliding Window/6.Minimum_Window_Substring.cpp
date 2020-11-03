#include <bits/stdc++.h>
using namespace std;
// leetcode 567
 int n;
    int m;
    int find(string &s,int j,unordered_map<char,int> map){
        int count=0;
        int i=j;
        while(i<n){
            if(map.find(s[i])!=map.end() && map[s[i]]>0){
                count++;
                map[s[i]]--;
            }
            if(count==m) return i-j+1;
            i++;
        }
        return INT_MAX-2;
    }
    string minWindow(string s, string t) {
       n=s.length();
       m=t.length();
        
        unordered_map<char,int> map;
        for(char ch:t) map[ch]++;
        int idx=0;
        int len=n+1;
        for(int i=0;i<n;i++){
            int size=find(s,i,map);
            if(size<len){
                idx=i;
                len=size;
            }
        }
        
        if(len>n) return "";
        return s.substr(idx,len);
            
    }
int main()
{
    string s = "cbaacbcbdfsacb";
    string t = "abc";
    cout << balancedString(t, s);
}
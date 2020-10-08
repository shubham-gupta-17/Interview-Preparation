#include<bits/stdc++.h>
using namespace std;
//leetcode 434
int countSegments(string s) {
        int n=s.length();
        if(n==0) return 0;
        stringstream str(s);
        int len=0;
        string word;
        while(str >> word){
            len++;
        }
        return len;
 }
 int main()
 {
 	countSegments("Hello, my name is John");
 	return 0;
 }
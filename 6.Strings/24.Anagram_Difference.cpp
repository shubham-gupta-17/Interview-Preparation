#include<bits/stdc++.h>
using namespace std;
// leetcode 1347

int minSteps(string &s, string &t) {
        int n=s.length();
        int m=t.length();
        if(n!=m) return -1;
        int *ana=new int[26]();
        for(char ch:s) ana[ch-'a']++;
        
        int *anat=new int[26]();
        for(char ch:t) anat[ch-'a']++;
        
        int count=0;
        for(int i=0;i<26;i++){
           if(ana[i]<anat[i]) count+=(anat[i]-ana[i]);
        }
        return count;
    }
int main(){
	cout<<minSteps("friend","family");
	return 0;
}
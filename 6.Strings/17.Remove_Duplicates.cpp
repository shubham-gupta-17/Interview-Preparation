#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin>>s;
	int n=s.length();
	string ans="";
	for(int i=0;i<n;){
		char ch=s[i];
		ans+=ch;
		i++;
		while(i<n && s[i]==ch) i++;
	}
	cout<<ans;
	return 0;
}
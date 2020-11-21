#include<bits/stdc++.h>
using namespace std;
// leetcode 1347
int main(){
	string s="aeiouuuaaa";
	find_Sequence(s,0,0,0,"");
	cout<<len<<endl;
	cout<<find_Sequence_DP(s);
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
// geeksforgeeks.org/longest-ordered-subsequence-of-vowels/
// Approach 1: Recursion 
char vow[5]={'a','e','i','o','u'};
int len=0;
void find_Sequence(string &s,int i,int size,int j,string ans){
	
	if(i==s.length() && j==5){
        //cout<<ans<<endl;
		len=max(len,size);
		return;
	}

	if(i>s.length() || j>5) return ;
	if(s[i]==vow[j]){
		find_Sequence(s,i+1,size+1,j+1,ans+s[i]);
		find_Sequence(s,i+1,size+1,j,ans+s[i]);
	}
	else find_Sequence(s,i+1,size,j,ans);
	return ;

}
// =============================================================================
// Approach 2: DP
int mapp(char ch){
	if(ch=='a') return 0;
	if(ch=='e') return 1;
	if(ch=='i') return 2;
	if(ch=='o') return 3;
	return 4;

}
int find_Sequence_DP(string &s){
	// a->e->i->o->u
	int n=s.length();
	int **dp=new int*[n];
	for(int i=0;i<n;i++)
		dp[i]=new int[5]();

	if(s[0]=='a') dp[0][0]=1;
	int ans=0;
	for(int i=1;i<n;i++){
		// character is not a vowel
		if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u') continue;
		int mapi=mapp(s[i]);
        dp[i][mapi]=1;
		for(int j=0;j<i;j++){

			int mapj=mapp(s[j]);
            // if j char is same as i or j is one less than i
			if(mapi-mapj==1 || mapi-mapj==0)  dp[i][mapi] =max (dp[i][mapi] , dp[j][mapj] + 1);
		}

		ans=max(ans,dp[i][mapi]);
	}
   
	return ans;
}
int main(){
	string s="aeiouuuaaa";
	find_Sequence(s,0,0,0,"");
	cout<<len<<endl;
	cout<<find_Sequence_DP(s);
	return 0;
}
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// leetcode 1079
int subsequence(string&s,bool *vis,int i)
    {
        if(i==s.length()) return 0;
        int count=0;
        bool *vis1=new bool[26]();
        for(int j=0;j<s.length();j++)
        {
            int idx=s[j]-'A';
            if(!vis1[idx] && !vis[j]){
                vis1[idx]=true;
                vis[j]=true;
                count+=subsequence(s,vis,i)+1;
                vis[j]=false;
            }
        }
        return count;
 }
int numTilePossibilities(string &tiles) {
    int n=tiles.length();
    if(n==0) return 0;
    bool *vis=new bool[n]();
    return subsequence(tiles,vis,0);
}

int main()
{
	cout<<numTilePossibilities("AAAAA");
	return 0;
}
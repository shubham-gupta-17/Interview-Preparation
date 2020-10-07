#include<bits/stdc++.h>
using namespace std;
// leetcode 30
 unordered_map<string,int> map;
    int n;
    bool *vis;
    bool find(string &s,int i,int count,int m)
    {
        if(count==n) {
            return true;
        }
        string tar="";
        bool flag=false;
        for(int j=i;j<m;j++)
        {
            tar+=s[j];
            if(map.find(tar)==map.end() || vis[j]) continue;
             if(map[tar]>0){
                map[tar]-=1;
                flag=flag || find(s,j+1,count+1,m);
                map[tar]+=1;
            }
            else vis[j]=true;
        }
        return flag;
        
    }
    vector<int> findSubstring(string &s, vector<string>& words) {
        n=words.size();
        vector<int>ans;
        if(n==0 || s=="") return ans;
        for(string &word:words)
            map[word]+=1;
        int m=s.length();
        for(int i=0;i<m;i++)
        {
            vis=new bool[m]();
            if(find(s,i,0,m)){    
            ans.push_back(i);
            }
        }
        return ans;
    }

//-===============================================================================================================
unordered_map<string,int> map;
    int n;
    bool *vis;
    int k;
    bool find(string &s,int i,int count)
    {
        if(count==n) {
            return true;
        }
        string tar=s.substr(i,k);
        bool flag=false;
             if(map[tar]>0){
                map[tar]-=1;
                flag=flag || find(s,i+k,count+1);
                map[tar]+=1;
            }
        return flag;
        
    }
    vector<int> findSubstring_opti(string &s, vector<string>& words) {
        n=words.size();
        vector<int>ans;
        if(n==0 || s=="") return ans;
        for(string &word:words)
            map[word]+=1;
        int m=s.length();
        k=words[0].length();
        for(int i=0;i<m;i++)
        {
            vis=new bool[m]();
            if(find(s,i,0)){    
            ans.push_back(i);
            }
        }
        return ans;
    }


//=================================================================================================================
void find_Substring_best()
{
	 int n=words.size();
        vector<int>ans;
        if(n==0 || s=="") return ans;
        for(string &word:words)
            map[word]+=1;
        
        int m=s.length();
       int k=words[0].length();
        int t=k*n;
        int i=0;
        while(i<=m-t)
        {
            string s1=s.substr(i,t);
            unordered_map<string,int> map1;
            int r=0;
            int c=0;
            while(r<n){
                string tmp=s1.substr(c,k);
                map1[tmp]+=1;
                c+=k;
                r++;
            }
            if(map==map1) ans.push_back(i);
            i++;
        }
        return ans;

}
int main()
{
	// Approach 1: O(n^2)
	findSubstring();

	// Approach 2:O(n)
	findSubstring_opt();


	//Approach 3:O(n)
	find_substring_best()
	

}

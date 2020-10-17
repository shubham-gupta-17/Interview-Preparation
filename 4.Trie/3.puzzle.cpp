#include<iostream>
#include<vector>
using namespace std;
// leetcode 1178
int **word;
int **puzzle;
int find(string&words,int j,string &puzzles,int i){
    
    if(word[j][puzzles[0]-'a']!=1) return 0;
    for(char &ch:words){
        if(puzzle[i][ch-'a']!=1) return 0;
    }
    return 1;

}
vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
    int n=words.size();
    int m=puzzles.size();
    
    word=new int*[n];
    for(int i=0;i<n;i++) word[i]=new int[26]();
    
    puzzle=new int*[m];
    for(int i=0;i<m;i++) puzzle[i]=new int[26]();
    
    for(int i=0;i<n;i++)
    {   
        for(char &ch:words[i])
            word[i][ch-'a']=1;
    }
    
    for(int i=0;i<m;i++)
    {
        for(char &ch:puzzles[i])
            puzzle[i][ch-'a']=1;
    }
    
    vector<int>ans(m,0);
    for(int i=0;i<m;i++){
        
        for(int j=0;j<n;j++)
        {
            if(find(words[j],j,puzzles[i],i)==1) ans[i]++;
        }
    }
    return ans;
    

}
//=====================================================================================================
//Approach 2
vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int n=puzzles.size();
        int m=words.size();
         vector<int> ans(n,0);
       
        unordered_map<char,vector<int>>map;
        
        for(string &s:words){
            
            int mask=0;
            for(char& ch:s){
                int j=(ch-'a');
                mask = ((1<<j) | mask);
            }
            
            for(int i=0;i<26;i++){
                if((mask&(1<<i))>0) map['a'+i].push_back(mask);
            }
            
        }
      
        for(int i=0;i<n;i++){
            
            string s=puzzles[i];
            int pmask=0;
            for(char ch:s){
                pmask = (pmask | (1<<(ch-'a')));
            }
            int count=0;
            
            for(int  mask : map[puzzles[i][0]]){  
             if(((mask & pmask)==mask)) count++;
            }
            ans[i]=count;
            
        }
        return ans;

}
//==================================================================================================
// Approach 3
 int getmask(string &s){
         int mask=0;
            for(char& ch:s){
                int j=(ch-'a');
                mask = ((1<<j) | mask);
            }
         return mask;
     }
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int n=puzzles.size();
        int m=words.size();
         vector<int> ans;
       
        unordered_map<int,int>map;
        
        for(string &s:words){
           int mask=getmask(s);
           map[mask]+=1;
        }
      
       for(string &s:puzzles){
           int pmask=getmask(s);
           int first=(1<<(s[0]-'a'));
           int count=0;
           for(int i=pmask; i>0 ;i=((i-1) & pmask)){
               if(map.find(i)!=map.end() && (i&first)>0) count+=map[i];
           }
           ans.push_back(count);
       }
        return ans;

}
int main()
{
    vector<string> word={"aaaa","asas","able","ability","actt","actor","access"};
    vector<string>puzzle={"aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"};
    findNumOfValidWords(word,puzzle);
}

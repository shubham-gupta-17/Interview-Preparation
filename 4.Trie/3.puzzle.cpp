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

//============================================================================================
// bit manupluation
int main()
{
    vector<string> word={"aaaa","asas","able","ability","actt","actor","access"};
    vector<string>puzzle={"aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"};
    findNumOfValidWords(word,puzzle);
}
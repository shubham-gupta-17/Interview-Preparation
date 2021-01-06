#include<iostream>
#include<vector>
using namespace std;
// leetcode 1178
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

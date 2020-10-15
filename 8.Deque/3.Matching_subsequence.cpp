#include<bits/stdc++.h>
using namespace std;
// leetcode 792
 int numMatchingSubseq(string S, vector<string>& words) {
        unordered_map<char,deque<string>> map;
        for(string &s:words)
            map[s[0]-'0'].push_back(s);
        
        int count=0;
        for(char &ch:S)
        {
            if(map.find(ch)!=map.end())
            {
                int size=map[ch].size();
                while(size--){
                    string word=map[ch].front();
                    map[ch].pop_front();
                    
                    if(word.length()==1) count++;
                    else map[word[1]].push_back(word.substr(1));
                    
                }
            }
                
        }
        return count;
}
int main()
{
    string s="abcde";
    vector<string> word={"a","bb","acd","ace"};
    numMatchingSubseq(s,word);
    return 0;
    
}
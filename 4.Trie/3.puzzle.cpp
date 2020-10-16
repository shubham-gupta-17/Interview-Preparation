#include<iostream>
  #include<vector>
  using namespace std;
  class Trie{
      public:
        vector<Trie*> arr;
        bool wordend=false;
        string word="";
        Trie(){
            arr.assign(26,nullptr);
        }
        
    };
    Trie *node=new Trie();
    void create(string &s)
    {
        Trie *curr=node;
        bool *vis=new bool[26]();
        for(int i=0;i<s.length();i++)
        {
            int idx=s[i]-'a';
            
            if(curr->arr[idx]==nullptr &&!vis[idx]){
                curr->arr[idx]= new Trie();
                vis[idx]=true;
            }       
            if(curr->arr[idx]!=nullptr)
            curr=curr->arr[idx];
        }
       
        curr->wordend=true;
        curr->word=s;
    }
    void display(Trie *root,int c){
        if(root->wordend) {
            cout<<root->word<<endl;  
        }
        
        for(int i=0;i<26;i++)
        {
            if(root->arr[i]!=nullptr)
                display(root->arr[i],c+1);
        }
        
        return ;
    }
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        int n=puzzles.size();
        vector<int> ans(n,0);
        
       
        for(string &s:words)
            create(s);
        
        dusplay();
        return ans;
    }
int main()
{
    vector<string> word={"aaaa","asas","able","ability","actt","actor","access"};
    vector<string>puzzle={"aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz"};
    findNumOfValidWords(word,puzzle);
}
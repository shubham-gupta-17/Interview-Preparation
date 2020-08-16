  #include<iostream>
  #include<vector>
  using namespace std;
  class Node{
  public:
    bool word_end=false;
    string word="";
    vector<Node*> child;
    Node()
    {
      this->child.assign(26,nullptr);
    }
  };
  Node *root=nullptr;
  void insert(string& word)
  {
    Node *curr=root;
    for(int i=0;i<word.length();i++){
      int idx=word[i]-'a';
      if(curr->child[idx]==nullptr) curr->child[idx]=new Node();
      curr=curr->child[idx];
    }
    curr->word_end=true;
    curr->word=word;
  }

  int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
  vector<string>ans;
  int n,m;
  void dfs(Node *node,int r,int c,vector<vector<char>>&board)
  {
      if(node->word_end)
      {
        node->word_end=false;
        ans.push_back(node->word);
      }

      char ch=board[r][c];
      board[r][c]='#';
      for(int d=0;d<4;d++)
      {
        int x=r+dir[d][0];
        int y=c+dir[d][1];
        if(x>=0 && x<n && y>=0 && y<m && board[x][y]!='#' && node->child[board[x][y]-'a']!=nullptr)
          dfs(node->child[board[x][y]-'a'],x,y,board);
      }
      board[r][c]=ch;
      return ;
  }

  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
       n=board.size();
       m=board[0].size();
       int k=words.size();
       if(n==0 || m==0 || k==0) return {};

       root=new Node();
       for(string &s:words)
         insert(s);

        for(int i=0;i<n;i++)
        {
          for(int j=0;j<m;j++)
          {
              if(root->child[board[i][j]-'a']!=nullptr)
                dfs(root->child[board[i][j]-'a'],i,j,board);
          }
        }

        return ans;

   }
  int main()
  {
    vector<vector<char>> board = {
      {'o','a','a','n'},
      {'e','t','a','e'},
      {'i','h','k','r'},
      {'i','f','l','v'}
    };
    vector<string>  words = {"oath","pea","eat","rain"};

    vector<string> arr=findWords(board,words);
    for(string &s:arr)
      cout<<s<<endl;
    return 0;
  }

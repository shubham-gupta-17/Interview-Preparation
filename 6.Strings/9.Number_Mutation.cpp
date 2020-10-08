#include<bits/stdc++.h>
using namespace std;
// leetcode 433
int minMutation(string start, string end, vector<string>& bank) {
        int n=start.length();
        int m=end.length();
        if(n!=m) return 0;
        unordered_map<string,bool>map;
        for(string &s:bank)
            map[s]=true;
       int mut=0;
       queue<string> que;
        que.push(start);
        
        char ch[4]={'A','C','G','T'};
       while(!que.empty()){
           int size=que.size();
           while(size--){
               string top=que.front();
               que.pop();
            
               if(top==end) return mut;
               
               for(int i=0;i<n;i++){
                   
                   for(int j=0;j<4;j++){
                       char diff=top[i];
                       top[i]=ch[j];
                      
                       if(map[top]){
                           map[top]=false;
                           que.push(top);
                       }

                       top[i]=diff;
                   }
               }
               
           }
           mut++;
       }
       
        return -1;
}

int main()
{
  return 0;
}
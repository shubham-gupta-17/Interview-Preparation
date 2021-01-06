#include<bits/stdc++.h>
using namespace std;
// leetcode 502
#define pp pair<int,int>
class compare{
    public :
    bool operator()(pp p1,pp p2){
        return p1.second < p2.second; 
    }
};
int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
    int n=Capital.size();
    if(n==0) return 0;
    int profit=0;
    priority_queue<pp, vector<pp>, compare> que;
    int i=0;
    
    vector<vector<int>> idx(n,vector<int>(2,0));
    for(int i=0;i<n;i++){
        idx[i][0]=Capital[i];
        idx[i][1]=Profits[i];
    }
    
    sort(idx.begin(),idx.end(),[](vector<int> a,vector<int> b){
            return a[0]<b[0];
    });
    
    //0=cpital 1=profit
    int j=0;
    while(i<k && i<n){
        
        while(j<n &&idx[j][0]<=W )
                que.push({idx[j][0],idx[j++][1]});
            
        
        if(que.empty()) return W;
        W+=que.top().second;
        que.pop();
        i++;
    }
    
    return W;
}

//====================================================================================

class compare{
    public:
    bool operator()(int a,int b){
        return a < b;
    }
};
int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
    int n=Capital.size();
    if(n==0) return 0;
    int i=0;
    int *vis=new int[n]();
    priority_queue<int, vector<int>, compare>que;
    
    while(i<k && i<n){
        for(int j=0;j<n;j++){
            if(Capital[j]<=W && vis[j]==0){
                vis[j]=1;
                que.push(Profits[j]);
            }
                //if(que.size()>1) que.pop();
            
        }
            
            if(que.empty()) return W;
            W+=que.top();
            que.pop();
            i++;
        
    }
    return W;
}
int main(){
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
// leetcode 743
 #define pp vector<int>
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        if(src==dst) return 0;
        priority_queue<pp,vector<pp>,greater<pp>> que;
        que.push({0,K+1,src});
        unordered_map<int,vector<pair<int,int>>> map;
        for(vector<int> arr:flights){
            map[arr[0]].push_back({arr[1],arr[2]});
        }
        bool *vis=new bool[n]();
        int *dis=new int[n]();
        while(!que.empty()){
            int size=que.size();
            while(size--){
                pp top=que.top();
                que.pop();
                int u=top[2];
                int wsf=top[0];
                //if(vis[u]) continue;
                if(u==dst) return wsf;
                if(top[1]==0) continue;
                vis[u]=true;
                dis[u]=wsf;
                for(pair<int,int> p:map[u]){
                    int v=p.first;
                    int w=p.second;
                   // if(!vis[v]){
                        que.push({w+wsf,top[1]-1,v});
                    
                }
            }
        }
        return -1;
    }
int main()
{
    vector<vector<int>> arr = {{2, 1, 1}, {2, 3, 1}, {3, 1, 4}};
    networkDelayTime(arr, 4, 2);
    return 0;
}
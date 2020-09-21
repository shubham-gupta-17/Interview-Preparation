#include<bits/stdc++.h>
using namespace std;
int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        int n=routes.size();
        if(n==0) return 0;
        unordered_map<int,vector<int>> map;
        for(int i=0;i<n;i++)
        {
            for(int stop:routes[i])
                map[stop].push_back(i); //means the ith bus travels through this stop(station)
        }
        
        queue<int> que;
        que.push(S);
        int bus=0;
        unordered_map<int,bool> vis;
        vis[S]=true;
        while(!que.empty())
        {
            int size=que.size();
            while(size--)
            {
                int top=que.front();
                que.pop();
                if(T==top) return bus;
        
                for(int i:map[top])
                {
                    for(int j:routes[i]){
                        if(vis[j]) continue;
                        vis[j]=true;
                        que.push(j);
                    }
                   routes[i].clear();   // as there are lot of insert in map and routes if we clear the routes after traversing it once will reduce iterating it over and over again  
                }
                               
            }
            bus++;
        }
        return -1;
}
int main()
{
    vector<vector<int>> routes={{1,2,7},{3,6,7}};
    int S=1;
    int T=7;
    numBusesToDestination(routes,S,T);
    return 0;
}
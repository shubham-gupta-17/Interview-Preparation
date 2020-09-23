#include<bits/stdc++.h>
using namespace std;
vector<int>arr;
vector<vector<int>>graph;
void create(vector<vector<int>>&edges,int n)
{
    graph.resize(n,vector<int>());
    for(int i=0;i<edges.size();i++)
    {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
}
int find_height(int i,int n)
{
        queue<int> que;
        que.push(i);
        int *vis=new int[n]();
        int height=0;
        while(!que.empty())
        {
            int size=que.size();
            while(size--)
            {
                int top=que.front();
                que.pop();
                if(vis[top]) continue;
                vis[top]=1;

                for(int j:graph[top])
                {
                    if(vis[j]) continue;
                    que.push(j);
                }
            }
            height++;

        }
        return height;
}
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==0) return arr;
        create(edges,n);

        int *ans=new int[n];
        int height=INT_MAX;
        for(int i=0;i<n;i++){
            ans[i]=find_height(i,n);
            height=min(height,ans[i]);
        }

        // find max
        for(int i=0;i<n;i++)
        {
            if(ans[i]==height) arr.push_back(i);
        }

        return arr;

}
int main()
{
    int n=6;
    vector<vector<int>> edges={{3,0},{3,1},{3,2},{3,4},{5,4}};
    findMinHeightTrees(n,edges);
    return 0;
}

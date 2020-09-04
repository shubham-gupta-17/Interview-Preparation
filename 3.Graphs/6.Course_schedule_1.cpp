#include<bits/stdc++.h>
using namespace std;
void add(int u,int v,vector<vector<int>>&graph)
{
        graph[u].push_back(v);
}
bool canFinish(int num, vector<vector<int>>& pre) {
        int n=pre.size();
        if(n==0) return true;

        // make graph
        vector<vector<int>>graph(num,vector<int>());
        for(int i=0;i<n;i++)
            add(pre[i][0],pre[i][1],graph);

        // use khans algo
        vector<int>edge(num,0);
        //count incidentEdges
        for(int i=0;i<num;i++)
        {
            for(int v:graph[i])
                edge[v]++;
        }

        queue<int> que;
        int count=0;
        // find sources
        for(int i=0;i<num;i++)
        {
            if(edge[i]==0) que.push(i);
        }
        if(que.size()==0) return false;

        while(!que.empty())
        {
            int vtx=que.front();
            que.pop();

            count++;
            for(int i:graph[vtx])
            {
                if(--edge[i]==0) que.push(i);
            }
        }

        if(count!=num) return false;
        return true;
}
int main()
{
    vector<vector<int>> arr={{1,0},{0,1}};
    cout<<canFinish(2,arr);
    return 0;

}

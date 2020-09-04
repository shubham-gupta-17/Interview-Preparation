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
vector<int> findOrder(int num, vector<vector<int>>& pre) {
      vector<int>arr;
      if(pre.size()==0) {
          for(int i=0;i<num;i++)
          arr.push_back(i);
          return arr;
      }
      if(canFinish(num,pre)) return ans;
      return arr;
  }
int main()
{
    vector<vector<int>> arr={{1,0},{2,0},{3,1},{3,2}};
    cout<<canFinish(2,arr);
    vector<int> a=findOrder(4,arr);
    return 0;

}

#include<bits/stdc++.h>
using namespace std;
// leetcode 310
// Approach 1: O(n^2) time and O(n) space
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


// ============================================================================================================
 vector<int> findMinHeightTrees_opti(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        vector<int> root;
        
        if(n==1){
            root.push_back(0);
            return root;
        }
         vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        vector<int> root;
        
        if(n==1){
            root.push_back(0);
            return root;
        }
        
        // create a graph using set as we have to find vertexs in O(1);
        vector<unordered_set<int>> graph(n);
        for(int i=0;i<m;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            graph[u].insert(v);
            graph[v].insert(u);
        }
        
        // push leaf nodes in root;
        vector<int> leaf;
        for(int i=0;i<n;i++)
        {
            if(graph[i].size()==1) leaf.push_back(i);
        }
        for(int i:leaf) cout<<i<<" ";
        // keep on removing leaf from graph
        
        while(1)
        {
            vector<int> next;
            for(int vertex: leaf)
            {
                for(int source: graph[vertex])
                {
                    graph[source].erase(vertex);
                    if(graph[source].size()==1) next.push_back(source);
                    //if(graph[source].size()==0) root.push_back(source);
                    
                }
                
            }
             if(next.empty()) return leaf;
                leaf=next;
            
            
        }
        
        return root;
    }
        // create a graph using set as we have to find vertexs in O(1);
        vector<unordered_set<int>> graph(n);
        for(int i=0;i<m;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            graph[u].insert(v);
            graph[v].insert(u);
        }
        
        // push leaf nodes in root;
        vector<int> leaf;
        for(int i=0;i<n;i++)
        {
            if(graph[i].size()==1) leaf.push_back(i);
        }
        for(int i:leaf) cout<<i<<" ";
        // keep on removing leaf from graph
        
        while(1)
        {
            vector<int> next;
            for(int vertex: leaf)
            {
                for(int source: graph[vertex])
                {
                    graph[source].erase(vertex);
                    if(graph[source].size()==1) next.push_back(source);
                    //if(graph[source].size()==0) root.push_back(source);
                    
                }
                
            }
             if(next.empty()) return leaf;
                leaf=next;
            
            
        }
        
        return root;
}
int main()
{
    int n=6;
    vector<vector<int>> edges={{3,0},{3,1},{3,2},{3,4},{5,4}};
    cout<<findMinHeightTrees(n,edges)<<endl;
    cout<<findMinHeightTrees_opti(n,edges);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
// leetcode 973
 class point{
        public:
        int x=0;
        int y=0;
        double dist=0;
        point(int x1,int y1){
            x=x1;
            y=y1;
            dist=sqrt((x*x) + (y*y));
        }  
    };
    class compare{
        public:
        bool operator()(point p1,point p2){
            return p1.dist > p2.dist;
        }
    };
    vector<vector<int>>ans;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue<point,vector<point>,compare> que;
        
        for(vector<int> arr:points){
            que.push({arr[0],arr[1]});
        }
        while(K--){
            ans.push_back({que.top().x,que.top().y});
            que.pop();
        }
        return ans;
    }
int main(){

    vector<vector<int>>points={{1,3},{-2,2}};
    int k=2;
    
}
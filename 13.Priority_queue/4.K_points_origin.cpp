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
//================================================================================
    // Quick Select Algorithm : custom implementation
int distance(vector<int>& p) {
    return p[0]*p[0] + p[1]*p[1];
}

int partition(vector<vector<int>>& arr, int low, int high) {
    int pivot = distance(arr[high]);
    for (int i = low; i < high; ++i) {
        if(distance(arr[i]) < pivot)
            swap(arr[i], arr[low++]);
    }
    swap(arr[high], arr[low]);
    return low;
}
vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    int l = 0, r = points.size() - 1;
    --K;
    while(true) {
        int p = partition(points, l, r);
        if (p == K)
            break;
        if (p < K) {
            l = p + 1;
        } else {
            r = p - 1;
        }
    }
    return vector<vector<int>>(points.begin(), points.begin() + K + 1);
}

//=====================================================================================
    //quick select using inbuilt function

vector<vector<int>> kClosest(vector<vector<int>>& ps, int K) {
  nth_element(begin(ps), begin(ps) + K, end(ps), [](vector<int> &a, vector<int> &b) {
      return a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1];
  });
  ps.resize(K);
  return ps;
}
int main(){

    vector<vector<int>>points={{1,3},{-2,2}};
    int k=2;
    kClosest(points,k);
    return 0;
}
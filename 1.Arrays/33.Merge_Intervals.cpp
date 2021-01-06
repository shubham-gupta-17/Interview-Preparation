#include<bits/stdc++.h>
using namespace std;
// leetcode 57
vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n=intervals.size();
        if(n==0 && newInterval.size()==0) return ans;
        if(newInterval.size()==0) return intervals;
        int x=newInterval[0];
        int y=newInterval[1];
        bool flag=false;
        if(n==0){
            flag=true;
            ans.push_back({x,y});
        }
        
        for(vector<int> arr:intervals)
        {
            int a=arr[0];
            int b=arr[1];
            // check if newIntervals overlaps with any one and if yes then merge and mark flag as true
            if(!flag && a<=y && x<=b) {
                flag=true;
                ans.push_back({min(a,x),max(b,y)});
            }
            // if newInterval comes btw two intervals i.e. does not overlap 
            else if(!flag){
                if(ans.size()==0 && y<a){
                    flag=true;
                    ans.push_back({x,y});
                }
                else if(ans.size()>0 && x>ans[ans.size()-1][1] && y<a){
                    flag=true;
                    ans.push_back({x,y});
                }
                ans.push_back({a,b});
            }
            
            // check if current interval overlaps with any existing interval
            else if(flag && a<=ans[ans.size()-1][1] && ans[ans.size()-1][0]<=b){
                int a1=ans[ans.size()-1][0];
                int b1=ans[ans.size()-1][1];
                ans.pop_back();
                ans.push_back({min(a,a1),max(b,b1)});
            } 
            else ans.push_back({a,b});
        }
        if(!flag) ans.push_back({x,y});
        return ans;
}
int main(){

}
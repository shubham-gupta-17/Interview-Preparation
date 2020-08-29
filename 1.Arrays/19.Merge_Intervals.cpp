#include<bits/stdc++.h>
using namespace std;
// leetcode 56
vector<vector<int>> ans;
vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n=intervals.size();
        if(n==0) return ans;

        // sorting using lambda function
        // sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
       //          if(a[0]==b[0]) return b[1]<a[1];
       //          else return a[0]<b[0];
       //      });
        sort(intervals.begin(),intervals.end());
        int i=0;
        while(i<n)
        {
            int j=i;
            int maxx=intervals[i][1];
            while(j<n-1 && maxx>=intervals[j+1][0]){
                 j++;
                maxx=max(maxx,intervals[j][1]);
            }
            vector<int> tmp;
            tmp.push_back(intervals[i][0]);
            tmp.push_back(maxx);
            ans.push_back(tmp);
            i=j+1;
        }
        return ans;
}
int main()
{
  vector<vector<int>> arr={{1,3},{2,6},{8,10},{15,18}};
  int n=4;
  merge(arr);
  for(int i=0;i<n;i++)
        {
            cout<<ans[i][0]<<" "<<ans[i][1]<<endl;
        }
  return 0;
}

#include<iostream>
#include<vector>
using namespace std;
//Question link:https://leetcode.com/problems/couples-holding-hands/
// Resource : https://leetcode.com/problems/couples-holding-hands/discuss/336706/The-general-mathematical-idea%3A-permutation-graph-and-graph-decomposition.
int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        if(n==0) return 0;

        int map[n];
        for(int i=0;i<n;i++){
            map[row[i]]=i;
        }

        int ans=0;
        for(int i=0;i<n;i+=2)
        {
            int c1=row[i];
            int c2=row[i+1];

            if((c1%2==0 && c2==c1+1) || (c1%2==1 && c2==c1-1)) continue;

            int part=(c1%2==0)? map[c1+1]: map[c1-1];
            swap(row[i+1],row[part]);
            map[c2]=part;
            map[row[i+1]]=i+1;
            ans++;
        }

        return ans;
}
int main()
{
  vector<int>row={0,2,3,4,5,1};
  cout<<minSwapsCouples(row);
  return 0;
}

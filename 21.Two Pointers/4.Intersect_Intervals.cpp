#include<bits/stdc++.h>
using namespace std;
// leetcode 986
 vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int n=A.size();
        int m=B.size();
        int i=0;
        int j=0;
        vector<vector<int>>ans;
        while(i<n && j<m){
            int A_start=A[i][0];
            int A_end=A[i][1];
            int B_start=B[j][0];
            int B_end=B[j][1];
            
            //if((B_start>=A_start && B_start<=A_end) || (B_end>=A_start && B_end <=A_end) ||(A_end>=B_start && A_end <=B_end)  ){
               if(A_start<=B_end && B_start<=A_end){
                int x=max(A_start,B_start);
                int y=min(A_end ,B_end);
                ans.push_back({x,y});
            }
            if(B_end >= A_end) i++;
            else if(A_end > B_end) j++;
                
        }
        return ans;
}
int main(){
    vector<int> a={{0,2},{5,10},{13,23},{24,25}};
    vector<int> b={{1,5},{5,14},{15,20},{21,26}};
    intervalIntersection(a,b);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
vector <int> countDistinct (int A[], int n, int k)
{
    //code here.
    int start=0;
    int end=0;
    int count=0;
    vector<int> ans;
    unordered_map<int,int> map;
    while(end<k){
        if(map.find(A[end])==map.end()) count++;
        map[A[end]]++;
        end++;
    }
    ans.push_back(count);
    while(end<n){
       if(map[A[start]]==1) {
           map.erase(A[start++]);
           count--;
       }
       else map[A[start++]]--;
       if(map.find(A[end])==map.end() || map[A[end]]==0) count++;
       map[A[end]]++;
       end++;
       ans.push_back(count);
    }
    return ans;
}
int main(){
    int n=7;
    int *a=new int[n];
    countDistinct(a,n,4);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/maximum-length-subsequence-difference-adjacent-elements-either-0-1/
int find_Subseq(int n,int arr[]){
    int *dp=new int[n]();
    for(int i=0;i<n;i++) dp[i]=1;
    int ans=0;
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            int diff=abs(arr[i]-arr[j]);
            if(diff==0 || diff==1) 
                dp[i]=max(dp[i],dp[j]+1);
        }
        ans=max(ans,dp[i]);
    }
    return ans;
}

// Approach 2: Hashmap : O(n) time and space
int find_Subseq_map(int n,int arr[]){
    unordered_map<int,int> map;
    // search for arr[i],arr[i+1],arr[i-1] and store max length against arr[i];
    int ans=0;
    for(int i=0;i<n;i++){
        int num=arr[i];
        int len=0;
        if(map.find(num)!=map.end()) len=map[num];
        if(map.find(num-1)!=map.end()) len=max(len,map[num]);
        if(map.find(num+1)!=map.end()) len=max(len,map[num+1]);
        map[num]=len+1;
        ans=max(ans,len+1);
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
	int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    cout<<find_Subseq(n, arr)<<endl;
    cout<<find_Subseq_map(n,arr);
	return 0;
}
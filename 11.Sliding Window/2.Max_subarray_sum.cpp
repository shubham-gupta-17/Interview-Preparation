#include<bits/stdc++.h>
using namespace std;
// find max subarray sum of length k
int main()
{
    int arr[] = { 1, 4, 2, 10, 2, 3, 1, 0, 20 }; 
    int k=4;
    int n=sizeof(arr)/sizeof(int);
    int window_sum=0;
    for(int i=0;i<k;i++)  window_sum+=arr[i];
    int max_sum=window_sum;
    for(int i=k;i<n;i++){
        window_sum+=arr[i]-arr[i-k];
        max_sum=max(max_sum,window_sum);
    }
    cout<<max_sum;
    return 0;
}
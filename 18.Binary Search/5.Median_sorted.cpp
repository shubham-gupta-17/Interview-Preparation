#include<bits/stdc++.h>
using namespace std;
// leetcode 4
 double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int i=0;
        int j=0;
        int k=0;
        int *arr=new int[n+m]();
        while(i<n && j<m){
            if(nums1[i]<=nums2[j])
                arr[k]=nums1[i++];
            else arr[k]=nums2[j++];
            k++;
        }
        
        while(i<n) arr[k++]=nums1[i++];
        while(j<m) arr[k++]=nums2[j++];
        
        int mid=(n+m)/2;
        if((n+m)%2==0) return (arr[mid]+arr[mid-1])/2.0;
        return arr[mid];
        
}
int main(){
    
}
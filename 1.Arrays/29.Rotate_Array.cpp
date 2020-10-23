#include<bits/stdc++.h>
using namespace std;
// ======================================================================
// Approach 1: O(n*k) time and O(1) space

 void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n) k=(k%n);
        if(k==0 || k%n==0) return ;
        while(k--){
            int num=nums[n-1];
            for(int i=n-1;i>0;i--){
                nums[i]=nums[i-1];
            }
            nums[0]=num;
        }
        return ;
}

//=====================================================================================
// Approach 2:
/*
    let a= [1,2,3,4,5,6,7]
k = 3.

we have to first reverse the whole array by swapping first element with the last one and so on..
you will get[7,6,5,4,3,2,1]

reverse the elements from 0 to k-1
reverse the elements 7,6,5
you will get [5,6,7,4,3,2,1]

reverse the elements from k to n-1
reverse the elements 4,3,2,1
you will get[5,6,7,1,2,3,4]

*/
void reverse(vector<int>&nums,int start,int end){
        while(start<=end)
            swap(nums[start++],nums[end--]);
        return ;
}
void rotate(vector<int>& nums, int k) {
    int n=nums.size();
    if(k==0 || !(k%n)) return ;
    if(k>n) k%=n;
    
    // reverse all nums
    reverse(nums,0,n-1);
    
    // reverse from 0 to k-1
    reverse(nums,0,k-1);
    
    // reverse from k to n-1;
    reverse(nums,k,n-1);
    return ;
}

int main(){
    vector<int> a={1,2,3,45,6};
    rotate(a,13);
    return 0;
}
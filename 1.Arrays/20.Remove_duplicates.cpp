#include<bits/stdc++.h>
using namespace std;
// leetcode 80
int remove(vector<int>&nums,int k)
{
   int n=nums.size();
        if(n==0) return 0;
        int i=1;
        int j=1;
        int count=1;
        // start with j=1;
        // here i denotes iterator on output array and j is an iterator over input array
        while(j<n)
        {
            if(nums[j]==nums[j-1])
            {
                count++;  // if element is equal to previous element increment the count
                if(count<=k){  // if count less than k swap element of input array with output array
                    nums[i++]=nums[j];
                }
            }
            else{
                count=1;  // if not equal than set count=1 and swap element
                nums[i++]=nums[j];
            }
            j++;
        }
        return i;
}
int main()
{
    vector<int> arr={0,0,0,0,1,1,1,2,2,3,3,3};
    cout<<remove(arr,2)<<endl;
    cout<<remove_dequeue(arr,2);
    return 0;
}
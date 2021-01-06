 #include<bits/stdc++.h>
using namespace std;
//  leetcode 153
 int findMin(vector<int>& nums) {
        int start=0;
        if(nums.size()==0) return -1;
        int end=nums.size()-1;
        if(nums.size()==1) return nums[0];
        while(start<=end){
            int mid=(start+end)/2;
            int num=nums[mid];
            //int target=(mid>0) ? nums[mid-1]:0;
            if(mid>0 && num < nums[mid-1]) return num;
            
            // if there is rotation and mid lies in 1st part
            if(num>nums[end]){
                start=mid+1;
            }
            // if lies in 2nd part
            else if(num<nums[start]){
                 end=mid-1;
            }
            // 3rd part is traditional binary search
            else{
                 end=mid-1;
            }
        }
        return nums[0];

}
int main(){
    vector<int> num={5,6,7,8,9,1,2,3,4,5,5,5,5,5};
    cout<<search(nums,7);
    return 0;
}
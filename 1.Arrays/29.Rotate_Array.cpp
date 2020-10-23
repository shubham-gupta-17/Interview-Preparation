#include<bits/stdc++.h>
using namespace std;
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
int main(){
    vector<int> a={1,2,3,45,6};
    rotate(a,13);
    return 0;
}
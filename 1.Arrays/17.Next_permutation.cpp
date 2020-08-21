#include<iostream>
#include<vector>
using namespace std;
void find_next(vector<int>&nums)
{
  int n=nums.size();
     if(n==0) return;
     int i1=0;
     int i2=0;
     for(int i=n-2;i>=0;i--)
     {
         if(nums[i]<nums[i+1]){
             i1=i;
             break;
         }
     }
     for(int i=n-1;i>=0;i--)
     {
         if(nums[i]>nums[i1])
         {
             i2=i;
             break;
         }
     }


     swap(nums[i1],nums[i2]);
     int i;
     if(i1==i2) i=0;
     else i=i1+1;
     int j=n-1;
     while(i<j)
     {
         swap(nums[i++],nums[j--]);
     }
     return ;
}
int main()
{
  vector<int> a={3,2,1};
  /*
      edge case : if(i1==0 && i2==0 ) i.e. for case a=321 or 12 there is no break point 
  */
  find_next(a);
  return 0;
}

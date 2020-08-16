#include<iostream>
#include<queue>
#include<set>
#include<vector>
#include<bits/stdc++.h>
using namespace std;
/*
 Question link:https://www.geeksforgeeks.org/find-k-pairs-smallest-sums-two-arrays/
  Resource link : https://leetcode.com/problems/find-k-pairs-with-smallest-sums/discuss/84551/simple-Java-O(KlogK)-solution-with-explanation
  for queue: https://www.geeksforgeeks.org/stl-priority-queue-for-structure-or-class/?ref=rp
*/
class node{
  public :
  int i;
  int j;
  int sum;
  node(int i,int j,int sum)
  {
    this->i=i;
    this->j=j;
    this->sum=sum;
  }

};
struct compare{
bool operator()(node const&p1,node const&p2)
{
 return p1.sum>p2.sum;
}
  };

vector<vector<int>> find_k_pair_opti(vector<int>&a,vector<int>&b,int k)
{
  int n=a.size();
  int m=b.size();
   vector<vector<int>>ans;
   if(n==0 || m==0)  return ans;
  priority_queue<node, vector<node>, compare> p;
  for(int i=0;i<n && i<k;i++)
    p.push(node(i,0,a[i]+b[0]));
 while(k-->0)
 {
   if(p.empty()) return ans;
   node q=p.top();
   p.pop();
   vector<int> arr;
   arr.push_back(a[q.i]);
   arr.push_back(b[q.j]);
   if(q.j +1 <m)
   p.push(node(q.i,q.j+1,a[q.i]+b[q.j+1]));

   if(arr.size()!=0) ans.push_back(arr);
 }
 return ans;

}

//=========================================================================================================
#define pi pair<int,pair<int,int>>
#define pii pair<int,int>
 vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
     int n1=nums1.size();
     int n2=nums2.size();
     vector<vector<int>> arr;
     if(n1==0 || n2==0) return arr;
     priority_queue<pi , vector<pi>, greater<pi>> p;
     set<pii> map;
     map.insert(make_pair(0,0));
     int sum=nums1[0]+nums2[0];
     p.push(make_pair(sum,make_pair(0,0)));
     int i=0;
     int j=0;
     while(k-->0)
     {
         if(p.empty()) return arr;
         pi pq=p.top();
         p.pop();
         i=pq.second.first;
         j=pq.second.second;
         vector<int>ans;
         ans.push_back(nums1[i]);
         ans.push_back(nums2[j]);

         if(i+1<n1){
         pii tmp=make_pair(i+1,j);
         sum=nums1[i+1]+nums2[j];
         if(map.find(tmp)==map.end())
         {
             p.push(make_pair(sum,tmp));
             map.insert(tmp);
         }}

         if(j+1<n2){
         pii tmp1=make_pair(i,j+1);
         sum=nums1[i]+nums2[j+1];
          if(map.find(tmp1)==map.end())
         {
             p.push(make_pair(sum,tmp1));
             map.insert(tmp1);
         }}

         if(ans.size()!=0) arr.push_back(ans);
     }
     return arr;


 }
void display(vector<vector<int>>&ans)
{
  for(int i=0;i<ans.size();i++)
  cout<<ans[i][0]<<" "<<ans[i][1]<<endl;

  return;
}
int main()
{
  vector<int>nums1={1,7,11};
  vector<int>nums2={2,4,6};
  int k=3;
  vector<vector<int>>ans=kSmallestPairs(nums1,nums2,k);  //T.C= klogn

  vector<vector<int>>arr= find_k_pair_opti(nums1,nums2,k);  //T.C= klogk
  display(ans);
  display(arr);
  return 0;
}

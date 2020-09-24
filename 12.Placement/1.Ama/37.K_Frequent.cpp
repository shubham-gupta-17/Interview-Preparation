#include<bits/stdc++.h>
using namespace std;
#define pp pair<string,int>

vector<string> topKFrequent(vector<string>& words, int k) {
       int n=words.size();
       vector<string> ans;
       if(n==0) return ans;

       map<string,int>map;
       for(string &s:words)
       {
            map[s]+=1;
       }

       vector<pp> arr;
          for(auto it:map){
              arr.push_back(it);
          }

          sort(arr.begin(),arr.end(),[](pp a,pp b){
             if(a.second==b.second) return a.first<b.first;
             return a.second>b.second;
          });


       for(int i=0;i<k;i++)
           ans.push_back(arr[i].first);

       return ans;

}
int main()
{
   vector<string> arr={"i", "love", "leetcode", "i", "love", "coding"};
   topKFrequent(arr,2);
   return 0;
}

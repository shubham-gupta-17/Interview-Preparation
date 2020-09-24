#include<bits/stdc++.h>
using namespace std;
#define pp pair<string,int>
// Approach 1:
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
//===============================================================================
struct compare{
        bool operator()(pp a,pp b){
           if(a.second==b.second) return a.first < b.first;
           return a.second > b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();
        vector<string> ans(k,"");
        if(n==0) return ans;

        map<string,int>map;
        for(string &s:words)
        {
             map[s]+=1;
        }

       priority_queue<pp, vector<pp>, compare> que;

        for(auto it:map)
        {
            que.push(it);
            if(que.size()>k) que.pop();
        }

        for(int i=0;i<k;i++)
        {
            pp top=que.top();
            ans.push_back(top.first);
            que.pop();
        }
        return ans;

    }
int main()
{
   vector<string> arr={"i", "love", "leetcode", "i", "love", "coding"};
   topKFrequent(arr,2);
   return 0;
}

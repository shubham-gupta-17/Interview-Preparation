#include <bits./stdc++.h>
using namespace std;
// leetcode 974
 int subarraysDivByK(vector<int>& A, int k) {
        int n=A.size();
        if(n==0 || k==0) return 0;
        unordered_map<int,int> map;
        int sum=0;
        int count=0;
         map[0]=1;
        for(int ele:A)
        {
            sum+=ele;
            int mod=(sum%k+k)%k;
            if(map.find(mod)!=map.end()) count+=map[mod];
            map[mod]++;
           
        }
        
       return count;
}
int main()
{
    vector<int> ar = {4,5,0,-2,-3};
    cout << subarraysDivByK(ar, 5);
    return 0;
}
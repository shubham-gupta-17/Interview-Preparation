#include<bits/stdc++.h>
using namespace std;

// leetcode 1208
 int equalSubstring(string s, string t, int maxCost) {
        int n=s.length();
        int m=t.length();
        if(n==0 || m==0) return 0;
         int len=0,maxlen=0,start=0,end=0;
        while(end<n)
        {
            maxCost-=cost;
            if(maxCost<0)
            {
                maxCost+=abs(s[start]-t[start]);
                start++;
            }
            maxlen=max(maxlen,end-start+1);
            end++;
        }

        return maxlen  // end-start;
}
int main()
{
    string s="krpgjbjjznpzdfy"
    string t="nxargkbydxmsgby"
    int cost=14
    cout<<equalSubstring(s,t,cost);

return 0;
}
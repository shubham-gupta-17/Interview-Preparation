#include<bits/stdc++.h>
using namespace std;
// leetcode 402
string removeKdigits(string num, int k) {
        string res;
       int keep = num.size() - k;
       // we are using stack approach because we have to ensure that 1st min no must be at bottom of stack
       // eg - num= 1234560 and k=6
       // num= 4659823 and k=5
       for (int i=0; i<num.size(); i++) {
           while (res.size()>0 && res.back()>num[i] && k>0) {
               res.pop_back();
               k--;
           }
           res.push_back(num[i]);
       }

       res.erase(keep);

       // trim leading zeros
       int s = 0;
       while (s<res.size()-1 && res[s]=='0')  s++;
       res.erase(0, s);

       return res=="" ? "0" : res;
}
int main()
{
    cout<<removeKdigits("4659823",5);
    return 0;
}

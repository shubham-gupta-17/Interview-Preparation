#include<bits/stdc++.h>
using namespace std;
// leetcode  201
int rangeBitwiseAnd(int m, int n) {
        if(m==0) return 0;
        int i=0;
        while(m!=n){
            m >>=1;
            n >>=1;
            i++;
        }
       return  m <<=i;
}
int main()
{
    cout<<rangeBitwiseAnd(10,302);
}
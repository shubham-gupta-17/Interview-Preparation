#include<bits/stdc++.h>
using namespace std;
int main()
{
    int =1254;
    int res = 0;
        int pre = Integer.MAX_VALUE;
        int offset = 1;
        while(N != 0) {
            int digit = N % 10;
            if(digit > pre) {
                res = digit * offset - 1;
                pre = digit - 1;
            }else {
                res = res + digit * offset;
                pre = digit;
            }
            offset *= 10;
            N = N / 10;
        }
    cout<< res;
    return 0;
}
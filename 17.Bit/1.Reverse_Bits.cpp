#include<bits/stdc++.h>
using namespace std;
// leetcode  190

 uint32_t reverseBits(uint32_t n) {
        int res=0;
        if(n==0) return 0;
       
        for(int i=0;i<32;i++){
            
            res <<= 1;
            if((n&1)) res|=1;
            
            n>>=1;
        }
        return res;
 }
 int main()
 {
 	reverseBits(00000010100101000001111010011100);
 	return 0;
 }
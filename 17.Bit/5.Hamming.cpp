#include<bits/stdc++.h>
using namespace std;
// leetcode 461
int hammingDistance1(int x, int y) {
        int bit=0;
        int i=0;
        while(x>0 || y>0){
            int bit1=(x&1);
            int bit2=(y&1);
            cout<<bit1<<" "<<bit2<<endl;
            if(bit1!=bit2) bit++;
            x>>=1;
            y>>=1;
        }
        return bit;
}
//========================================================================

int hammingDistance2(int x,int y){
    int dist=0;
    int n=(x^y);
    while(n>0){
        n&=(n-1);
        dist++;
    }
    return dist;
}
int main()
{
    hammingDistance1(20,40);
    hammingDistance2(20,40);

}
#include <bits/stdc++.h>
using namespace std;
// leetcode 441
 int arrangeCoins(int n) {
        return floor(-0.5+sqrt((long)2*n+0.25));
    }
int main()
{   
    int n;
    cin>n;
    cout<<arrangeCoins(n);
    return 0;
}
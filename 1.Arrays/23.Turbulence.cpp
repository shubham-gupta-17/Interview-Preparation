#include <bits/stdc++.h>
using namespace std;
// leetcode 978
int maxTurbulenceSize(vector<int>& A) {
        int n=A.size(); 
        int inc = 1, dec = 1, result = 1;
         for(int i=0;i<n-1;i++){
             if(A[i]>A[i+1]){
                 dec=inc+1;
                 inc=1;
             }
             else if(A[i]<A[i+1]){
                 inc=dec+1;
                 dec=1;
             }
             else{
                 dec=1;
                 inc=1;
                 
             }
             result=max(result,max(dec,inc));
         }
        return result;

}
int main()
{
    vector<int> a={9,4,2,10,7,8,8,1,9};
    cout<<maxTurbulenceSize(a);
    return 0;
}
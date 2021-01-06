#include<bits/stdc++.h>
using namespace std;
// leetcode 11
int maxArea(vector<int>& A) {
        int S = 0, i = 0, j = A.size() -1;
        while (i < j) {
            S = max(S, (j - i) *min(A[i], A[j]));
            if (A[i] < A[j]) i++; else j--;
        }
        return S;
}
int main(){
    vector<int> arr={1,2,1};
    cout<<maxArea(arr);
    return 0;
}
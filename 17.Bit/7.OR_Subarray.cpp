#include<bits/stdc++.h>
using namespace std;
// leetcode 898
int subarrayBitwiseORs(vector<int>& A) {
        vector<int> or_results;
        if(A.empty()) return 0;
        int i = 0, j = 0;
        for(auto a : A){
            int start = or_results.size(); // log the start point of the OR result of sub arrays end with current element.
            or_results.emplace_back(a);
            for(int k = i; k < j; k++){ // using current element to make OR operation with all sub arrays end with previous element.
                int a2 = or_results[k] | a;
                if(a2 > or_results.back()){
                    or_results.emplace_back(a2);
                }
            }
            i = start, j = or_results.size(); // set the start and end position of the OR result of sub arrays end with current element.
        }
        return unordered_set<int>(or_results.begin(), or_results.end()).size();
}
int main(){
    vector<int> nums={1,2,3,4,5,6};
    cout<<subarrayBitwiseORs(nums);
    return 0;
}
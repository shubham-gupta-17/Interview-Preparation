#include <bits/stdc++.h>
using namespace std;
// leetcode 1497
bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
        int *mod=new int[k]();
        for(int ele:arr){
            int num=ele%k;
            if(num<0) num+=k;
            mod[num]++;
        }
        
        if(mod[0]%2!=0) return false;
        for(int i=1;i<=k/2;i++){
            if(mod[i]!=mod[k-i]) return false;
        }
        return true;
       
}
int main()
{
    vector<int> arr={1,2,3,4,5,6,7,8,9,5};
    cout << canArrange(arr,5);
    return 0;
}
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
 bool canArrange(vector<int>& arr, int k) {
        int n=arr.size();
        int m=n/2;
        
        unordered_map<int,int> map;
        for(int ele:arr)
            map[ele%k]++;
        
        for(int ele:arr){
            int mod=ele%k;
            bool flag=false;
            if(map[-mod]>0){
                if(map[-mod]==1) map.erase(-mod);
                else map[-mod]--;
                flag=true;
            }
           if(!flag && map[k-mod]>0){
                if(map[k-mod]==1) map.erase(k-mod);
                else map[k-mod]--;
                flag=true;
            }
            if(!flag && map[-k-mod]>0){
                if(map[-k-mod]==1) map.erase(-k-mod);
                else map[-k-mod]--;
                flag=true;
            }
           
            if(!flag){
                cout<<endl<<map[-30435]<<endl;
                return false;
            } 
        }
        
        return true;
        
    }
int main()
{
    vector<int> arr={1,2,3,4,5,6,7,8,9,5};
    cout << canArrange(arr,5);
    return 0;
}
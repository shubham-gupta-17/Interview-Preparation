#include<bits/stdc++.h>
using namespace std;
 // leetcode 1239
unordered_map<string,int> map;
    int n;
    int mask(string&s){
        int mask=0;
         for(char ch:s) {
                int idx=1<<(ch-'a');
                if((mask&idx)==idx){
                   return 0;
                }
                mask |=idx;
            }
        return mask;
    }
    int find(vector<string>&arr,int i,string ans){
        if(i==n) return 0;
        
        int mask_a=0;
        if(map.find(ans)==map.end()) map[ans]=mask(ans);
        mask_a=map[ans];
        
        if(mask_a==0) return 0;
        
        int ans_length=ans.length();
        for(int j=i+1;j<n;j++){
            int mask_b=map[arr[j]];
            if(mask_b==0) continue;
            
            if((mask_a&mask_b)==0) 
                ans_length=max(ans_length,find(arr,j,ans+arr[j]));
        }
        
        return ans_length;
        
    }
    int maxLength(vector<string>& arr) {
         n=arr.size();
        if(n==0) return 0;
        for(string s:arr){
            map[s]=mask(s);
        }
       
        int ans_length=0;
        for(int i=0;i<n;i++){
            if(map[arr[i]]==0) continue;
            
            int curr=arr[i].length();
            ans_length=max(ans_length,curr);
            ans_length=max(ans_length,find(arr,i,arr[i]));
        }
        return ans_length;
    }
int main(){
	vector<string> arr={"ae","er","dfg"};
	cout<<maxLength(arr);
	return 0;

}

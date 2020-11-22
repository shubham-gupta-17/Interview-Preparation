#include <bits/stdc++.h>
using namespace std;
// leetcode 134
int n;
    bool bfs(int idx,vector<int>&gas,vector<int>&cost){
        int curr=idx+1;
        int fuel=gas[idx];
        int prev=idx;
        int count=0;
        while(count<n){
            if(fuel<0) return false;
            if(curr>=n) curr-=n;
            if(prev>=n) prev-=n;
            fuel=fuel-cost[prev];
            if(fuel<0) return false;
            fuel+=gas[curr];
            curr++;
            prev++;
            count++;
        }
        return true;
        
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        n=gas.size();
        for(int i=0;i<n;i++){
            if(bfs(i,gas,cost)) return i;
        }
        return -1;
    }
int main(){
	vector<int> gas={2,3,4};
	vector<int> cost={3,4,3};
	cout<<canCompleteCircuit(gas,cost);
	return 0;
}
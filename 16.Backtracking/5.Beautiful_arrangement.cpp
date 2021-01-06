#include<bits/stdc++.h>
using namespace std;
// leetcode 526
 int find(int n,int *vis,int i,int num){
        if(i==n+1)  return 1;
        
        int count=0;
        for(int no=1;no<=n;no++){
            if(!vis[no] &&(no%i==0 || i%no==0)){
                vis[no]=true;
                count+=find(n,vis,i+1,no);
                vis[no]=false;
            }
        }
        return count;
    }
int countArrangement(int N) {
    int *vis=new int[N+1]();
    return find(N,vis,1,0);
}
int main(){
    cout<<countArrangement(15);
    return 0;
}
#include<iostream>
using namespace std;
// leetcode 949
bool *vis=new bool[4]();
    string res="";
    void find(string ans,int i,int count,vector<int>&arr){
        if(count==3){
            if(ans>"2359" || ans.substr(2,2)>="60") return ;
            cout<<ans<<" ";
            res=max(res,ans);
            return ;
        }
        if(vis[i]) return ;
        vis[i]=true;
        for(int j=0;j<4;j++){
            if(!vis[j]) find(ans+to_string(arr[j]),j,count+1,arr);
        }
        vis[i]=false;
    }
    string largestTimeFromDigits(vector<int>& arr) {
       
        for(int i=0;i<4;i++){
            find(to_string(arr[i]),i,0,arr);
        }
        if(res=="") return  res;
        string ans="";
        for(int i=0;i<4;i++){
            ans+=res[i];
            if(i==1) ans+=':';
        }
        return ans;
   }
int main(){
	int a=132;
	numberToWords(a);
	return 0;
}

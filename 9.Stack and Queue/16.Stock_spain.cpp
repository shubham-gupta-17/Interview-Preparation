 #include<bits/stdc++.h>
using namespace std;
// leetcode 946
 stack<pair<int,int>> st;
    StockSpanner() {
        st.push({-1,-1});
    }
    int i=0;
    int next(int price) {
        if(st.top().first==-1) {
            st.push({price,0});  
            i++;
            return 1;
        }
        int ans=0;
        while(st.top().first!=-1 && price>=st.top().first){
            st.pop();
        }
        ans=i-st.top().second;
        st.push({price,i});
        i++;
        return ans;
        
}
int main(){

}
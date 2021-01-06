    #include<bits/stdc++.h>
    using namespace std;
    // leetcode 946
 bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n=pushed.size();
        int m=popped.size();
        if(m>n) return false;
        stack<int> st;
        int j=0;
        for(int i=0;i<n;i++){  
            st.push(pushed[i]);
            while(j<m && !st.empty() && popped[j]==st.top()){
                st.pop();
                j++;
            }
        }
        return j==m;
}
int main(){
    vector<int>push={1,2,3,4,5};
    vector<int>pop={4,5,3,2,1};
    cout<<validateStackSequences(push,pop);
    return 0;
}
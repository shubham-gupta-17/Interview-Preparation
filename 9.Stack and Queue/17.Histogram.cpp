   #include<bits/stdc++.h>
   using namespace std;
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        st.push(-1);
        int height,width,area,max_area=0;
        int i=0;
        for(;i<n;i++)
        {
            while(st.top()!=-1 && heights[st.top()]>=heights[i])
            {
                height=heights[st.top()];
                st.pop();
                width=i-st.top()-1;
                
                area=height*width;
                
                max_area=max(area,max_area);
            }
            st.push(i);
            
        }
       
            while (!st.empty() && st.top()!=-1)
        {
                height=heights[st.top()];
                st.pop();
                width=i-st.top()-1;
                
                area=height*width;
                max_area=max(area,max_area);
                
        }
        
        
        return max_area;
    }
   int main(){
       vector<int> a={2,1,5,6,2,3};
       cout<<largestRectangleArea(a);
       return 0;
   } 
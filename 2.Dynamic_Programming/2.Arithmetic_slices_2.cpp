#include<iostream>
using namespace std;
//Helpful article : https://leetcode.com/articles/arithmetic-slices-ii-subsequence/#
//Question link :https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
  #define intt long long  
    int numberOfArithmeticSlices(int n,int *a) {
        intt result=0;
        vector<unordered_map<intt,intt>> map(n);
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                intt diff=(intt)A[i]-(intt)A[j];
                if(map[j].find(diff)!=map[j].end()){
                    map[i][diff]+=map[j][diff];
                    result+=map[j][diff];   
                }
                map[i][diff]+=1;
            }
        }
        
        return(int) result;
    }
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	cout<<numberOfArithmeticSlices(n,a);
	return 0;
}
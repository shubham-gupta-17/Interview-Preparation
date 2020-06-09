#include <iostream>
using namespace std;
void find_leaders(int n,int*a,int i,int max_val)   // it is O(n) and dp solution will be O(n^2).A
{
    if(i==-1) return;
    if(a[i]>=max_val)
     {
         find_leaders(n,a,i-1,a[i]);
         cout<<a[i]<<" ";
         return;
     }
     find_leaders(n,a,i-1,max_val);
}
int main() {
	int t;
	cin>>t;
	while(t-->0)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    find_leaders(n,a,n-1,a[n-1]);
	    cout<<endl;
	}
	return 0;
}
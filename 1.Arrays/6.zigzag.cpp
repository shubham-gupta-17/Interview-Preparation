#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t-->0)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    for(int i=0;i<n;i++)
	    {
	        if(i<n-1 && i%2==0 && a[i]>a[i+1])
	         swap(a[i],a[i+1]);
	        if(i<n-1 && i%2!=0 && a[i]<a[i+1])
	        swap(a[i],a[i+1]);
	    }
	    for(int i=0;i<n;i++)
	    cout<<a[i]<<" ";
	    cout<<endl;
	}
	return 0;
}
#include <iostream>
using namespace std;
int find_equillibrium(int n,int*a)
{
    int idx=-1;
    int rightsum=0;
    int leftsum=0;
    for(int i=0;i<n;i++)
    rightsum+=a[i];
    for(int i=0;i<n;i++)
    {
        rightsum-=a[i];
        if(leftsum==rightsum)
        return idx=i+1;
        leftsum+=a[i];
    }
    return idx;
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
	    cout<<find_equillibrium(n,a)<<endl;
	}
	return 0;
}
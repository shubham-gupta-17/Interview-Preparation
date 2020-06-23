#include<iostream>
using namespace std;
int rain_water_1(int*a,int n)
{
	int *left=new int[n]();
	int *right=new int[n]();
	left[0]=a[0];
	for(int i=1;i<n;i++)
		left[i]=max(left[i-1],a[i]);
	right[n-1]=a[n-1];
	for(int i=n-2;i>=0;i--)
		right[i]=max(right[i+1],a[i]);

	int ans=0;
	for(int i=0;i<n;i++)
		ans+=min(left[i],right[i])-a[i];
	return ans;
}
int main()
{
	
	int n=4;
	int arr[]={7,4,0,9};
	cout<<rain_water_1(arr,n);
}
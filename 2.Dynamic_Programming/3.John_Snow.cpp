#include<iostream>
#include<climits>
using namespace std;
//Question link:https://codeforces.com/problemset/problem/768/C
int main()
{
	int n;
	int x,k;
	cin>>n>>k>>x;
	int *a=new int[1100]();  // it will initialise my array by default value 0;
	for(int i=0;i<n;i++)
	{
		int xi;
		cin>>xi;
		a[xi]++;
	}
	int *temp=new int[1100];
	int m=1100;    // length is 1100 because values are in range of 0 to 1000
	while(k--)
	{
		for(int i=0;i<m;i++)
			temp[i]=a[i];
		int parity=0;  // 0 corresponds to ceil
		for(int i=0;i<m;i++)
		{
			if(a[i]>0)
			{
				int value=(i^x);
				int change=a[i]/2;   // it will give floor value 
				if(parity==0)  change+=(a[i]&1);  // we have to take ceil only if count(a[i]) is odd and parity is 0
				temp[i]-=change;
				temp[value]+=change;  // store changes in temp because we have to take XOR of original count before iterations
				parity^=(a[i]&1);   // parity will change when a[i] is odd 
			}
		}
		for(int i=0;i<m;i++)
			a[i]=temp[i];
	}

	int min_val=INT_MAX;
	int max_val=INT_MIN;
	for(int i=0;i<m;i++)
	{
		if(a[i]>0)
		{
			min_val=min(i,min_val);
			max_val=max(i,max_val);
		}
	}

	cout<<max_val<<" "<<min_val;
	return 0;
}
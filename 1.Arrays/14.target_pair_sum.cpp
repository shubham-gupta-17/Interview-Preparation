#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	int target;
	cin>>target;
	sort(a,a+n);
		int start=0;
		int end=n-1;
		while(start<end)
		{
			
			int sum=a[start]+a[end];
			if(sum==target){
			cout<<a[start]<<" and "<<a[end]<<endl;
			start++;
			end--;
			}

			else if(sum<target) 
				start++;
			
			else end--;
		}
	
	return 0;
}

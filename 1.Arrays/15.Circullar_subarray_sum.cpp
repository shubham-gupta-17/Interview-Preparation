#include<iostream>
#include<climits>
 // https://leetcode.com/problems/maximum-sum-circular-subarray/discuss/178422/One-Pass
// https://leetcode.com/problems/maximum-sum-circular-subarray/submissions/
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
		cin>>arr[i];
		int max_sum=INT_MIN;
		int curr_max=0;
		int min_sum=INT_MAX;
		int curr_min=0;
		int total=0;
		for(int a:arr)
		{
			curr_max=max(curr_max+a,a);
			max_sum=max(max_sum,curr_max);
			total+=a;
			curr_min=min(curr_min+a,a);
			min_sum=min(min_sum,curr_min);
		}
		int ans=max_sum>0 ? max(max_sum,total-min_sum) : max_sum;
		cout<<ans<<endl;
	}
	return 0;
}

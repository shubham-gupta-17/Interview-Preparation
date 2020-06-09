#include <iostream>
#include<unordered_map>
using namespace std;
// handles only non negative numbers time:O(n) , space :O(1)
void find_sum(int n,sum s,int*a)
{
	int idx[2]={-1};
	    bool cont=false;
	    int i=0,j=0;
	    int sum=0;
	    while(j<n)
	    {
	        sum+=a[j];
	         if(sum>s)
	        {
	            while(sum>s && i<j)
	            sum-=a[i++];
	        }
	        if(sum==s)
	        {
	            idx[0]=i;
	            idx[1]=j;
	            cont=true;
	            break;
	        }
	        j++;
	    }
	    if(cont)
	    cout<<idx[0]+1<<" "<<idx[1]+1<<endl;
	    else 
	    cout<<"-1"<<endl;
	return ;
}

// handles negative numbers also it returns number of subarrays with sum=k
int find_sum_map(int n,int k,int*a)
{
    unordered_map<int,int>map;
    int count=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum==k) count++;
        if(map.find(sum-k)!=map.end()) count+=map[sum-k];
        //else if(map.find(sum-k)==map.end()) 
        map[sum]++;
    }
    return count;
    
}

int main() {
	int t;
	cin>>t;
	while(t-->0)
	{
	    int n;
	    int s;
	    cin>>n>>s;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    find_sum(n,s,a);
	}
	return 0;
}
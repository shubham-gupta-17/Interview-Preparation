#include <iostream>
#include<algorithm>
using namespace std;
//Question link:https://www.geeksforgeeks.org/chocolate-distribution-problem/
void find_candi_from_array(int *a,int students,int n,int m)
{
	if(students>n)  return ;
	sort(a,a+n);
	int diff=0;
	int min_diff=(int)1e8;
	for(int i=0;i+students-1<n;i++)
	{
		diff=a[i+m-1]-a[i];
		min_diff=min(diff,min_diff);
	}
	cout<<min_diff;
	return ;
}
int main() {
	int t;
	cin>>t;
	while(t-->0)
	{
	    int n,m;
	    cin>>n>>m;
	    int candi_sum=(n*(n+1))/2;
	    if(candi_sum<=m)
	    {
	        while(candi_sum<=m)
	        m-=candi_sum;
	    }
	    int i=1;
	        while(m>=i)
	        {
	            m-=i;
	            i++;
	        }
	   
	    cout<<m<<endl;
	}
	return 0;
}
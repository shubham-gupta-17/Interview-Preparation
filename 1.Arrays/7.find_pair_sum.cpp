#include <iostream>
#include<set>
using namespace std;
int find_sum_pair(int n,int*a,int k)
{
    set<int>map;
    for(int i=0;i<n;i++)
    map.insert(a[i]);
    for(int i=0;i<n;i++)
    {
        if(map.find(k-a[i])!=map.end() || map.find(a[i]-k)!=map.end())
        return 1;
    }
    return -1;
}
int main() {
    int t;
    cin>>t;
    while(t-->0)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        cout<<find_sum_pair(n,a,k)<<endl;
    }
	return 0;
}
#include<iostream>
#include<algorithm>
#include<climits>
#include<map>
using namespace std;
// Question link:https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaybus-station/
int platforms_01(int*arr,int*dep,int n)
{
	int ans=INT_MIN;
	int platform=1;
	for(int i=0;i<n;i++)
	{	
		platform=1;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]>=arr[i] && arr[j]<=dep[i] || arr[i]>=arr[j] && arr[i]<=dep[j])
				platform++;
		}
		ans=max(platform,ans);
	}
	return ans;
}

/*this is the best approach as it will handle all the cases including what to do when arrival time of one train is equal
 to departure time of another train in that case we need to increment the number of platform the hashmap will not handle
 that case because it doesn't compare time it works on char value so it might be possible that it will fail in some cases*/

int platform_02(int arr[],int dep[],int n)
{
	sort(arr,arr+n);
	sort(dep,dep+n);
	int i=1;
	int j=0;
	int platform=1;
	int ans=INT_MIN;
	while(i<n && j<n)
	{
		if(arr[i]<=dep[j]){
		 platform++;
		 i++;
		}
		else if(arr[i]>dep[j]){
		 platform--;
		 j++;
		}
		ans=max(ans,platform);
	}
	return ans;
}
int platform_03(int*arr,int*dep,int n)
{
	multimap<int,char>map;
	for(int i=0;i<n;i++)
	{
		map.insert(make_pair(arr[i],'a'));
		map.insert(make_pair(dep[i],'d'));
	}
	//multimap<int,char>::iterator it=map.begin();
	int ans=INT_MIN;
	int platform=0;
	for(auto it=map.begin();it!=map.end();it++)
	{
		if(it->second=='a') platform++;
		else if(it->second=='d') platform--;
		ans=max(ans,platform);
	}
	return ans;
}
int main()
{
	int arr[] = { 900, 940, 950, 1100, 1500, 1800 }; 
    int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 }; 
    int n=sizeof(arr)/sizeof(int);
    cout<<n<<endl;
    //O(n^2) approach
    cout<<platforms_01(arr,dep,n)<<endl;
    cout<<platform_03(arr,dep,n)<<endl;
    cout<<platform_02(arr,dep,n)<<endl;
    
    return 0;
}
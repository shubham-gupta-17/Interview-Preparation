#include <iostream>
#include<string>
using namespace std;
//Question link : https://practice.geeksforgeeks.org/problems/stock-buy-and-sell
string stocks(int*a,int n)
{
    string s="";
    int profit=0;
    int i=0;
    while(i<n)
    {
        int buy=a[i];
        while(i<n && a[i+1]<=a[i]) i++;
        if(i<n-1){
            buy=a[i];
            s+="("+ to_string(i)+" ";
            i++;
        } 
        while(i<n-1 && a[i+1]>=a[i]) i++;
        if(i<n && a[i]>buy)
        {
            profit+=a[i]-buy;
            if(a[i]-buy!=0)
            s+=to_string(i)+") ";
        }
        i++;
    }
    return profit<=0?"No Profit" : s;
    
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    cout<<stocks(a,n)<<endl;
	}
	return 0;
}
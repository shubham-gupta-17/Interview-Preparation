#include <bits/stdc++.h>
using namespace std;
// leetcode 43
string multiply(string num1, string num2) {
        int n1=num1.length();
        int n2=num2.length();
        if(num1=="0" || num2=="0") return "0";
        int arr[n1+n2];
        for(int i=0;i<n1+n2;i++)
        {
            arr[i]=0;
        }
        for(int i=n1-1;i>=0;i--)
        {
            for(int j=n2-1;j>=0;j--)
            {
                int mul=(num1[i]-'0')*(num2[j]-'0');
                int sum=arr[i+j+1]+mul;
                arr[i+j+1]=sum%10;
                arr[i+j]+=sum/10;
            }
        }
        string ans="";
        for(int a:arr)
        {
            if(ans.length()==0 && a==0)
                continue;
            ans+=to_string(a);
        }
        return ans;
    }
int main(){
    cout<<multiply("123","234");
    return 0;
}
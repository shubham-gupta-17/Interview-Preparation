#include<iostream>
using namespace std;
// leetcode 273
 string ones[20]={"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string tens[10]={"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string thousands[4]={"", "Thousand", "Million", "Billion"};
    string find(int n){
        if(n==0) return "";
        else if(n<20) return ones[n]+" ";
        else if(n<100) return tens[n/10]+" "+find(n%10);
        else return ones[n/100] + " Hundred "+ find(n%100);
    }
    string numberToWords(int num) {
        if(num==0) return "Zero";
        int i=0;
        string ans="";
        while(num>0){
            if(num%1000!=0) ans=find(num%1000) + thousands[i] +" " + ans;
            num/=1000;
            i++;
        }
        while(ans[ans.length()-1]==' ') ans.pop_back();
        return ans;
    }
int main(){
	int a=132;
	numberToWords(a);
	return 0;
}

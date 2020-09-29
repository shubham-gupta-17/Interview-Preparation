#include<bits/stdc++.h>
using namespace std;
// Most efficient approach O(n) time and O(1) space
string decodeString(const string& s, int& i) {
    string res;
    
    while (i < s.length() && s[i] != ']') {
        if (!isdigit(s[i]))
            res += s[i++];
        else {
            int n = 0;
            while (i < s.length() && isdigit(s[i]))
                n = n * 10 + s[i++] - '0';
                
            i++; // '['
            string t = decodeString(s, i);
            i++; // ']'
            
            while (n-- > 0)
                res += t;
        }
    }
    
    return res;
}

string decodeString(string s) {
    int i = 0;
    return decodeString(s, i);
}

// stack based O(N) time and space
string decodeString_stack(string s) {
        int n=s.length();
        if(n==0) return "";
        string res="";
        stack<int> num;
        stack<string> str;
        int i=0;
        while(i<n){
            if(isdigit(s[i])){
                int no=0;
                while(i<n && isdigit(s[i])) no = no*10 +s[i++] - '0';
                num.push(no);
            }
            
            else if(s[i]=='['){
                str.push(res);
                res="";
                i++;
            }
            else if(s[i]==']'){
                int count=num.top();
                num.pop();
                string tmp=str.top();
                str.pop();
                for(int j=0;j<count;j++) tmp+=res;
                //tmp+=res;
                res=tmp;
                i++;
                
            }
            else res+=s[i++];
        }
        return res;
}
int main()
{
    string s="3[a]2[bc]";
    cout<<decodeString(s);
    cout<<decodeString_stack(s);
    return 0;
}
#incude<bits/stdc++.h>
using namespace std;
string swapp(string &s,int i,int j)
{
   string a=s;
   swap(a[i],a[j]);
   return a;
}
int kSimilarity(string A, string B) {
   int n=A.length();
   int m=B.length();
   if(n!=m) return 0;
   if(A==B) return 0;
   queue<string> que;
   unordered_map<string,bool> map;
   que.push(B);
   map[B]=true;
   int ans=0;
   while(!que.empty())
   {
       int size=que.size();
       ans++;
       while(size--)
       {
           string s=que.front();
           que.pop();

           // find 1st non matching character
           int i=0;
           while(s[i]==A[i]) i++;

           // find s[j]==A[i] && A[j]!=s[j]
           for(int j=i+1;j<n;j++)
           {
               if(s[j]==A[i] && s[j]!=A[j]){
                   string tmp=swapp(s,i,j);
                   if(tmp==A) return ans;
                   if(!map[tmp]){
                   que.push(tmp);
                   map[tmp]=true;
               }
               }
           }
       }
   }
   return ans;

}
int main()
{
  string A="abcdeabcdeabcdeabcde";
  string B="aaaabbbbccccddddeeee";

  cout<<kSimilarity(A,B);
  return 0;
}

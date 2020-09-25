#include <bits/stdc++.h>
using namespace std;
// leetcode 895
class pp{
      public :
        int x;
        int pos=0;
        int count=0;
        pp(int v,int p,int c){
            x=v;
            pos=p;
            count=c;
        }
    };
struct compare{
    bool operator()(pp s1,pp s2){
        if(s1.count==s2.count) return s1.pos < s2.pos;
        else return s1.count < s2.count;
    }
};
unordered_map<int,int> map;
priority_queue<pp, vector<pp>, compare> que;
int pos=0;
void push(int x) {
   map[x]+=1;
   que.push({x,pos++,map[x]});
}

int pop() {
    int x=que.top().x;
    que.pop();
    map[x]--;
    return x;
}
int main()
{
   push(5);
   push(7);
   push(5);
   push(7);
   push(4);
   push(5);
   push(7);
   push(4);
   cout<<pop();
   cout<<pop();
   cout<<pop();
   cout<<pop();
   cout<<pop();
   cout<<pop();
   cout<<pop();
   cout<<pop();
   return 0;

}

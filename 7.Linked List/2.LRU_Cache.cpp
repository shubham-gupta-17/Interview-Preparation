#include<bits.stdc++.h>
using namespace std;
unordered_map<int,int>map;
list<int> ll;
int cap;
void LRUCache(int capacity) {
   cap=capacity;
   cout<<cap;
}

int get(int key) {
   if(map.find(key)==map.end()) return -1;
   ll.remove(key);
   ll.push_front(key);
   return map[key];
}

void put(int key, int value) {
   if(map.find(key)!=map.end())
   {
       ll.remove(key);
       map[key]=value;
       ll.push_front(key);
   }
   else{
       map[key]=value;
       ll.push_front(key);
       if(ll.size()>cap){
            int tmp = ll.back();
           map.erase(tmp);
           ll.pop_back();

       }
   }
}
int main()
{
  int capacity=2;
  LRUCache(capacity);
  put(1,1);
  put(2,2);
  cout<<get(1)<<endl;
  put(3,3);
  cout<<get(3);

  return 0;

}

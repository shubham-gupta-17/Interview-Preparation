#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Graph_Genric{
  // for datatypes other than string we can use vector or list
  map<T,vector<T>*> m;
  int sizee=0;
  bool vect=false;
public:

  vector<string> path;
  void dfs(T source,T dest,int j,string pat,set<T> map2){
     if(source==dest){
       pat+=source;
       cout<<pat<<endl;
       //path.push_back(pat);
       return ;
     }
     map2.insert(source);
     auto arr=m[source];
     for(int i=0;i<arr->size();i++)
     {
       //if(source=="yogi")cout<<arr->at(i)<<" ";
       if(map2.find(arr->at(i))==map2.end()){
         //cout<<j<<"->"<<source<<endl;
         dfs(arr->at(i),dest,j+1,pat+source+"->",map2);
       }
     }
     map2.erase(source);
     return ;
  }

  Graph_Genric(){

  }

  void addedge(T u,T v,bool a){
    if(m.find(u)==m.end()) m[u]=new vector<T>();
    if(m.find(v)==m.end()) m[v]=new vector<T>();
    m[u]->push_back(v);
    m[v]->push_back(u);
  }

  void print(){
    for(auto p:m){
       cout<<p.first<<"->";
        vector<T>*arr=p.second;
       for(int i=0;i<arr->size();i++)
         cout<<arr->at(i)<<" ";

      cout<<endl;
    }
  }

  void bfs(T source){
    queue<T>*que=new queue<T>();
    set<T> map;
    que->push(source);
    map.insert(source);
    while(!que->empty())
    {
       auto graph=que->front();
       que->pop();
       cout<<graph<<"->";

       auto it=m[graph];
       for(int i=0;i<it->size();i++)
        {
          if(map.find(it->at(i))==map.end()){
            que->push(it->at(i));
            map.insert(it->at(i));
          }
        }
    }
  }

  int  size(){
    return m.size();
  }

  vector<string> all_path(T source,T dest){
      set<T> ma;
      dfs(source,dest,0,"",ma);
      for(string &s:path)
      cout<<s<<endl;
      cout<<m.size();
      return path;
  }

};
int main()
{
   Graph_Genric<string> g1;
   g1.addedge("putin","trump",false);
   g1.addedge("putin","modi",false);
   g1.addedge("putin","pope",false);
   g1.addedge("modi","trump",true);
   g1.addedge("modi","yogi",true);
   g1.addedge("yogi","prabhu",false);
   g1.addedge("prabhu","modi",false);
   g1.addedge("prabhu","pope",false);
   g1.print();
   cout<<endl;
   g1.bfs("putin");
   cout<<endl;

   vector<string> ans=g1.all_path("putin","pope");
   for(string &s:ans)
   cout<<s<<endl;
   return 0;
}

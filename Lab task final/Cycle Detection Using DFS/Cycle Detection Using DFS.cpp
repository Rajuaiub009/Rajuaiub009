#include<iostream>
#include<set>
#include<vector>

using namespace std;

set<int>w;

set<int>g;

set<int>b;

int flag=0;

void Edge(vector<int>adj[],int u,int v)
  {

    adj[u].push_back(v);

  }

void CycleDetect(int u,vector<int>adj[]){

w.erase(u);

g.insert(u);

for(int i=0;i<adj[u].size();i++)
    {

       if(w.find(adj[u][i])!=w.end())

     {

       CycleDetect(adj[u][i],adj);

     }

if(g.find(adj[u][i])!=g.end())
    {

       flag=1;

    }

}

b.insert(u);

g.erase(u);

}

int main()
{

vector<int>adj[5];

Edge(adj,0,1);

Edge(adj,0,2);

Edge(adj,1,2);

Edge(adj,2,0);

Edge(adj,2,3);

Edge(adj,3,3);


for(int i=0;i<5;i++){

w.insert(i);

}

CycleDetect(0,adj);

if(flag==0)
{
    cout<<"Graph does not contain any cycle"<<endl;
}


else
{
    cout<<"Graph contains cycle"<<endl;
}


return 0;

}

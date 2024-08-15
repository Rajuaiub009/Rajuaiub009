#include <iostream>
#include <algorithm>

using namespace std;

class Edge{
public:

    int s;
    int d;
    int w;
};


bool compare(Edge e1,Edge e2)
{
    return e1.w<e2.w;
}


int GetParent(int v,int parent[])
{
    if(parent[v]==v)
        {
        return v;
        }

   return GetParent(parent[v],parent);
}


int main()
{
    int n,e;
    cout<<"Enter the number of vertices: ";

    cin>>n;

    cout<<"Enter the number of edges: ";
        cin>>e;

    Edge edges[e];

        cout<<"Enter the edges: (Source, Destination and Weight for each Edge) ";

    for(int i=0;i<e;i++)
    {
        cout<<"Edge "<< i <<":";
        cin>>edges[i].s>>edges[i].d>>edges[i].w;
    }


    sort(edges,edges+e,compare);
    Edge output[n-1];


    int parent[n];

    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }

    int count=0;
    int i=0;
    int total=0;

    while(count < n-1)
    {
        Edge CurrentEdge=edges[i];

        int p1=GetParent(CurrentEdge.s,parent);
        int p2=GetParent(CurrentEdge.d,parent);

                if(p1!=p2)
            {
            output[count]=CurrentEdge;
            count++;
            parent[p1]=p2;
        }
        i++;
    }


    cout<<"The Minimum Spanning Tree is:";
    cout<<"Source"<<"\t"<<"Destination"<<"\t"<<"Weight:"<<endl;

    for(int i=0;i<n-1;i++)
    {
        if(output[i].s<output[i].d)
        {
            cout<<output[i].s <<output[i].d <<output[i].w<<endl;
        }
        else

            cout<< output[i].d <<output[i].s <<output[i].w<<endl;
            total = total + output[i].w;

    }
    cout<<"The total weight of MST is:" << total;
    return 0;
}

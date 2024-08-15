#include <iostream>
#include<conio.h>

using namespace std;
int c[20][20] , s[20], i , j, t , v , vis[20] , visd[20];

int main()
{
    int  n , m;

    cout<<"Enter the no of vertices:";
    cin>>n;

    cout<<"Enter The no of edges:";
    cin>>m;

    cout<<"EDGES:";

    for(int k = 1; k<=m; k++)
    {
        cin>>i>>j;
        c[i][j] = 1;
    }
    cout << "Enter initial vertex to Traversal from:";
    cin>>v;

    cout<<"DFS order of visited verticies:";
    cout<< v << " ";

    visd[v]=1;
    int k = 1;

    while(k<n)
    {
        for(j=n; j>=1; j--)
            if(c[v][j]!=0 && visd[j]!=1 && vis[j]!=1)
            {
                vis[j]=1;
                s[t]=j;
                t++;
            }
        v=s[--t];
        cout<< v << " ";
        k++;
        vis[v]=0;
        visd[v]=1;
    }



    return 0;
}

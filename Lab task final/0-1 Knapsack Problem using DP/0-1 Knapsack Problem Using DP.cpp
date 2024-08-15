#include <iostream>

using namespace std;

int max(int x, int y)
 {
     if(x>y)
     {
         return x;
     }
     else
     {
         return y;
     }
 }

int KnapSack(int W, int w[], int v[], int n)
{


    if (n == 0 || W == 0)
        return 0;


    if (w[n - 1] > W)
        return KnapSack(W, w, v, n - 1);


    else
        return max(
            v[n - 1]
                + KnapSack(W - w[n - 1],
                           w, v, n - 1),
            KnapSack(W, w, v, n - 1));
}

int main()
{
    int n;

    cout<<"Enter total items:";
    cin>>n;

    int v[n];

    cout<<"Enter value of the items:";
    for(int i=0; i<n; i++)
    {
        cin>> v[i];
    }

    int w[n];
    cout<<"Enter Weight of the items:";
    for(int i=0; i<n; i++)
    {
        cin>> w[i];
    }


    int W;
    cout<<"Enter the Maximum Weight:";
    cin>>W;

    cout <<"The result is:"<< KnapSack(W, w, v, n);
    return 0;
}

#include <iostream>

using namespace std;

int C[50];

int CoinChange(int C[], int a, int num)
{
    if(a==0)
    {
        return 1;
    }
    if(a<0)
    {
        return 0;
    }

     int r=0;

    for (int i = 0; i < a; i++)
    {
        r += CoinChange(C, a, num - C[i]);
    }

    return r;
}


int main()
{
    int a;

    cout<<"Enter the number of input:";

    cin>>a;

    int C[a];

    for(int i=0; i<a; i++)
    {
        cin>> C[i];
    }

    int num;

   cout<<"Enter the Total number:";
   cin>>num;

   cout << "Output:"<<(C,a,num);

   return 0;
}

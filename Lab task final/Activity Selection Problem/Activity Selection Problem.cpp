#include <iostream>

using namespace std;

int S[50];
int E[50];

void ActivitySelection(int S[] , int E[] , int n)
{
    int i;

    cout<< "Selected Activities:";
    i=0;
    cout<<" "<<i;


    for(int j=1; j<n; j++)
    {
        if(S[j] >= E[i])
        {
            cout<<" "<<j;
            i=j;
        }
    }
}

int main()
{
    int n, i, j;

    cout<<"Enter the size of the array:";
    cin>> n;

    int S[n];
    cout<<"First Elements:";
    for(int i=0; i<n; i++)
    {
        cin>> S[i];
    }

    int E[n];

    cout<<"End elements:";
    for(int i=0; i<n; i++)

    {
        cin>> E[i];
    }
    ActivitySelection(S , E , n );

}

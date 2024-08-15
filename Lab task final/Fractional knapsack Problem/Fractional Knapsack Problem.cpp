#include <iostream>

using namespace std;

int main()
{
    int a[5][100], num, w, u[100],cw, m = -1, tp=0;

    cout<<"Enter the number of object you want to take:";
    cin>> num;

    cout<<"Enter the weight of the knapsack:";
    cin>> w;

    for(int i=0; i<num; i++)
    {
        cin>> a[0][i] >> a[1][i];
    }

    for(int i=0; i<num; i++)
    {
        u[i] = 0;
    }

    cw = w;

    while(cw >= 0)
    {
        m = -1;

    for(int i = 0; i<num; i++)
    {
        if ((u[i] == 0) && ((m == -1) || (((float) a[1][i]
                    / (float) a[0][i]) > ((float) a[1][m]
                    / (float) a[0][m]))))
                    {
                        m = i;
                    }
    }

    u[m] = 1;

        cw -= a[0][m];

        tp += a[1][m];


           if (cw >= 0)
        {
            cout << "object " << m + 1 << " Weight: "
                    << a[0][m] << " Profit: " << a[1][m]
                    << " completely in the bag, Space left: " << cw;
        }

        else
        {
            cout << "object " << m + 1 << " Weight: "
                    << (a[0][m] + cw) << " Profit: "
                    << (a[1][m] / a[0][m]) * (a[0][m]
                            + cw) << " partially in the bag, Space left: 0"
                    << " Weight added is: " << cw + a[0][m];

            tp -= a[1][m];
            tp += ((a[1][m] / a[0][m]) * (a[0][m]
                    + cw));
        }


    }
    cout << "Bags filled with objects worth: " << tp;
    return 0;

}

#include <iostream>
#include <Cstring>

using namespace std;
int max(int x, int y);

int LCS(char *S1, char *S2, int m, int n )
{
    int L[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
        if (i == 0 || j == 0)
            L[i][j] = 0;

        else if (S1[i - 1] == S2[j - 1])
            L[i][j] = L[i - 1][j - 1] + 1;

        else
            L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
    return L[m][n];
}

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

int main()
{
    char S1[50];
    char S2[50];

      cout<<"Enter 1st Strings:";
      cin>>S1;

      cout<<"Enter 2nd Strings:";
      cin>>S2;

    int m = strlen(S1);
    int n = strlen(S2);

    cout << "Length of LCS is: "<<LCS(S1, S2, m, n);

    return 0;
}

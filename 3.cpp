#include <bits/stdc++.h>
using namespace std;

void LCS()
{
    string str1, str2;
    cin>>str2>>str1;

    int n = str1.size();
    int m = str2.size();

    int lcs[n + 1][m + 1];

    memset(lcs, 0, sizeof(lcs));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            }
            else
            {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }

    // Display the dynamic programming array
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            cout << lcs[i][j] << "  ";
        }
        cout << endl;
    }

    int i = n, j = m;

    string lcs_string;

    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            lcs_string = str1[i - 1] + lcs_string;
            i--;
            j--;
        }
        else if (lcs[i - 1][j] > lcs[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    cout << endl;

    cout << "Longest Common Subsequence Length: " << lcs[n][m] << endl;

    cout << "Longest Common Subsequence: " << lcs_string << endl;

}

void ED()
{

    string str1, str2 ;
    cin>>str2>>str1;
    int n = str1.size() ;
    int m = str2.size() ;

    int ED[n+1][m+1];

    for (int j=0 ; j< m+1 ; j++)
    {
        ED[0][j] = j ;
    }


    for(int i=0 ; i<n+1 ; i++)
    {
        ED[i][0] = i ;
    }


    for(int i=1 ; i<n+1 ; i++)
    {
        for(int j=1 ; j<m+1 ; j++)
        {
            if(str1[i-1] == str2[j-1])
            {
                ED[i][j] = ED[i-1][j-1] ;
            }
            else
            {
                ED[i][j] = 1+min({ED[i-1][j], ED[i][j-1], ED[i-1][j-1]}) ;
            }
        }
    }
    for(int i=0 ; i<n+1 ; i++)
    {
        for(int j=0 ; j<m+1 ; j++)
        {
            cout << ED[i][j] << "  ";
        }
        cout << endl;
    }

    int i = m, j = n;
    while (i > 0 || j > 0)
    {
        if (i > 0 && j > 0 && str1[i - 1] == str2[j - 1])
        {
            cout << "No operation: " << str1[i - 1] << endl;
            i--;
            j--;
        }
        else if (j > 0 && (i == 0 || ED[i][j - 1] <= ED[i - 1][j] && ED[i][j - 1] <= ED[i - 1][j - 1]))// Insert operation
        {

            cout << "Insert: " << str2[j - 1] << " at position " << i + 1 << endl;
            j--;
        }
        else if (i > 0 && (j == 0 || ED[i - 1][j] <= ED[i][j - 1] && ED[i - 1][j] <= ED[i - 1][j - 1]))    // Delete operation
        {

            cout << "Delete: " << str1[i - 1] << " from position " << i << endl;
            i--;
        }
        else   // Replace operation
        {

            cout << "Replace: " << str1[i - 1] << " at position " << i << " with " << str2[j - 1] << endl;
            i--;
            j--;
        }
    }

}





int main()
{
    char input;
    cout<<"Enter 'e' or 'E' for Edit distance and 'L' or 'l' for LCS :" <<endl;
    cin>>input;
    if(input == 'L' || input == 'l' ) //for activating  LCS function
    {
        LCS();
    }
    if(input == 'E' || input == 'e' )//for activating  ED function
    {
        ED();
    }

    return 0;
}

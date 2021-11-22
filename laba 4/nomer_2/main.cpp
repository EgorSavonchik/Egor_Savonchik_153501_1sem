#include <iostream>
#include <cmath>

using namespace std;

#define N 100
#define M 100

int check();

int main()
{
    int minim;

    cout << "finds the smallest element among the elements below the main diagonal" << endl;
    cout << "enter array with " << N << " lines and " << M  << " columns"<< endl;

    int ar[N][M];

    for(int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
            ar[i][j] = check();
    }

    minim = ar[N-1][0];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ( ar[i][j] < minim)
            {
                minim = ar[i][j];
            }
        }
    }

    cout << "minimum = " << minim;
}


int check()    //examination for +- number
{
    int x = 0, i, m = 0, minis = 0;
    string n;

    cin >> n;

    while (m == 0)
    {
        minis = 0;

        if (n[0] == '-')
        {
            minis = 1;
            n[0] = '0';
        }

        for (i = 0; i < (int)n.length(); i++)
        {
            if (!((n[i] - '0') >= 0 and (n[i] - '0') <= 9))
            {
                cout << "incorrect number" << endl;

                m = 1;
                break;
            }
        }
        if (m == 1)
        {
            m = i = 0;

            cout << "enter right number" << endl;
            cin >> n;
        }

        if (i == (int)n.length())
        {
            for (int a = 0; a < (int)n.length(); a++)
            {
                x += (n[a] - '0') * pow(10, n.length() - a -1);
            }
            m = 1;
        }
    }

    if (minis == 0)
    {
        return(x);
    }
    else
    {
        return(-x);
    }
}

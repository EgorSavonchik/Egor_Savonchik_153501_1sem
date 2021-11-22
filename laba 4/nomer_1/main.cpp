#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#define k  5

int ucheck();

int main()
{
    cout << "program determines if the array is symmetric" << endl;
    cout << "enter array of length " << k << endl;

    int ar[k];

    for (int i = 0 ;i < k; i++)
    {
        ar[i] = ucheck();
    }

    for (int i = 0; i < k / 2; i++)
        if (ar[i] != ar[k - i - 1])
            {
                cout << "not symmetrical";
                return(0);
            }

    cout << "symmetrical";
}


int ucheck()    //examination for +- number
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

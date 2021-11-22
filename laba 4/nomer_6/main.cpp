#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int ucheck();
int check();

int main()
{
    int n, m, maxim;

    cout << "construct a matrix whose elements have the property " << endl << "B[i][j] equal to the maximum element matrix A located above and to the left of (i,j)" << endl;
    cout << "enter matrix A" << endl;
    cout << "enter number of lines n" << endl;
    n = ucheck();
    cout << "enter number of columns m" << endl;
    m = ucheck();

    cout << "enter array with " << n << " lines and " << m  << " columns"<< endl;
    cout.precision(3);

    int** p_arr = new int *[n];

    for(int i = 0; i < n; i++)
    {
        p_arr[i] = new int [m];
    }

    int** p_new = new int *[n];

    for(int i = 0; i < n; i++)
    {
        p_new[i] = new int [m];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            p_arr[i][j] = check();
        }
    }


    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            maxim = p_arr[i][j];
            for(int i1 = i; i1 >= 0; i1--)
            {
                for(int j1 = j; j1 >= 0; j1--)
                {
                    if (p_arr[i1][j1] > maxim)
                    {
                        maxim = p_arr[i1][j1];
                    }
                }
            }
        p_new[i][j] = maxim;
        }
    }


    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << p_new[i][j] << '\t';
        }
    cout << endl;
    }


    for (int i = 0; i < n; i++)
    {
        delete[] p_new[i];
    }
    delete[] p_new;


    for (int i = 0; i < n; i++)
    {
        delete[] p_arr[i];
    }
    delete[] p_arr;
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

int ucheck() //examination for + number
{
    int x = 0, i, m = 0;
    string n;

    cin >> n;

    while (m == 0)
    {
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

    return(x);
}


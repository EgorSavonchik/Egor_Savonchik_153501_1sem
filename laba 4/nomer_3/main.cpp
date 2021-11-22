#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int check();
int ucheck();

int main()
{
    int n, sum_min = 0, sum_max = 0, limit_min, limit_max;

    cout << "finds the sum of the smallest elements of odd lines and the largest elements of even lines square matrix" << endl;
    cout << "enter number of lines and columns n" << endl;
    n = ucheck();

    cout << "enter array with " << n << " lines and " << n  << " columns"<< endl;

    int** p_arr = new int *[n];

    for(int i = 0; i < n; i++)
    {
        p_arr[i] = new int [n];
    }

    for(int i = 0; i < n; i++)
    {
        for(int a = 0; a < n; a++)
        {
            p_arr[i][a] = check();
        }
    }

    for(int i = 0; i < n; i++)
    {
        if ((i+1) % 2 == 0)
        {
            limit_min = INT_MIN;

            for(int a = 0; a < n; a++)
            {
                if (p_arr[i][a] > limit_min)
                {
                    limit_min = p_arr[i][a];
                }
            }

            sum_max += limit_min;
        }
        else
        {
            limit_max = INT_MAX;

            for(int a = 0; a < n; a++)
            {
                if (p_arr[i][a] < limit_max)
                {
                    limit_max = p_arr[i][a];
                }
            }
            sum_min += limit_max;
        }
    }

    cout << "sum of the smallest elements of odd lines " << sum_min << endl << "sum of the largest elements of even lines " << sum_max;

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




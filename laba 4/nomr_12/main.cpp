#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int ucheck();
int check();

int main()
{
    int n, j = 0;

    cout << "removes duplicate elements from an array" << endl;
    cout << "enter array length n" << endl;
    n = ucheck();

    cout << "enter array of length " << n << endl;
    int* p_arr = new int [n];

    int* p_new1 = new int [n];

    int* p_new2 = new int [n];

    for (int i = 0; i < n; i++)
    {
        p_arr[i] = check();
    }

    for (int i = n - 1; i >= 0; i--)
    {
        p_new1[i] = p_arr[i];
        for(int a = 0; a < i; a++)
        {
            if (p_new1[i] == p_arr[a])
            {
                p_new1[i] = INT_MAX;
                break;
            }
        }
    }

    for(int i = 0; i < n; i++)
        {
            if (p_new1[i] != INT_MAX)
            {
                p_new2[j] = p_new1[i];
                j++;
            }
        }

    for(int i = 0; i < j; i++)
    {
        cout << p_new2[i] << " ";
    }

    delete[] p_new1;
    delete[] p_new2;
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


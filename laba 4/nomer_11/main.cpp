#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int ucheck();

int main()
{
    int n, d1= 0, d2 = 0, d3 = 0, d4 = 0;

    cout << "finds the diagonal with the maximum sum of numbers in a three-dimensional array" << endl;
    cout << "enter matrix order n" << endl;
    n = ucheck();

    cout << "enter matrix " << n << " order" << endl;
    int ***p_arr = new int**[n];

    for(int i = 0; i < n; i++)
    {
        p_arr[i] = new int*[n];

        for(int j = 0; j < n; j++)
        {
            p_arr[i][j]=new int[n];
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << "layer" << i << endl;
        for (int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                 p_arr[i][j][k] = ucheck();
            }
        }
    }


    for (int i = 0, j = 0, k = 0; i < n; i++, j++, k++)
    {
        d1 += p_arr[i][j][k];
    }

    for (int i = 0, j = 0, k = n - 1; i < n; i++, j++, k--)
    {
        d2 += p_arr[i][j][k];
    }

    for (int i = n - 1, j = 0, k = 0; j < n; i--, j++, k++)
    {
        d3 += p_arr[i][j][k];
    }

    for (int i = 0, j = n - 1, k = 0; i < n; i++, j--, k++)
    {
        d4 += p_arr[i][j][k];
    }

    if (d1 >= d2 and d1 >= d3 and d1 >= d4)
    {
        cout << "sum = " << d1 << " diagonal from " << "(" << 0 << "," << 0 << "," << 0 << ")" << " to " << "(" << n - 1 << "," << n - 1 << "," << n - 1 << ")";
    }
    else if (d2 >= d1 and d2 >= d3 and d2 >= d4)
    {
        cout << "sum = " << d2 << " diagonal from " << "(" << 0 << "," << 0 << "," << n - 1 << ")" << " to " << "(" << n - 1 << "," << n - 1 << "," << 0 << ")";
    }
    else if (d3 >= d1 and d3 >= d2 and d3 >= d4)
    {
        cout << "sum = " << d3 << " diagonal from " << "(" << n - 1 << "," << 0 << "," << 0 << ")" << " to " << "(" << 0 << "," << n - 1 << "," << n - 1<< ")";
    }
    else
    {
        cout << "sum = " << d4 << " diagonal from " << "(" << 0 << "," << n - 1 << "," << 0 << ")" << " to " << "(" << n - 1 << "," << 0 << "," << n - 1 << ")";
    }


    for (int i = 0; i < n; i++)
        {
        for (int j = 0; j < n; j++)
            {
            delete [] p_arr[i][j];
            }
        delete [] p_arr[i];
        }
    delete [] p_arr;
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



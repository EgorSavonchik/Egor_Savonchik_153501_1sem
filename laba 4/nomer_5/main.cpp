#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int check();
int ucheck();

int main()
{
    int n, m;

    cout << "builds the result of smoothing a given real matrix" << endl;
    cout << "enter number of lines n" << endl;
    n = ucheck();
    cout << "enter number of columns m" << endl;
    m = ucheck();

    cout << "enter array with " << n << " lines and " << m  << " columns"<< endl;
    cout.precision(4);

    double** p_arr = new double *[n];

    for(int i = 0; i < n; i++)
    {
        p_arr[i] = new double [m];
    }

    double** p_new = new double *[n];

    for(int i = 0; i < n; i++)
    {
        p_new[i] = new double [m];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> p_arr[i][j];
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(INT_MAX , '\n');
                j--;
                cout << "incorrect number" << endl;
                cout << "enter right number" << endl;
            }
        }
    }


    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if (i == 0)
            {
                if (j == 0)
                {
                    p_new[i][j] = (p_arr[i + 1][j] + p_arr[i][j + 1]) / 2.0;
                }
                else if (j == m - 1)
                {
                    p_new[i][j] = (p_arr[i + 1][j] + p_arr[i][j - 1]) / 2.0;
                }
                else
                {
                    p_new[i][j] = (p_arr[i][j + 1] + p_arr[i][j - 1] + p_arr[i + 1][j]) / 3.0;
                }
            }
            else if (i == n - 1)
            {
                if (j == 0)
                {
                    p_new[i][j] = (p_arr[i - 1][j] + p_arr[i][j+1]) / 2.0;
                }
                else if (j == m - 1)
                {
                    p_new[i][j] = (p_arr[i - 1][j] + p_arr[i][j - 1]) / 2.0;
                }
                else
                {
                    p_new[i][j] = (p_arr[i][j + 1] + p_arr[i][j - 1] + p_arr[i - 1][j]) / 3.0;
                }
            }
            else if (j == 0)
            {
                p_new[i][j] = (p_arr[i - 1][j] + p_arr[i + 1][j] + p_arr[i][j + 1]) / 3.0;
            }
            else if (j == m - 1)
            {
                p_new[i][j] = (p_arr[i - 1][j] + p_arr[i + 1][j] + p_arr[i][j - 1]) / 3.0;
            }
            else
            {
                p_new[i][j] = (p_arr[i - 1][j] + p_arr[i + 1][j] + p_arr[i][j - 1] + p_arr[i][j + 1]) / 4.0;
            }
        }
    }

    cout << "smoothed matrix" << endl;

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



#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int ucheck();
int check();

int main()
{
    int n, m, num = 0;

    cout << "finds the number of local minimum of the matrix(if the element is less than its neighbors)" << endl;
    cout << "enter number of lines n" << endl;
    n = ucheck();
    cout << "enter number of columns m" << endl;
    m = ucheck();

    cout << "enter array with " << n << " lines and " << m  << " columns"<< endl;

    int** p_arr = new int *[n];

    for(int i = 0; i < n; i++)
    {
        p_arr[i] = new int [m];
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
            if (i == 0)
            {
                if (j == 0)
                {
                    if (p_arr[i+1][j] > p_arr[i][j] and p_arr[i][j+1] > p_arr[i][j])
                    {
                        num++;
                    }
                }
                else if (j == m - 1)
                {
                    if (p_arr[i + 1][j] > p_arr[i][j] and p_arr[i][j - 1] > p_arr[i][j])
                    {
                        num++;
                    }
                }
                else
                {
                    if (p_arr[i][j + 1] > p_arr[i][j] and p_arr[i][j - 1] > p_arr[i][j] and p_arr[i + 1][j] > p_arr[i][j])
                    {
                        num++;
                    }
                }
            }
            else if (i == n - 1)
            {
                if (j == 0)
                {
                    if (p_arr[i - 1][j] > p_arr[i][j] and p_arr[i][j+1] > p_arr[i][j])
                    {
                        num++;
                    }
                }
                else if (j == m - 1)
                {
                    if (p_arr[i - 1][j] > p_arr[i][j] and p_arr[i][j - 1] > p_arr[i][j])
                    {
                        num++;
                    }
                }
                else
                {
                    if (p_arr[i][j + 1] > p_arr[i][j] and p_arr[i][j - 1] > p_arr[i][j] and p_arr[i - 1][j] > p_arr[i][j])
                    {
                        num++;
                    }
                }
            }
            else if (j == 0)
            {
                if (p_arr[i - 1][j] > p_arr[i][j] and p_arr[i + 1][j] > p_arr[i][j] and p_arr[i][j + 1] > p_arr[i][j])
                {
                    num++;
                }
            }
            else if (j == m - 1)
            {
                if (p_arr[i - 1][j] > p_arr[i][j] and p_arr[i + 1][j] > p_arr[i][j] and p_arr[i][j - 1] > p_arr[i][j])
                {
                    num++;
                }
            }
            else
            {
                if (p_arr[i - 1][j] > p_arr[i][j] and p_arr[i + 1][j] > p_arr[i][j] and p_arr[i][j - 1] > p_arr[i][j] and p_arr[i][j + 1] > p_arr[i][j])
                {
                    num++;
                }
            }
        }
    }

    cout << "number of local minimum " << num;

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

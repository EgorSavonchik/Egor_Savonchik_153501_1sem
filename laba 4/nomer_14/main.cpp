#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int ucheck();

int main()
{
    int n, m;

    cout << "adds number to the field for the game of sapper" << endl;
    cout << "enter number of lines n" << endl;
    n = ucheck();

    cout << "enter number of lines m" << endl;
    m = ucheck();

    cout << "fields for the game of sapper" << endl;
    char** p_arr = new char *[n];

    for(int i = 0; i < n; i++)
    {
        p_arr[i] = new char [m];
    }

    char** p_new = new char *[n + 2];

    for(int i = 0; i < n + 2; i++)
    {
        p_new[i] = new char [m + 2];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> p_arr[i][j];

            if (!(p_arr[i][j] == '.' or p_arr[i][j] == '*'))
            {
                cout << "incorrect symbol" << endl << "enter symbol" << endl;
                j--;
            }
        }
    }


    for(int i = 0; i < n + 2; i++)
    {
        for(int j = 0; j < m  + 2; j++)
        {
            if(i == 0 or j == 0 or i == n + 1 or j == m + 1)
            {
                p_new[i][j] = '0';
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(p_arr[i][j] == '.')
            {
                p_new[i + 1][j + 1] = '0';
            }
            else
            {
                p_new[i + 1][j + 1] = '1';
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(p_new[i + 1][j + 1] == '1')
            {
                p_arr[i][j] = '*';
            }
            else
            {
                p_arr[i][j] = ((p_new[i][j] - '0') + (p_new[i][j + 1] - '0') + (p_new[i][j + 2] - '0') + (p_new[i + 1][j] - '0') + (p_new[i + 1][j + 2] - '0') + (p_new[i + 2][j] - '0') + (p_new[i + 2][j + 1] - '0') + (p_new[i + 2][j + 2] - '0')) + '0';
            }
        }
    }


    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << p_arr[i][j] << '\t';
        }
    cout << endl;
    }

    for (int i = 0; i < n + 2; i++)
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

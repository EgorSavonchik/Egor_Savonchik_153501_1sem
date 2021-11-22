#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int ucheck();
int check();

int main()
{
    int n, sum =0;

    cout << "finds the product of two square matrix" << endl;
    cout << "enter number of lines and columns n" << endl;
    n = ucheck();


    int** p_arrfir = new int *[n];

    for(int i = 0; i < n; i++)
    {
        p_arrfir[i] = new int [n];
    }


    int** p_arrsec = new int *[n];

    for(int i = 0; i < n; i++)
    {
        p_arrsec[i] = new int [n];
    }


    int** p_new = new int *[n];

    for(int i = 0; i < n; i++)
    {
        p_new[i] = new int [n];
    }

    cout << "enter first matrix(with number of lines and columns equal " << n << ")" << endl;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            p_arrfir[i][j] = check();
        }
    }

    cout << "enter second matrix(with number of lines and columns equal " << n << ")" << endl;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            p_arrsec[i][j] = check();
        }
    }


    for (int str = 0; str < n; str++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                sum += p_arrfir[str][j] * p_arrsec[j][i];
            }

        p_new[str][i] = sum;
        sum = 0;
        }
    }


    cout << "products equal" << endl;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
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
        delete[] p_arrsec[i];
    }
    delete[] p_arrsec;

    for (int i = 0; i < n; i++)
    {
        delete[] p_arrfir[i];
    }
    delete[] p_arrfir;
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



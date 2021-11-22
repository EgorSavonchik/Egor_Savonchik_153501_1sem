#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int ucheck();

int main()
{
    int n, n2, order = 0, counter = 2;

    cout << "The table is filled in according to the following algorithm:" << endl << "All natural numbers are entered into the the table in order." << endl
    << "1 becomes in the top-left cell, then the left-most blank cell in the very first row of the table is selected and filled.";
    cout << "Then, while the last filled cell has a heighbor on the left and is full, we go down and fill in the next cell." << endl
    << "When there is no heighbor to he left, then filling the cell in the first columns is filled," << endl << "then the filling algorithm will be repeated." << endl;
    cout << "prints the lines and column that the number is in" << endl;

    cout << "enter the number" << endl;
    n = ucheck();

    n2 = n;

    for(int i = 1; n > 0; i += 2)
    {
        n -= i;
        order++;
    }

    int** p_arr = new int *[order];

    for(int i = 0; i < order; i++)
    {
        p_arr[i] = new int [order];
    }


    for(int i = 0; i < order; i++)
    {
        for(int j = 0; j < order; j++)
        {
            p_arr[i][j] = 0;
        }
    }

    p_arr[0][0] = 1;

    for(int i = 1; i < order; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            p_arr[j][i] = counter;
            counter++;
        }

        for (int j = i - 1; j >= 0; j--)
        {
            p_arr[i][j] = counter;
            counter++;
        }
    }


    for(int i = 0; i < order; i++)
    {
        for(int j = 0; j < order; j++)
        {
            if(p_arr[i][j] == n2)
            {
                cout << "i " << i << " j " << j;
            }
        }
    }


    for (int i = 0; i < order; i++)
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
            if (!((n[i] - '0') >= 0 && (n[i] - '0') <= 9) || n[i] == '0')
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

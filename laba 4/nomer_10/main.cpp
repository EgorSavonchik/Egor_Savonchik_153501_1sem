#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int ucheck();

int main()
{
    int n,val = 1, a, b;

    cout << "builds a magic square of any order" << endl;
    cout << "enter square order n" << endl;
    n = ucheck();

    int** p_arr = new int *[n];

    for(int i = 0; i < n; i++)
    {
        p_arr[i] = new int [n];
    }

    int** p_new = new int *[n];

    for(int i = 0; i < n; i++)
    {
        p_new[i] = new int [n];
    }



    if (n % 2 == 1)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n;j++)
            {
                p_arr[i][j] = val;
                val++;
            }
        }

        a = 0;
        b = n / 2;
        for(int i = 0; i < n; i++)
        {

            if (i % 2 == 1)
            {
                for(int j = 1; j < n; j += 2)
                {
                    if(j >= n)
                    {

                        break;
                    }
                    p_new[i][j] = p_arr[a][b];
                    p_arr[a][b] = 0;
                    a++;
                    b++;
                }
            }
            else
            {
                for(int j = 0; j < n; j +=2)
                {

                    if(j >= n)
                    {
                        break;
                    }
                    p_new[i][j] = p_arr[a][b];
                    p_arr[a][b] = 0;
                    a++;
                    b++;
                }
            }

        a = a - n / 2 ;
        b = b - n / 2 - 1;
        }

        for(int i = 0; i <= (n / 2); i++)
        {
            for(int j = 0; j < n; j++)
            {
                if ( p_arr[i][j] != 0)
                {
                    swap(p_arr[i][j],p_arr[n - i - 1][n - j - 1]);
                }
            }
        }


    }






    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << p_arr[i][j] << '\t';
        }
    cout << endl;
    }

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
        delete[] p_arr[i];
    }
    delete[] p_arr;
}

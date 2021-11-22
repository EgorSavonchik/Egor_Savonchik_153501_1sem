#include <iostream>

using namespace std;

double** create_2m_cindouble(int n, int k);
int** create_2m_cint(int n, int k);
void delet_2m(int n, auto** A);
int amout_main_dio_even(int n, int k, int** A);
int arrpr(int n, int* p_arr);
void out(int n, auto* p_arr);
void checkfor0(int n, int k, double** A);
void coup(int n, int k, double** A);
double arrmean(int n, int* p_arr);
int check();

int main()
{
    int choice;

    cout << "select the required task:" << endl;
    cout << "1) crates an array of elements located on the main diagonal of given array and having an even value." << endl
    << "finds the product of array elements" << endl;
    cout << "2) determines whether are zero-valued elements of the input array. if there are, then determine their" << endl
    << "indexes and the total number. rearranges the elements of this array in reverse order" << endl;
    cout << "3) creates a array of elements, located in even columns of this array and having an odd value. calculate" << endl
    << "the arithmetic mean of the elements of a array" << endl;

    while(1)
    {
        choice = check();

        if(choice <= 3 && choice >= 1)
        {
            break;
        }
    }

    switch(choice)
    {
        case 1:
        {
            int n, k, leng_1m;

            cout << "enter n and k" << endl;

            n = check();
            k = check();

            int** A = create_2m_cint(n, k);

            leng_1m = amout_main_dio_even(n, k, A);

            int* p_arr = new int[leng_1m];

            for(int i = 0, j = 0; i < n and i < k; i++)
            {
                if(A[i][i] % 2 == 0)
                {
                    p_arr[j] = A[i][i];
                    j++;
                }
            }

            out(leng_1m, p_arr);
            cout << arrpr(leng_1m, p_arr);

            delete[] p_arr;
            delet_2m(n, A);
        }

        break;

        case 2:
        {
            int n, k;

            cout << "enter n and k" << endl;

            n = check();
            k = check();

            double** A = create_2m_cindouble(n, k);

            checkfor0(n, k, A);

            coup(n, k, A);

            for(int i = 0; i < n; i++)
            {
                out(k, A[i]);
            }
        }

        break;

        case 3:
        {
            int n, k, amout = 0;

            cout << "enter n and k" << endl;

            n = check();
            k = check();

            int** A = create_2m_cint(n, k);

            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < k; j += 2)
                {
                    if( A[i][j] % 2== 1)
                    {
                        amout++;
                    }
                }
            }

            int* p_arr = new int[amout];

            for(int i = 0, a = 0; i < n; i++)
            {
                for(int j = 0; j < k; j += 2)
                {
                    if( A[i][j] % 2 == 1)
                    {
                        p_arr[a] = A[i][j];
                        a++;
                    }
                }
            }

            cout << arrmean(amout, p_arr);
        }
    }
}

double** create_2m_cindouble(int n, int k)
{
    double** A = new double *[n];

    cout << "enter array " << n << " * " << k << endl;

    for(int i = 0; i < n; i++)
    {
        A[i] = new double [k];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < k; j++)
        {

            while(!(cin >> A[i][j]))
            {
                cin.clear();
                cin.ignore(INT_MAX - 1, '\n');
                cout << "incorrect number" << endl;
            }
        }
    }

    return(A);
}

int** create_2m_cint(int n, int k)
{
    int** A = new int *[n];

    cout << "enter array " << n << " * " << k << endl;

    for(int i = 0; i < n; i++)
    {
        A[i] = new int [k];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < k; j++)
        {
            while(!(cin >> A[i][j]))
            {
                cin.clear();
                cin.ignore(INT_MAX - 1, '\n');
                cout << "incorrect number" << endl;
            }
        }
    }

    return(A);
}

void delet_2m(int n, auto** A)
{
    for (int i = 0; i < n; i++)
    {
        delete[] A[i];
    }
    delete[] A;
}

int amout_main_dio_even(int n, int k, int** A)
{
    int amout = 0;

    for(int i = 0; i < n and i < k; i++)
    {
        if( A[i][i] % 2 == 0)
        {
            amout++;
        }
    }

    return(amout);
}

int arrpr(int n, int* p_arr)
{
    int arraypr = 1;
    for(int i = 0; i < n; i++)
    {
        arraypr *= p_arr[i];
    }
    if(arraypr == 1)
    {
        return(0);
    }
    else
    {
        return(arraypr);
    }
}

void out(int n, auto* p_arr)
{
    for(int i = 0; i < n; i++)
    {
        cout << p_arr[i] << '\t';
    }
    cout << endl;
}

void checkfor0(int n, int k, double** A)
{
    int amout = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < k; j++)
        {
            if ( A[i][j] == 0)
            {
                cout << "0 located " << i << " " << j << endl;
                amout++;
            }
        }
    }

    if ( amout == 0)
    {
        cout << "no 0" << endl;
    }
}

void coup(int n, int k, double** A)
{
    int a = n - 1, b = k - 1;

    double** p_arr = new double *[n];

    for(int i = 0; i < n; i++)
    {
        p_arr[i] = new double [k];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < k; j++)
        {
            p_arr[i][j] = A[i][j];
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < k; j++)
        {
            A[i][j] = p_arr[a][b - j];
        }

        a--;
    }
}

double arrmean(int n, int* p_arr)
{
    double sum = 0.0;

    for(int i = 0; i < n; i++)
    {
        sum += p_arr[i];
    }

    return(sum / n);
}

int check()
{
int n;

    cin >> n;

    while(n <= 0 || cin.get() != '\n')
    {
        cin.clear();
        cin.ignore(INT_MAX - 1, '\n');
        cout << "incorrect number" << endl;

        cin >> n;
    }

    return(n);
}

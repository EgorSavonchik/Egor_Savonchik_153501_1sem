#include <iostream>
#include <string>

using namespace std;

string powstr(const string& str, int k);
int len(const string& a);
bool k_bit(string str, int k);

int main()
{
    string* A = new string[10000];
    string* B = new string[10000];

    A[0] = "0";

    int counterB, n, counterA = 1, k = 1, counterBIN = 1, tmp;

    cout << "Displays the n-th smallest bindecimal number." << endl;
    cout << "enter n" << endl;

    cin >> n;

    while(n < 1 || n > 10000 || cin.get() != '\n')
    {
        cin.clear();
        cin.ignore(INT_MAX - 1, '\n');
        cout << "incorrect number" << endl;

        cin >> n;
    }

    while(n >= counterBIN)
    {
        tmp = counterB = 0;

        for(int i = 0; i < counterA; i++)
        {
            if(!k_bit(A[i], k))
            {
                A[tmp] = A[i];
                tmp++;
            }
        }

        counterA = tmp;

        for(int i = 0; i < counterA; i++)
        {
            B[i] = powstr(A[i], k - 1);
            counterB++;
        }

        for(int i = 0; i < counterB; i++)
        {
            A[counterA] = B[i];
            counterA++;
        }

        counterBIN += counterB;
        k++;
    }

    cout << B[counterB - (counterBIN - n)];

    delete[] A;
    delete[] B;
}

bool k_bit(string str, int k)
{
    int bit, i = 0;
    int lenstr = len(str);

    for( ; i != (k); i++)
    {
        bit = (str[lenstr - 1] - '0') % 2;
        str[lenstr - 1] = str[lenstr - 1] - bit;

        for(int j = lenstr - 1; j >= 0; j--)
        {
            if((str[j] - '0') % 2 == 0)
            {
                str[j] = (str[j] - '0') / 2 + '0';
            }
            else
            {
                str[j] = (str[j] - '0') / 2 + '0';

                if(j != lenstr - 1)
                {
                    str[j + 1] = str[j + 1] + 5;
                }

            }
        }
    }

    return(bit);
}


int len(const string& a)
{
    int len = 0;

    for( ; a[len] != '\0'; len++);

    return(len);
}

string powstr(const string& str, int k)
{
    string deg = "1";

    if(k == 0)
    {
        return("1");
    }

    for(int i = 0; i < k; i++)
    {
        deg += '0';
    }

    for(int i = len(deg) - 1, j = len(str) - 1; i >= 0 && j >= 0; i--, j--)
    {
        deg[i] = str[j];
    }

    return(deg);
}

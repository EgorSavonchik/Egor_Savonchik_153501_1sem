#include <iostream>

using namespace std;

int main()
{
    int len, min_len = 0, max_len = 0, mins = 0, maxs = 0;

    cout << "finds all words of maximum and minimum length" << endl;

    char* str = new char[100];

    for(int i = 0; i < 100; i++)
    {
        str[i] = getchar();

        if ((int)str[i] == 10)
        {
            len = i;
            break;
        }
    }

    min_len = len;

    for(int i; i < len; i++)
    {
        for( ; str[i] != ' ' && i < len; i++)
        {
            mins++;
            maxs++;
        }

        if(maxs >= max_len)
        {
            max_len = maxs;
        }

        if(mins <= min_len)
        {
            min_len = mins;
        }

        mins = maxs = 0;
    }

    char* min_str = new char[min_len];
    char* max_str = new char[max_len];

    for(int i = 0; i < len; i++)
    {
        for( ; str[i] != ' ' && i < len; i++)
        {
            min_str[mins] = str[i];
            max_str[maxs] = str[i];

            mins++;
            maxs++;
        }

        if(mins == min_len)
        {
            cout << "min ";
            for(int j = 0; j < min_len; j++)
            {
                cout << min_str[j];
            }
            cout << endl;
        }

        if(maxs == max_len)
        {
            cout << "max ";
            for(int j = 0; j < max_len; j++)
            {
                cout << max_str[j];
            }
            cout << endl;
        }

        mins = maxs = 0;
    }

    delete[] min_str;
    delete[] max_str;
    delete[] str;
}

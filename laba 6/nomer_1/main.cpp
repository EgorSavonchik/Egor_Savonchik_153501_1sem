#include <iostream>

using namespace std;

int main()
{
    int len, num;

    cout << "prints the even numbers of the given string " << endl;

    char str[80];

    for(int i = 0; i < 80; i++)
    {
        str[i] = getchar();

        if ((int)str[i] == '\n')
        {
            len = i;
            break;
        }
    }

    for(int i = 0; i <= len; i++ )
    {
        num = 0;

        for( ; str[i] != ' ' && i < len; i++)
        {
            num = num * 10 + (int)str[i] - '0';
        }

        if(num % 2 == 0)
        {
            cout << num << " ";
        }
    }
}

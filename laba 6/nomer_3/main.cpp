#include <iostream>
#include <string>

using namespace std;

int check();

string palindrom(string str);

int main()
{
    int n;
    cout << "takes an array of length n stings, checks if a string is a palindrome" << endl;
    cout << "enter number of string n" << endl;

    n = check();

    getchar();

    string* given = new string[n];

    for(int coun = 0; coun < n; coun++)
    {
        for(int i = 0; i < INT_MAX; i++)
        {
            given[coun] += getchar();

            if ((int)given[coun][i] == 10)
            {
                break;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << "string " << i + 1 << palindrom(given[i]) << endl;
    }
    delete[] given;
}

string palindrom(string str)
{
    int counter = 0;

    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] != ' ' and (int)str[i] != 10)
        {
            str[counter] = str[i];
            counter++;
        }
    }
    for(int i = 0; i < counter / 2; i++)
    {
        if(str[i] != str[counter - i - 1])
        {
            return (" No.");
        }
    }

    return (" Yes.");
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

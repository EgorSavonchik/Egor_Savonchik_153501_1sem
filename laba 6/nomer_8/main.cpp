#include <iostream>
#include <string>

using namespace std;

bool check(string str, string str_sougth);
int check();

int main()
{
    int n;
    string str_given, str_sougth, str_check;
    bool label;

    cout << "the clip can be placed on any letter, it can also be moved to the right several times, after that if can be moved" << endl
    << "to the left several times, when the chip placed or moved, the letter on which it becomes written in a new string" << endl;

    cout << "program determines whether it is possible to get another from one string in this way" << endl;
    cout << "enter the number of requests" << endl;
    n = check();

    for(int coun = 0; coun < n; coun++)
    {
        label = false;
        str_check = "";

        cout << "enter start line and the line we are checking" << endl;
        cin >> str_given >> str_sougth;

        for(int start_char = 0; start_char < str_given.length() && !label; start_char++)
        {
            str_check = "";

            str_check += str_given[start_char];

            label = check(str_check, str_sougth);

            for(int forwar = start_char + 1; forwar < str_given.length() && !label; forwar++)
            {
                str_check += str_given[forwar];

                label = check(str_check, str_sougth);

                for(int opposit = forwar  - 1; opposit >= 0 && !label; opposit--)
                {
                    str_check += str_given[opposit];

                    label = check(str_check, str_sougth);
                }

                str_check.erase(forwar + 1 - start_char);
            }
        }

        if(label)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}

bool check(string str, string str_sougth) //чтобы не писать много ифов
{
    if(str == str_sougth)
    {
        return(true);
    }
    else
    {
        return(false);
    }
}

int check()
{
    int n;

    cin >> n;

    while( n <= 0 || cin.get() != '\n')
    {
        cin.clear();
        cin.ignore(INT_MAX - 1, '\n');
        cout << "incorrect number" << endl;

        cin >> n;
    }

    return(n);
}

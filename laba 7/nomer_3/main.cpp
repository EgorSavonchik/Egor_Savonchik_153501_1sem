#include <iostream>
#include <string>

using namespace std;

int len(const string& str);
void add(string& str); //перевод в дополнительный + дополнение до равного размера
string sum(const string& num1, const string& num2);
string zero_del(const string& str);
string bin_check();

int main()
{
    string num1, num2;

    cout << "find the sum of binary numbers given in natural form(addition in complementary code)" << endl;
    cout << "enter numbers in natural form" << endl;

    num1 = bin_check();
    num2 = bin_check();

    add(num1);
    add(num2);

    cout << zero_del(sum(num1, num2));
}

int len(const string& a)
{
    int len = 0;

    for( ; a[len] != '\0'; len++);

    return(len);
}

void add(string& str)
{
    int length = len(str);

    if(str[0] == '0')
    {
        for(int i = 0; i < 32 - length; i++)
        {
            str = '0' + str;
        }
    }
    else
    {
        for(int i = 0; i < 32; i++)
        {
            if(i < 32 - length)
            {
                str = '1' + str;
            }
            else
            {
                if(i == 32 - length)
                {
                    continue;//знаковый не надо переворачивать
                }

                if(str[i] == '0')
                {
                    str[i] = '1';
                }
                else
                {
                    str[i] = '0';
                }
            }
        }

        str[31]++;

        for(int i = 31; str[i] == '2'; i--)
        {
            str[i] -= 2;
            str[i - 1]++;
        }
    }
}


string sum(const string& num1, const string& num2)
{
    string res = "";

    for(int i = 0; i < 32; i++)
    {
        res += "0";
    }

    for(int i = 31; i >= 0; i--)
    {
        res[i] += num1[i] + num2[i] - '0' - '0';

        if(res[i] > '1')
        {
            res[i] -= 2;

            if(i != 0)
            {
                res[i - 1] += 1;
            }
        }
    }

    if(res[0] == '1')
    {
        res[31]--;

        for(int i = 31; (int)res[i] == '0' - 1; i--)
        {
            res[i] = '1';

            res[i - 1]--;
        }

        for(int i = 1; i < 32; i++)
        {
            if(res[i] == '0')
            {
                res[i] = '1';
            }
            else
            {
                res[i] = '0';
            }
        }
    }

    return(res);
}

string zero_del(const string& str)
{
    string res;
    res += str[0];

    bool copystr = false;

    for(int i = 1; i < 32; i++)
    {
        if(str[i] == '1' && !copystr)
        {
            copystr = true;
        }

        if(copystr)
        {
            res += str[i];
        }
    }

    return(res);
}

string bin_check()
{
    string str;
    bool normal = false;

    cin >> str;

    while(!normal)
    {
        normal = true;

        for(int i = 0; i < len(str); i++)
        {
            if(str[i] > '1' || str[i] < '0')
            {
                cin.clear();
                cin.ignore(INT_MAX -  1, '\n');
                cout << "incorrect number" << endl;

                cin >> str;

                normal = false;
            }
        }
    }

    return(str);
}

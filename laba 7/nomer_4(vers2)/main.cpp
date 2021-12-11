#include <iostream>
#include <string>

using namespace std;

string bin_check();
string del_zero(string res, int len_max);
bool comprasion(int* num1, int* num2, int len_max);
string lit_trans(int* num_arr, int len);
int len(string str);
string sum(int* num1, int* num2, int len_max);
string sub(int* num1, int* num2, int len_max);
void addition(int* num1, int* num2, string str1, string str2, int len_max);

int main()
{
    string str1, str2, res, sign_res = "";
    int choice, len_max;
    bool sign1 = 0, sign2 = 0; //по умолчанию знак +

    cout << "select function 1 - sum, 2 - sub" << endl;

    cin >> choice;

    while(choice < 1 || choice > 2 ||cin.get() != '\n')
    {
        cin.clear();
        cin.ignore(INT_MAX - 1, '\n');
        cout << "incorrect number" << endl;

        cin >> choice;
    }

    str1 = bin_check();
    str2 = bin_check();

    if(str1[0] == '-')
    {
        sign1 = 1;
        str1[0] = '0';
    }

    if(str2[0] == '-')
    {
        sign2 = 1;
        str2[0] = '0';
    }

    if(len(str1) > len(str2))
    {
        len_max = len(str1) + 1;
    }
    else
    {
        len_max = len(str2) + 1;
    }

    int* num1 = new int[len_max];
    int* num2 = new int[len_max];

    addition(num1, num2, str1, str2, len_max);

    if((sign1 && sign2 && choice == 1) || (sign1 == 1 && sign2 == 0 && choice == 2))
    {
        res = sum(num1, num2, len_max);
        sign_res = '-';
    }
    else if((sign1 == 0 && sign2 == 1 && choice == 1) || (sign1 == 0 && sign2 == 0 && choice == 2))
    {
        if(comprasion(num1, num2, len_max))
        {
            res = sub(num1, num2, len_max);
        }
        else
        {
            res = sub(num2, num1, len_max);
            sign_res = '-';
        }
    }
    else if((sign1 == 1 && sign2 == 0 && choice == 1) || (sign1 && sign2 && choice == 2))
    {
        if(comprasion(num1, num2, len_max))
        {
            res = sub(num1, num2, len_max);
            sign_res = '-';
        }
        else
        {
            res = sub(num2, num1, len_max);
        }
    }
    else if ((sign1 == 0 && sign2 == 0 && choice == 1) || (sign1 == 0 && sign2 == 1 && choice == 2))
    {
        res = sum(num1, num2, len_max);
    }

    res = del_zero(res, len_max);

    cout << sign_res << res;

    delete[] num1;
    delete[] num2;
}

string sum(int* num1, int* num2, int len_max)
{
    int* sum_result = new int[len_max];
    string res;

    for(int i = 0; i < len_max; i++)
    {
        sum_result[i] = 0;
    }

    for(int i = len_max - 1; i > 0; i--)
    {
        sum_result[i] += num1[i] + num2[i]; // плюс чтобы учесть переход на новый разряд в прошлом действии

        if(sum_result[i] > 16)
        {
            sum_result[i] -= 17;
            sum_result[i - 1]++;
        }

    }

    res = lit_trans(sum_result, len_max);

    delete[] sum_result;

    return(res);
}

int len(string str)
{
    int len = 0;

    for( ; str[len] != '\0'; len++);

    return(len);
}

void addition(int* num1, int* num2, string str1, string str2, int len_max)
{
    for(int i = len_max - 1; i >= 0; i--)
    {
        if(i - len_max + len(str1) >= 0)
        {
            if(str1[i - len_max + len(str1)] - '0' > 9)
            {
                num1[i] = str1[i - len_max + len(str1)] - 'A' + 10;
            }
            else
            {
                num1[i] = str1[i - len_max + len(str1)] - '0';
            }
        }
        else
        {
            num1[i] = 0;
        }

        if(i - len_max + len(str2) >= 0)
        {
            if(str2[i - len_max + len(str2)] - '0' > 9)
            {
                num2[i] = str2[i - len_max + len(str2)] - 'A' + 10;
            }
            else
            {
                num2[i] = str2[i - len_max + len(str2)] - '0';
            }
        }
        else
        {
            num2[i] = 0;
        }
    }
}

string lit_trans(int* num_arr, int len)
{
    string lit = "";

    for(int i = len - 1; i >= 0; i--)
    {
        if(num_arr[i] < 10)
        {
            lit = (char)(num_arr[i] + '0') + lit;
        }
        else
        {
            lit = (char)(num_arr[i] + 'A' - 10) + lit;
        }
    }

    return(lit);
}

string sub(int* num1, int* num2, int len_max) // для num1 - num2
{
    string res;

    for(int i = len_max - 1; i > 0; i--)
    {
        num1[i] -= num2[i];

        for(int j = i; num1[j] < 0; j--)
        {
            num1[j] += 17;
            num1[j - 1]--;
        }
    }

    res = lit_trans(num1, len_max);

    return(res);
}

string del_zero(string res, int len_max)
{
    string without_zero = "";
    int num_zero = 0;

    for(int i = 0; i < len_max; i++)
    {
        if(res[i] == '0')
        {
            num_zero++;
        }
        else
        {
            break;
        }
    }

    for(int i = num_zero; i < len_max; i++)
    {
        without_zero += res[i];
    }

    if(without_zero == "")
    {
        return("0");
    }

    return(without_zero);
}

bool comprasion(int* num1, int* num2, int len_max)
{
    for(int i = 0; i < len_max; i++)
    {
        if(num1[i] > num2[i])
        {
            return(1);
        }
    }

    if(num1[len_max - 1] == num2[len_max - 1])
    {
        return(1);
    }

    return(0);
}

string bin_check()
{
    string str;
    bool normal = false;
    int i;

    cin >> str;

    while(!normal)
    {
        i = 0;
        normal = true;

        if(str[0] == '-')
        {
            i++;
        }

        for( ; i < len(str); i++)
        {
            if(!((str[i] >= '1' && str[i] <= '9') || ((str[i] >= 'A' && str[i] <= 'Z'))))
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

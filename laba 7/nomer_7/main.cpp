#include <iostream>

using namespace std;

int sum(int a, int b);
int sub(int a, int b);
int mult(int a, int b);
int divide(int a, int b);
int mod(int a, int b);
int modul(int a);

int given[] = {3, 47, 197};

int main()
{
	int num, primary;
	bool label = true;

	cout << "Determines if the entered number is divisible by 3, 47, 197" << endl;
	cout << "enter number" << endl;

	cin >> num;
    primary = num;

    while(cin.get() != '\n')
    {
        cin.clear();
        cin.ignore(sub(INT_MAX, 1), '\n');
        cout << "incorrect number" << endl;

        cin >> num;
    }

	num = modul(num);

	for (int i = 0; (i < 3) && label; )
	{
		if (mod(num, given[i]) == 0)
		{
			cout << primary << " divided by " << given[i] << endl;
		}
		else
        {
            cout << primary << " not divisible by " << given[i] << endl;
        }

		i = sum(i, 1);
	}
}

int sum(int a, int b)
{
	int res = a ^ b, rank = (a & b) << 1; // ксор - сумма, сдвиг - показывает разряд

	while (rank)
	{
		int tmp = res;
		res ^= rank; //переход на разряд
		rank = (tmp & rank) << 1;
	}

	return(res);
}

int sub(int a, int b)
{
	b = sum(~b, 1); //доп код
	return(sum(a, b));
}

int mult(int a, int b) // столбиком
{
	int res = 0;

	while (b)
	{
		if (b & 1)
		{
			res = sum(res, a);
		}

		a <<= 1;
		b >>= 1;
	}

	return(res);
}

int divide(int a, int b)
{
	int res = 0;

	while (a >= b)
	{
		res = sum(res, 1);
		a = sub(a, b);
	}

	return(res);
}

int mod(int a, int b)
{
	return(sub(a, mult(divide(a, b), b)));
}

int modul(int a)
{
	if (a < 0)
	{
		return(sub(0, a));
	}
	else
	{
		return(a);
	}
}

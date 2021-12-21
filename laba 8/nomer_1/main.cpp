#include <cstdio>
#include <cstring>

using namespace std;

int length = 0;

struct worker
{
    char name[100];
    int depart;
    char position[100];
    int experience;
    int age;
};

int enter_int(int down_reg = -10000, int up_reg = 10000);
void line();
void sort_on_exp(worker*& employees);
worker* delete_with_conditional(worker* employees);
void out_with_conditional(worker* employees);
bool condition(char str1[100], char str2[100]);
int len(char str[100]);
void create(worker*& employees);
void out(worker* employees);
worker* push(worker* employees, int append);
void add(worker*& employees);
void correct(worker*& employees);

int main()
{
    int choice;
    worker *employees;

    printf("Program for compiling a list of workers consisting of full name, number of department, work experience, position, age, and allows to perform operation on it\n");
    printf("choice function\n");

    do
    {
        line();
        printf("1)create list \n2)out content \n3)add employee in list \n4)out employeers selected department with work experience > 20 \n5)delete employeers selected department with work experience < 3 \n6)sort ascending by work expereince \n7)correct selected employee \n8)exit\n");
        line();
        choice = enter_int(1, 8);
        line();

        switch(choice)
        {
        case 1 :
            {
                create(employees);
                break;
            }
        case 2 :
            {
                out(employees);
                break;
            }
        case 3 :
            {
                add(employees);
                break;
            }
        case 4 :
            {
                out_with_conditional(employees);
                break;
            }
        case 5 :
            {
                employees = delete_with_conditional(employees);
                break;
            }
        case 6 :
            {
                sort_on_exp(employees);
                break;
            }
        case 7 :
            {
                correct(employees);
                break;
            }
        }
    } while(choice != 8);


    if(length != 0)
    {
        delete[] employees;
    }
}

void create(worker*& employees)
{
    int choice;

    printf("choice input method: \n1) input a given number of workers \n2) before this symptom appears \n3) ask if you need to enter\n");
    line();
    choice = enter_int(1, 3);
    line();

    if(length != 0)
    {
        delete[] employees;
        length = 0;
    }

    switch(choice)
    {
    case 1 :
    {
        int append;

        printf("enter a number employess\n");
        line();
        append = enter_int(0);
        line();

        employees = push(employees, append);

        break;
    }
    case 2 :
        {
            do
            {
                employees = push(employees, 1);
            } while(employees[length - 1].age > 17);

            break;
        }
    case 3 :
        {
            for(int select = 1; select != 2 ; )
            {
                employees = push(employees, 1);

                printf("continue: \n1)Yes \n2) No \n");
                line();
                select = enter_int(1, 2);
                line();
            }

            break;
        }
    }
}

void out(worker* employees)
{
    if(length == 0)
    {
        printf("array is not set\n");
        return;
    }

    for(int i = 0; i < length; i++)
    {
        printf("employee %i\n", i + 1);
        printf("name %s\n", employees[i].name);
        printf("depart %i\n", employees[i].depart);
        printf("experience %i\n", employees[i].experience);
        printf("position %s\n", employees[i].position);
        printf("age %i\n", employees[i].age);
        printf("\n");
    }
}

worker* push(worker* employees, int append)
{
    length += append;

    worker* extended = new worker[length];

    for(int i = 0; i <= length - append - 1; i++)
    {
        strcpy(extended[i].name, employees[i].name);//массив нельзя прировнять поэтому использую копирование
        extended[i].depart = employees[i].depart;
        extended[i].experience = employees[i].experience;
        strcpy(extended[i].position, employees[i].position);
        extended[i].age = employees[i].age;
    }

    for(int i = length - append; i < length; i++)
    {
        printf("employee %i\n", i + 1);

        printf("name: ");
        fflush(stdin);
        gets(extended[i].name);

        printf("depart: ");
        extended[i].depart = enter_int(1);

        printf("experience: ");
        extended[i].experience = enter_int(0);

        printf("position: ");
        fflush(stdin);
        gets(extended[i].position);

        if(len(extended[i].position) == 0)
        {
            if(extended[i].experience < 3)
            {
                strcpy(extended[i].position, "trainee");
            }
            else if(extended[i].experience < 5)
            {
                strcpy(extended[i].position, "manager");
            }
            else
            {
                strcpy(extended[i].position, "director");
            }
        }

        printf("age: ");
        extended[i].age = enter_int(0);

        printf("\n");
    }

    if(length != append)
    {
        delete[] employees;
    }

    return(extended);
}

void add(worker*& employees)
{
    if(length == 0)
    {
        printf("array is not set\n");
        return;
    }

    employees = push(employees, 1);
}

int len(char str[100])
{
    int i = 0;

    for( ; str[i] != '\0'; i++);

    return(i);
}

void out_with_conditional(worker* employees)
{
    if(length == 0)
    {
        printf("array is not set\n");
        return;
    }

    int need_depart;

    printf("enter depart: ");
    need_depart = enter_int(1);

    for(int i = 0; i < length; i++)
    {
        if((employees[i].depart ==  need_depart) && (employees[i].experience > 20))
        {
            printf("employee %i\n", i + 1);
            printf("name %s\n", employees[i].name);
            printf("depart %i\n", employees[i].depart);
            printf("experience %i\n", employees[i].experience);
            printf("position %s\n", employees[i].position);
            printf("age %i\n", employees[i].age);
            printf("\n");
        }
    }
}

worker* delete_with_conditional(worker* employees)
{
    if(length == 0)
    {
        printf("array is not set\n");
        return(employees);
    }

    int need_depart, new_length = 0;

    printf("enter depart: ");
    need_depart = enter_int(1);//ограничение?

    for(int i = 0; i < length; i++)
    {
        if((employees[i].depart != need_depart) || (employees[i].experience >= 3))
        {
            new_length++;
        }
    }

    worker* updated = new worker[new_length];

    for(int i = 0, j = 0; i < length; i++)
    {
        if((employees[i].depart != need_depart) || (employees[i].experience >= 3))
        {
            strcpy(updated[j].name, employees[i].name);
            updated[j].depart = employees[i].depart;
            updated[j].experience = employees[i].experience;
            strcpy(updated[j].position, employees[i].position);
            updated[j].age = employees[i].age;
            j++;
        }
    }

    delete[] employees;

    length = new_length;

    return(updated);
}

void sort_on_exp(worker*& employees)
{
    if(length == 0)
    {
        printf("array is not set\n");
        return;
    }

    int left = 0, rigth = length - 1;
    bool swapped = true;
    worker trade;

    while((left < rigth) && swapped)
    {
        swapped = false;

        for(int i = 0; i < rigth; i++)
        {
            if(employees[i].experience > employees[i + 1].experience)
            {
                trade = employees[i];
                employees[i] = employees[i + 1];
                employees[i + 1] = trade;

                swapped = true;
            }
        }

        rigth--;

        for(int i = left; i > 0; i--)
        {
            if(employees[i].experience < employees[i - 1].experience)
            {
                trade = employees[i];
                employees[i] = employees[i - 1];
                employees[i - 1] = trade;

                swapped = true;
            }
        }

        left++;
    }
}

void line()
{
    for(int i = 0; i < 100; i++) printf("-");
    printf("\n");
}

int enter_int(int down_reg, int up_reg)
{
    char num[100];
    int out = 0;
    bool incorrect = true;

    while(incorrect)
    {
        out = 0;
        incorrect = false;

        fflush(stdin);
        gets(num);

        for(int i = 0; num[i] != '\0'; i++)
        {
            if(num[i] >= '0' && num[i] <= '9')
            {
                out = out * 10 + num[i] - '0';
            }
            else
            {
                incorrect = true;
                break;
            }
        }

        if(out <= up_reg && out >= down_reg && !incorrect)
        {
            return(out);
        }
        else
        {
            incorrect = true;
        }

        printf("incorrect number \nenter anew\n");
    }
}

void correct(worker*& employees)
{
    if(length == 0)
    {
        printf("array nit set\n");
        return;
    }

    printf("select a number employeer\n");
    line();
    int number = enter_int(1, length);
    line();
    number--;

    printf("select a element: \n1)name \n2)depart \n3)experience \n4)posotion \n5)age \n");
    line();
    int choice = enter_int(1, 5);
    line();

    switch(choice)
    {
    case 1 :
        {
            char correct[100];
            printf("name: ");
            fflush(stdin);
            gets(correct);
            line();

            strcpy(employees[number].name, correct);

            break;

        }
    case 2 :
        {
            printf("depart: ");
            int correct = enter_int(1);
            line();
            employees[number].depart = correct;

            break;
        }
    case 3 :
        {
            printf("experience: ");
            int correct = enter_int(0);
            line();
            employees[number].experience = correct;

            break;
        }
    case 4 :
        {
            char correct[100];
            printf("position: ");
            fflush(stdin);
            gets(correct);
            line();
            strcpy(employees[number].position, correct);
            line();

            break;
        }
    case 5 :
        {
            printf("age: ");
            int correct = enter_int(0);
            line();
            employees[number].age = correct;

            break;
        }
    }
}

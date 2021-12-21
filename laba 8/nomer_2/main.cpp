#include <cstdio>
#include <fstream>
#include <cstring>

using namespace std;

int length = 0;

struct participant
{
    char country[100];
    char team[100];
    char name[100];
    int number;
    int age;
    int height;
    int weight;
};

bool inside(char** teams, int len, char verifiable[100]);//проверить, находится ли строка verifiable в массиве строк длиной len
void young_team(participant* sportsmans);
void correct(participant*& sportsmans);
participant* delete_number(participant* sportsmans);
void add(participant*& sportsmans);
participant* push_one(participant* sportsmans);// увеличивает длину массива структур на 1
void out(participant* sportsmans);
participant* initialization(participant*& sportsmans);// считывает с файла входные данные
int enter_int(int down_reg  = -10000, int up_reg = 10000); //проверка на ввод интовых чисел
void line();

int main()
{
    int choice;
    participant* sportsmans;

    printf("program reads from a file information about participants in sports competitions containing: country, team, name, game number, age, height, weight and allows to perform operation on it, after writes the result to a file\n");
    printf("Select function\n");

    do
    {
        line();
        printf("1)initialization list from file \n2)add participans in list \n3)delete participant with selected ordinal number \n4)correct information about participant with selected ordinal number \n5)view contents \n6)displaying information about the youngest team \n7)exit \n");
        line();
        choice = enter_int(1, 7);
        line();

        switch(choice)
        {
        case 1 :
            {
                sportsmans = initialization(sportsmans);
                break;
            }
        case 2 :
            {
                add(sportsmans);
                break;
            }
        case 3 :
            {
                sportsmans = delete_number(sportsmans);
                break;
            }
        case 4 :
            {
               correct(sportsmans);
               break;
            }
        case 5 :
            {
               out(sportsmans);
               break;
            }
        case 6 :
            {
               young_team(sportsmans);
               break;
            }
        }
    } while(choice != 7);

    ofstream fout;

    fout.open("Output.txt");

    for(int i = 0; i < length; i++)
    {
        fout << sportsmans[i].country << '\n';
        fout << sportsmans[i].team << '\n';
        fout << sportsmans[i].name << '\n';
        fout << sportsmans[i].number << '\n';
        fout << sportsmans[i].age << '\n';
        fout << sportsmans[i].height << '\n';
        fout << sportsmans[i].weight << '\n';
    }

    fout.close();

    if(length != 0)
    {
        free(sportsmans);
    }
}

participant* initialization(participant*& sportsmans)
{
    if(length != 0) //если массив уже задан - удалить и прочитать заново
    {
        free(sportsmans);
        length = 0;
    }

    ifstream fin;

    fin.open("input.txt");

    for(int i = 0; !fin.eof(); i++)
    {
        sportsmans = push_one(sportsmans);

        fin.getline(sportsmans[i].country, 100, '\n');
        fin.getline(sportsmans[i].team, 100, '\n');
        fin.getline(sportsmans[i].name, 100, '\n');
        fin >> sportsmans[i].number;
        fin >> sportsmans[i].age;
        fin >> sportsmans[i].height;
        fin >> sportsmans[i].weight;
        fin.ignore(INT_MAX, '\n');
    }

    fin.close();

    return(sportsmans);
}

void out(participant* sportsmans)
{
    if(length == 0)
    {
        printf("array is not set\n");
        return;
    }

    for(int i = 0; i < length; i++)
    {
        printf("participant %i\n", i + 1);
        printf("country %s\n", sportsmans[i].country);
        printf("team %s\n", sportsmans[i].team);
        printf("name %s\n", sportsmans[i].name);
        printf("number %i\n", sportsmans[i].number);
        printf("age %i\n", sportsmans[i].age);
        printf("weight %i\n", sportsmans[i].weight);
        printf("height %i\n", sportsmans[i].height);
        if(i != length - 1)
        {
            printf("\n");
        }
    }
}

participant* push_one(participant* sportsmans)
{
    participant* extended;
    length++;

    extended = (participant*)calloc(length, sizeof(struct participant));

    for(int i = 0; i < length - 1; i++)
    {
        strcpy(extended[i].country, sportsmans[i].country);
        strcpy(extended[i].team, sportsmans[i].team);
        strcpy(extended[i].name, sportsmans[i].name);
        extended[i].number = sportsmans[i].number;
        extended[i].age = sportsmans[i].age;
        extended[i].height = sportsmans[i].height;
        extended[i].weight = sportsmans[i].weight;
    }

    if(length != 1)
    {
        free(sportsmans);
    }

    return(extended);
}

void add(participant*& sportsmans)
{
    sportsmans = push_one(sportsmans);

    printf("country: ");
    fflush(stdin);
    gets(sportsmans[length - 1].country);

    printf("team: ");
    fflush(stdin);
    gets(sportsmans[length - 1].team);

    printf("name: ");
    fflush(stdin);
    gets(sportsmans[length - 1].name);

    printf("number: ");
    sportsmans[length - 1].number = enter_int(1);

    printf("age: ");
    sportsmans[length - 1].age = enter_int(0);

    printf("height: ");
    sportsmans[length - 1].height = enter_int(0);

    printf("weight: ");
    sportsmans[length - 1].weight = enter_int(0);
}

participant* delete_number(participant* sportsmans) //удаляет элемент массива по порядковому номеру
{
    if(length == 0)
    {
        printf("array is not set\n");
        return(sportsmans);
    }


    participant* updated = (participant*)calloc(length - 1, sizeof(struct participant));
    int number;

    printf("enter number participant: ");
    number = enter_int(1, length);

    number--;// т к индексы идут с 0

    for(int i = 0, j = 0; i < length; i++)
    {
        if(i != number)
        {
            strcpy(updated[j].country, sportsmans[i].country);
            strcpy(updated[j].team, sportsmans[i].team);
            strcpy(updated[j].name, sportsmans[i].name);
            updated[j].number = sportsmans[i].number;
            updated[j].age = sportsmans[i].age;
            updated[j].height = sportsmans[i].height;
            updated[j].weight = sportsmans[i].weight;
            j++;
        }
    }

    free(sportsmans);

    length--;

    return(updated);
}

void correct(participant*& sportsmans)//изменят выбранное поле структуры с порядковым номером
{
    if(length == 0)
    {
        printf("array is not set\n");
        return;
    }

    int number, choice;

    printf("enter number participant: ");
    number = enter_int(0, length);
    number--;
    line();

    printf("select element to correct: \n1)country \n2)team \n3)name \n4)number \n5)age \n6)height \n7)weight \n");
    line();
    choice = enter_int(1, 7);
    line();

    switch(choice)
    {
    case 1 :
        {
            char correct[100];
            printf("country: ");
            fflush(stdin);
            gets(correct);
            line();
            strcpy(sportsmans[number].country, correct);

            break;
        }
    case 2 :
        {
            char correct[100];
            printf("team: ");
            fflush(stdin);
            gets(correct);
            line();
            strcpy(sportsmans[number].team, correct);

            break;
        }
    case 3 :
        {
            char correct[100];
            printf("name: ");
            fflush(stdin);
            gets(correct);
            line();
            strcpy(sportsmans[number].name, correct);

            break;
        }
    case 4 :
        {
            int correct;
            printf("number: ");
            correct = enter_int(1);
            line();
            sportsmans[number].number = correct;

            break;
        }
    case 5 :
        {
            int correct;
            printf("age: ");
            correct = enter_int(0);
            line();
            sportsmans[number].age = correct;

            break;
        }
    case 6 :
        {
            int correct;
            printf("height: ");
            correct = enter_int(0);
            line();
            sportsmans[number].height = correct;

            break;
        }
    case 7 :
        {
            int correct;
            printf("weight: ");
            correct = enter_int(0);
            line();
            sportsmans[number].weight = correct;

            break;
        }
    }
}

void young_team(participant* sportsmans)
{
    int different_team = 0, number_players = 0, minim = 0;

    char** teams = (char**)calloc(length, sizeof(char*));
    for(int i = 0; i < length; i++)
    {
        teams[i] = (char*)calloc(100, sizeof(char));
    }

    for(int i = 0; i < length; i++)
    {
        if(!inside(teams, different_team, sportsmans[i].team))
        {
            strcpy(teams[different_team], sportsmans[i].team);
            teams[different_team][strlen(sportsmans[i].team)] = '\0';
            different_team++;
        }
    }

    double* average_age = (double*)calloc(different_team, sizeof(double));

    for(int i = 0; i < different_team; i++)
    {
        number_players = 0;

        for(int j = 0; j < length; j++)
        {
            if(!strcmp(teams[i], sportsmans[j].team))
            {
                number_players++;
                average_age[i] += sportsmans[j].age;
            }
        }

        average_age[i] /= number_players;
    }

    for(int i = 0; i < different_team; i++)
    {
        if(average_age[minim] > average_age[i])
        {
            minim = i;
        }
    }

    for(int i = 0; i < length; i++)
    {
        if(!strcmp(teams[minim], sportsmans[i].team))
        {
            printf("participant %i\n", i + 1);
            printf("country %s\n", sportsmans[i].country);
            printf("team %s\n", sportsmans[i].team);
            printf("name %s\n", sportsmans[i].name);
            printf("number %i\n", sportsmans[i].number);
            printf("age %i\n", sportsmans[i].age);
            printf("weight %i\n", sportsmans[i].weight);
            printf("height %i\n", sportsmans[i].height);
        }
    }

    for(int i = 0; i < length; i++)
    {
        free(teams[i]);
    }

    free(teams);
    free(average_age);
}

bool inside(char** teams, int len, char verifiable[100])
{
    for(int i = 0; i < len; i++)
    {
        if(!strcmp(teams[i], verifiable))
        {
            return(true);
        }
    }
    return(false);
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

void line()
{
    for(int i = 0; i < 100; i++) printf("-");
    printf("\n");
}

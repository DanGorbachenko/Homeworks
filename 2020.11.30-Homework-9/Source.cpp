#include<iostream>
#include<iomanip>
#include<string>
#include<ctime>
#include<cmath>
using namespace std;

void resolveError(int errorCode)
{
    string error11 = "You entered not a number!";
    string error12 = "Your number contains other symbols!";
    string error13 = "Please, enter a number like 523456!";
    string error21 = "You entered too big number!";
    string error22 = "You number is too big!";
    string error23 = "Please, enter a number more than -9223372036854775809 and less than 9223372036854775808";
    string errors1[3] = { error11, error12, error13 };
    string errors2[3] = { error21, error22, error23 };
    srand(time(NULL));
    if (errorCode == 1)
    {
        cout << errors1[rand() % 2] << endl << errors1[2] << endl;
    }
    if (errorCode == 2)
    {
        cout << errors2[rand() % 2] << endl << errors2[2] << endl;
    }
}

int readInt(long long& number)
{
    long long result = 0;
    int check[19] = { 9, 2, 2, 3, 3, 7, 2, 0, 3, 6, 8, 5, 4, 7, 7, 5, 8, 0, 7 };
    string str;
    getline(cin, str);
    if (str.size() >= 20)
    {
        number = 0;
        return 2;    //Too big value
    }
    for (int i = 0; i < str.size(); i++)
    {
        if (!isdigit(str[i]))
        {
            number = 0;
            return 1;    //String is not a number
        }
    }
    if (str.size() == 19)
    {
        for (int i = 0; i < 19; i++)
        {
            if (str[i] - '0' > check[i])
            {
                number = 0;
                return 2;
            }
            if (str[i] - '0' < check[i])
            {
                break;
            }
        }
    }
    for (int i = 0; i < str.size(); ++i)
    {
        result = 10 * result + str[i] - '0';
    }
    number = result;
    return 0;
}

int readDouble(double& number)
{
    double result = 0;
    string str;
    getline(cin, str);
    for (int i = 0; i < str.size(); i++)
    {
        if (!isdigit(str[i]) && str[i] != '.')
        {
            number = 0;
            return 1;    //String is not a number
        }
    }
    int index = str.size();
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == '.')
        {
            index = i;
        }
    }
    for (int i = 0; i < index; ++i)
    {
        result = 10 * result + str[i] - '0';
    }
    for (int i = index + 1; i < str.size(); ++i)
    {
        result = result + (double)(str[i] - '0') / pow(10, i - index);
    }
    number = result;
    return 0;
}

void sum(long long number1, double number2)
{
    cout << number1 + number2;
}

int main()
{
    //long long number1 = 9223372036854775807;
    //double number2 = 19223372036854775807.999;
    long long number1;
    double number2;
    int error1, error2;
    do
    {
        error1 = readInt(number1);
        error2 = readDouble(number2);
        if (error1 || error2)
        {
            resolveError(error1);
            resolveError(error2);
        }
        else
        {
            break;
        }
    } while (true);
    sum(number1, number2);
    return 0;
}

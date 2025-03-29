#include "Number.h"
#include<iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

Number::Number(const char* value, int base)
{
    this->baza = base;
    this->value = new char[strlen(value) + 1];
    strcpy_s(this->value, strlen(value)+1, value);
}

Number::~Number()
{
    delete[] this->value;
}

Number::Number(const Number& nr)
{
    this->value = new char[strlen(nr.value) + 1];
    strcpy_s(this->value, strlen(nr.value) + 1, nr.value);
    this->baza = nr.baza;
}

Number::Number(Number&& nr)
{
    this->value = nr.value;
    this->baza = nr.baza;
    nr.value = nullptr;
    nr.baza = 0;

}

void Number::SwitchBase(int newBase)
{
    if (newBase < 2 || newBase > 16)
    {
        cerr << "Baza invalida!" << endl;
        return;
    }

    // Convertim valoarea din baza actuală în baza 10
    int decimalValue = 0;
    int len = strlen(value);

    for (int i = 0; i < len; i++)
    {
        char digit = value[i];
        int digitValue;
        if (digit>='0'&&digit<='9')
            digitValue = digit - '0';
        else
            digitValue = toupper(digit) - 'A' + 10;
        decimalValue = decimalValue * baza + digitValue;
    }

    // Convertim valoarea din baza 10 în noua bază
    char buffer[65]; // Suficient pentru reprezentarea unui număr mare
    int index = 0;

    do
    {
        int remainder = decimalValue % newBase;
        if (remainder < 10)
            buffer[index] = '0' + remainder;
        else
            buffer[index] = 'A' + remainder - 10;
        index++;
        decimalValue /= newBase;
    } while (decimalValue > 0);

    buffer[index] = '\0';

    // Inversăm manual șirul obținut
    for (int i = 0, j = index - 1; i < j; i++, j--)
    {
        char temp = buffer[i];
        buffer[i] = buffer[j];
        buffer[j] = temp;
    }

    // Eliberăm memoria și alocăm pentru noua valoare
    delete[] value;
    value = new char[index + 1];
    strcpy_s(value, static_cast<rsize_t>(index) + 1, buffer);

    // Actualizăm baza
    baza = newBase;
}


void Number::Print()
{
    printf( "%s\n", this->value);
}

int Number::GetDigitsCount()
{
    return strlen(this->value);
}

int Number::GetBase()
{
    return this->baza;
}

void Number::operator++()
{

}

void Number::operator++(int numar)
{


}

void Number::operator--()
{
    int len = strlen(this->value);
    for (int i = 0;i < len;i++)
    {
        this->value[i] = this->value[i + 1];
    }
}

void Number::operator--(int numar)
{
    this->value[strlen(this->value) - 1] = '\0';
}

bool Number::operator!()
{
    this->SwitchBase(10);
    int val = atoi(this->value);

    return !val;
}

int Number::operator[](int index)
{
    char ch = this->value[index];
    if (ch >= '0' && ch <= '9')
        return ch - '0';
    else if (ch >= 'a' && ch <= 'f')
        return ch - 'a' + 10;
    else if (ch >= 'A' && ch <= 'F')
        return ch - 'A' + 10;

    return 0;
}

Number& Number::operator=(Number&& num) {
    if (this != &num) { // Verificăm auto-asignarea
        // Eliberăm memoria curentă
        delete[] value;

        // Mutăm resursele din num în obiectul curent
        this->value = num.value;
        this->baza = num.baza;

        // Resetăm obiectul mutat pentru a nu elibera memoria de două ori
        num.value = nullptr;
        num.baza = 0;
    }
    return *this;
}


bool Number::operator<(Number nr)
{
    this->SwitchBase(10);
    nr.SwitchBase(10);

    int value1 = atoi(this->value);
    int value2 = atoi(nr.value);

    return value1 < value2;
}

bool Number::operator>(Number nr)
{   
    this->SwitchBase(10);
    nr.SwitchBase(10);
    int value1 = atoi(this->value);
    int value2 = atoi(nr.value);

    return value1 > value2;
}

bool Number::operator<=(Number nr)
{
    this->SwitchBase(10);
    nr.SwitchBase(10);
    int value1 = atoi(this->value);
    int value2 = atoi(nr.value);

    return value1 <= value2;
}

bool Number::operator>=(Number nr)
{
    this->SwitchBase(10);
    nr.SwitchBase(10);
    int value1 = atoi(this->value);
    int value2 = atoi(nr.value);

    return value1 >= value2;
}

bool Number::operator==(Number nr)
{
    this->SwitchBase(10);
    nr.SwitchBase(10);
    int value1 = atoi(this->value);
    int value2 = atoi(nr.value);

    return value1 == value2;
}

bool Number::operator<(int numar)
{
    this->SwitchBase(10);
    int val = atoi(this->value);

    return val < numar;
}

bool Number::operator>(int numar)
{
    this->SwitchBase(10);
    int val = atoi(this->value);

    return val > numar;
}

bool Number::operator<=(int numar)
{
    this->SwitchBase(10);
    int val = atoi(this->value);

    return val <= numar;
}

bool Number::operator>=(int numar)
{
    this->SwitchBase(10);
    int val = atoi(this->value);

    return val >= numar;
}

bool Number::operator==(int numar)
{
    this->SwitchBase(10);
    int val = atoi(this->value);

    return val == numar;
}

int operator+(Number nr, int numar)
{
    nr.SwitchBase(10);
    int val = atoi(nr.value);

    return val + numar;
}

Number operator+(const Number& num1, const Number& num2)
{
    int val1, val2, rez,lungime=0;
    Number aux1(num1.value, num1.baza);
    Number aux2(num2.value, num2.baza);
    aux1.SwitchBase(10);
    aux2.SwitchBase(10);
    val1 = atoi(aux1.value);
    val2 = atoi(aux2.value);
    rez = val1 + val2;
    char rezultat[100];
    for (int i = 0;rez;i++)
    {
        rezultat[i] = (rez % 10 + '0');
        rez /= 10;
        lungime++;
    }
    rezultat[lungime] = '\0';
    int left = 0;
    int right = lungime-1;

    while (left < right) 
    {
        swap(rezultat[left], rezultat[right]);
        left++;
        right--;
    }
    Number aux3(rezultat, 10);
    if (num1.baza > num2.baza)
    {
        aux3.SwitchBase(num1.baza);
        return Number(aux3.value, num1.baza);
    }
    else
    {
        aux3.SwitchBase(num2.baza);
        return Number(aux3.value, num2.baza);
    }
}

int operator-(Number nr, int numar)
{
    nr.SwitchBase(10);
    int val = atoi(nr.value);

    return val - numar;
}


bool operator==(int numar, Number nr)
{
    nr.SwitchBase(10);
    int val = atoi(nr.value);

    return val == numar;
}



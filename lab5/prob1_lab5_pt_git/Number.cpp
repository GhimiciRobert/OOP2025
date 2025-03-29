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
        std::cerr << "Baza invalida!" << std::endl;
        return;
    }

    // Verificăm dacă numărul este negativ
    bool isNegative = (value[0] == '-');

    // Convertim valoarea din baza actuală în baza 10
    int decimalValue = 0;
    int len = strlen(value);

    for (int i = isNegative ? 1 : 0; i < len; i++) // Ignorăm semnul dacă e negativ
    {
        char digit = value[i];
        int digitValue;
        if (digit >= '0' && digit <= '9')
            digitValue = digit - '0';
        else
            digitValue = toupper(digit) - 'A' + 10;

        decimalValue = decimalValue * baza + digitValue;
    }

    // Aplicăm semnul
    if (isNegative)
        decimalValue = -decimalValue;

    // Convertim valoarea din baza 10 în noua bază
    char buffer[65]; // Suficient pentru reprezentarea unui număr mare
    int index = 0;

    // Tratează cazul special pentru 0
    if (decimalValue == 0)
    {
        buffer[index++] = '0';
    }
    else
    {
        int absValue = abs(decimalValue); // Lucrăm cu valoarea absolută
        while (absValue > 0)
        {
            int remainder = absValue % newBase;
            if (remainder < 10)
                buffer[index++] = '0' + remainder;
            else
                buffer[index++] = 'A' + remainder - 10;
            absValue /= newBase;
        }

        // Dacă numărul original a fost negativ, adăugăm semnul '-'
        if (decimalValue < 0)
            buffer[index++] = '-';
    }

    buffer[index] = '\0';

    // Inversăm manual șirul obținut
    for (int i = 0, j = index - 1; i < j; i++, j--)
        std::swap(buffer[i], buffer[j]);

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

Number operator-(const Number& num1, const Number& num2)
{
    Number aux1(num1.value, num1.baza);
    Number aux2(num2.value, num2.baza);

    // Convertim ambele numere în baza 10
    aux1.SwitchBase(10);
    aux2.SwitchBase(10);

    // Convertim valorile în `int`
    int val1 = strtol(aux1.value, nullptr, 10);
    int val2 = strtol(aux2.value, nullptr, 10);

    int rez = val1 - val2;

    // Convertim rezultatul în string
    char rezultat[100];
    snprintf(rezultat, sizeof(rezultat), "%d", rez);

    // Construim obiectul rezultat
    Number aux3(rezultat, 10);

    // Convertim rezultatul în baza cea mai mare dintre cele două
    aux3.SwitchBase(std::max(num1.baza, num2.baza));

    return Number(aux3.value, std::max(num1.baza, num2.baza));
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



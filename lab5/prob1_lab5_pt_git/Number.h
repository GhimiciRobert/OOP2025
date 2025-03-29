#pragma once
class Number
{
    char* value;
    int baza;
public:
    Number(const char* value, int base); // where base is between 2 and 16
    ~Number();
    Number(const Number& num);
    Number(Number&& num);


    void SwitchBase(int newBase);
    void Print();
    int  GetDigitsCount(); // returns the number of digits for the current number
    int  GetBase(); // returns the current base
    friend int operator+(Number num, int numar); //addition
    friend Number operator+(const Number& num1, const Number& num2);
    friend Number operator-(const Number& num1, const Number& num2);
    friend int operator-(Number num, int numar); //substract

    void operator--();
    void operator--(int numar);


    bool operator!();
    int operator[](int index); //index operator

    Number& operator=(Number&& num); //move asignment operator


    bool operator<(Number num);
    bool operator>(Number num);
    bool operator<=(Number num);
    bool operator>=(Number num);
    bool operator==(Number num);
    bool operator<(int numar);
    bool operator>(int numar);
    bool operator<=(int numar);
    bool operator>=(int numar);
    bool operator==(int numar);
    friend bool operator==(int numar, Number nr);
};
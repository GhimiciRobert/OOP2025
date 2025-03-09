#include "student.h"
#include<cstring>


void student::Init()
{
    count_m = 0;
    count_e = 0;
    count_i = 0;
}

void student::Add_note_m(float x)
{


    note_m[count_m] = x;
    count_m++;

}

void student::Add_note_e(float x)
{
    note_e[count_e] = x;
    count_e++;
}

void student::Add_note_i(float x)
{
    note_i[count_i] = x;
    count_i++;
}

void student::setNume(char* nume)
{
    strcpy_s(this->nume, 20, nume);
}

char* student::getNume()
{
    return this->nume;
}
float student::medie_finala_m()
{
    float medie_m = 0;
    for (int i = 0; i < count_m; i++)
        medie_m = medie_m + note_m[i];
    medie_m = medie_m / count_m;
    return medie_m;
}

float student::medie_finala_e()
{
    float medie_e = 0;
    for (int i = 0; i < count_e; i++)
        medie_e = medie_e + note_e[i];
    medie_e = medie_e / count_e;
    return medie_e;
}

float student::medie_finala_i()
{
    float medie_i = 0;
    for (int i = 0; i < count_i; i++)
        medie_i = medie_i + note_i[i];
    medie_i = medie_i / count_i;
    return medie_i;
}

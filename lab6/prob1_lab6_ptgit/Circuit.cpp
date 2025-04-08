#include "Car.h";
#include<stdio.h>
#include "Circuit.h";
#include "weather.h";
#include<cstring>
#include "Audi.h";
#include "Porsche.h";
#include "Mercedes.h";
#include "BMW.h";
#include<iostream>
using namespace std;

void Circuit::SetLength(double lungime)
{
    this->length = lungime;
}

void Circuit::SetWeather(weather vreme)
{
    this->vreme = vreme;
}

void Circuit::AddCar(Car* car)
{
    if (index < max_cars) {
        masini[index++] = car;
    }
}


void Circuit::Race()
{
    for (int i = 0;i < index;i++)
    {
        double fuel_necesar = masini[i]->Get_fuel_cons(vreme) * this->length / 100;
        if (fuel_necesar <= masini[i]->Get_fuel_cap()) 
        {
            double timp = this->length / masini[i]->Get_av_speed(vreme);
            this->ranks[i] = timp;
        }
        else 
        {
            this->ranks[i] = -1;
        }
    }
}

void Circuit::FinalRanks()
{
    for (int i = 0; i < index; ++i) {
        for (int j = i + 1; j < index; ++j) {
            if (ranks[i] == -1) continue;
            if (ranks[i] > ranks[j]) {
                swap(ranks[i], ranks[j]);
                swap(masini[i], masini[j]);
            }
        }
    }
    for (int i = 0;i < index;i++)
    {
        if (ranks[i] != -1)
        {
            printf("%s a terminat cursa in %f ore.\n", masini[i]->Get_car_name(), ranks[i]);
        }
    }
    for (int i = 0;i < index;i++)
    {
        if (ranks[i] == -1)
        {
            printf("%s nu a terminat cursa.\n", masini[i]->Get_car_name());
        }
    }
}






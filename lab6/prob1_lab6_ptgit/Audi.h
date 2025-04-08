#pragma once
#include "Car.h";
#include<stdio.h>
#include "weather.h";
#include<cstring>
#include "Audi.h";
#include<iostream>
class Audi :
    public Car
{
public:
    Audi()
    {
        fuel_capacity = 80.0;
        fuel_consumption[0] = 10.5;
        fuel_consumption[1] = 8;
        fuel_consumption[2] = 11;
        average_speed[0] = 120;
        average_speed[1] = 160;
        average_speed[2] = 100;
    }
    double Get_fuel_cap() const override {
        return fuel_capacity;
    }

    double Get_fuel_cons(weather vreme) const override {
        switch (vreme)
        {
        case Rain:
            return fuel_consumption[0];
        case Sunny:
            return fuel_consumption[1];
        case Snowy:
            return fuel_consumption[2];
        }
    }

    double Get_av_speed(weather vreme) const override {
        switch (vreme)
        {
        case Rain:
            return average_speed[0];
        case Sunny:
            return average_speed[1];
        case Snowy:
            return average_speed[2];
        }
    }

    const char* Get_car_name() const override {
        return "Audi";
    }

};


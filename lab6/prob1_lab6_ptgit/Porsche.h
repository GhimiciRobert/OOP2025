#pragma once
#include "Car.h";
#include<stdio.h>
#include<cstring>
#include "weather.h";
#include<iostream>
class Porsche :
    public Car
{
public:
    Porsche()
    {
        fuel_capacity = 83;
        fuel_consumption[0] = 13;
        fuel_consumption[1] = 10.2;
        fuel_consumption[2] = 15;
        average_speed[0] = 132;
        average_speed[1] = 180;
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
        return "Porsche";
    }

};


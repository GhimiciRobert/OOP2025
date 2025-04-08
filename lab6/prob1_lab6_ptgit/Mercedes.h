#pragma once
#include "Car.h";
#include<stdio.h>
#include<cstring>
#include "weather.h";
#include<iostream>
class Mercedes :
    public Car
{
public:
    Mercedes()
    {
        fuel_capacity = 75.0;
        fuel_consumption[0] = 12.3;
        fuel_consumption[1] = 9.1;
        fuel_consumption[2] = 14.7;
        average_speed[0] = 125;
        average_speed[1] = 168;
        average_speed[2] = 110;
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
        return "Mercedes";
    }

};


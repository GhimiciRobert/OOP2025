#pragma once
#include "Car.h";
#include<stdio.h>
#include "weather.h";
#include<cstring>
#include "BMW.h";
#include<iostream>
class BMW : public Car
{
public:
	BMW()
	{
        fuel_capacity = 73.0;
        fuel_consumption[0] = 9.5;
        fuel_consumption[1] = 8.8;
        fuel_consumption[2] = 11.2;
        average_speed[0] = 121;
        average_speed[1] = 155;
        average_speed[2] = 103;
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
        return "BMW";
    }

};


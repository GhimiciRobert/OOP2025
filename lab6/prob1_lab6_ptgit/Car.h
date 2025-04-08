#pragma once
#include "Car.h";
#include<stdio.h>
#include "weather.h";
#include<cstring>
#include<iostream>
class Car
{
protected:
	double fuel_capacity;
	double fuel_consumption[3];
	double average_speed[3];
public:
	
	virtual double Get_fuel_cap() const = 0;
	virtual double Get_fuel_cons(weather vreme) const = 0;
	virtual double Get_av_speed(weather vreme) const = 0;
	virtual const char* Get_car_name() const = 0;
	virtual ~Car() {}
};


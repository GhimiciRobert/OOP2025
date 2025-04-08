#pragma once
#include "Car.h"
#include<stdio.h>
#include "Circuit.h";
#include "weather.h";
#include<cstring>
#include "Audi.h";
#include "Porsche.h";
#include "Mercedes.h";
#include "BMW.h";
#include<iostream>



class Circuit
{
private:
	double length;
	weather vreme;
	Car** masini;
	int index;
	int max_cars;
	double* ranks;
public:
	Circuit(int maxc = 10) {
		this->max_cars = 10;
		this->index = 0;
		this->masini = new Car* [max_cars];
		this->ranks = new double[max_cars];
	}
	~Circuit()
	{
		for (int i = 0; i < index; ++i) {
			delete masini[i];
		}
		delete[] masini;
		delete[] ranks;
		
	}
	void SetLength(double lungime);
	void SetWeather(weather vreme);
	void AddCar(Car* car);
	void Race();
	void FinalRanks();

	
};


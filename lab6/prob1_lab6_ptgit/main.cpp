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
int main()
{
	
	
	Circuit c(10);
	c.SetLength(500);
	c.SetWeather(weather::Rain);
	c.AddCar(new Audi());
	c.AddCar(new BMW());
	c.AddCar(new Mercedes());
	c.AddCar(new Porsche());
	
	c.Race();
	c.FinalRanks();
	return 0;
}
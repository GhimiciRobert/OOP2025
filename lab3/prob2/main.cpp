#include"Canvas.h"
#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;

int main()
{
	
	Canvas a(20, 20);
	a.DrawCircle(5, 10, 4, '*');
	//a.DrawLine(5, 5, 45, 15, '#');
	a.DrawRect(3, 3, 10, 10, '+'); 
	a.Print();
	return 0;
}
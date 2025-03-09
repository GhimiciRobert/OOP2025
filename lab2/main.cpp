#include<iostream>
#include<stdio.h>
#include"numberl_list.h"
using namespace std;
int main()
{
	numberl_list a;
	a.Init();
	a.Add(3);
	a.Add(2);
	a.Add(1);
	a.Sort();
	a.Print();
	return 0;
}
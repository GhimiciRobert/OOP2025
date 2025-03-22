#include "Sort.h"
#include<time.h>
#include <stdio.h> 
#include <stdlib.h>
#include <stdarg.h>
#include<cstring>
#include<iostream>
using namespace std;
int main()
{
	Sort c1(10, 10, 100);
	int v[5] = { 5, 4, 3, 2, 1 };
	Sort c2(5, v);
	Sort c3(6, 1, 2, 3, 4, 5, 6);
	char c[] = "122,34,16,78";
	Sort c4(4, c);
	//c1.BubbleSort();
	c4.QuickSort(true);
	//c1.Print();
	c4.Print();
	//c3.Print();


}
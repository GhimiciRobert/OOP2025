#include"mathClass.h"
#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	printf("suma de mai multe numere: %d\n", Math::Add(4, 8, 4, 2, 1));
	printf("concatenez 2 siruri:%s\n", Math::Add("HALA", " MADRID"));
	return 0;
}
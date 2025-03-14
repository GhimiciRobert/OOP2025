#include "mathClass.h"
#include<stdarg.h>
#include<cstring>

int Math::Add(int a, int b)
{
	return a + b;
}

int Math::Add(int a, int b, int c)
{
	return a + b + c;
}

double Math::Add(double a, double b)
{
	return a + b;

}

double Math::Add(double a, double b, double c)
{
	return a + b + c;
}

int Math::Mul(int a, int b)
{
	return a * b;
}

int Math::Mul(int a, int b, int c)
{
	return a * b * c;
}

double Math::Mul(double a, double b)
{
	return a * b;
}

double Math::Mul(double a, double b, double c)
{
	return a * b * c;
}

int Math::Add(int count, ...)
{
	int i, sum=0;
	va_list x;
	va_start(x, count);
	for (i = 1;i <= count;i++)
		sum += va_arg(x, int);
	va_end(x);
	return sum;
}

char* Math::Add(const char* s1, const char* s2)
{
	if (!s1 || !s2)
		return nullptr;
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	char* sir_rez = new char[l1 + l2 + 1];
	strcpy_s(sir_rez, 100, s1);
	strcat_s(sir_rez, 100, s2);
	return sir_rez;
}

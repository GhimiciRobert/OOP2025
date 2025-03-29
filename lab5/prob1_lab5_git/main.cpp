#include "Number.h"
#include<iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
	Number n1("5a", 16);
	Number n2("88", 9);
	Number n3 = n1+n2;
	n3--;
	n3.Print();
	//n2.SwitchBase(16);
	//Number n3 = n1 + n2;
	//n2.Print();
	int x = n2 - 10;
	//printf("%d", x);
	if (x == (n2-10))
		printf("1\n");
	if ( n1 >= x)
		printf("1\n");
	else printf("0\n");


}
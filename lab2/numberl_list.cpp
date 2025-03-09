#include<stdio.h>
#include "numberl_list.h"

void numberl_list::Init()
{
	count = 0;
}

bool numberl_list::Add(int x)
{
    if (count >= 10)
        return false;
    numbers[count] = x;
    count++;
    return true;
}

void numberl_list::Sort()
{
    bool ok;
    int aux;
    do
    {
        ok = true;
        for (int i = 0; i < count - 1; i++)
        {
            if (numbers[i] > numbers[i + 1])
            {
                aux = numbers[i];
                numbers[i] = numbers[i + 1];
                numbers[i + 1] = aux;
                ok = false;
            }
        }
    } while (!ok);
}

void numberl_list::Print()
{
    for (int i = 0; i < count; i++)
        printf("%d ", numbers[i]);
}

#include "Sort.h"
#include<time.h>
#include <stdio.h> 
#include <stdlib.h>
#include <stdarg.h>
#include<cstring>
#include<iostream>
using namespace std;

Sort::Sort(int count, int mini, int maxi)
{
	this->count = count;
	this->vector = new int[count];
	time_t t;
	srand((unsigned)time(&t));
	for (int i = 0; i < count; i++) 
	{
		this->vector[i] = mini + rand() % (maxi - mini + 1);
	}
}

Sort::Sort(int count, int* x)
{
	this->count = count;
	this->vector = new int[count];
	for (int i = 0;i < count;i++)
	{
		this->vector[i] = x[i];
	}
}

Sort::Sort() :vector(new int[5] {1, 2, 3, 4, 5}) 
{ 
	this->count = 5; 
}

Sort::Sort(int count, ...)
{
	this->vector = new int[count];
	this->count = count;
	va_list x;
	va_start(x, count);
	for (int i = 0; i < count; i++)
	{
		this->vector[i] = va_arg(x, int);
	}
	va_end(x);
}

Sort::Sort(int count, char* c)
{
	this->count = count;
	int nr = 0;
	int p = 1;
	this->vector = new int[count];
	for (int i = strlen(c) - 1;i >= 0;i--)
	{
		if (c[i] == ',') {
			this->vector[--count]=nr;
			nr = 0;
			p = 1;
			continue;
		}
		nr = nr + (c[i] - '0') * p;
		p *= 10;
	}
	this->vector[count-1] = nr;
}


void Sort::InsertSort(bool ascendent)
{
	int n = this->count;
	for (int i = 1; i < n; ++i) {
		int key = this->vector[i];
		int j = i - 1;

		/* Move elements of arr[0..i-1], that are
		   greater than key, to one position ahead
		   of their current position */
		while (j >= 0 && this->vector[j] > key) {
			this->vector[j + 1] = this->vector[j];
			j = j - 1;
		}
		this->vector[j + 1] = key;
	}
}

int Sort::Partition(int low, int high, bool ascendent)
{
	int pivot = this->vector[high]; // Alegem ultimul element ca pivot
	int i = low - 1;          // Indexul elementului mai mic

	for (int j = low; j < high; j++) {
		if ((ascendent && this->vector[j] < pivot) || (!ascendent && this->vector[j] > pivot)) {
			i++;
			std::swap(this->vector[i], this->vector[j]); // Mutăm elementele mai mici/mai mari pe partea corectă
		}
	}
	std::swap(this->vector[i + 1], this->vector[high]); // Punem pivotul la locul său corect
	return i + 1; // Returnăm poziția pivotului
}

void Sort::QuickSortHelper(int low, int high, bool ascendent)
{

	if (low < high) {
		int pivotIndex = Partition(low, high, ascendent);
		QuickSortHelper(low, pivotIndex - 1, ascendent);
		QuickSortHelper(pivotIndex + 1, high, ascendent);
	}
}

void Sort::QuickSort(bool ascendent)
{
	if (this->count > 1) {
		QuickSortHelper(0, this->count - 1, ascendent);
	}
}

void Sort::BubbleSort(bool ascendent)
{
	int n = this->count;
	bool swapped;

	for (int i = 0; i < n - 1; i++) {
		swapped = false;
		for (int j = 0; j < n - i - 1; j++) {
			if (this->vector[j] > this->vector[j + 1]) {
				swap(this->vector[j], this->vector[j + 1]);
				swapped = true;
			}
		}

		// If no two elements were swapped, then break
		if (!swapped)
			break;
	}
}

void Sort::Print()
{
	this->count = count;
	for (int i = 0;i < count;i++)
		printf("elementul %d este: %d\n", i, this->vector[i]);
}

int Sort::GetElementsCount()
{
	return this->count;
}

int Sort::GetElementFromIndex(int index)
{
	return this->vector[index];
}

#pragma once
class Sort
{
    int* vector;
    int count;
public:
    Sort(int count, int mini, int maxi);
    Sort(int count, int* x);
    Sort();
    Sort(int count, ...);
    Sort(int count, char* c);
    void InsertSort(bool ascendent = false);
    int Partition(int low, int high, bool ascendent);
    void QuickSortHelper(int low, int high, bool ascendent);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};


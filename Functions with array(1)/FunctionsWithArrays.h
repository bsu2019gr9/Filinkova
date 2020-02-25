#pragma once
void* makeArrOfInt(int*&, int);
//int* makeArrOfInt(int N);
void freeMemory(int*&);
void initRandomArray(int*, int*, const int, const int);
void initArray(int*, int*, const int);
void initArray2(int*, int*, int, int);
void printArray(int*,int*);
void inputArray(int*,int*);
void swap(int&, int&);
void reverse(int*, int*);
int* findMin(int*, int*);
int* findMax(int*, int*);
//void findMaxMin(int*, int*, int&, int&);
int findSum(int*,int*);
void howManyPositiveNegativeArray(int*, int*);
void bubbleSort(int*, int*);
void quickSort(int*, int*);


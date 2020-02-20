#pragma once
void initArray(int* arr, const int N, int A = -10, int B = 10);
void printArray(int* arr, const int N);
void inputArray(int* arr, const int N);
int findMin(int* arr, const int N);
int findMax(int* arr, const int N);
void findMaxMin(int* arr, int N, int& min, int& max);
int findSum(int* arr, const int N);
void reverse(int* arr, const int N);
void trim(int* arr, const int N, int a, int b);
void howManyPositiveNegativeArray(int* arr, const int N);
void findChainOfElements(int* arr, const int N);
int* giveMemory(int);
void freeMemory(int*);
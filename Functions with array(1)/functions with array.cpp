//основные функции для работы с одномерными массивами
#include<iostream>
#include<iomanip>
#include<ctime>
#include "FunctionsWithArrays.h"
using namespace std;

void* makeArrOfInt(int*& arr, int N) {
	arr = new (nothrow) int[N];
	if (!arr) exit(404);}

int* makeArrOfInt(int N) {
	int* arr = nullptr;
	arr = new int[N];
	return arr;}

void freeMemory(int*& arr) {
	delete[] arr;  arr = nullptr; }

void initRandomArray(int* beg, int* end, const int M, const int m){
	srand(time(0));
	int d = M - m + 1;
	for (int* p = beg; p < end; ++p)
		* p = rand() % d + m;}

void initArray(int* beg, int* end, const int m = 0) {
	for (int* p = beg; p < end; ++p)
	* p = m;}

void initArray2(int* beg, int* end, int A = -10, int B = 10)//инициализация значениий элементов массива случайными числами от А до В (от -10 до 10).
{
	srand(time(NULL));
	double k1 = (B - A) * 1.0 / (RAND_MAX);
	for (int* p = beg; p < end; ++p)
		* p = k1 * rand() + A;
}

void printArray(int* beg, int* end){
 for (int* p = beg; p < end; ++p)
	cout << setw(3) << *p << ";";
 cout << '\n';}

void inputArray(int* beg, int* end) //Ввод значений элементов массива размера N с клавиатуры
{for (int* p = beg; p < end; ++p) cin >> *p; cout << '\n';}

void swap(int& a, int& b){
	int buf;
	buf = a;a = b;b = buf;}

void reverse(int* beg, int* end) {
	for (int* p = beg, *q = end - 1; p < q; ++p, --q)
	{swap(*p, *q);}
}

int* findMin(int* beg, int* end){
	int*  min = beg;
	for (int* p = beg; p < end; ++p){
		if (*p < *min) min = p;}
	return min;
}

int* findMax(int* beg,int* end){
	int* max = beg;
	for (int* p = beg; p < end; ++p)
	{if (*p > *max) max = p;}
	return max;
}

void findMaxMin(int* beg, int* end, int& min, int& max)//нахождение 2 параметров максимума и минимума в массиве 
{  for (int* p = beg; p < end; ++p){
	if (*p < min)min = *p;
    if (*p > max)max = *p;}
}

int findSum(int* beg, int* end) //возвращает сумму элементов в массиве
{    int sum = 0;
	for (int* p = beg; p < end; ++p) sum += *p;
	return sum;
}

void howManyPositiveNegativeArray(int* beg, int* end)//кол-во отриц./положит. чисел
{
	int counterPositive(0), counterNegative(0);
	for (int* p=beg;  p < end; ++p) {
		(*p < 0) ? counterNegative++ : counterPositive++;
	}
}

void bubbleSort(int* beg, int* end)
{
	for (int j = 0; j < end - beg - 1; ++j)
		for (int* p = beg; p < end - 1; ++p)
		{
			if (*p > * (p + 1)) swap(*p, *(p + 1));
		}
}
	
void quickSort(int* beg, int* end) {
	if ((end - beg) <= 1)return;
	int* i = beg;
	int* j = end - 1;
	int half = *(beg + (end - beg) / 2);
	while (i <= j) {
		while (*i < half) ++i;
		while (*j > half) --j;
		 if (i <= j)
		 {
			swap(*i, *j);
			++i; --j;
		}
	}
	if (beg < j) quickSort(beg, j + 1);
	if (end > i) quickSort(i, end);
}

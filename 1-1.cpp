#include <iostream>
#include <iomanip>
#include<ctime>
#include "FunctionsWithArrays.h"
using namespace std;
void quickSort(int*, int*);
void printArray(int*, int*);
int Task1(int*, int*);
//В массиве размера N, заполненного случ.числами от - 10 до 10,
//подсчитать количество элементов, встречающихся более одного раза

int Task2(int*, int*);
//В массиве размера N, заполненного случ.числами от - 10 до 20,
//определить максимальную длину последовательности равных элементов

int Task1(int* beg, int* end) {
	quickSort(beg, end);
	printArray(beg, end);
	int k = 0;
	for (int* p = beg; p < end; ++p)
	{
		if (*p == *(p+1)) ++k;
		if (*p == *(p + 1) && *(p + 1) == *(p + 2)) --k;
	}
	return k;
}

int Task2(int* beg, int* end)
{
	int maxLength = 0, k = 1;
	for (int* p = beg; p < end; ++p)
	{
		if (*p == *(p+1)) ++k;
		else {
			if (maxLength < k) {maxLength = k; }
			k = 1;
		}
	}
	if (maxLength < k) { maxLength = k;}
	return maxLength;
}

int* makeArrOfInt(int N) {
	int* arr = nullptr;
	arr = new int[N];
	return arr;
}
void swap(int& a, int& b) {
	int buf;
	buf = a; a = b; b = buf;
}

void initRandomArray(int* beg, int* end,  int A,  int B) {
	srand(time(0));
	if (A > B)swap(A, B);
	double k1 = (B - A) * 1.0 / (RAND_MAX);
	for (int* p = beg; p < end; ++p)
		* p = k1 * rand() + A;

}
void printArray(int* beg, int* end) {
	for (int* p = beg; p < end; ++p)
		cout << setw(3) << *p << ";";
	cout << '\n';
}

void freeMemory(int*& arr) {
	delete[] arr;  arr = nullptr;
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


int main()
{
	int N;
	cout << "Enter size of array: \n";
	cin >> N;
	int* arr = makeArrOfInt(N);
	initRandomArray(arr, arr + N,10,-10);
	cout << "Task 1\n";
	printArray(arr, arr + N);
	cout << " \nThe answer of the Task 1 is "<<Task1(arr, arr + N) << "\n";
	initRandomArray(arr, arr + N, 20, -10);
	cout << "\nTask 2\n";
	printArray(arr, arr + N);
	cout << "The answer of the Task 2 is " << Task2(arr, arr + N);
	freeMemory(arr);
}


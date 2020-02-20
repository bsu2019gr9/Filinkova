//основные функции для работы с одномерными массивами
#include<iostream>
#include<iomanip>
#include<ctime>
#include "FunctionsWithArrays.h"
using namespace std;
void initArray(int* arr, int N, int A = -10, int B = 10)//инициализация значениий элементов массива случайными числами от А до В (от -10 до 10).
{
	srand(time(NULL));
	double k1 = (B - A) * 1.0 / (RAND_MAX);
	for (int i = 0; i < N; ++i)
		arr[i] = k1 * rand() + A;
}
void printArray(int* arr, const int N) //печать массива
{for (int i = 0; i < N; ++i)cout << arr[i]<< '\n';}

void inputArray(int* arr, const int N) //Ввод значений элементов массива размера N с клавиатуры
{for (int i = 0; i < N; ++i)cin >> arr[i];}

int findMin(int* arr, const int N)//возвращает минимум в массиве 
{
	int min = arr[0];
	for (int i = 0; i < N; ++i) if (arr[i] < min)min = arr[i];
	return min;
}

int findMax(int* arr,const int N) //возвращает максимум в массиве
{
	int max = arr[0];
	for (int i = 0; i < N; ++i)if (arr[i] > max)max = arr[i];
	return max;
}

void findMaxMin(int* arr, int N, int& min, int& max) //нахождение 2 параметров максимума и минимума в массиве
{for (int i = 0; i < N; ++i)
{ if (arr[i] < min)min = arr[i];
  if (arr[i] > max) max = arr[i];}
}

int findSum(int* arr,const int N) //возвращает сумму элементов в массиве
{ int sum = 0;
	for (int i = 0; i < N; i++) sum += arr[i];
	return sum;
}

void reverse(int* arr, const int N)// reverse "на месте"(Преобразуем текущий массив: записываем значения в "обратном порядке" (начиная от последнего элемента и заканчивая первым))
{ int buf;
	for (int i = 0; i < N / 2; ++i) {
		buf = arr[i];
		arr[i] = arr[N - i - 1];
		arr[N - i - 1] = buf;
	}
}

void trim(int* arr, const int N, int a, int b)
//сжатие массива,удаляя из него все элементы,модуль которых находится в интервале[a,b]
// Освободившиеся в конце массива элементы заполняем нулями.
{
	int j = 0;
	for (int i = 0; i < N; ++i)
		if (abs(arr[i]) < a || abs(arr[i]) > b)
		{
			arr[j] = arr[i]; j++;
		}
	for (int i = j; i < N; ++i) arr[i] = 0;
}

void howManyPositiveNegativeArray(int* arr, const int N)//кол-во отриц./положит. чисел
{
	int counterPositive(0), counterNegative(0);
	for (int i = 0; i < N; ++i) {
		(arr[i] < 0) ? counterNegative++ : counterPositive++;
	}
	cout << "The value of negative numbers is " << counterNegative << '\n';
	cout << "The value of positive numbers is " << counterPositive << '\n';
}

void findChainOfElements(int* arr, const int N)
//нахождение цепочки элементов
{
	int tmp(arr[0]); int len1(0), len2;
	for (int i = 0; i < N; ++i) {
		arr[0] = arr[i + 1];
		++len1;
		if (arr[0] == tmp) break;
	}
	len2 = N - len1;
	if (len1 > len2)cout << "the max len is " << len1 << '\n';
	else if (len1 == len2)cout << "len1 = len2 = " << len1 << '\n';
	else cout << "the max len is " << len2 << '\n';
}

int* giveMemory(int N = 10) {
	int* arr = new(nothrow) int[N];
	if (!arr) { cout << "No memory\n"; exit(1); }
	return arr;
}
void freeMemory(int* arr) 
{ if (!arr) 
		delete[] arr; 
	else cout << "Array is empty\n";}
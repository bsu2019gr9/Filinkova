//В массиве А(N,M) переставить строки в порядке возрастания элементов последнего столбца
#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

int** makeArrOfInt(int N, int M) {
	int** arr = new (nothrow) int* [N];
	if (!arr) exit(404);
	for (size_t i = 0; i < N; i++) {
		arr[i] = new (nothrow) int[M];
		if (!arr[i]) exit(404);
	}
	return arr;
}

void randInitArray(int** arr, int N, int M) {
	srand(time(NULL));
	for (size_t i = 0; i < N; i++)
		for (size_t j = 0; j < M; j++) {
			arr[i][j] = rand() % 20 - 10;
		}
}

void printArray(int** arr, int N, int M) {
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < M; j++)
			cout << setw(3) << arr[i][j]; cout << "\n";
		}
}

void freeMemory(int**& arr, int N, int M) {
	for (size_t i = 0; i < M; i++) {
		delete[] arr[i];
		arr[i] = nullptr;}
	delete[] arr;
	arr = nullptr;
}

void swap(int& a, int& b) {
	int buf;
	buf = a; a = b; b = buf;
}

void swapRows(int** arr,int j) {
	int* tmp;
	tmp = arr[j];
	arr[j] = arr[j + 1];
	arr[j + 1] = tmp;

}
//Переставляет строки в порядке возрастания последнего столбца
void permuteRows_And_IncreaseElementsOfCal(int** arr, int N, int M)
{
	int* p = new int[N];
	for (size_t j = 0; j < N; j++) {
		*(p + j) = arr[j][M - 1];
	}
	for (size_t i = 0; i < N; i++) {
		for (size_t j = 0; j < N - i - 1; j++) {
			if (*(p + j) > * (p + j + 1)) {
				swap(*(p + j), *(p + j + 1));
				swapRows(arr, j);
			}
		}
	}
	delete[]p;
}

int main() {
	int N,M;
	cout << "Enter the number of rows and cols" << '\n';
	cin >> N >> M;
	int** A = makeArrOfInt(N, M);
	randInitArray(A, N, M);
	printArray(A, N, M); cout << '\n';
	permuteRows_And_IncreaseElementsOfCal(A, N, M);
	printArray(A, N, M);
	freeMemory(A, N, M);
	system("pause");
	return 0;
}

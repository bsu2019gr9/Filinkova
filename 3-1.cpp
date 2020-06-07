// Преобразовать каждое слово в строке, удалив в нём заданную букву.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<string.h>
using namespace std;
const int N = 1000;
void deleteYourSymbol(char* str, char* symb) {
	int i = strcspn(str, symb);
	char* tmp = nullptr;
	tmp = new(nothrow) char[N];
	while (i < strlen(str)) {
		strcpy(tmp, str + (i + 1));
		strcpy(str + i, tmp);
		i = strcspn(str, symb);
	}
	delete[] tmp;
}

int main()
{
	
	char* str = nullptr;
	str = new(nothrow) char[N];
	char* symb = nullptr;
	symb = new(nothrow) char[2];
	cout << "Write a string: \n";
	cin.getline(str, N);
	cout << "Enter the symbol\n";
	cin >> symb;
	deleteYourSymbol(str, symb);
	cout << str;
	delete[] str;
	return 0;
}

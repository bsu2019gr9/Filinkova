//В тексте выбрать все слова, начинающиеся с гласных букв, и расположить их в порядке возрастания
// количества букв в слове.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <clocale>
#include <cstring>
using namespace std;
int word = 0;
static char vowelsEn[] =  "A a E e I i O o U u Y y ";
static char vowelsRus[] = "А а Е е И и О о У у Ы ы Э э Я я ";
const int N = 100500;

void readFileAndSeparateWords(char** str)
{
	char* tmp = new char[N];
	ifstream file1("d:\\input1.txt"); // отсюда читаем (поток типа ifstream= input file stream)
	ofstream file2("d:\\rezult.txt");//сюда пишем (поток типа ofstream= output file stream)
	if (!file1) { cout << "No file. Can't open\n"; exit(1); }
	if (!file2) { cout << " file Can't create\n"; exit(1); }
	while (1) {
		file1.getline(tmp, N - 1); 
		if (file1.eof()) break;
		if (file1.fail()) file1.clear();

	    char *sep = strtok(tmp, " ][,.-;\'\"?!-:”—");
		while (sep!=0) {
			for (int i = 0; i < 12; i++) {
				if (sep[0] == vowelsEn[i] || sep[0] == vowelsRus[i]) {
					str[word] = new (nothrow) char[25];
					strcpy(str[word], sep);
					word++;
				}
			}
			sep = strtok(NULL, " ,.-;\'\t0123456789”?!-:—*( '')  ");
		}
		delete[] sep;
	}
	
	delete[] tmp;
	file1.close();//закрыли файл
}

void swapStr(char* a, char* b) {
	char* buf = new(nothrow) char[25];
	strcpy(buf, b);
	strcpy(b, a);
	strcpy(a, buf);
	delete[] buf;
}

//сортировка пузырьком
void bubbleSort(char** arr) {
	ifstream file2("d:\\rezult.txt");
	if (!file2) {
		cout << "No file d:\\result.txt. Can't create\n";
		exit(1);
	}
	for (int i = 0; i < word; i++) {
		for (int j = 0; j < word - i - 1; j++) {
			if (strlen(arr[j]) > strlen(arr[j + 1])) {
				swapStr(arr[j], arr[j + 1]);
			}
		}
	}

}

void printArr(char** arr) {
	ofstream file2("d:\\rezult.txt");
	for (int i = 0; i < word; i++) {
		file2 << arr[i] << '\n';
		 //cout << arr[i] << '\n';
	}
	file2.close();
}

int main() {
	setlocale(LC_ALL, "Russian");
	
	char** str = new(nothrow) char* [N];
	if (!str) cout << "There are no memory\n";
	readFileAndSeparateWords(str);
	bubbleSort(str);
	printArr(str);
	system("pause");
  return 0;
}

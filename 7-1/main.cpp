/*В объекте хранится информация о багаже пассажиров : фамилия и имя пассажира,
количество мест багажа и вес каждого места багажа.
f)Создания/удаления/ редактирование багажа
g)Вывести список пассажиров в алфавитном порядке
h)Определить пассажира с наибольшим(наименьшим) количеством мест багажа(веса багажа)
i)Определить, имеется ли пассажир,багаж которого состоит из одной единицы весом более 20 кг
*/
#define _CRT_SECURE_NO_WARNINGS
#include "Passenger_luggage.h"
#include <iostream>
#include <fstream>
using namespace std;
int M = 100;

int main()
{
	Passenger_luggage* humen = nullptr;
	humen = new(nothrow)Passenger_luggage[M];
	int choice=0;
	char* filename = new (nothrow) char[50];
    humen[0].set_passenger("Filinkova", "Darya", 14, 4);
	humen[1].set_passenger("Sarnaskaya", "Darya", 10, 2);
	humen[2].set_passenger("Gradovich", "Liza", 26, 1);
	humen[3].set_passenger("Stasenko", "Tanya", 18, 3);
	humen[4].set_passenger("Pahomovich", "Ksenia", 30, 1);
	humen[5].set_passenger("Chapko", "Tanya", 17, 2);
	humen[6].set_passenger("Zhinko", "Nastya", 31, 5);
	humen[7].set_passenger("Vorobyov", "Kolya", 13, 4);
	humen[8].set_passenger("Dolmatova", "Vanda", 20, 3);
	humen[9].set_passenger("Aniskova", "Zlata", 22, 1);
	humen[10].set_passenger("Moroz", "Alena", 12, 5);
	humen[11].set_passenger("Dobronravov", "Fedor", 28, 2);
	humen[12].set_passenger("Svetlov", "Andrey", 19, 4);

	humen[9].set_passenger("Aniskova", "Zlata", 22, 1);
	while (1)
	{
		cout << "Please choose what you want to do:\n";
		cout << "1 - Create information about passenger and his luggage\n";
		cout << "2 - Edit information about passenger and his luggage\n";
		cout << "3 - Sort and print passengers by alphabet\n";
		cout << "4 - Find passenger with the biggest luggage\n";
		cout << "5 - Find passenger with luggage more then 20kg\n";
		cout << "6 - Print information about passenger and his luggage \n";
		cout << "7 - Read the information from file\n";
		cout << "8 - Write information to the file \n";
		cout << "0 - exit\n";
		cin >> choice;

		switch (choice)
		{
		case 0:
			return 0;
			break;
		case 1:
			create_iformation_about_passenger_and_luggage(humen, M);
			break;
		case 2:
			remove_iformation_about_passenger_and_luggage(humen, M);
			break;
		case 3:
			sort_and_print_passengers_by_alphabet(humen,M);
			break;
		case 4:
			find_passenger_with_the_biggest_luggage(humen, M);
			break;
		case 5:
			find_passenger_with_luggage_more_then_20kg(humen, M);
			break;
		case 6:
			print_iformation_about_passenger_and_luggage(humen, M);
			break;
		case 7:
			cout << "Please enter your filename,from which the information will be read\n";
			cin >> filename;
			readFromFile(humen, M, filename);
			break;
		case 8:
			cout << "Please enter your filename,where the information will be written\n";
			cin >> filename;
			writeToFile(humen, M, filename);
			break;

		default:
			cout << "Your number doesn't exist.Please try again\n";
			break;
		}
	}
	return 0;
}
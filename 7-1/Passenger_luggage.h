#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

class Passenger_luggage
{
private:
	char* surname;//фамилия пассажира
	char* name;//имя пассажира
	int number_of_luggage_places;//количество мест багажа
	int weight;//вес багажа

public:
	Passenger_luggage();//конструктор без параметров
	Passenger_luggage( char* surname,  char* name, int number_of_luggage_places, int weight); //конструктор с параметрами
	~Passenger_luggage();//деструктор
	Passenger_luggage(const Passenger_luggage& other);	//конструктор копирования

	void set_surname(const char*);//задаём фамилию пассажира
	void set_name(const char*);//задаём имя пассажира
	void set_number_of_luggage_places(int);//задаём количество мест багажа
	void set_weight(int);//задаём вес багажа
	void set_passenger(const char*, const char*, int, int);//задаём полностью информацию о пассажире и его багаже

	void remove_surname();//удаляем фамилию пассажира
	void remove_name();//удаляем имя пассажира
	void remove_number_of_luggage_places();//удаляем количество мест багажа
	void remove_weight();//удаляем вес багажа
	void remove_passenger(const char*, const char*, int, int);//удаляем полностью информацию о пассажире и его багаже

	void edit_surname(const char*);//редактируем фамилию пассажира
	void edit_name(const char*);//редактируем имя пассажира
	void edit_number_of_luggage_places(int);//редактируем количество мест багажа
	void edit_weight(int);//редактируем вес багажа
	void edit_passenger(const char*, const char*, int, int);//редактируем полностью информацию о пассажире и его багаже

	int get_weight();//получаем информацию о весе багажа
	int get_number_of_luggage_places();//получаем информацию о кол-ве мест багажа
	char* get_surname();//получаем информацию о фамилии пассажира
	char* get_name();//получаем информацию об  имени пассажира

	friend ostream& operator<<(ostream& output, const Passenger_luggage& p);
	friend istream& operator>>(istream& input, Passenger_luggage& p);
	
};

void sort_and_print_passengers_by_alphabet(Passenger_luggage*, int&);//сортировка и вывод списка пассажиров в алфавитном порядке

Passenger_luggage* find_passenger_with_the_biggest_luggage(Passenger_luggage*, const int);//находим пассажира с наибольшим весом багажа
bool find_passenger_with_luggage_more_then_20kg(Passenger_luggage*, const int);// проверяем, есть ли пассажир,багаж которого состоит из одной единицы весом более 20 кг

void print_iformation_about_passenger_and_luggage(Passenger_luggage*, int&);//печатать  информацию о пасажире и его багаже

int readFromFile(Passenger_luggage*, const int, char*);//чтение из файла
void writeToFile(Passenger_luggage* ,const int ,char* );//запись в файл

void freeMemory(Passenger_luggage*, int);//освобождаем память
Passenger_luggage* create_iformation_about_passenger_and_luggage(Passenger_luggage*, int&);//создать информацию о пасажире и его багаже
Passenger_luggage* remove_iformation_about_passenger_and_luggage(Passenger_luggage*, int&); // удалить информацию о пассажире и его багаже
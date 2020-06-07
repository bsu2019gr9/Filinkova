#include "Passenger_luggage.h"
#include <iostream>
#include<iomanip>
#define _CRT_SECURE_NO_WARNINGS

Passenger_luggage::Passenger_luggage() {
	surname =new (nothrow) char[50];
	name = new (nothrow) char[50];
	number_of_luggage_places = 0;
	weight = 0;
{
	if (!name || !surname) { cout << "404";  return; }
}
}

Passenger_luggage::Passenger_luggage(char* _surname,char* _name, int _number_of_luggage_places, int _weight) :
	surname(new (nothrow) char[strlen(_surname) + 1]),
	name(new (nothrow) char[strlen(_name) + 1]),
	number_of_luggage_places(_number_of_luggage_places),
	weight(_weight)
	{
		if (!surname) { cout << " 404";  return; }
		strcpy(surname, _surname);
	
	    if (!name) { cout << "404"; return; }
	    strcpy(name, _name);
	}

Passenger_luggage:: ~Passenger_luggage() {
	delete[]surname;
	surname = nullptr;
	delete[]name;
	name = nullptr;
	//cout << "work destructor\n";
}


Passenger_luggage::Passenger_luggage(const Passenger_luggage& other) :
	name(new (nothrow) char[strlen(other.name) + 1]),
	surname(new (nothrow) char[strlen(other.surname) + 1]),
	number_of_luggage_places(other.number_of_luggage_places),
	weight(other.weight)
	
{
	if (!name) { cout << "404"; return; }
	strcpy(name, other.name);
	if (!name) { cout << "404";  return; }
	strcpy(name, other.name);
}

void Passenger_luggage::set_surname(const char* _surname) {
	this->surname = new (nothrow) char[strlen(_surname) + 1];
	strcpy(this->surname, _surname);
}

void Passenger_luggage::set_name(const char* _name) {
	this->name = new (nothrow) char[strlen(_name) + 1];
	strcpy(this->name, _name);
}

void Passenger_luggage::set_number_of_luggage_places(int _number_of_luggage_places) {
	this->number_of_luggage_places = _number_of_luggage_places;
}

void Passenger_luggage::set_weight(int _weight) {
	this->weight = _weight;
}

void Passenger_luggage::set_passenger(const char* _surname, const char* _name, int _number_of_luggage_places, int _weight) {
	set_surname(_surname);
	set_name(_name);
	set_number_of_luggage_places(_number_of_luggage_places);
	set_weight(_weight);
}


void Passenger_luggage::remove_surname() {
	if (this->surname) {
		this->surname = nullptr;
		delete[] this->surname;
	}
}

void Passenger_luggage::remove_name() {
	if (this->name) {
		this->name = nullptr;
		delete[] this->name;
	}
}

void Passenger_luggage::remove_number_of_luggage_places() {
	this->number_of_luggage_places = 0;
}

void Passenger_luggage::remove_weight() {
	this->weight = 0;
}

void Passenger_luggage::remove_passenger(const char* _surname, const char* _name, int _number_of_luggage_places, int _weight) {
	remove_surname();
	remove_name();
	remove_number_of_luggage_places();
	remove_weight();
}


void Passenger_luggage::edit_surname(const char* _surname) {
	remove_surname();
	set_surname(_surname);
}

void Passenger_luggage::edit_name(const char* _name) {
	remove_name();
	set_name(_name);
}

void Passenger_luggage::edit_number_of_luggage_places(int _number_of_luggage_places) {
	set_number_of_luggage_places(_number_of_luggage_places);
}

void Passenger_luggage::edit_weight(int _weight) {
	set_weight(_weight);
}

void Passenger_luggage::edit_passenger(const char* _surname, const char* _name, int _number_of_luggage_places, int _weight) {
	remove_passenger(surname, name, number_of_luggage_places, weight);
	set_passenger(_surname, _name, _number_of_luggage_places, _weight);
}


int Passenger_luggage::get_weight() {
	if (this->weight)  
		cout << this->weight << "\n";
	else cout << "not found\n ";
	return weight;
}

int Passenger_luggage::get_number_of_luggage_places() {
	if (this->number_of_luggage_places)
		cout << this->number_of_luggage_places << "\n";
	else 
		cout << "not found\n ";
	return number_of_luggage_places;
}

 char* Passenger_luggage::get_surname() {
	if (this->surname)  
		cout << this->surname << "\n"; 
	else 
		cout << "not found \n";
	return surname;
}
 char* Passenger_luggage::get_name() {
	 if (this->name)
		 cout << this->surname << "\n";
	 else
		 cout << "not found \n";
	 return name;
 }


ostream& operator<<(ostream& output, const Passenger_luggage& p)
{
	output << p.name <<'-' <<p.surname << '-' <<p.number_of_luggage_places << '-'<<p.weight<< '\n';
	return output;
}
istream& operator>> (istream& input, Passenger_luggage& p)
{
	cout << "Write surname:\n";
	input >> p.surname;
	cout << "Write name:\n";
	input >> p.name;
	cout << "Write number_of_luggage_places:\n";
	input >> p.number_of_luggage_places;
	cout << "Write weight:\n";
	input >> p.weight;
	return input;
}

Passenger_luggage* find_passenger_with_the_biggest_luggage(Passenger_luggage* passenger, const int n)
{
	Passenger_luggage* max = passenger;
	for (int i = 1; i < n; i++)
	{
		max = (passenger[i].get_weight() > max->get_weight()) ? passenger + i : max;
	}
	return max;
}


bool find_passenger_with_luggage_more_then_20kg(Passenger_luggage* passenger,const int n)
{
	
	for (int i = 1; i < n; i++)
	{
		if (passenger[i].get_number_of_luggage_places() == 1 && passenger[i].get_weight() > 20) return true;
	}
	return false;
}

void sort_and_print_passengers_by_alphabet(Passenger_luggage* passenger, int &n)
{
	Passenger_luggage tmp;
	char* curr, * prev;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			curr = passenger[j].get_surname();
			prev = passenger[i].get_surname();
			if (prev && curr)
			{
				if (strcmp(prev, curr) > 0)  swap(passenger[i], passenger[j]);
			}
		}
	}
	print_iformation_about_passenger_and_luggage(passenger,n);
}

int readFromFile(Passenger_luggage* passenger, const int n, char* filename)
{
	ifstream from(filename, ios::binary);
	if (!from) {
		cout << "We can't find your file\n";
		return 0;
	}
	int number_of_luggage_places;
	int weight;
	size_t size;
	char tmp1[50],tmp2[50];
	int k = 0;
	while (k < n)
	{
		if (from.eof())break;
		
		from.read((char*)& size, sizeof(size_t));
		from.read((char*)& tmp1, size);
		passenger[k].set_surname(tmp2);

		from.read((char*)& size, sizeof(size_t));
		from.read((char*)& tmp2, size);
		passenger[k].set_name(tmp2);

		from.read((char*)& weight, sizeof(int));
		passenger[k].set_weight(weight);

		from.read((char*)& number_of_luggage_places, sizeof(int));
		passenger[k].set_number_of_luggage_places(number_of_luggage_places);
		++k;
	}
	cout << "the information was read from your file\n";
	from.close();
	return k;
}

void writeToFile(Passenger_luggage* passenger, const int n, char* filename)
{
	ofstream In(filename, ios::binary);
	if (!n) {
		cout << "Nothing to write,please try again\n"; }
	char tmp1[50],tmp2[50];
	int number_of_luggage_places;
	int weight;
	size_t size;
	for (int k = 0; k < n; ++k)
	{

		strcpy(tmp1, passenger[k].get_surname());
		size = strlen(tmp1) + 1;
		In.write((char*)& size, sizeof(size_t));
		In.write((char*)& tmp1, size);

		strcpy(tmp2, passenger[k].get_name());
		size = strlen(tmp2) + 1;
		In.write((char*)& size, sizeof(size_t));
		In.write((char*)& tmp2, size);

		weight = passenger[k].get_weight();
		In.write((char*)& weight, sizeof(int));

		number_of_luggage_places = passenger[k].get_number_of_luggage_places();
		In.write((char*)& number_of_luggage_places, sizeof(int));

	}
	In.close();
	cout << "all is good.Your data was written to file\n";
}

void freeMemory(Passenger_luggage* passenger, int n)
{
	if (passenger)
	{ delete[] passenger;
	passenger = nullptr;
	}
}

void print_iformation_about_passenger_and_luggage(Passenger_luggage* passenger, int& n)
{
for (int i = 0; i < n; ++i) {
	cout << setw(5) << i << "|" << passenger[i]; cout << '\n';
	}
}

Passenger_luggage* create_iformation_about_passenger_and_luggage(Passenger_luggage* passenger, int& n) {
	cin >> passenger[n];
	++n;
	return  passenger;
}

Passenger_luggage* remove_iformation_about_passenger_and_luggage(Passenger_luggage* passenger, int& n)
{
	Passenger_luggage* tmp = new(nothrow)Passenger_luggage[n - 1];
	for (int i = 0; i < (n - 1); ++i)
	{
		tmp[i] = passenger[i];
	}
	freeMemory(passenger, n);
	--n;
	return tmp;
	cout << "Done";
}
//Построить таблицу приближенных значений функции
//f(x)=ln(1+x)+e^2x на отрезке [a,b](в данном случае от 0 до 1)
//с шагом h(0.1)(eps=0.0001).Результаты представить в виде таблицы
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;
double Exp(double x, double eps)
{
	double sum = 1, term = 1;
	int i = 1;
	while( fabs(term) > eps)
	{
		term = term * x / i;
		sum += term;
		i++;
	}
	return sum;
}
double Log(double x, double eps)
{
	double sum = 0, term =-1;
	int i = 1;
	while ((fabs(term)/i) >eps)
	{
		term = -term * x;
		sum += term/i;
		i++;
	}
	return sum;
}

int main()
{
	double a, b, h, eps;
	cout << "Enter a,b,h,eps\n";
	cin >> a >> b >> h >> eps;
	
	cout << "Table of function value\n\n";
	for (double x = a; x <= b + h/2; x += h)
	{
		cout << "x=";
		cout << x;
		cout.width(13);
		cout << Log(x, eps) + Exp(2 * x, eps);;
		cout.width(13);
		cout << log(x + 1) + exp(x) * exp(x)<<"\n";

	}
	return 0;
}

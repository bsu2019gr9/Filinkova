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
	for (int i = 1; fabs(term) > eps; ++i)
	{
		term = term * x / i;
		sum += term;
	}
	return sum;
}
double Logarithm(double x, double eps)
{
	double sum = 0, term =-1; 
	for (int i = 1; (fabs(term)/i) >eps; ++i)
	{
		term = -term * x;
		sum += term/i;
	}
	return sum;
}
double Sum2_OfTheLogAndExp(double x, double eps)
{
	double sum = 0;
	sum = log(x + 1) + exp(x)*exp(x);
	return sum;
}
double Sum1_OfTheLogAndExp(double x, double eps)
{
	double sum = 0;
	sum = Logarithm(x, eps) + Exp(2*x, eps);
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
		cout << Sum1_OfTheLogAndExp(x, eps);
		cout.width(13);
		cout << Sum2_OfTheLogAndExp(x, eps)<<"\n";

	}
	return 0;
}

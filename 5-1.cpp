//Класс прямоугольник в декартовой прямоугольной с / к
#include <iostream>
using namespace std;

class Rectangle {
private:
	double x1, x2, y1, y2;
public:
	Rectangle();
	~Rectangle();

	Rectangle(double a, double b, double c, double d);
	void operator=(const Rectangle& other);
	Rectangle operator+(const Rectangle& other);
	Rectangle operator-(const Rectangle& other);
	Rectangle(const Rectangle& other);
	friend void operator<<(ostream& output, const Rectangle& tmp);
	friend void operator>>(istream& input, Rectangle& tmp);
	double length();
	double height();
	double Perimeter(double& a, double& b);
	double Area(double& a, double& b);

};

int main()
{
	Rectangle rectangle1;
	Rectangle rectangle2;
	Rectangle* rectangle3 = new (nothrow) Rectangle[10];
	double a, b;
	cin >> rectangle1;
	a = rectangle1.length();//длина прямоугольника
	b = rectangle1.height();//высота прямоугольника
	cout << "The first rectangle:\n";
	cout << rectangle1;
	cout << "The length of the first rectangle : " << a << '\n';
	cout << "The height of the first rectangle : " << b << '\n';
	cout << "Area of the first rectangle: " << rectangle1.Area(a, b) << '\n';//площадь прямоуг.
	cout << "Perimeter of the first rectangle: " << rectangle1.Perimeter(a, b) << '\n';//периметр прямоуг.
	rectangle2 = rectangle1;//присваиваем второму прямоугольнику координаты первого
	cout << "The second rectangle:\n";
	cout << rectangle2;
	*rectangle3 =rectangle1 + rectangle2;//складываются координаты 2-ух прямоугольников
	cout << "The third rectangle:\n";
	cout << *rectangle3;
	delete[] rectangle3;
	system("pause");
}
void Rectangle::operator=(const Rectangle& other)
{
	this->x1 = other.x1;
	this->x2 = other.x2;
	this->y1 = other.y1;
	this->y2 = other.y2;
}
Rectangle::Rectangle() :
	x1(0),
	x2(0),
	y1(1),
	y2(1)
{
	//cout << "no params constructor working \n";
};

Rectangle::~Rectangle() {// cout << "destructor working for...\n"; 
};

Rectangle::Rectangle(const Rectangle& other) :
	x1(other.x1),
	x2(other.x2),
	y1(other.y1),
	y2(other.y2)
{
	//cout << "copy constructor working for (" << this->x1 << ';' << this->x2 << ';' << this->y1 << ';' << this->y2 << ")\n";
};

/*Rectangle::Rectangle(const Rectangle& other) {
	*this = other;
};*/


Rectangle::Rectangle(double a, double b, double c, double d) :
	x1(a),
	x2(b),
	y1(c),
	y2(d)
{
	//cout << "constructor working for (" << this->x1 << ';' << this->x2 << ';' << this->y1 << ';' << this->y2 << ")\n";
};

void operator>>(istream& input, Rectangle& tmp)
{
	cout << "Enter the first point(x1,y1):\n";
	input >> tmp.x1 >> tmp.y1;
	cout << "Enter the diagonal point(according to the first)(x2,y2):\n";
	input >> tmp.x2 >> tmp.y2;
	while ((tmp.x2 == tmp.x1) || (tmp.y1 == tmp.y2)) {
		cout << "Enter the diagonal point one more time(x2 and y2 aren't equal to x1 and y2!!)\n";
		input >> tmp.x2 >> tmp.y2;
	}
}
void operator<<(ostream& output, const Rectangle& tmp)
{
	output << "Your points:" << "A(" << tmp.x1 << "," << tmp.y1 << ")" << ";" << "C(" << tmp.x2 << "," << tmp.y2 << ")" << ";" << '\n';
};

Rectangle Rectangle::operator+(const Rectangle& other) {
	Rectangle tmp;
	tmp.x1 = this->x1 + other.x1;
	tmp.x2 = this->x2 + other.x2;
	tmp.y1 = this->y1 + other.y1;
	tmp.y2 = this->y2 + other.y2;
	return tmp;
};
Rectangle Rectangle:: operator-(const Rectangle& other) {
	Rectangle tmp;
	tmp.x1 = abs(this->x1 - other.x1);
	tmp.x2 = abs(this->x2 - other.x2);
	tmp.y1 = abs(this->y1 - other.y1);
	tmp.y2 = abs(this->y2 - other.y2);
	return tmp;
};
double Rectangle::length() {
	return (abs(x1 - x2));
}
double Rectangle::height() {
	return (abs(y1 - y2));
}
double Rectangle::Perimeter(double& a, double& b) {
	return (a + b) * 2;
}
double Rectangle::Area(double& a, double& b) {
	return a * b;
}

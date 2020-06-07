//Класс прямоугольник в декартовой прямоугольной с / к
#include <iostream>
using namespace std;

class Rectangle {
private:

	double x1, y1, x2, y2;//(x1,y1)-левая нижняя координата, (x2,y2)- правая верхняя координата
	void CheckForExistence(double x1, double x2, double y1, double y2);//проверка на существование прямоугольника

public:

	Rectangle();// конструктор без параметров
	Rectangle(const Rectangle& other);// конструктор копирования
	Rectangle(double a, double b, double c, double d);// конструктор с параметрами 
	~Rectangle();// деструктор

	void operator=(const Rectangle& other);//оператор присваивания
	Rectangle operator*(const double n); //хотелось бы увидеть. Это по моему несложно (n>0)
	Rectangle operator+(const Rectangle&) const; //сложение двух дробей ??????????
	Rectangle operator-(const Rectangle&) const;// вычитание 2-ух координат(соотвественно x1-x2,y1-y2)

	friend ostream& operator<<(ostream& output, const Rectangle& tmp);//вывод
	friend istream& operator>>(istream& input, Rectangle& tmp);//ввод
	
	void operator+=(const Rectangle& other);
	void operator-=(const Rectangle& other);

	bool operator==(const Rectangle&) const;
	bool operator!=(const Rectangle&) const;

	double length() const;//длина прямоуг
	double height() const;//высота прямоуг

	double Perimeter() ;//периметр
	double Area() ;//площадь
	void printRectangle() ;//печать прямоугольника
	
};


int main()
{
	Rectangle rectangle1;
	Rectangle rectangle2;

	Rectangle* rectangle3 = new (nothrow) Rectangle[10];
	Rectangle* rectangle4 = new Rectangle(1, 2,4,6 );
	cin >> rectangle1;
	cout << "The first rectangle:\n"; cout << rectangle1;
	cout << "The length of the first rectangle : " << rectangle1.length() << '\n';//длина прямоуг
	cout << "The height of the first rectangle : " << rectangle1.height() << '\n';//высота прямоуг
	cout << "Area of the first rectangle: " << rectangle1.Area() << '\n';//площадь прямоуг.
	cout << "Perimeter of the first rectangle: " << rectangle1.Perimeter() << '\n';//периметр прямоуг.
	rectangle1.printRectangle();//печать прямоугольника
	
	rectangle2 = rectangle1;//присваиваем второму прямоугольнику координаты первого

	cout << "The second rectangle:\n";
	cout << rectangle2;
	*rectangle3 = rectangle1 + rectangle2;//складываются координаты 2-ух прямоугольников
	cout << "The third rectangle:\n";
	cout << *rectangle3;
	//cout << fff(rectangle1);
	//cout << ggg(rectangle4);
	Rectangle rectangle5(1, 0, 0, 0);
	//cout << ttt(rectangle5);
	delete[] rectangle3;
	system("pause");
}
void Rectangle::operator=(const Rectangle& other)
{
	this->x1 = other.x1;
	this->y1 = other.y1;
	this->x2 = other.x2;
	this->y2 = other.y2;
};
Rectangle::Rectangle() :
	x1(0),
	y1(0),
	x2(1),
	y2(1)
{
	//cout << "no params constructor working \n";
};

Rectangle::~Rectangle() {// cout << "destructor working for...\n"; 
};

Rectangle::Rectangle(const Rectangle& other) :
	x1(other.x1),
	y1(other.y1),
	x2(other.x2),
	y2(other.y2)
{
	//cout << "copy constructor working for (" << this->x1 << ';' << this->x2 << ';' << this->y1 << ';' << this->y2 << ")\n";
};

/*Rectangle::Rectangle(const Rectangle& other) {
	*this = other;//так получится рекрсивный вызов!!!!
};*/


void Rectangle::CheckForExistence(double x1, double x2, double y1, double y2) //проверка на существование прямоугольника
{
	if (x1 >= x2 || y1 >= y2) throw "Bad arguments";
};
Rectangle::Rectangle(double a, double b, double c, double d) : 
	        x1(a),
		y1(b),
		x2(c),
		y2(d)	
{
	CheckForExistence(x1,x2,y1,y2);
};

istream& operator>>(istream& input, Rectangle& tmp)
{
	cout << "Enter the first point(x1,y1):\n";
	input >> tmp.x1 >> tmp.y1;
	cout << "Enter the diagonal point(according to the first)(x2,y2):\n";//не видно, что надо "выше и правее!!!"
	input >> tmp.x2 >> tmp.y2;

	CheckForExistence(tmp.x1, tmp.x2, tmp.y1, tmp.y2);
	return input;
};
ostream& operator<<(ostream & output, const Rectangle & tmp)
{
	 output << "Your points:" << "A(" << tmp.x1 << "," << tmp.y1 << ")" << ";" << "C(" << tmp.x2 << "," << tmp.y2 << ")" << ";" << '\n';
	return output;
};

Rectangle Rectangle::operator+(const Rectangle& other) const
{
	Rectangle tmp(this->x1 + other.x1, this->y1 + other.y1, this->x2 + other.x2, this->y2 + other.y2);//а если получится 0 или неверный????
	return tmp;

};
Rectangle Rectangle:: operator-(const Rectangle& other)  const
{
	Rectangle tmp(this->x1 - other.x1, this->y1 - other.y1, this->x2 - other.x2, this->y2 - other.y2);//а если получится 0 или неверный????
	return tmp;
};
double Rectangle::length() const {
	return (x2 - x1);
};
double Rectangle::height() const {
	return (y2 - y1);
};
double Rectangle::Perimeter() {
	return (length() + height()) * 2;//слишком много вызовов, но можно и так.
};
double Rectangle::Area() {
	return length() * height();
};
void Rectangle::printRectangle(const char c='*') {//в первом семестре делали так!!!!

	for (int i = 1; i <= height(); i++)
	{
		for (int j = 1; j <= length(); j++)
		{
			cout << c;
		}
		cout << '\n';
	}
};
bool Rectangle::operator==(const Rectangle& other) const
{
	return ((length() == other.length()) && (height() == other.height()));
};
bool Rectangle::operator!=(const Rectangle& other) const
{

	return !(*this == other);
};
void Rectangle::operator+=(const Rectangle& other) {
	*this = *this + other;
};
void Rectangle::operator-=(const Rectangle& other) {
	*this = *this - other;
};
Rectangle fff(Rectangle rect) {
	return rect;
};
Rectangle* ggg(Rectangle* rect) {
	return rect;
};
Rectangle ttt(Rectangle& rect) {
	return rect;
};

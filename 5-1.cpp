#include <iostream>
#include <clocale>

using namespace std;

class Rectangle{
private:
	int x1, x2, y1, y2;
public:
	Rectangle();
	~Rectangle(); 
	
	Rectangle(int a, int b, int c, int d);
    void operator=(const Rectangle& other);
	Rectangle operator+(const Rectangle& other);
	Rectangle operator-(const Rectangle& other);
	Rectangle(const Rectangle& other);
	friend void operator<<(ostream& output, const Rectangle& tmp);
	friend void operator>>(istream& input, Rectangle& tmp);
	int length();
	int height();
	int Perimeter(int& a, int& b);
	int Area(int& a, int& b);

};

int main()
{
	Rectangle rectangle1;
	Rectangle rectangle2;
	Rectangle rectangle3; 
	int a{ 0 }, b{ 0 };
	cin >> rectangle1;
	a = rectangle1.length();//длина прямоугольника
	b = rectangle1.height();//высота прямоугольника
	rectangle2 = rectangle1;
	cout << "The first rectangle:\n";
	cout << rectangle1;
	cout << "The length of the first rectangle : " << a<<'\n';
	cout << "The height of the first rectangle : " << b<<'\n';
	cout << "Area of the first rectangle: " << rectangle1.Area(a, b)<<'\n';
	cout << "Perimeter of the first rectangle: " << rectangle1.Perimeter(a, b) << '\n';
	//Rectangle* rectangle4 = new Rectangle(rectangle1);
	//Rectangle* rect5 = &rectangle2;
	rectangle2 = rectangle1;
	cout << "The second rectangle:\n";
	cout<< rectangle2; 
	rectangle3 = rectangle1 + rectangle2;//складываются координаты 2-ух прямоугольников
	cout << "The third rectangle:\n";
    cout<< rectangle3;
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
	y1(0),
	y2(0)
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


Rectangle::Rectangle(int a, int b, int c, int d) :
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
	cout << "Enter the diagonal point(according to the first)(x2,y2):\n" ;
	input >> tmp.x2 >> tmp.y2;
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
int Rectangle:: length() {
	return (abs(x1 - x2));
}
int Rectangle::height() {
	return (abs(y1 - y2));
}
int Rectangle::Perimeter(int& a, int& b) {
	return (a + b) * 2;
}
int Rectangle::Area(int& a, int& b) {
	return a * b;
}

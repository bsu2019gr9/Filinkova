//горизонтальный градиент(слева направо)
#include <iostream>
#include <fstream> 

using namespace std;

struct color {
public:
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

int main() {

	ifstream fff("d:\\1.bmp", ios::binary);
	ofstream ggg("d:\\rezult.bmp", ios::binary);

	if (!fff) { cout << "No file d:\\1.bmp. Can't open\n"; exit(1); }
	if (!ggg) { cout << " file d:\\rezult.bmp. Can't create\n"; exit(1); }

	char buf[30];
	color c;
	float R, G, B; // первый цвет(начиная слева)
	float r, g, b; // конечный цвет (заканчивая справа)
	int step; // количество шагов
	float step_R, step_G, step_B;
	int newstep;
	float tmp_R, tmp_G, tmp_B;
	unsigned int width, height;

	cout << "Enter step:\n";
	cin >> step;

	cout << "Enter start color (R G B): \n";
	cin >> R >> G >> B;

	cout << "Enter finish color (r g b) : \n";
	cin >> r >> g >> b;

	fff.read((char*)&buf, 18);//чтение 18 байт заголовка bmp
	ggg.write((char*)&buf, 18);//запись 18 байт заголовка bmp
	fff.read((char*)&width, 4); cout << "width=" << width; //чтение width из заголовка bmp
	fff.read((char*)&height, 4); cout << ", height=" << height; //чтение height из заголовка bmp
	width = 400;
	ggg.write((char*)&width, 4);//запись width в заголовок bmp 
	height = 160;
	ggg.write((char*)&height, 4);//запись height в заголовок bmp
	fff.read((char*)&buf, 28);//чтение 28 байт заголовка bmp
	ggg.write((char*)&buf, 28);//запись 28 байт заголовка bmp

	if (step >= width) { step = width; }

	newstep = width / step;

	if (!newstep) { newstep = 1; }

	step_R = (r - R) / ((width / newstep) - 1);
	step_G = (g - G) / ((width / newstep) - 1);
	step_B = (b - B) / ((width / newstep) - 1);


	tmp_R = R; tmp_G = G; tmp_B = B;

	for (int i = 1; i <= height; ++i) {
		for (int j = 1; j <= width; ++j) {
			if (((width - j) >= newstep) && (!(j % newstep))) {
				R += step_R;
				G += step_G;
				B += step_B;
			}
			c.r = (unsigned char)R;
			c.g = (unsigned char)G;
			c.b = (unsigned char)B;
			ggg.write((char*)& c, 3);
		}
		R = tmp_R;
		G = tmp_G;
		B = tmp_B;
	}
	fff.close();
	ggg.close();
	return 0;
}

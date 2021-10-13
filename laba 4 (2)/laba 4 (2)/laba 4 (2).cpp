
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996);

using namespace std;

int n;
float pi = 3.1415926535;

struct coordinates {
	int x, y;
};

struct Circle {
	coordinates* coord = new coordinates[n];
	int radius;
	float square;
};

void Input(Circle* st) { 
	cout << "Введите координаты (X и Y): "; cin >> st->coord->x >> st->coord->y;
	cout << "Введите радиус круга: "; cin >> st->radius;
	cout << endl;
}

float Square(Circle* st) { 
	return pi * pow(st->radius, 2);
}

void Output(Circle* st) {
	cout << st->coord->x << "  " << st->coord->y << setw(8) << st->radius << setw(17) << Square(st);
	cout << endl;
}

void sort(Circle* st) {
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++) {
			if (st[j].radius > st[j + 1].radius) swap(st[j], st[j + 1]);
		}
}

int main() {
	setlocale(LC_ALL, "rus");

	cout << "Введите количество кругов: ";
	cin >> n;

	Circle* stud = new Circle[n];

	for (int i = 0; i < n; i++) 
	Input(&stud[i]);
	cout << endl;

	cout << "X  Y" << setw(10) << "Радиус" << setw(15) << "Площадь\n";
	for (int i = 0; i < n; i++) Output(&stud[i]);

	cout << "\nС сортировкой:\n";
 sort(stud);
	cout << "X  Y" << setw(10) << "Радиус" << setw(15) << "Площадь\n";
	for (int i = 0; i < n; i++) Output(&stud[i]);
}
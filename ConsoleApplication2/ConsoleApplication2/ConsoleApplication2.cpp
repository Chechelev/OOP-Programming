/*10.Заданные  точки плоскости рассортировать по возрастанию расстояния от начала координат.
Для сортировки использовать алгоритм выбора минимального элемента.*/

#include <iostream>
#include <cmath>
#include <time.h>
#include <windows.h>

using namespace std;

class Rastoyanie { //класс

	int* x2, * y2;
	double* dist;
	int x1, y1;
	int a;
	double s, sold;

public:
	Rastoyanie(int n);
	void vvod();
	void distance();
	void sort();
	void output();

	~Rastoyanie() {

		delete[] x2;
		delete[] y2;
		cout << "Очистка памяти" << endl;
	}
};

Rastoyanie::Rastoyanie(int n) { a = n; } //конструктор

void Rastoyanie::vvod()
{

	x2 = new int[a];
	y2 = new int[a];
	dist = new double[a];
	// указатели
	int* X2 = x2;
	int* Y2 = y2;

	for (X2, Y2; X2<=&x2[0] + a-1; X2++, Y2++) {

		*X2 = rand() % 10;
		*Y2 = rand() % 10;
	}
	cout << "Множество сгенерировано" << endl;
}


void Rastoyanie::distance() {
	double dx, dy, x1, y1;
	int i;
	x1 = 0;
	y1 = 0;
	dx = (x2[0] - x1);
	dy = (y2[0] - y1);
	sold = sqrt((dx * dx + dy * dy));
	//указатель
	double* ds = &s;
	*ds = 0;
	dist[0] = sold;

	for (i = 1; i < a; i++) {
		dx = (x2[i] - x1);
		dy = (y2[i] - y1);
		*ds = sqrt((dx * dx + dy * dy));
		dist[i] = *ds;
		if (*ds <= sold)
		{
			sold = *ds;
		}
	}
};



//сортировка мин элементом
void Rastoyanie::sort() {
	int k = 0, k1 = 0, nmin;
	double g;

	for (int i = 0; i < a - 1; i++)
	{
		nmin = i;

		for (int j = i + 1; j < a; j++)
			if (dist[j] < dist[nmin])
				nmin = j;

		if (nmin != i)
		{
			k = x2[i]; k1 = y2[i]; g = dist[i];
			x2[i] = x2[nmin]; 
			y2[i] = y2[nmin]; 
			dist[i] = dist[nmin];
			x2[nmin] = k; 
			y2[nmin] = k1; 
			dist[nmin] = g;
		}
	}
}


HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

void Rastoyanie::output()
{
	cout << "Вывод множества: " << endl;
	for (int i = 0; i < a; i++)
		//указатель
		cout << i + 1 << " точка с координатами: " << * (x2+i) << "; " << *(y2+i)<< endl;
	cout << endl;

	SetConsoleTextAttribute(handle, (0 | 14));
	cout << "Минимальное от начала координат: " << sold << '\n' << '\n';
	SetConsoleTextAttribute(handle, (0 | 15));
};


int main()
{
	setlocale(0, "");
	srand(time(0));
	int n;
	cout << "Введите размерность: ";
	cin >> n;
	Rastoyanie obj(n);
	obj.vvod();
	obj.distance();
	obj.sort();
	obj.output();

	return 0;
}
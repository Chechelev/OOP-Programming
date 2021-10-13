// lab5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include<iostream>
#include <iomanip>
#include <windows.h>

using namespace std;
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

class Matrix {

private:
	int** a, * b;
	int* sum;
	int n;

public:

	Matrix(int m) { // конструктор
		n = m;
		b = new int[n];
		a = new int* [n]; 
		for (int i = 0; i < n; i++) {
			cout << "Введите кол-во элементов в строке"<<" "<< i + 1 << ":" << " ";
			cin >> b[i];
			a[i] = new int[n];
		}

	}

	//прототипы функций
	void input();
	void search();
	void condition();
	void output();

	~Matrix() { //деструктор
		cout << "\nРаботает деструктор. Удаление массива\n";
		for (int i = 0; i < n; i++)
			delete[] a[i];
			delete[] a;
			delete[] b;
	}

};

void Matrix::input() { 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < b[i]; j++) {
			a[i][j] = rand() % 10;
			cout << setw(5) << a[i][j];
		}
		cout << endl;
	}
}

void Matrix::search() { //сумма
	sum = new int[n]; 
	int s = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < b[i]; j++) s += a[i][j];
		sum[i] = s; s = 0;
		cout << sum[i] << "\n"<<endl;
	}
	
}

void Matrix::condition() { //вывод матрицы с выполненым условием
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (sum[i] > sum[j]) {
				swap(a[i], a[j]);
				swap(b[i], b[j]);
				swap(sum[i], sum[j]);
			}
			else if (sum[i] == sum[j]) { //среднее значение
				int f = sum[i] / b[i], h = sum[j] / b[j];
				if (f < h) {
					swap(a[i], a[j]);
					swap(b[i], b[j]);
					swap(sum[i], sum[j]);
				}
			}
}

void Matrix::output() {
	SetConsoleTextAttribute(handle, (0 | 14));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < b[i]; j++) cout << setw(5) << a[i][j];
		cout << endl;
	}
	SetConsoleTextAttribute(handle, (0 | 15));
}

int main() {
	setlocale(0, "");
	int n;

	cout << "Введите количество строк матрицы: "; cin >> n;

	Matrix  Obj(n);
	cout << "\nМатрица имеет вид:\n";
	Obj.input();
	Obj.search();
	cout << "\nОтсортированный массив:\n";
	Obj.condition();
	Obj.output();

	cout << endl;

	return 0;
}
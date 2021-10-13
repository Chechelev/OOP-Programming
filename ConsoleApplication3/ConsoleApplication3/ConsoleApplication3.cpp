#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	string s, current;
	int max, i = 0;
	char* p;
	getline(cin, s);
	char* mass = new char[s.length()];
	char* m = new char[s.length()];
	strcpy(mass, s.c_str());
	p = strtok(mass, " ; ,.-_");
	current = p;
	max = current.length();

	while (p != 0) {                             // определение длины наибольшего слова
		current = p;
		if (current.length() > max)
			max = current.length();
		p = strtok(NULL, " ; ,.-_");
	}

	strcpy(mass, s.c_str());
	p = strtok(mass, " ; ,.-_");

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	while (p!=0) {	                            // нахождение и вывод слов нужной длины без повторов
		current = p;
		strcpy(m, s.c_str());// 
		m[i] = '\0';

		//int n = 0;                        // это вывод строки до текущего слова(для проверки)
		//cout << "output: ";
		//while (n!=i) {
		//	cout << m[n];
		//	n++;
		//}
		//cout << '\n';

		if (current.length() < max) {}
		else {
			if (strstr(m, p) != 0) {}
			else {
				SetConsoleTextAttribute(handle, (0 | 13));
				cout << p << ' ';

				SetConsoleTextAttribute(handle, (0 | 15));
			}
		}
		strcpy(m, s.c_str());//увеличиваем подстроку чтобы попасть на первый символ
		if (i != 0) {
			while (isalpha(m[i]) == 0) {
				i++;
			}
		}

		i += current.length();// добавляем длину текущего слова к подстроке для поиска
		p = strtok(NULL, " ; ,.-_");
	}
	cout << '\n';

	system("pause");
	return 0;
}
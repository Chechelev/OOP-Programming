include <iostream>
#include <math.h>
#include <conio.h>

#include <cstdlib>
using namespace std;
int const Nmax = 50;


class Coordinates
{
    unsigned n;
    float* x;    /*Объявляем указатель на динамический массив. */
    float* y;
    int result[3];

public:

    Coordinates(int size) {
        if (size<1 || size>Nmax) n = Nmax / 2; else n = size;
        x = new float[n]; // 
        y = new float[n];
    }

    // Метод для ввода массива, вводим координаты
    void MyDef()
    {
        cout << "Enter the coordinates of the points:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "x[" << i + 1 << "]=";
            cin >> x[i];
            cout << "y[" << i + 1 << "]=";
            cin >> y[i];
            if (i > 0 && x[i] == x[i - 1] && y[i] == y[i - 1])
            {
                cout << "This point already exists. Enter another point" << endl;
                i--;
            }
        }
    }


    void Show() // вывод координат
    {
        cout << "the coordinates of the points:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "(" << x[i] << "," << y[i] << ") ";
        }
        cout << endl;
    }


    void rasn() // нахождение количества точек в треугольник, нахождение вершин треуголиника 

    {
        int a, b, c, f = 0, t = 0;
        int min_result = 2147483647;



        for (int j = 0; j < n; j++)         // рассматривает треугольник, перебирает все точки, проверяет входят они в него или нет        
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int h = k + j + 2; h < n; h++)
                {
                    int t = 0;
                    for (int i = 0; i < n; i++)
                    {
                        int a = (x[j] - x[i]) * (y[k] - y[j]) - (x[k] - x[j]) * (y[j] - y[i]);
                        int b = (x[k] - x[i]) * (y[h] - y[k]) - (x[h] - x[k]) * (y[k] - y[i]);
                        int c = (x[h] - x[i]) * (y[j] - y[h]) - (x[j] - x[h]) * (y[h] - y[i]);

                        /* Если они одинакового знака, то точка внутри треугольника,
                          если что-то из этого - ноль, то точка лежит на стороне,
                          иначе точка вне треугольника.*/

                        if ((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0))
                        {
                            t++; // количество точек внутри треугольника 
                        }
                    }

                    if (sqrt(pow(n / (2 - t), 2)) < min_result) // должен находить здесь разность между кол-вом точек, но не делает
                    {
                        min_result = n - 3 - t - t; // разность  между всеми точками и точками внутри треугольника 
                        result[0] = j;
                        result[1] = k;
                        result[2] = h;
                    }
                }
            }
        }
        for (int j = 0; j < 3; j++)
        {
            S
                cout << "Apex " << j << ": (" << x[result[j]] << "; " << y[result[j]] << ")" << endl;  //вывод выершин треугольника красным цветом



        }
        ~Coordinates()   // диструктор, освобождает память 
        {
            cout << "\nThe destructor deletes array\n";
            _getch();

            delete[]x;
            delete[]y;
        }
    };

    int main(int argc, char* argv[])
    {
        int n;
        cout << "size="; cin >> n;
        Coordinates ObjArr(n);  // объект
        ObjArr.MyDef();
        ObjArr.Show();
        ObjArr.rasn();

        _getch(); return 0;
    }
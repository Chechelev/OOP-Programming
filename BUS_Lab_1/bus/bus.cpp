//Bus: Фамилия и инициалы водителя, Номер автобуса, Номер маршрута, Марка, Год начала эксплуатации, Пробег.Создать массив объектов.Вывести :
//    а) список автобусов для заданного номера маршрута;
//    б) список автобусов, которые эксплуатируются больше 10 лет;
//    в) список автобусов, пробег у которых больше 10 000 км.


#include <conio.h>
#include <string.h>
#include <iostream>
using namespace std;

struct date // дата начала эксплуатации
{
    int year;
};

//=======     class Bus   =================

class Bus {
    char name[30];
    int num;
    int route;
    char brand[30];
public:
    Bus();
    date t;
    int run;
    int  getroute();
    int  getyear();
    int  getrange();
    void show();
};


Bus::Bus()
{
    cout << endl;
    cout << "Input name: "; cin >> name;
    cout << "Input bus number: "; cin >> num;
    cout << "Input route: "; cin >> route;
    cout << "Input brand: "; cin >> brand;
    cout << "Input start of expluatation: "; cin >> t.year;
    cout << "Input run of a bus: "; cin >> run;
}


void Bus::show()
{
    cout << "Driver name: " << name << endl;
    cout << "Bus number is: " << num << endl;
    cout << "Bus route is: " << route << endl;
    cout << "Bus brand is: " << brand << endl;
    cout << "Start of expluatation: " << t.year << endl;
    cout << "Range: " << run << endl;

}


int Bus::getroute() { return route; }
int Bus::getyear() { return t.year; }
int Bus::getrange() { return run ; }

void spisroute(Bus spis[], int n)//список автобусов для заданного номера маршрута;
{
    int r;
    cout << endl;
    cout << "Input route number: ";  cin >> r;
    cout << "==================" << endl;
    cout << endl;
    for (int i = 0; i < n; i++) {
        if (spis[i].getroute() == r) {
            spis[i].show();
        }
    }
    cout << endl;
}

void oldBuses(Bus spis[], int n) //список автобусов, которые эксплуатируются больше 10 лет;
{
    cout << endl;
    cout << "list of old busses" << endl;
    cout << "==================" << endl;
    cout << endl;
    for (int i = 0; i < n; i++) {
        if (spis[i].t.year + 10 < 2021) {
            spis[i].show();
       }
        cout << endl;
    }
}

void aliveBuses(Bus spis[], int n) //список автобусов, которые эксплуатируются больше 10 лет;
{
    cout << endl;
    cout << "Busses with the range of 10000+ km" << endl;
    cout << "==================================" << endl;
    cout << endl;
    for (int i = 0; i < n; i++) {
        if (spis[i].run > 10000) {
            spis[i].show();
        }
        cout << endl;
    }
}

//=========    main   ================
int main()
{
    Bus *spis;
    int n;
    cout << "Input a number of busses: "; cin >> n;
    spis = new Bus[n];
    for (int i = 0; i < n; i++) {
        cout << "==============================" << endl;
        spis[i].show();
    }
    spisroute(spis, n);
    oldBuses(spis, n);
    aliveBuses(spis, n);
    delete[] spis;
    cout << "press any key!";
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

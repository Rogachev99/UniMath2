#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;

double fn(double x, double y) {
  return 0.221 * (pow(x,2) + sin(1.2*x)) + 0.452*y;
}

int main() {

  // задаём начальные условия
  double a = 0;
  double b = 1;
  double h = 0.1;
  double x = 0;
  double y = 0;

  ofstream file;
  file.open("data1.dat");

  // Первый метод или метод Эйлера
  //cout << x << " \t " << y << endl;
  file << x << " " << y << endl;
  for (double counter=1; counter<=(b-a)/h; counter++) {
    x = a + counter * h; // подсчитываем x
    y = y + h * fn(x, y); // подсчитываем значение функции
    // выводим на экран
    //cout << x << " \t " << y << endl;
    file << x << " " << y << endl;
  }
  file.close();

  file.open("data2.dat");
  // второй метод или метод Рунге-Кутты
  // Снова задаём начальные условия перед вычислением второго метода
  x = 0;
  y = 0;
  // оставляем пустой отступ для лучшей читабельности
  // cout << endl;

  // cout << x << " \t " << y << endl;
  file << x << " " << y << endl;
  for (double counter = 1; counter <= (b-a) / h; counter++) {

    double k1 = fn(x,y);
    double k2 = fn(x + h/2  ,y + k1*h/2);
    double k3 = fn(x + h/2  ,y + k2*h/2);
    double k4 = fn(x + h    ,y + k3*h);
    // подсчитываем аргумент
    x = a + counter * h;
    // Подсчитываем значение функции
    y = y + h/6 * (k1 + 2*k2 + 2*k3 + k4);
    // Выводим значения функции на экран
    // cout << x << " \t " << y << endl;
    file << x << " " << y << endl;
  }
  file.close();

  return 0;
}

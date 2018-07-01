
#include <cmath>
#include <iostream>
using namespace std;

double function(double x, double y) {
  return 0.158*(pow(x,2) + sin(0.8*x))+1.164*y;
}

// Метод Эйлера
// a - начало промежутка
// b - конец-промежутка
double find(double a, double b, double h) {

  // Начальные условия
  double x = 0;
  double y = 0;

  // Выводим название метода
  cout << "Метод Эйлера" << endl;

  // Выводим начальные точки функции
  cout << x << ": " << y << endl;

  for (double i=1; i<=(b-a)/h; i++) {
    // Подсчитываем x и y
    x = a + i * h;
    y = y + h * function(x, y);
    // Выводим значения функции на экран
    cout << x << ": " << y << endl;
  }
}

// Метод Рунге-Кутты
// a - начало промежутка
// b - конец-промежутка
double find2(double a, double b, double h) {
  // Начальные условия
  double x = 0;
  double y = 0;

  cout << endl << "Метод Рунге-Кутты" << endl;
  cout << x << ": " << y << endl;

  for (double i=1;i<=(b-a)/h; i++) {
    double k1 = function(x,y);
    double k2 = function(x + h/2  ,y + k1*h/2);
    double k3 = function(x + h/2  ,y + k2*h/2);
    double k4 = function(x + h    ,y + k3*h);
    x = a + i * h;
    y = y + h/6 * (k1 + 2*k2 + 2*k3 + k4);
    // Выводим значения функции на экран
    cout << x << ": " << y << endl;
  }
}

int main() {
  // Запускаем первый метод
  find(0,1,0.1);
  // Запускаем второй метод
  find2(0,1,0.1);

  return 0;
}

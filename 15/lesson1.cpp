#include <iostream>
#include <cmath>
using namespace std;

double fn(double x) {
  // функция
  return sqrt(0.3*pow(x,2) + 2.3) / (1.8 + sqrt(2*x + 1.6));
}

double p1(double x0, double h) {
  // считаем первую производную
  return (fn(x0+h) - fn(x0-h)) / (2 * h);
}

double p2(double x0, double h) {
  // считаем вторую производную
  return (fn(x0+h) - 2 * fn(x0) + fn(x0-h)) / pow(h,2);
}

// Численное дифференцирование
int main() {
  // шаг
  double h = 0.01;
  // Начальная точка
  double x0 = 0;
  // Вывод первой производной
  cout << "p1: " << p1(x0, h) << endl;
  // вывод второй производной
  cout << "p2: " << p2(x0, h) << endl;

  return 0;
}

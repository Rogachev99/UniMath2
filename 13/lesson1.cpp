
// Задание 1: Численное дифференцирование
#include <cmath>
#include <iostream>
using namespace std;

// Наша функция, с которой мы работаем
double function(double x) {
  return sqrt(0.4*x + 1.7) / (1.5*x + sqrt(pow(x,2) + 1.3));
}

// Первая производная
double first(double x, double h) {
  double y_minus = function(x - h);
  double y_plus = function(x + h);
  return (y_plus - y_minus) / (2 * h);
}

// Вторая производная
double second(double x, double h) {
  double y_minus = function(x - h);
  double y_plus = function(x + h);
  return (y_plus - 2 * function(x) + y_minus) / pow(h,2);
}

int main() {
  // Заданные условия задачи
  double h = 0.01;
  double x = 0;

  cout << "Первая производная: " << first(x, h) << endl;
  cout << "Вторая производная: " << second(x, h) << endl;
  return 0;
}

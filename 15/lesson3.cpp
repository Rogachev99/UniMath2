#include <iostream>
#include <cmath>
using namespace std;

// Функция
double fn(double x) {
  return 2 * pow(x-1,2) - exp(x);
}

// Производная
double pr(double x) {
  return 4*x - exp(x) - 4;
}

int main() {
  // начальная точка
  double x = 0;
  // Точность
  double eps = 0.0001;

  // Итеративный метод
  double x1;
  do {
    // предыдущая точка
    x1 = x;
    // x = f(x)
    x = (-1.0/2 * exp(x) + 1 + pow(x,2)) / 2;
    // Подсчитываем до тех пор, пока производная не станет меньше eps
  } while (abs(x1 - x) >= eps);
  // Возвращаем приблизительный корень
  cout << "Первый метод: " << x << endl;

  // начальная точка
  x = 0;

  // Метод Ньютона
  double value;
  do {
      // значение функции
      value = fn(x);
      // текущая значение
      x = x - value / pr(x);
      // Если значение функции меньше eps, то завершаем цикл
  } while (abs(value) >= eps);
  // Возвращаем приблизительный корень
  cout << "Второй метод: " << x << endl;

  return 0;
}

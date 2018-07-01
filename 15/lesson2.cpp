#include <iostream>
#include <cmath>
using namespace std;

double fn(double x) {
  // функция
  return sqrt(0.3 * pow(x,2) + 2.3) / (1.8 + sqrt(2*x + 1.6));
}

// Численное интегрирование
int main() {
  // Промежуток интегрирования
  double a = 0.8;
  double b = 1.6;

  int n = 15; // столько точек обработаем (точки интегрирования)
  double sum; // здесь будем хранить сумму
  double h;

  // Считаем по формуле средних треугольников
  sum = 0; // обнуляем сумму
  h = (b - a) / n;
  // Начинаем подсчёт интеграла
  for (int counter=0; counter<n; counter++) {
    // текущая точка функции
    double x = (a + (h*counter)) + h/2;
    // прибавляем к сумме
    sum += fn(x);
  }
  cout << "Первый метод: " << (h * sum) << endl;

  // Считаем по формуле трапеций
  sum = 0; // обнуляем сумму
  h = (b - a) / n; // подсчитываем h
  // Начинаем подсчёт интеграла
  for (int counter=0; counter<n; counter++) {
    // прибавляем к сумме
    sum += fn(a + h*counter) + fn(a + h*(counter+1));
  }
  // возвращаем интеграл
  cout << "Второй метод: " << ((b - a) / n) * 1.0/2 * sum << endl;

  // Вычисление по формуле Симпсона
  sum = 0; // обнуляем сумму
  h = (b - a) / n;
  // начинаем подсчёт интеграла
  for (int counter=1; counter<=n; counter++) {
    double xi = a + h*counter; // текущий x
    // Прибавляем к сумме
    sum += fn(xi) + 4*fn(xi - h/2) + fn(a + h*(counter-1));
  }
  cout << "Третий метод: " << h/6 * sum << endl;

  return 0;
}

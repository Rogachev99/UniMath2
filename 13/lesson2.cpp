
// Задание 2: Численное интегрирование
#include <cmath>
#include <iostream>
using namespace std;

// Наша функция, с которой мы работаем
double function(double x) {
  return sqrt(0.4*x + 1.7) / (1.5*x + sqrt(pow(x,2) + 1.3));
}

// Вычисление по формуле средних прямоугольников
// интегрирование от точки a, до точки b
// n - количество секторов, на который мы делим отрезок от a до b
double method1(double a, double b, int n) {
  // вычисляем шаг
  double h = (b - a) / n;
  // Отдельная переменная для хранения суммы
  double sum = 0;
  for (int i = 0; i < n; i++) {
    // текущий x - это точка a + (шаг * количество шагов)
    double xi = a + (h*i);
    sum += function(xi + h/2);
  }
  // Возвращаем сумму
  return h * sum;
}

// Вычисление по формуле трапеций
// интегрирование от точки a, до точки b
// n - количество секторов, на который мы делим отрезок от a до b
double method2(double a, double b, int n) {
  // вычисляем шаг
  double h = (b - a) / n;
  // Храним сумму
  double sum = 0;
  for (int i=0; i<n; i++) {
    // берём текущую точку
    double xi   = a + (h*i);
    // берём следующую точку
    double xii  = a + (h*(i+1));
    // прибавляем к сумме
    sum += function(xi) + function(xii);
  }
  // возвращаем интеграл
  return ((b - a) / n) * 1.0/2 * sum;
}


// Вычисление по формуле Симпсона
// интегрирование от точки a, до точки b
// n - количество секторов, на который мы делим отрезок от a до b
double method3(double a, double b, int n) {
  double h = (b - a) / n;
  double sum = 0;
  for (int i=1; i<=n; i++) {
    // Предыдущая точка x(i-1)
    double x = a + (h*(i-1));
    // Текущая точка x(i)
    double xi = a + h*i;
    // считаем сумму
    sum += function(xi) + 4*function(xi - h/2) + function(x);
  }
  // возвращам интеграл
  return h/6 * sum;
}

int main() {
  // Число точек интегрирования
  int n = 15;
  double a = 1.2;
  double b = 2.6;
  // Теперь выводим все интагралы
  cout << "Формула средних прямоугольников: " << method1(a, b, n) << endl;
  cout << "Формула трапеций: " << method2(a, b, n) << endl;
  cout << "Формула Симпсона: " << method3(a, b, n) << endl;
  return 0;
}

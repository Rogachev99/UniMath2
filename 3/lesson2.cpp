#include <iostream>
#include <cmath>
using namespace std;

double function(double x);

int main() {
  int n = 15; // число точек интиегрирования
  double a = 0.4; // начальная точка
  double b = 1.2; // конечная точка
  double h = (b - a) / n; // шаг интегрирования
  double sum; // сумма в которой будем хранить значение интеграла
  double x1, x2; // текущая и следующая точки

  // Подсчёт интеграла по формуле средних треугольников
  sum = 0; // обнуляем сумму перед расчётом
  for (int i = 0; i < n; i++) {
    x1 = a + (h*i);
    sum = sum + function(x1 + h/2);
  }
  cout << h * sum << endl; // выводим значение интеграла

  sum = 0; // обнуляем сумму перед расчётом
  for (int i=0; i<n; i++) {
    x2 = a+(h*(i+1));
    x1 = a+(h*i);
    sum = sum + function(x1) + function(x2);
  }
  sum = ((b-a)/n)*1/2.0*sum;
  cout << sum << endl; // выводим значение интеграла

  sum = 0; // обнуляем сумму перед расчётом
  for (int i=1; i<=n; i++) {
    x1 = a + (h*(i-1));
    x2 = a + h*i;
    sum += function(x2) + 4*function(x2 - h/2) + function(x1);
  }
  cout << h/6 * sum << endl; // выводим значение интеграла
}

double function(double x) {
    return sqrt(0.5*x+2) / (sqrt(2*pow(x,2) + 1)+0.8);
}

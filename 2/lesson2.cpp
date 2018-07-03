
#include <iostream>
#include <cmath>
using namespace std;

// Наша функция, с которой мы работаем

// Вычисление по формуле средних прямоугольников
// интегрирование от точки a, до точки b
// n - количество секторов, на который мы делим отрезок от a до b
double method1(double a, double b, int n) {
  // вычисляем шаг
}

// Вычисление по формуле трапеций
// интегрирование от точки a, до точки b
// n - количество секторов, на который мы делим отрезок от a до b
double method2(double a, double b, int n) {
  // вычисляем шаг
}


// Вычисление по формуле Симпсона
// интегрирование от точки a, до точки b
// n - количество секторов, на который мы делим отрезок от a до b
double method3(double a, double b, int n) {
}

double funkcia(double x);
int main()
{
  int n = 11;
  double a=0.2, b=0.8, h=(b-a)/n, sum;

  // Средние треугольники
  sum = 0;
  for (int i=0; i<n; i++)
  { sum += funkcia((a+(h*i)) + h/2); }
  sum = h * sum;
  cout << sum << endl;

  // формула трапеций
  sum = 0;
  for (int i=0; i<n; i++)
  { sum += funkcia(a+(h*i)) + funkcia(a+(h*(i+1))); }
  sum = h* (1.0/2) *sum;
  cout << sum << endl;

  // формула симпсона
  sum = 0;
  for (int i=1; i<=n; i++)
  { sum += funkcia(a+h*i) + 4*funkcia((a+h*i) - h/2)
            + funkcia(a+(h*(i-1))); }
  sum = h/6*sum;
  cout << sum << endl;
}
double funkcia(double x)
{
  return sin(2*x+0.5)/(2+cos(pow(x,2)+1));
}

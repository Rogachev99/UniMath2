
#include <iostream>
#include <cmath>
using namespace std;

double funkcia(double x);
int main()
{
  int n = 11;
  double a=0.2, b=0.8, h=(b-a)/n, sum;

  // Средние треугольники
  sum = 0;
  // подсчитываем сумму
  for (int i=0; i<n; i++)
  { sum += funkcia((a+(h*i)) + h/2); }
  sum = h * sum;
  cout << sum << endl;

  // формула трапеций
  sum = 0;
  // подсчитываем сумму
  for (int i=0; i<n; i++)
  { sum += funkcia(a+(h*i)) + funkcia(a+(h*(i+1))); }
  sum = h* (1.0/2) *sum;
  cout << sum << endl;

  // формула симпсона
  sum = 0;
  // подсчитываем сумму
  for (int i=1; i<=n; i++)
  { sum += funkcia(a+h*i) + 4*funkcia((a+h*i) - h/2)
            + funkcia(a+(h*(i-1))); }
  sum = h/6*sum;
  cout << sum << endl;
}

// Заданная функция
double funkcia(double x)
{
  return sin(2*x+0.5)/(2+cos(pow(x,2)+1));
}

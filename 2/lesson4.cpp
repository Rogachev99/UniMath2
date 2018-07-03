#include <iostream>
#include <cmath>
using namespace std;


// Метод Эйлера
// a - начало промежутка
// b - конец-промежутка
double find(double a, double b, double h) {

  // Начальные условия
}

// Метод Рунге-Кутты
// a - начало промежутка
// b - конец-промежутка
double find2(double a, double b, double h) {
  // Начальные условия
}

double funkcia(double x, double y);
void print(double x, double y);

int main() {
  double a=0, b=1, h=0.1;

  double x = 0, y = 0;
  print(x, y);
  for (double i=1; i<=(b-a)/h; i++) {
    x = a+i*h;
    y = y+h*funkcia(x,y);
    print(x, y);
  }

  x = 0; y = 0;
  print(x, y);

  double k1, k2, k3, k4;
  for (double i=1;i<=(b-a)/h; i++) {
    k1 = funkcia(x,y);
    k2 = funkcia(x+h/2,y+k1*h/2);
    k3 = funkcia(x+h/2,y+k2*h/2);
    k4 = funkcia(x+h,y+k3*h);
    y = y+h/6*(k1+2*k2+2*k3+k4);
    x = a+i*h;
    print(x, y);
  }
}

void print(double x, double y)
{
    cout << "f(" << x << ")" << " = " << y << endl;
}
double funkcia(double x, double y)
{
  return cos(x + y) + 0.5*(x-y);
}

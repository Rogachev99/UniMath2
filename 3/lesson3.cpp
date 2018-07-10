#include <cmath>
#include <iostream>
using namespace std;

double function(double x);
double derivative(double x);

int main() {
  double x = 0.1; // начальная точка
  double eps = 0.0001; // допустимая ошибка

  // Итеративный метод
  double x1;
  do {
        x1 = x;
        x = 1.0/pow(2,x);
        // Если разница между двумя рассматриваемыми точками меньше допустимой ошибки
    } while(abs(x1-x) >= eps);
  // Возвращаем точку близкую к корню
  cout << x << endl;

  x = 0.1;
  do {
      x1 = function(x);
      x = x - x1 / derivative(x); // текущая точка
  } while(abs(x1) >= eps);
  cout << x << endl;
}


// Заданная функция
double function(double x) {
    return x*pow(2,x)-1;
}

// Производная заданной функции
double derivative(double x) {
    return log(2)*x*pow(2,x)+pow(2,x);
}

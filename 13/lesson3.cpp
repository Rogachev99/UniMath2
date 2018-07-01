
// Задание 3: Методы решения нелинейных алгебраических уравнений
#include <cmath>
#include <iostream>
using namespace std;

// Наша функция, с которой мы работаем
double function(double x) {
  return log(x) - 2 + x;
}

// Производная нашей функции
double p_function(double x) {
  return 1/x + 1;
}

// Итеративный метод
// x - начальная точка
// eps - допустимая ошибка (точность)
double find(double x, double eps) {
  double x1;
  while (true) {
    x1 = x; // прошлая точка
    x = -log(x) + 2; // текущая точка
    // Если разница между двумя рассматриваемыми точками меньше допустимой ошибки
    if (abs(x1 - x) < eps) {
      // выходим из цикла
      break;
    }
  }
  // Возвращаем точку близкую к корню
  return x;
}

// Метод Ньютона
double find2(double x, double eps) {
  double fun;
  while (true) {
      fun = function(x);
      x = x - fun / p_function(x); // текущая точка
      // Если значение функции меньше eps
      if (abs(fun) < eps) {
        // выходим из цикла
        break;
      }
  }
  // Возвращаем точку близкую к корню
  return x;
}

int main() {
  // В качестве начальной точки возмём 1
  double x = 1;
  // Устанвливаем допустимую ошибку
  double eps = 0.0001;
  cout << "Итеративный метод: " << find(x, eps) << endl;
  cout << "Метод Ньютона: " << find2(x, eps) << endl;
  return 0;
}

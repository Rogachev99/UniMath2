#include <cmath>
#include <iostream>
using namespace std;

// Квадратура круга методом Монте-Карло
int main() {
  // Количество испытаний
  int n = 100000;
  // Успешные попадания в круг
  int G = 0;
  // Начинаем испытания
  for (int counter=0;counter<n;counter++) {
    // генерируем случайное число от 0 до 1 и присваиваем x
    double X = (double)rand() / RAND_MAX;
    // генерируем случайное число от 0 до 1 и присваиваем y
    double Y = (double)rand() / RAND_MAX;
    // Проверяем успешное попадание
    if (sqrt(pow(X,2) + pow(Y,2)) <= 1) {
      // Прибавляем счётчик
      G = G + 1;
    }
  }
  // Выводим результат
  cout << "П: " << (4 * (double)G / (double)n) << endl;
  return 0;
}

#include <cmath>
#include <iostream>
using namespace std;

double function(double x, double y);

int main() {
    double a = 0;
    double b = 1;
    double h = 0.1;
    // Начальные условия
    double x = 0;
    double y = 0;

    // Метод Эйлера
    // Выводим начальные точки функции
    cout << x << ": " << y << endl;
    for (double iterator = 1; iterator <= (b-a)/h; iterator++) {
        x = a + iterator * h;
        y = y + h * function(x, y);
        cout << x << " - " << y << endl;
    }

    // Метод Рунге-Кутты
    // обнуляем начальные условия
    x = 0; y = 0;
    cout << x << " - " << y << endl;
    for (double iterator=1; iterator <= (b-a)/h; iterator++) {
        double k1 = function(x,y);
        double k2 = function(x + h/2  ,y + k1*h/2);
        double k3 = function(x + h/2  ,y + k2*h/2);
        double k4 = function(x + h    ,y + k3*h);
        x = a + iterator * h;
        y = y + h/6 * (k1 + 2*k2 + 2*k3 + k4);
        cout << x << " - " << y << endl;
    }
}

double function(double x, double y) {
    return cos(x) / (x+1) - 0.5*pow(y,2);
}

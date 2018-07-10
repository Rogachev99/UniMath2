#include <iostream>
#include <cmath>
using namespace std;

double function(double x);

int main() {
    // начальные условия
    double h = 0.01;
    double x = 0;

    double ym = function(x - h);
    double yp = function(x + h);
    // Подсчитываем первую производную
    cout << (yp - ym) / (2 * h) << endl;

    // Подсчитываем вторую производную
    cout << (yp - 2 * function(x) + ym) / pow(h,2) << endl;
}

double function(double x) {
    return sqrt(0.5*x + 2) / (sqrt(2*pow(x,2) + 1) + 0.8);
}

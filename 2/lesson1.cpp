#include <cmath>
#include <iostream>
using namespace std;

// прототип нашей функци
double funkcia(double x);

int main()
{
        // Начальные условия
        double h = 0.01, x = 0;

        double ym = funkcia(x-h), yp = funkcia(x+h);
        // подсчитываем первую производную
        cout << (yp-ym)/(2*h) << endl;
        // подсчитываем вторую производную
        cout << (yp-2*funkcia(x)+ym) / pow(h,2) << endl;
}
double funkcia(double x)
{
        // Заданная функция
        return sin(2*x+0.5)/(2+cos(pow(x,2)+1));
}

#include <cmath>
#include <iostream>
using namespace std;
double funkcia(double x);
int main()
{
  double h = 0.01, x = 0;
  double ym = funkcia(x-h),yp = funkcia(x+h);
  cout << (yp-ym)/(2*h) << endl; // первая производная
  cout << (yp-2*funkcia(x)+ym) / pow(h,2) << endl; // вторая производная
}
double funkcia(double x)
{
  return sin(2*x+0.5)/(2+cos(pow(x,2)+1));
}

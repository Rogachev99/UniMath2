#include <iostream>
#include <cmath>
using namespace std;

double funkcia(double x);
double proiz(double x);

int main()
{
  double x=-2.5, eps=0.0001;

  // итеративный метод
  double x_last;
  do
  {
    x_last = x;
    x = -2 / (pow(x,2)+2*x);
  } while (abs(x_last-x)>=eps);
  cout << x << endl;

  // метод ньютона
  x=-2.5;
  double funkcia_val;
  do
  {
      funkcia_val = funkcia(x);
      x = x - funkcia_val / proiz(x);
  } while (abs(funkcia_val)>=eps);
  cout << x << endl;
}

double funkcia(double x)
{
  return pow(x,3)+2*pow(x,2)+2;
}
double proiz(double x)
{
  return x*(3*x+4);
}

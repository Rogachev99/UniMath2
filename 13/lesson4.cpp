
#include <cmath>
#include <iostream>
using namespace std;

double function(double x, double y) {
  return 0.158*(pow(x,2) + sin(0.8*x))+1.164*y;
}

double find(double y, double a, double b, double h) {
  double ly;
  for (double x = a; x <= b; x += h) {
    cout << x << endl;
  }
  for (double x = a; x <= b; x += h) {
    ly = y;
    y = y + h * function(x, y);
    cout << y << endl;
  }
}

int main() {
  find(0,0,1,0.1);
  return 0;
}

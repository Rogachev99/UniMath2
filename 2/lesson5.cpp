#include <iostream>
#include <cmath>
using namespace std;
double rn();
int main()
{
  double N = 100000, G = 0;
  double x, y, rast;
  for (int i=1;i<=N;i++) {
    x = rn(); y = rn();
    rast = sqrt(pow(x,2) + pow(y,2)); // расстояние от центра
    if (rast <= 1) { G+=1; } // попадание
  }
  cout << G/N*4 << endl;
}
double rn()
{
  return rand()/(double)RAND_MAX;
}

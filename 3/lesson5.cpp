#include <iostream>
#include <cmath>
using namespace std;

int main() {
    srand(time(0));
    // Количество испытаний
    double N = 100000;
    // Количество попаданий
    int G = 0;

    for (int i=1; i < (N+1); i++) {
        double x = rand()/(double)RAND_MAX;
        double y = rand()/(double)RAND_MAX;
        // Подсчитываем попадание
        double distance = sqrt(pow(x,2) + pow(y,2));
        if (distance <= 1) {
            G+=1;
        }
    }
    double answer = G / N*4;
    cout << answer << endl;

    return 0;
}

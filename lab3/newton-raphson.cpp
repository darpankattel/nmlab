#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

double func (double x) {
    return x*x-25;
}

double derif (double x) {
    return 2*x;
}

int main () {
    const double tol_error = 0.000001, tol_zero_error = 0.000001, max_iter = 1000;
    double x_new, x_old = 25;
    int i = 0;
    do {
        if (abs(derif(x_old)) < tol_zero_error) {
            cout << "Derivative becomes zero" << endl;
            exit(0);
        }
        x_new = x_old - (func(x_old)/derif(x_old));
        x_old = x_new;
        i++;
        if (i == max_iter) {
            cout << "Oscillatory case" << endl;
            exit(0);
        }
    } while (abs(func(x_new)) > tol_error);
    cout << "The root is " << x_new << endl;
    return 0;
}
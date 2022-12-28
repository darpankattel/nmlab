#include <iostream>
using namespace std;

double func (double x) {
    return x*x - 25;
}

int main () {
    const double tol_error = 0.000001, tol_zero_error = 0.000001, max_iter = 99999;
    double a = 3.0, b = 8.0, c = 0;
    int i = 0;
    do {
        if (abs(func(b) - func(a)) > tol_zero_error) {
            c = (a * func(b) - b * func(a)) / (func(b) - func(a));
            a = b;
            b = c;
            i++;
            if (i == max_iter) {
                cout << "Max iteration reached" << endl;
                return 0;
            }
        } else {
            cout << "Division by zero error" << endl;
            exit(0);
        }
    } while (abs(func(c)) > tol_error);
    cout << "The root is " << c << endl;
    return 0;
}
// trapezoidal rule
#include <iostream>
#include <cmath>

using namespace std;

class TrapezoidalRule {
private:
    double (*f)(double); // function pointer for the function to integrate
    double x0, xn, h; // initial and final boundaries, and height of subintervals
    int n; // number of subintervals
public:
    TrapezoidalRule(double (*f)(double), double x0, double xn, int n) {
        this->f = f;
        this->x0 = x0;
        this->xn = xn;
        this->n = n;
        this->h = (xn - x0) / n;
    }
    double integrate() {
        double sum = 0.5 * (f(x0) + f(xn));
        for (int i = 1; i < n; i++) {
            double x = x0 + i * h;
            sum += f(x);
        }
        return sum * h;
    }
};

// hard-coded function to integrate
double func(double x) {
    return 1/(1+x*x);
}

int main() {
    // create an instance of the TrapezoidalRule class
    TrapezoidalRule trapz(func, 0, 1, 16);

    // calculate the integral using the trapezoidal rule
    double result = trapz.integrate();

    // print the result
    cout << "Area under the curve: " << result << endl;

    return 0;
}

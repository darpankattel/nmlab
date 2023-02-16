// 1/3 and 3/8th rule
#include <iostream>
#include <cmath>

using namespace std;

class SimpsonRule {
private:
    double (*f)(double); // function pointer for the function to integrate
    double x0, xn, h; // initial and final boundaries, and height of subintervals
    int n; // number of subintervals
public:
    SimpsonRule(double (*f)(double), double x0, double xn, int n) {
        this->f = f;
        this->x0 = x0;
        this->xn = xn;
        this->n = n;
        this->h = (xn - x0) / n;
    }
    double integrate_1_3() {
        double sum = f(x0) + f(xn);
        for (int i = 1; i < n; i += 2) {
            double x = x0 + i * h;
            sum += 4 * f(x);
        }
        for (int i = 2; i < n; i += 2) {
            double x = x0 + i * h;
            sum += 2 * f(x);
        }
        return sum * h / 3;
    }
    double integrate_3_8() {
        double sum = f(x0) + f(xn);
        for (int i = 1; i < n; i += 3) {
            double x = x0 + i * h;
            sum += 3 * f(x);
        }
        for (int i = 2; i < n; i += 3) {
            double x = x0 + i * h;
            sum += 3 * f(x);
        }
        for (int i = 3; i < n; i += 3) {
            double x = x0 + i * h;
            sum += 2 * f(x);
        }
        return sum * 3 * h / 8;
    }
};

// hard-coded function to integrate
double func(double x) {
    return 1/(1+x*x);
}

int main() {
    // create an instance of the SimpsonRule class
    SimpsonRule simpson(func, 0, 1, 6);

    // calculate the integral using Simpson's 1/3 rule
    double result_1_3 = simpson.integrate_1_3();

    // print the result
    cout << "Area under the curve using Simpson's 1/3 rule: " << result_1_3 << endl;

    // calculate the integral using Simpson's 3/8 rule
    double result_3_8 = simpson.integrate_3_8();

    // print the result
    cout << "Area under the curve using Simpson's 3/8 rule: " << result_3_8 << endl;

    return 0;
}

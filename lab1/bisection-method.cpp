#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
const double error = 0.000005;
int noOfIterations = 0;

double d_to_r(double deg)
{
    return deg * M_PI / 180.0;
}

double f(double x) {
    // return (x*x*x - 9*x - 1);// [-1, 1]
    // return (x*x - 25);// [0, 10]
    // return (sin(x));// [-45, 45]
    return (sin(x) - 0.98);// [45, 90]
    // return (log10(x) - 1); // [1, 19]
    // return (exp(x) - 2.718); // [0, 2]
}

double bisect(double a, double b) {
    if (f(a) * f(b) > 0) {
        cout << "No root lies between x = " << a << " and x = " << b << endl;
        exit(0);
    }
    if (f(a) == 0)
        return a;
    if (f(b) == 0)
        return b;
    double c = 0;
    int n = log10(abs(b-a)/error)/log10(2);
    cout << "Min. Required Iterations: " << n << endl;
    while (abs(b-a) >= error) {
        if (noOfIterations == n + 1) {
            break;
        }
        noOfIterations++;
        c = (a+b) / 2.0;
        if (f(c) == 0.00) {
            break;
        }
        if (f(a)*f(c) > 0) {
            a = c;
        } else {
            b = c;
        }
    }
    return c;
}

int main () {
    double a = 45, b = 90, ans;
    ans = bisect(d_to_r(a), d_to_r(b));
    // ans = bisect(a, b);
    cout << "The value of the root is " << ans << endl;
    cout << "Iterations: " << noOfIterations << endl;
    return 0;
}
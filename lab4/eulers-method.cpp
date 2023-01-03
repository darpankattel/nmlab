// Numerical solution of initial value problems envolving 1st order ODEs using
// 1.   Euler's Method
// 2.   RK2 method
// 3.   RK4 method
#include <iostream>
using namespace std;

double func (double x, double y) {
    // 2 * x + 3; y(0) = 2; find y(1); ans : 6
    // x + y; y(0) = 1; find y(1); ans 3.4365
    // x * x + 2 * x - y; y(1) = 2; find y(0); ans 2.71828
    // x * x + y; y(0) = 2; find y(1); ans 7.8731
    return x * x + y;
}

int main () {
    double x_init, y_init, y_new, x_find, h;
    cout << "Enter initials:\nx: ";
    cin >> x_init;
    cout << "y: ";
    cin >> y_init;
    cout << "Enter x to find y(x): ";
    cin >> x_find;
    cout << "Enter h: ";
    cin >> h;
    int count = 0;
    while (x_init < x_find) {
        y_new = y_init + h * func(x_init, y_init);
        y_init = y_new;
        x_init += h;
    }
    cout << "y(" << x_find << ") = " << y_init << endl;
    return 0;
}
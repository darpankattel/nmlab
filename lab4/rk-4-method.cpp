// Numerical solution of initial value problems envolving 1st order ODEs using
// 1.   Euler's Method
// 2.   RK2 method
// 3.   RK4 method
#include <iostream>
using namespace std;

double func (double x, double y) {
    // return 2 * x + 3; // y(0) = 2; find y(1); ans : 6
    // return x + y; // y(0) = 1; find y(1); ans 3.4365
    // return x * x + 2 * x - y; // y(1) = 2; find y(0); ans 2.71828
    return x * x + y; // y(0) = 2; find y(1); ans 7.8731
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
    double k1, k2, k3, k4, k;
    while (x_init < x_find) {
        k1 = h*func(x_init, y_init);
        k2 = h*func(x_init + h/2, y_init + k1/2);
        k3 = h*func(x_init + h/2, y_init + k2/2);
        k4 = h*func(x_init + h, y_init + k3);
        k = (k1 + 2*k2 + 2*k3 + k4) / 6.0;
        y_new = y_init + k;
        y_init = y_new;
        x_init += h;
        cout << "(" << x_init << ", " << y_init <<")" << endl;
    }
    cout << "y(" << x_find << ") = " << y_init << endl;
    return 0;
}
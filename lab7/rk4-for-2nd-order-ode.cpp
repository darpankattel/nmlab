#include <iostream>
using namespace std;

double f(double x, double y, double z) {
    return z;
}
double g(double x, double y, double z) {
    return x*z*z - y*y;
}

int main () {
    double x0, y0, z0, h, xn;
    double k1, l1, k2, l2, k3, l3, k4, l4, k, l;
    cout << "Enter the value of x0, y0, z0, h, xn: ";
    cin >> x0 >> y0 >> z0 >> h >> xn;
    while (x0 < xn) {
        k1 = h*f(x0, y0, z0);
        l1 = h*g(x0, y0, z0);

        k2 = h*f(x0+h/2, y0+k1/2, z0+l1/2);
        l2 = h*g(x0+h/2, y0+k1/2, z0+l1/2);

        k3 = h*f(x0+h/2, y0+k2/2, z0+l2/2);
        l3 = h*g(x0+h/2, y0+k2/2, z0+l2/2);

        k4 = h*f(x0+h, y0+k3, z0+l3);
        l4 = h*g(x0+h, y0+k3, z0+l3);

        k = (k1 + 2*k2 + 2*k3 + k4) / 6;
        l = (l1 + 2*l2 + 2*l3 + l4) / 6;

        x0+=h;
        y0+=k;
        z0+=l;
    }
    cout << "(x, y, z) = (" << x0 << ", " << y0 << ", " << z0 << ")";
    return 0;
}
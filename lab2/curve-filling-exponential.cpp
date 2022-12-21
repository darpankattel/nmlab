#include <iostream>
#include <cmath>
using namespace std;

double det(double a, double b, double c, double d) {
    return d*a - b*c;
}

int main () {
    const int n = 7;
    double points [n][2] = {{12, 65}, {13, 94}, {45, 123}, {65, 545}, {15, 21}, {98, 56}, {45, 1}};
    double sumy = 0, sumx = 0, sumxy = 0, sumx2 = 0, a, b;

    for (int i = 0; i < n; i++) {
        sumx += points[i][0];
        sumy += log(points[i][1]);
        sumxy += points[i][0] * log(points[i][1]);
        sumx2 += points[i][0] * points[i][0];
    }

    cout << sumx << "," << sumy << "," << sumxy << "," << sumx2 << endl;
    a = exp(det(sumx2, sumxy, sumx, sumy) / det(sumx2, sumx, sumx, n));
    b = det(n, sumx, sumy, sumxy) / det(sumx2, sumx, sumx, n);

    cout << "The best fitting curve is y=" << a << "e^(" << b << "x)" << endl;

    return 0;
}
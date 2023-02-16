#include <iostream>
#include <cmath>
using namespace std;

double max(double* vector, int n) {
    double max = 0;
    for (int i = 0; i < n; i++)
    {   
        if (abs(vector[i]) > abs(max)) max = vector[i];
    }
    return max;
}

int main () {
    unsigned int n = 3;
    // ans: 11.291, {0.288, 0.334, 1}
    double a[n][n] = {
        5, 2, -1,
        2, 5, -2,
        -1, -2, 4
    },
    x[n] = {1, 1, 1},

    // 3.42, {-1, 1.42, -1}
    // double a[n][n] = {
    //     2, -1, 0,
    //     -1, 2, -1,
    //     0, -1, 2
    // },
    // x[n] = {0, 1, 0},
    z[n], y[n], d[n], l,
    e = 0.000005, D_MAX;
    do
    {
        for (int i = 0; i < n; i++) {
            z[i] = 0;
            for (int j = 0; j < n; j++)
                z[i] += a[i][j] * x[j];
        }

        l = max(z, n);
        for (int i = 0; i < n; i++) y[i] = z[i] / l;
        for (int i = 0; i < n; i++) d[i] = abs(y[i] - x[i]);
        D_MAX = abs(max(d, n));
        for (int i = 0; i < n; i++) x[i] = y[i];  
        
    } while (D_MAX > e);
    double k = 0;
    for (int i = 0; i < n; i++)
    {
        k += y[i] * y[i];
    }
    k = sqrt(k);
    cout << k << endl;
    
    cout << "Results:\nLargest Eigen Value: " << l << endl << "[" << endl;
    for (int i = 0; i < n; i++) cout << "\t" << y[i]/k << endl;
    cout << "]";
    return 0;
}
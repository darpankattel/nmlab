#include <iostream>
using namespace std;

int main () {
    int n;
    double x_to_find, sum = 0;
    cout << "Enter the no. of available data: ";
    cin >> n;
    cout << "Enter the value for which f(x) is to be calculated: ";
    cin >> x_to_find;
    double x[n], y[n], factor[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter x[" << i << "] and y[" << i << "]: ";
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; i++) {
        factor[i] = 1.0;
        for (int j = 0; j < n; j++) {
            if (i != j)
                factor[i] = factor[i] * ((x_to_find - x[j]) / (x[i] - x[j]));
        }
    }
    for (int i = 0; i < n; i++)
        sum += factor[i] * y[i];
    cout << sum << endl;
    return 0;
}
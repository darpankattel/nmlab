// Solution of System of Linear Algebraic Equation
// 1. Gauss Jordan Method
// 2. Gauss Elimintaion Method

#include <iostream>
#include <cstdlib>
using namespace std;
const double TOLERANCE = 0.000001;

// double problem[3][4] = {
//     3, 2, 1, 10,
//     4, 1, 1, 9,
//     1, 2, 2, 11
// };

double problem[4][5] = {
    3, 2, 1, 1, 14,
    4, 1, 1, 2, 17,
    1, 2, 2, 3, 23,
    3, 2, 6, 5, 45
};


class System {
    private:
    const int n;

    public:
    System (int len): n(len) {
        // for (int i = 0; i < 3; i++) {
        //     for (int j = 0; j < 4; j++) {
        //         matrix[i+j] = data[i+j];
        //     }
        // }
        // cout << endl;
    }

    class Solution {
        private:
        const int n;
        double* soln;

        public:
        Solution (double* ans, int len): n(len) {
            soln = new double[n];
            for (int i = 0; i < n; i++) {
                soln[i] = ans[i];
            }
        }
        void print_solution () {
            for (int i = 0; i < n; i++)
            {
                cout << soln[i] << "\t";
            }
            cout << endl;
        }
    };
    Solution get_solution_jordan() {
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                if (i == j)
                    continue;
                if (abs(problem[j][j]) <= TOLERANCE)
                    exit(0);
                double temp = problem[i][j] / problem[j][j];
                for (int k = 0; k < n + 1; k++) {
                    problem[i][k] = problem[i][k] - temp * problem[j][k];
                }
            }
        }
        double ans[n];
        for (int i = 0; i < n; i++) {
            ans[i] = problem[i][n] / problem[i][i];
        }
        return Solution(ans, n);
    }
    Solution get_solution_elimination() {
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                if (i >= j)
                    continue;
                if (abs(problem[j][j]) <= TOLERANCE)
                    exit(0);
                double temp = problem[i][j] / problem[j][j];
                for (int k = 0; k < n + 1; k++) {
                    problem[i][k] = problem[i][k] - temp * problem[j][k];
                }
            }
        }
        double ans[n];
        for (int i = n-1; i >= 0; i--) {
            ans[i] = problem[i][n];
            for (int j = n; j > i; j--) {
                ans[i] -= problem[i][j] * ans[j];
            }
            ans[i] /= problem[i][i];
        }
        return Solution(ans, n);
    }
};

int main () {
    System* my_system = new System(4);

    System::Solution solution_jordan = my_system->get_solution_jordan();
    cout << "Jordan: ";
    solution_jordan.print_solution();

    System::Solution solution_elimination = my_system->get_solution_elimination();
    cout << "Elimination: ";
    solution_elimination.print_solution();

    return 0;
}
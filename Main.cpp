#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

typedef vector<vector<double>> Matrix;

// Function to perform Cholesky Decomposition
bool CholeskyDecomposition(const Matrix& A, Matrix& L) {
    int n = A.size();

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            double sum = 0;
            for (int k = 0; k < j; ++k)
                sum += L[i][k] * L[j][k];

            if (i == j)
                L[i][j] = sqrt(A[i][i] - sum);
            else
                L[i][j] = (A[i][j] - sum) / L[j][j];
        }

        // Check for positive definiteness
        if (L[i][i] <= 0)
            return false;
    }
    return true;
}

// Function to print a matrix
void printMatrix(const Matrix& M) {
    int n = M.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << setw(10) << M[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    Matrix A = {{4, 12, -16},
                {12, 37, -43},
                {-16, -43, 98}};

    int n = A.size();
    Matrix L(n, vector<double>(n, 0));

    if (CholeskyDecomposition(A, L)) {
        cout << "Lower Triangular Matrix L:" << endl;
        printMatrix(L);
    } else {
        cout << "Matrix is not positive definite!" << endl;
    }

    return 0;
}

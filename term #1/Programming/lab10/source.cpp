#include "Header.h"


double** createMatrix(int n) {
    double** matrix = new double* [n];
    for (int i = 0; i < n; ++i)
        matrix[i] = new double[n];
    return matrix;
}

void findNewLineAndSwap(double** matrix, int n, int c, bool& reverseMatrixExists) {
    int ind = 0;
    reverseMatrixExists = false;
    for (int i = c + 1; i < n; ++i) {
        if (matrix[i][c] != 0) {
            ind = i;
            reverseMatrixExists = true;
        }
    }
    if (reverseMatrixExists) {
        for (int i = 0; i < 2 * n; ++i)
            swap(matrix[c][i], matrix[ind][i]);
    }
}

void straightWay(double** matrix, int n, bool& reverseMatrixExists) {
    int c = 0;
    double k;
    while (c < n) {
        k = matrix[c][c];
        if (k == 0) {
            findNewLineAndSwap(matrix, n, c, reverseMatrixExists);
            if (!reverseMatrixExists)
                return;
        }
        k = matrix[c][c];

        for (int i = 0; i < 2 * n; ++i)
            matrix[c][i] /= k;

        for (int i = c + 1; i < n; ++i) {
            k = matrix[i][c];
            for (int j = 0; j < 2 * n; ++j)
                matrix[i][j] -= k * matrix[c][j];
        }
        ++c;
    }
}

void reverseWay(double** matrix, int n) {
    double k;
    int c = 1;
    while (c < n) {
        for (int i = 0; i < n - c; ++i) {
            k = matrix[i][n - c];
            for (int j = 0; j < 2 * n; ++j)
                matrix[i][j] -= k * matrix[n - c][j];
        }
        ++c;
    }
}
void printMatrix(double** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << setw(8) << fixed << setprecision(4) << matrix[i][j] << defaultfloat;
        cout << endl;
    }
}

void printExtendedMatrix(double** matrix, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 2 * n; ++j)
            cout << setw(8) << setprecision(2) << matrix[i][j];
        cout << endl;
    }
}

double** multiplyMatrixes(double** A, double** B, int n) {
    double** C = createMatrix(n);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            C[i][j] = 0;
    
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                C[i][j] += A[i][k] * B[k][j];

    return C;
}

void deleteMatrix(double** matrix, int n) {
    for (int i = 0; i < n; ++i)
        delete[] matrix[i];
    delete[] matrix;
}
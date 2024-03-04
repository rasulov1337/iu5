#include "header.h"

int main() {
    setlocale(0, "");

    cout << "Введите порядок матрицы: ";

    int n;
    cin >> n;
    double** originalMatrix = createMatrix(n);

    // Заполнение входной матрицы
    for (int i = 0; i < n; ++i) {
        cout << "Введите значения элементов " << i + 1 << " строки: ";
        for (int j = 0; j < n; ++j)
            cin >> originalMatrix[i][j];
    }

    cout << "Исходная матрица:\n";
    printMatrix(originalMatrix, n);


    //  Заполнение расширенной матрицы
    double** extendedMatrix = createMatrix(2 * n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            extendedMatrix[i][j] = originalMatrix[i][j];
        
        for (int j = n; j < 2 * n; ++j) {
            if (i + n == j)
                extendedMatrix[i][j] = 1;
            else 
                extendedMatrix[i][j] = 0;
        }
    }

    bool reverseMatrixExists;
    straightWay(extendedMatrix, n, reverseMatrixExists);

    if (!reverseMatrixExists) {
        cout << "Обратная матрица не существует!\n";

        deleteMatrix(originalMatrix, n);
        deleteMatrix(extendedMatrix, 2 * n);
        return 0;
    }

    cout << "После прямого хода:\n\n";
    printExtendedMatrix(extendedMatrix, n);

    reverseWay(extendedMatrix, n);
    cout << "После обратного хода:\n\n";
    printExtendedMatrix(extendedMatrix, n);

    double** inverseMatrix = createMatrix(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            inverseMatrix[i][j] = extendedMatrix[i][n + j];

    cout << "Обратная матрица:\n\n";
    printMatrix(inverseMatrix, n);

    // произведение начальной и обратной к ней матриц
    cout << "Произведение начальной матрицы на ей обратную: " << endl;
    double** mul = multiplyMatrixes(originalMatrix, inverseMatrix, n);
    printMatrix(mul, n);
    
    
    // Free allocated memory
    deleteMatrix(originalMatrix, n);
    deleteMatrix(extendedMatrix, 2 * n);
    deleteMatrix(mul, n);
    deleteMatrix(inverseMatrix, n);
}
#include "MatrixOps.h"

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    const int rows = 3;
    const int cols = 3;

    int** matrixA = new int*[rows];
    int** matrixB = new int*[rows];
    int** result = new int*[rows];

    for (int i = 0; i < rows; ++i) {
        matrixA[i] = new int[cols];
        matrixB[i] = new int[cols];
        result[i] = new int[cols];
    }

    // Initialize matrixA and matrixB with values

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrixA[i][j] = i + j;
            matrixB[i][j] = i - j;
        }
    }

    std::cout << "Matrix A:" << std::endl;
    printMatrix(matrixA, rows, cols);

    std::cout << "Matrix B:" << std::endl;
    printMatrix(matrixB, rows, cols);

    MatrixOps::addMatrices(matrixA, matrixB, result, rows, cols);
    std::cout << "Result of addition:" << std::endl;
    printMatrix(result, rows, cols);

    MatrixOps::multiplyMatrices(matrixA, matrixB, result, rows, cols, rows, cols);
    std::cout << "Result of multiplication:" << std::endl;
    printMatrix(result, rows, cols);

    // Deallocate memory
    for (int i = 0; i < rows; ++i) {
        delete[] matrixA[i];
        delete[] matrixB[i];
        delete[] result[i];
    }

    delete[] matrixA;
    delete[] matrixB;
    delete[] result;

    return 0;
}

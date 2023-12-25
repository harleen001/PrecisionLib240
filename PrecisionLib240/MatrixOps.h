#ifndef MATRIXOPS_H
#define MATRIXOPS_H

#include <iostream>
#include <cmath>

class MatrixOps {
public:
    static void addMatrices(int** matrixA, int** matrixB, int** result, int rows, int cols) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[i][j] = matrixA[i][j] + matrixB[i][j];
            }
        }
    }

    static void subtractMatrices(int** matrixA, int** matrixB, int** result, int rows, int cols) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result[i][j] = matrixA[i][j] - matrixB[i][j];
            }
        }
    }

    static void multiplyMatrices(int** matrixA, int** matrixB, int** result, int rowsA, int colsA, int rowsB, int colsB) {
        for (int i = 0; i < rowsA; ++i) {
            for (int j = 0; j < colsB; ++j) {
                result[i][j] = 0;
                for (int k = 0; k < colsA; ++k) {
                    result[i][j] += matrixA[i][k] * matrixB[k][j];
                }
            }
        }
    }

    static void transposeMatrix(int** matrix, int** result, int rows, int cols) {
        for (int i = 0; i < cols; ++i) {
            for (int j = 0; j < rows; ++j) {
                result[i][j] = matrix[j][i];
            }
        }
    }

    static int determinant(int** matrix, int size) {
        if (size == 1) {
            return matrix[0][0];
        }

        int det = 0;
        int sign = 1;

        int** temp = new int*[size];
        for (int i = 0; i < size; ++i) {
            temp[i] = new int[size];
        }

        for (int i = 0; i < size; ++i) {
            getCofactor(matrix, temp, 0, i, size);
            det += sign * matrix[0][i] * determinant(temp, size - 1);
            sign = -sign;
        }

        for (int i = 0; i < size; ++i) {
            delete[] temp[i];
        }
        delete[] temp;

        return det;
    }

    static void getCofactor(int** matrix, int** temp, int p, int q, int size) {
        int i = 0, j = 0;
        for (int row = 0; row < size; ++row) {
            for (int col = 0; col < size; ++col) {
                if (row != p && col != q) {
                    temp[i][j++] = matrix[row][col];
                    if (j == size - 1) {
                        j = 0;
                        ++i;
                    }
                }
            }
        }
    }

    static void adjoint(int** matrix, int** adj, int size) {
        if (size == 1) {
            adj[0][0] = 1;
            return;
        }

        int sign = 1;
        int** temp = new int*[size];
        for (int i = 0; i < size; ++i) {
            temp[i] = new int[size];
        }

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                getCofactor(matrix, temp, i, j, size);
                sign = ((i + j) % 2 == 0) ? 1 : -1;
                adj[j][i] = sign * determinant(temp, size - 1);
            }
        }

        for (int i = 0; i < size; ++i) {
            delete[] temp[i];
        }
        delete[] temp;
    }

    static void invertMatrix(int** matrix, int** result, int size) {
        int det = determinant(matrix, size);
        if (det == 0) {
            std::cout << "Matrix is singular and cannot be inverted!" << std::endl;
            return;
        }

        int** adj = new int*[size];
        for (int i = 0; i < size; ++i) {
            adj[i] = new int[size];
        }

        adjoint(matrix, adj, size);

        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                result[i][j] = adj[i][j] / det;
            }
        }

        for (int i = 0; i < size; ++i) {
            delete[] adj[i];
        }
        delete[]
        adj[i];
    }
    delete[] adj;
}

static void identityMatrix(int** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (i == j) {
                matrix[i][j] = 1;
            } else {
                matrix[i][j] = 0;
            }
        }
    }
}

static bool isSymmetric(int** matrix, int size) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < i; ++j) {
            if (matrix[i][j] != matrix[j][i]) {
                return false;
            }
        }
    }
    return true;
}

static bool isSparse(int** matrix, int rows, int cols) {
    int zeroCount = 0;
    int totalCount = rows * cols;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] == 0) {
                ++zeroCount;
            }
        }
    }

    double sparsity = (static_cast<double>(zeroCount) / totalCount) * 100;
    return sparsity > 50; // Considered sparse if more than 50% of elements are zero
}

static void rotateMatrixClockwise(int** matrix, int size) {
    int** temp = new int*[size];
    for (int i = 0; i < size; ++i) {
        temp[i] = new int[size];
    }

    // Transpose matrix
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            temp[i][j] = matrix[j][i];
        }
    }

    // Reverse each row to rotate clockwise
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size / 2; ++j) {
            std::swap(temp[i][j], temp[i][size - j - 1]);
        }
    }

    // Copy rotated matrix back to original matrix
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = temp[i][j];
        }
    }

    for (int i = 0; i < size; ++i) {
        delete[] temp[i];
    }
    delete[] temp;
}


#endif // MATRIXOPS_H

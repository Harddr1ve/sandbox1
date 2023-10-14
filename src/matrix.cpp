#include "matrix.hpp"

matrix::matrix(/* args */)
{
}

matrix::~matrix()
{
}

void matrix::multiplyMatrix(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2, std::vector<std::vector<int>>& result) {
    int m1 = matrix1.size();
    int n1 = matrix1[0].size();
    int m2 = matrix2.size();
    int n2 = matrix2[0].size();

    if (n1 != m2) {
        std::cerr << "Error: matrices cannot be multiplied" << std::endl;
        return;
    }

    result.resize(m1);
    for (int i = 0; i < m1; i++) {
        result[i].resize(n2);
        for (int j = 0; j < n2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void matrix::printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}

void matrix::printMinors(const std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::vector<std::vector<int>> minor;
            for (int k = 0; k < n; k++) {
                if (k != i) {
                    std::vector<int> row;
                    for (int l = 0; l < n; l++) {
                        if (l != j) {
                            row.push_back(matrix[k][l]);
                        }
                    }
                    minor.push_back(row);
                }
            }
            std::cout << "Minor(" << i << "," << j << "):" << std::endl;
            printMatrix(minor);
        }
    }
}


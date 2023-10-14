#include <iostream>
#include <vector>
#include <cstring>

#include "matrix.hpp"

int main() {
    matrix m;
    std::vector<std::vector<int>> matrix1 = {{1, 2, 5, 1}, {3, 4, 5, 1}, {5, 6, 5, 1}, {7, 8, 5, 1}};
    std::vector<std::vector<int>> matrix2 = {{5, 6, 1, 2}, {7, 8, 3, 4}, {5, 6, 5, 6}, {7, 8, 7, 8}};
    std::vector<std::vector<int>> result;

    m.multiplyMatrix(matrix1, matrix2, result);
    // concatenate the two matrices
    matrix1.insert(matrix1.end(), matrix2.begin(), matrix2.end());

    // print the concatenated matrix
    for (const auto& row : matrix1) {
        for (const auto& element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "Result:" << std::endl;
    m.printMatrix(result);
    m.printMinors(result);
    
    return 0;
}
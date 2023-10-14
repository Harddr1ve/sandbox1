#include <gtest/gtest.h>
#include <vector>
#include <iostream>
#include "../src/matrix.hpp"

TEST(MatrixConcatenationTest, ConcatenationTest) {
    matrix m;
    std::vector<std::vector<int>> matrix1 = {{1, 2, 5, 1}, {3, 4, 5, 1}, {5, 6, 5, 1}, {7, 8, 5, 1}};
    std::vector<std::vector<int>> matrix2 = {{5, 6, 1, 2}, {7, 8, 3, 4}, {5, 6, 5, 6}, {7, 8, 7, 8}};
    std::vector<std::vector<int>> expected_result = {{1, 2, 5, 1}, {3, 4, 5, 1}, {5, 6, 5, 1}, {7, 8, 5, 1}, {5, 6, 1, 2}, {7, 8, 3, 4}, {5, 6, 5, 6}, {7, 8, 7, 8}};
    std::vector<std::vector<int>> result;

    matrix1.insert(matrix1.end(), matrix2.begin(), matrix2.end());

    ASSERT_EQ(matrix1, expected_result);
}

TEST(MatrixTest, MultiplyMatrix) {
    matrix m;
    std::vector<std::vector<int>> matrix1 = {{1, 2}, {3, 4}};
    std::vector<std::vector<int>> matrix2 = {{5, 6}, {7, 8}};
    std::vector<std::vector<int>> expected_result = {{19, 22}, {43, 50}};
    std::vector<std::vector<int>> result(2, std::vector<int>(2));
    m.multiplyMatrix(matrix1, matrix2, result);
    EXPECT_EQ(result, expected_result);
}

TEST(MatrixTest, PrintMatrix) {
    matrix m;
    std::vector<std::vector<int>> matrix = {{1, 2}, {3, 4}};
    testing::internal::CaptureStdout();
    m.printMatrix(matrix);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "1 2 \n3 4 \n");
}
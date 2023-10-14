#include <iostream>
#include <vector>
#include <cstring>

class matrix
{
private:
    /* data */
public:
    matrix(/* args */);
    ~matrix();
    void multiplyMatrix(const std::vector<std::vector<int>>& matrix1, const std::vector<std::vector<int>>& matrix2, std::vector<std::vector<int>>& result);
    void printMatrix(const std::vector<std::vector<int>>& matrix);
    void printMinors(const std::vector<std::vector<int>>& matrix);
};



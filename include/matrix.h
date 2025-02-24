#ifndef APP_MATRIX_H
#define APP_MATRIX_H
#include <string>
namespace lab{
class Matrix{
private:
    int _height;
    int _weight;

    Matrix(): _height(0), _weight(0){};
    Matrix(const int height, const int weight, bool isRandomValue);
    Matrix(const std::string& file_path);

    void _fill_random_values();
    Matrix operator*(const Matrix& right_matrix) const;
    void saveToFile(const std::string& file_path) const;





};
}// namespace lab



#endif //APP_MATRIX_H

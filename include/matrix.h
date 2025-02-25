#ifndef APP_MATRIX_H
#define APP_MATRIX_H

#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>

namespace lab {
    class Matrix {
        friend std::ostream &operator<<(std::ostream &out, const Matrix &matrix);

    private:
        size_t _height;
        size_t _width;
        std::vector<int> _matrix;

        void _fill_random_values(int start = 0, int end = 100);

    public:
        Matrix() : _height(0), _width(0) {};

        explicit Matrix(const std::string &file_path);

        Matrix(size_t height, size_t width, bool isRandomValue);

        size_t Height() const;

        size_t Width() const;

        Matrix operator*(const Matrix &B) const;

        void saveToFile(const std::string &file_path) const;

        void readFromFile(const std::string &file_path);

        int &operator()(size_t row, size_t column);
        const int& operator()(const size_t row, const size_t column) const;


    };


    Matrix::Matrix(const size_t height, const size_t width, const bool isRandomValue) {
        this->_height = height;
        this->_width = width;
        this->_matrix = std::vector<int>(_height * _width, 0);
        if (isRandomValue) {
            this->_fill_random_values();
        }
    }

    Matrix::Matrix(const std::string &file_path) {
        this->readFromFile(file_path);
    }

    void Matrix::_fill_random_values(const int start, const int end) {
        for (auto &element: this->_matrix) {
            element = std::rand() % (end - start + 1) + start;
        }
    }

    void Matrix::saveToFile(const std::string &file_path) const {
        std::ofstream out;
        out.open(file_path);
        if (out.is_open()) {
            out << this->_width << " " << this->_height << "\n";
            for (size_t i = 0; i < this->_height; i++) {
                for (size_t j = 0; j < this->_width; j++) {
                    out << this->_matrix[i * _width + j] << " ";
                }
                out << "\n";
            }
        }
        out.close();
    }

    void Matrix::readFromFile(const std::string &file_path) {
        std::ifstream in(file_path);
        if (in.is_open()) {
            in >> this->_width >> this->_height;
            this->_matrix = std::vector<int>(_width * _height);
            for (auto &elem: this->_matrix) {
                in >> elem;
            }
        }
    }

    int &Matrix::operator()(const size_t row, const size_t column) {
        return this->_matrix[row * _width + column];
    }
    const int &Matrix::operator()(const size_t row, const size_t column) const {
        return this->_matrix[row * _width + column];
    }

    std::ostream &operator<<(std::ostream &out, const Matrix &matrix) {
        for (size_t i = 0; i < matrix._height; i++) {
            for (size_t j = 0; j < matrix._width; j++) {
                out << matrix._matrix[i * matrix._width + j] << " ";
            }
            out << "\n";
        }
        return out;
    }

    size_t Matrix::Height() const {
        return this->_height;
    }

    size_t Matrix::Width() const {
        return this->_width;
    }


    Matrix Matrix::operator*(const lab::Matrix &B) const {
        if (this->_width != B._height) {
            throw std::invalid_argument("second matrix should have same count of rows as columns in first matrix.");
        }
        Matrix C(this->_height, B._width, false);

        for (int i = 0; i < C._height; i++) {
            for (int j = 0; j < C._width; j++) {
                int value = 0;
                for (int n = 0; n < this->_height; n++) {
                    value+=this->operator()(i, n)*B(n, j);
                }
                C(i, j) = value;
            }
        }
        return C;
    }

}// namespace lab
#endif //APP_MATRIX_H

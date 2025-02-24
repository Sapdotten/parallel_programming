#ifndef APP_MATRIX_H
#define APP_MATRIX_H

#include <string>
#include <vector>
#include <fstream>

namespace lab {
    class Matrix {
        friend std::ostream& operator<<(std:: ostream& out, const Matrix& matrix);
    private:
        size_t _height;
        size_t _width;
        std::vector<int> _matrix;

        void _fill_random_values(int start = -100, int end = 100);

    public:
        Matrix() : _height(0), _width(0) {};
        explicit Matrix(const std::string& file_path);

        Matrix(size_t height, size_t width, bool isRandomValue);


        Matrix operator*(const Matrix &right_matrix) const;

        void saveToFile(const std::string &file_path) const;

        void readFromFile(const std::string &file_path);

        int &operator()(size_t row, size_t column);


    };


    Matrix::Matrix(const size_t height, const size_t width, const bool isRandomValue) {
        this->_height = height;
        this->_width = width;
        this->_matrix = std::vector<int>(_height * _width, 0);
        if (isRandomValue) {
            this->_fill_random_values();
        }
    }
    Matrix::Matrix(const std::string& file_path){
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
            in>>this->_width>>this->_height;
            this->_matrix=std::vector<int>(_width*_height);
            for(auto& elem: this->_matrix){
                in>>elem;
            }
        }
    }

    int& Matrix::operator()(const size_t row, const size_t column) {
        return this->_matrix[row*_width+column];
    }

    std::ostream& operator<<(std:: ostream& out, const Matrix& matrix){
        for (size_t i = 0; i < matrix._height; i++) {
            for (size_t j = 0; j < matrix._width; j++) {
                out << matrix._matrix[i * matrix._width + j] << " ";
            }
            out << "\n";
        }
        return out;
    }


}// namespace lab
#endif //APP_MATRIX_H

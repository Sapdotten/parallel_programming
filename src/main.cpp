#include <iostream>
#include <ctime>
#include "../include/matrix.h"
#include <string>
#include <filesystem>
#include <chrono>
#include <fstream>

#define CURRENT_TIME std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count()

using namespace lab;

void createDirectoryIfNotExists(const std::string& directory) {
    if (!std::filesystem::exists(directory)) {
        std::filesystem::create_directory(directory);
    }
}

void saveTestResults(const std::string& file_for_time, int n, long long int total_time, int test_count) {
    std::ofstream out(file_for_time, std::ios::app);
    if (out.is_open()) {
        out << n << ";" << total_time / static_cast<double>(test_count) << '\n';
    } else {
        std::cerr << "Error opening the file to write results" << std::endl;
    }
}

int main() {
    std::srand(0);
    std::cout << "Here will be first lab" << std::endl;

    std::string file_for_time = "../data/time_result.csv";
    std::string data_folder = "../data";
    std::string matrix_folder = "examples";

    createDirectoryIfNotExists(data_folder);
    createDirectoryIfNotExists(data_folder + "/" + matrix_folder);

    matrix_folder = data_folder + "/" + matrix_folder;
    int test_count = 10;

    for (int n = 100, test = 1; n <= 1000; n += 100, test++) {
        std::string test_folder = matrix_folder + "/test_" + std::to_string(test);
        std::filesystem::create_directory(test_folder);

        long long int sum = 0;
        std::cout <<"Test "<<n<<"-size matrix"<<std::endl;
        for (int i = 0; i < test_count; i++) {
            Matrix A(n, n, true);
            Matrix B(n, n, true);
            A.saveToFile(test_folder + "/A");
            B.saveToFile(test_folder + "/B");

            long long int start = CURRENT_TIME;
            Matrix C = A * B;
            long long end = CURRENT_TIME;

            C.saveToFile(test_folder + "/C");
            sum += (end - start);
        }

        saveTestResults(file_for_time, n, sum, test_count);
    }

    return 0;
}

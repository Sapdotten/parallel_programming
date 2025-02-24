#include <iostream>
#include <ctime>
#include "../include/matrix.h"
using namespace lab;

int main(){
    std::cout<<"Here will be first lab"<< std::endl;
    std::srand(time(0));
    Matrix text(4, 4, true);
    text.saveToFile("example.txt");
    Matrix check("example.txt");
    std::cout<<check;
    std::cout<<check(1, 3);
    return 0;
}
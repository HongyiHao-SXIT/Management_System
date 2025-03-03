#include <iostream>
#include <limits>
using namespace std;

int menu() {
    char choose;
    do {
        system("cls");
        std::cout << "******************************************************" << std::endl;
        std::cout << "------------------Welcome to Library------------------" << std::endl;
        std::cout << "    *          【1】Add a new book                 *    " << std::endl;
        std::cout << "    *          【2】Display all books              *    " << std::endl;
        std::cout << "    *          【3】Search for a book              *    " << std::endl;
        std::cout << "    *          【4】Borrow a book                  *    " << std::endl;
        std::cout << "    *          【5】Return a book                  *    " << std::endl;
        std::cout << "    *          【6】Delete a book                  *    " << std::endl;
        std::cout << "    *          【7】Modify book information        *    " << std::endl;
        std::cout << "    *          【8】Display borrowed books         *    " << std::endl;
        std::cout << "    *          【0】Exit the library system        *    " << std::endl;
        std::cout << "******************************************************" << std::endl;
        std::cout << "Please select your operation (0 - 8):" << std::endl;
        std::cin >> choose;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (choose < '0' || choose > '8');
    return (choose - '0');
}
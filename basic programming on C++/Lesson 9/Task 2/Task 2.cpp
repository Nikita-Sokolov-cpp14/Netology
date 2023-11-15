#include <iostream>
#include <string>

#include "headers/Figure.h"

#include "headers/Triangle.h"
#include "headers/Tetragone.h"

#include "headers/Right_trng.h"
#include "headers/Ravnobed_trng.h"
#include "headers/Ravnostor_trng.h"

#include "headers/Parallelogram.h"
#include "headers/Romb.h"
#include "headers/Rectangle.h"
#include "headers/Square.h"

#include "headers/Errors.h"

void print_info(Figure* figure) {
    figure->print_figure();
}

int main()
{
    setlocale(LC_ALL, "Russian");

    //неправильная фигура
    std::cout << "Фигура 1" << std::endl;
    try {
        Triangle simple_trng(10, 11, 12, 30, 185, 65);
        print_info(&simple_trng);
    }
    catch (creation_error& err) {
        std::cout << err.what() << std::endl;
    }

    //правильная фигура
    std::cout << "\nФигура 2" << std::endl;
    try {
        Triangle simple_trng(10, 11, 12, 30, 85, 65);
        print_info(&simple_trng);
    }
    catch (creation_error& err) {
        std::cout << err.what() << std::endl;
    }

    std::cout << "\nФигура 3" << std::endl;
    try {
        Right_trng r_trng(45, 40, 95, 3, 4, 5);
        print_info(&r_trng);
    }
    catch (creation_error& err) {
        std::cout << err.what() << std::endl;
    }

    std::cout << "\nФигура 4" << std::endl;
    try {
        Right_trng r_trng(45, 45, 90, 3, 4, 5);
        print_info(&r_trng);
    }
    catch (creation_error& err) {
        std::cout << err.what() << std::endl;
    }

    std::cout << "\nФигура 5" << std::endl;
    try {
        Ravnobed_trng ravobed_trng(40, 95, 45, 2, 5, 2);
        print_info(&ravobed_trng);
    }
    catch (creation_error& err) {
        std::cout << err.what() << std::endl;
    }

    std::cout << "\nФигура 6" << std::endl;
    try {
        Ravnobed_trng ravobed_trng(30, 120, 30, 2, 5, 2);
        print_info(&ravobed_trng);
    }
    catch (creation_error& err) {
        std::cout << err.what() << std::endl;
    }

    std::cout << "\nФигура 7" << std::endl;
    try {
        Ravnostor_trng ravnostor_trng(60, 60, 60, 2, 1, 2);
        print_info(&ravnostor_trng);
    }
    catch (creation_error& err) {
        std::cout << err.what() << std::endl;
    }

    std::cout << "\nФигура 8" << std::endl;
    try {
        Ravnostor_trng ravnostor_trng(60, 60, 60, 2, 2, 2);
        print_info(&ravnostor_trng);
    }
    catch (creation_error& err) {
        std::cout << err.what() << std::endl;
    }

    std::cout << "\nФигура 9" << std::endl;
    try {
        Tetragone simple_tetragone(20, 40, 60, 340, 1, 2, 3, 6);
        print_info(&simple_tetragone);
    }
    catch (creation_error& err) {
        std::cout << err.what() << std::endl;
    }

    std::cout << "\nФигура 10" << std::endl;
    try {
        Tetragone simple_tetragone(20, 40, 60, 240, 1, 2, 3, 6);
        print_info(&simple_tetragone);
    }
    catch (creation_error& err) {
        std::cout << err.what() << std::endl;
    }

    std::cout << "\nФигура 11" << std::endl;
    try {
        Parallelogram parallelogram(40, 140, 40, 140, 1, 2, 3, 6);
        print_info(&parallelogram);
    }
    catch (creation_error& err) {
        std::cout << err.what() << std::endl;
    }

    std::cout << "\nФигура 12" << std::endl;
    try {
        Parallelogram parallelogram(40, 140, 40, 140, 1, 2, 1, 2);
        print_info(&parallelogram);
    }
    catch (creation_error& err) {
        std::cout << err.what() << std::endl;
    }

    std::cout << "\nФигура 13" << std::endl;
    try {
        Romb romb(40, 140, 40, 140, 1, 2, 1, 2);
        print_info(&romb);
    }
    catch (creation_error& err) {
        std::cout << err.what() << std::endl;
    }

    std::cout << "\nФигура 14" << std::endl;
    try {
        Romb romb(40, 140, 40, 140, 2, 2, 2, 2);
        print_info(&romb);
    }
    catch (creation_error& err) {
        std::cout << err.what() << std::endl;
    }

    std::cout << "\nФигура 15" << std::endl;
    try {
        Rectangle rectangle(40, 140, 40, 140, 1, 2, 1, 2);
        print_info(&rectangle);
    }
    catch (creation_error& err) {
        std::cout << err.what() << std::endl;
    }

    std::cout << "\nФигура 16" << std::endl;
    try {
        Rectangle rectangle(90, 90, 90, 90, 1, 2, 1, 2);
        print_info(&rectangle);
    }
    catch (creation_error& err) {
        std::cout << err.what() << std::endl;
    }

    std::cout << "\nФигура 17" << std::endl;
    try {
        Square square(40, 140, 40, 140, 1, 2, 1, 2);
        print_info(&square);
    }
    catch (creation_error& err) {
        std::cout << err.what() << std::endl;
    }

    std::cout << "\nФигура 18" << std::endl;
    try {
        Square square(90, 90, 90, 90, 2, 2, 2, 2);
        print_info(&square);
    }
    catch (creation_error& err) {
        std::cout << err.what() << std::endl;
    }

    return 0;
}
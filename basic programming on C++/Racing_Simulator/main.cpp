#include <iostream>
#include <windows.h>

#include "Lib/Headers/Racing.h"

//������� �������� ����������, ���� ����� ���������������� � ��� ��� ���������������
void print_registr(bool flag, int* reg_arr, int number_drivers) {
    if (flag) {
        std::cout << "����������������: ";
        for (int i = 0; i < number_drivers; ++i) {
            switch (reg_arr[i]) {
            case 1: std::cout << "�������. "; break;
            case 2: std::cout << "�������-���������. "; break;
            case 3: std::cout << "������. "; break;
            case 4: std::cout << "�������-���������. "; break;
            case 5: std::cout << "�����-������. "; break;
            case 6: std::cout << "����. "; break;
            case 7: std::cout << "�����. "; break;
            }
        }
        std::cout << "\n";
    }
    std::cout << "1. �������." << std::endl;
    std::cout << "2. �������-���������." << std::endl;
    std::cout << "3. �������." << std::endl;
    std::cout << "4. �������-���������." << std::endl;
    std::cout << "5. �����-������." << std::endl;
    std::cout << "6. ����." << std::endl;
    std::cout << "7. �����." << std::endl;
    std::cout << "0. ��������� �����������." << std::endl;
}
void swap(Racing* left, Racing* right) {
    Racing buf;
    buf = *left;
    *left = *right;
    *right = buf;
}
void sort(Racing* racing, int num_drivers) { //��������� ��������� �����
    for (int i = 0; i < num_drivers - 1; ++i) {
        if (racing[i] > racing[i + 1]) {
            swap(&racing[i], &racing[i + 1]);
        }
    }
}

int set_distance() { //������� ��� ������� ��������� � ������ ��������� ������
    int dist;
    std::cout << "������� ����� ��������� (������ ���� �������������): ";
    std::cin >> dist;
    if (dist < 0) {
        throw std::invalid_argument("��������� ������ 0");
    }
    return dist;
}
int set_type_of_racing() {
    int type_of_racing;
    std::cout << "�������� ��� �����: ";
    std::cin >> type_of_racing;
    if (type_of_racing != 1 && type_of_racing != 2 && type_of_racing != 3) {
        throw std::invalid_argument("����������� ��� �����. ������� ������ ��������!");
    }
    return type_of_racing;
}
//� ���� ������� �������� �������� ��� �����������. ����� ����������� ������ ��� ����� ��������� ��������
int set_switcher(int* reg_arr,int number_drivers,int type, bool* err_flag) {
    int switcher;
    std::cin >> switcher;
    if (switcher <= 4 && switcher > 0 && type == 2) {
        throw std::invalid_argument("��� ��������� ����� ������ ���������������� �������� ��! �������� ������ �� ��� 0 ��� ��������� �����������: ");
    }
    if (switcher > 4 && switcher <= 7 && type == 1) {
        throw std::invalid_argument("��� �������� ����� ������ ���������������� ��������� ��! �������� ������ �� ��� 0 ��� ��������� �����������: ");
    }
    if (switcher > 7 || switcher < 0) {
        throw std::invalid_argument("�� ����� ����������� ��������! ������� �������� �� ���������� ������: ");
    }
    if (switcher == 0 && number_drivers == 1) {
        throw std::invalid_argument("�������� ��� ���� �� ���� ��: ");
    }
    for (int i = 0; i < number_drivers; ++i) {
        if (switcher == reg_arr[i]) {
            throw std::invalid_argument("2 ���������� �� �� �����������! �������� ������ ��: ");
        }
    }
    *err_flag = false; //��� ��������, ��� ������ ���
    return switcher;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int type_of_racing; //����������, � ������� ��������� ��������� ��� �����
    int distance; // ���������
    int number_drivers; // ���� ������������������ ����������
    short switcher; // ���������� ������ ��������� ��� ��������� �����������
    int* reg_arr = new int[7]; // ������, � ������� � ���������� ����� ��������� ������������������ ���������. 
    bool flag; // =1 ���� ��������������� ���� �� 1 ��������. ������������ � ������� print_registr
    bool err_flag; // �� ��������� = 1. ���������� = 0, ���� ��� ������ ��� ����������� ���������
    bool racing_flag; // �� ��������� = 1. ����� ������������, ���� ������������ �� ������� ��� ��������
    std::cout << "����� ���������� � �������� ���������!" << std::endl;
    racing_flag = 1;
    while (racing_flag) {
        for (int i = 0; i < 7; ++i) { reg_arr[i] = 0; } // ����� ��� ���� �������� ��������
        std::cout << "1. ����� ��� ��������� ����������.\n2. ����� ��� ���������� ����������" << std::endl;
        std::cout << "3. ����� ��� ��������� � ���������� ����������." << std::endl;
        try { type_of_racing = set_type_of_racing(); }
        catch (std::invalid_argument& err) { //�����������, ���� ������� ������� �������� ���� �����
            std::cout << err.what() << std::endl;
            type_of_racing = set_type_of_racing();
        }
        try {
            distance = set_distance();
        }
        catch (std::invalid_argument& err) { // �����������, ���� ������� ������������� ���������
            std::cout << err.what() << std::endl;
            distance = set_distance();
        }
        std::cout << "������ ���������� ���������������� ��. ���������� ������� 2 ���������" << std::endl;
        std::cout << "������� 1 ��� ������ �����������:";
        std::cin >> switcher;
        number_drivers = 0;
        flag = 0;
        while (switcher != 0) { // �� ���� �������� �������� ���� �����
            print_registr(flag, reg_arr, number_drivers);
            err_flag = true;
            while (err_flag) { // � ���� ����� ��� ���� � ����������� ������� ����������
                try {
                    switcher = set_switcher(reg_arr, number_drivers, type_of_racing, &err_flag);
                }
                catch (std::invalid_argument& err) {
                    std::cout << err.what();
                }
            }
            reg_arr[number_drivers] = switcher;
            if (switcher != 0) { number_drivers++; }
            flag = 1;
        }

        Racing* racing = new Racing[number_drivers]; //����� ������� ������� ���������� Racing, ������� ����������
        for (int i = 0; i < number_drivers; ++i) {
            racing[i].init(reg_arr[i], distance); // ���������������� ������ ����������, ��������������� �������, � ����� ��������� ����� ��� ������� ���������
        }
        sort(racing, number_drivers);

        std::cout << "\n��������� �����:" << std::endl;
        for (int i = 0; i < number_drivers; ++i) {
            std::cout << racing[i] << std::endl;
        }
        std::cout << "������� 1 ��� ���������� ����� ����� ��� 0 ��� ����������." << std::endl;
        std::cin >> racing_flag; //=true ���� ����� ������ ����� �����
        delete[] racing;
    }
    delete[] reg_arr;
    system("pause");
    return 0;
}

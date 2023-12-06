#include <iostream>
#include <windows.h>

#include "Lib/Headers/Racing.h"

//Функция печатает информацию, кого можно зарегестрировать и кто уже зарегестрирован
void print_registr(bool flag, int* reg_arr, int number_drivers) {
    if (flag) {
        std::cout << "Зарегестрированы: ";
        for (int i = 0; i < number_drivers; ++i) {
            switch (reg_arr[i]) {
            case 1: std::cout << "Верблюд. "; break;
            case 2: std::cout << "Верблюд-быстроход. "; break;
            case 3: std::cout << "Кнтавр. "; break;
            case 4: std::cout << "Ботинки-вездеходы. "; break;
            case 5: std::cout << "Ковер-самолёт. "; break;
            case 6: std::cout << "Орел. "; break;
            case 7: std::cout << "Метла. "; break;
            }
        }
        std::cout << "\n";
    }
    std::cout << "1. Верблюд." << std::endl;
    std::cout << "2. Верблюд-быстроход." << std::endl;
    std::cout << "3. Кентавр." << std::endl;
    std::cout << "4. Ботинки-вездеходы." << std::endl;
    std::cout << "5. Ковер-самолёт." << std::endl;
    std::cout << "6. Орел." << std::endl;
    std::cout << "7. Метла." << std::endl;
    std::cout << "0. Завершить регистрацию." << std::endl;
}
void swap(Racing* left, Racing* right) {
    Racing buf;
    buf = *left;
    *left = *right;
    *right = buf;
}
void sort(Racing* racing, int num_drivers) { //сортирует резултаты гонок
    for (int i = 0; i < num_drivers - 1; ++i) {
        if (racing[i] > racing[i + 1]) {
            swap(&racing[i], &racing[i + 1]);
        }
    }
}

int set_distance() { //Функция для задания дистанции с учетом возможной ошибки
    int dist;
    std::cout << "Укажите длину дистанции (должна быть положительной): ";
    std::cin >> dist;
    if (dist < 0) {
        throw std::invalid_argument("Дистанция меньше 0");
    }
    return dist;
}
int set_type_of_racing() {
    int type_of_racing;
    std::cout << "Выберите тип гонки: ";
    std::cin >> type_of_racing;
    if (type_of_racing != 1 && type_of_racing != 2 && type_of_racing != 3) {
        throw std::invalid_argument("Неизвестный тип гонки. Введите верное значение!");
    }
    return type_of_racing;
}
//в этой функции вводится значение для регистрации. Также формирубтся ошибки при вводе неверного значения
int set_switcher(int* reg_arr,int number_drivers,int type, bool* err_flag) {
    int switcher;
    std::cin >> switcher;
    if (switcher <= 4 && switcher > 0 && type == 2) {
        throw std::invalid_argument("Для воздушной гонки нельзя зарегестрировать наземное ТС! Выберите другое ТС или 0 для окончания регистрации: ");
    }
    if (switcher > 4 && switcher <= 7 && type == 1) {
        throw std::invalid_argument("Для наземной гонки нельзя зарегестрировать воздушное ТС! Выберите другое ТС или 0 для окончания регистрации: ");
    }
    if (switcher > 7 || switcher < 0) {
        throw std::invalid_argument("Вы ввели неизвестное значение! Введите значение из указанного списка: ");
    }
    if (switcher == 0 && number_drivers == 1) {
        throw std::invalid_argument("Выберите еще хотя бы одно ТС: ");
    }
    for (int i = 0; i < number_drivers; ++i) {
        if (switcher == reg_arr[i]) {
            throw std::invalid_argument("2 одинаковых ТС не допускается! Выберите другое ТС: ");
        }
    }
    *err_flag = false; //это означает, что ошибки нет
    return switcher;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    int type_of_racing; //переменная, в которой храниться выбранный тип гонки
    int distance; // дистанция
    int number_drivers; // чсло зарегестрированных участников
    short switcher; // переменная выбора участника или окончания регистрации
    int* reg_arr = new int[7]; // массив, в котором в дальнейшем будут храниться зарегистрированные участники. 
    bool flag; // =1 если зарегистрирован хотя бы 1 участник. Используется в функции print_registr
    bool err_flag; // по умолчанию = 1. Становится = 0, если нет ошибок при регистрации участника
    bool racing_flag; // По умолчанию = 1. Гонки продолжается, пока пользователь не обнулит это значение
    std::cout << "Добро пожаловать в гоночный симулятор!" << std::endl;
    racing_flag = 1;
    while (racing_flag) {
        for (int i = 0; i < 7; ++i) { reg_arr[i] = 0; } // чтобы нее было мусорных значений
        std::cout << "1. Гонка для наземного транспорта.\n2. Гонка для воздушного транспорта" << std::endl;
        std::cout << "3. Гонка для наземного и воздушного транспорта." << std::endl;
        try { type_of_racing = set_type_of_racing(); }
        catch (std::invalid_argument& err) { //выполняется, если указано неерное значение типа гонки
            std::cout << err.what() << std::endl;
            type_of_racing = set_type_of_racing();
        }
        try {
            distance = set_distance();
        }
        catch (std::invalid_argument& err) { // выполняется, если введена отрицательная дистанция
            std::cout << err.what() << std::endl;
            distance = set_distance();
        }
        std::cout << "Теперь необходимо зарегестрировать ТС. Необходимо минимум 2 участника" << std::endl;
        std::cout << "Введите 1 для начала регистрации:";
        std::cin >> switcher;
        number_drivers = 0;
        flag = 0;
        while (switcher != 0) { // за одну итерацию проходит одна гонка
            print_registr(flag, reg_arr, number_drivers);
            err_flag = true;
            while (err_flag) { // в этом цикле идёт ввод и запоминание номеров участников
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

        Racing* racing = new Racing[number_drivers]; //нужно создать столько переменных Racing, сколько участников
        for (int i = 0; i < number_drivers; ++i) {
            racing[i].init(reg_arr[i], distance); // инициализируются классы участников, соответствующих номерам, а также считается время для каждого участника
        }
        sort(racing, number_drivers);

        std::cout << "\nРезултаты гонки:" << std::endl;
        for (int i = 0; i < number_drivers; ++i) {
            std::cout << racing[i] << std::endl;
        }
        std::cout << "Введите 1 для проведения новой гонки или 0 для завершения." << std::endl;
        std::cin >> racing_flag; //=true если нужно начать новую гонку
        delete[] racing;
    }
    delete[] reg_arr;
    system("pause");
    return 0;
}

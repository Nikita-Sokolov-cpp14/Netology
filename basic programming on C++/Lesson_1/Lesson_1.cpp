// Lesson_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream file("in.txt");
    std::ofstream out_file("out.txt");
    int N, M;
    std::string kursor;

    file >> kursor;
    N = std::stoi(kursor);
    int* arr_1 = new int[N];
    for (int i = 0; i < N; ++i)
    {
        file >> kursor;
        arr_1[i] = std::stoi(kursor);
    }

    file >> kursor;
    M = std::stoi(kursor);
    int* arr_2 = new int[M];
    for (int i = 0; i < M; ++i)
    {
        file >> kursor;
        arr_2[i] = std::stoi(kursor);
    }



    kursor = std::to_string(M);
    out_file << kursor << "\n";
    for (int i = 0; i < M; ++i)
    {
        i == 0 ? kursor = std::to_string(arr_2[M - 1]) : kursor = std::to_string(arr_2[i - 1]);
        out_file << kursor << " ";
    }

    kursor = std::to_string(N);
    out_file << "\n" << kursor << "\n";
    for (int i = 0; i < N; ++i)
    {
        i == N - 1 ? kursor = std::to_string(arr_1[0]) : kursor = std::to_string(arr_1[i + 1]);
        out_file << kursor << " ";
    }

    std::cout << "\n Finished" << std::endl;

    delete[] arr_1;
    delete[] arr_2;
    return 0;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

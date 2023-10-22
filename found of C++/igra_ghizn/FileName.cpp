#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
//#include <unistd.h>


int cols;
int rows;

// выводит игровое поле, номер поколения и кол-во живых клеток и проверяет условие, есть ли живые клетки
bool get_status_of_game(char **matrix)
{
	static int gen = 0;
	int alive_cs = 0;
	bool is_alive = false;

	gen++;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			std::cout << matrix[i][j] << " ";

			if (matrix[i][j] == '*')
			{
				alive_cs++;
				is_alive = true;
			}
		}
		std::cout << "\n";
	}

	std::cout << "Generation " << gen << ". Alive cells " << alive_cs << "\n\n";
	
	// проверка условия, есть ли живые клетки (проверка 1 условия остановки игры)
	if (is_alive == true)
	{
		return true;
	}
	else
	{
		std::cout << "All cells are dead. Game over";
		return false;
	}
}


//функция, определяющая следующее состояние клетки с индексами i_cel, j_cel
void be_live(char** matrix, char** next_matrix, int i_cel, int j_cel)
{
	int alive = 0; //число живых соседей клетки


	// сканирование поля без учета границ
	if (i_cel != 0 && i_cel != rows - 1 && j_cel != 0 && j_cel != cols - 1)
	{
		for (int i = i_cel - 1; i <= i_cel + 1; ++i)
		{
			for (int j = j_cel - 1; j <= j_cel + 1; ++j)
			{
				if (matrix[i][j] == '*' && (i != i_cel || j != j_cel))
				{
					alive++;
				}
			}
		}
	}

	//сканирование верхней и нижней границы поля без учета углов
	else if ((i_cel == 0 || i_cel == rows - 1) && j_cel != 0 && j_cel != cols - 1)
	{
		for (int i = i_cel - i_cel / (rows - 1) ; i <= i_cel + 1 - i_cel / (rows - 1); ++i)
		{
			for (int j = j_cel - 1; j <= j_cel + 1; ++j)
			{
				if (matrix[i][j] == '*' && (i != i_cel || j != j_cel))
				{
					alive++;
				}
			}
		}
	}

	//сканирование левой и правой границы поля без учета углов
	else if ((j_cel == 0 || j_cel == cols - 1) && i_cel != 0 && i_cel != rows - 1)
	{
		for (int i = i_cel - 1; i <= i_cel + 1; ++i)
		{
			for (int j = j_cel - j_cel / (cols - 1); j <= j_cel + 1 - j_cel / (cols - 1); ++j)
			{
				if (matrix[i][j] == '*' && (i != i_cel || j != j_cel))
				{
					alive++;
				}
			}
		}
	}
	
	//проверка верхнего левого угла
	if (i_cel == 0 && j_cel == 0)
	{
		matrix[i_cel][j_cel + 1] == '*' ? alive++ : 0;
		matrix[i_cel + 1][j_cel] == '*' ? alive++ : 0;
		matrix[i_cel + 1][j_cel + 1] == '*' ? alive++ : 0;
	}
	//проверка верхнего правого угла
	if (i_cel == 0 && j_cel == cols - 1)
	{
		matrix[i_cel][j_cel - 1] == '*' ? alive++ : 0;
		matrix[i_cel + 1][j_cel - 1] == '*' ? alive++ : 0;
		matrix[i_cel + 1][j_cel] == '*' ? alive++ : 0;
	}
	//проверка нижнего левого угла
	if (i_cel == rows - 1 && j_cel == 0)
	{
		matrix[i_cel - 1][j_cel] == '*' ? alive++ : 0;
		matrix[i_cel - 1][j_cel + 1] == '*' ? alive++ : 0;
		matrix[i_cel][j_cel + 1] == '*' ? alive++ : 0;
	}
	//проверка нижнего правого угла
	if (i_cel == rows - 1 && j_cel == cols - 1)
	{
		matrix[i_cel][j_cel - 1] == '*' ? alive++ : 0;
		matrix[i_cel - 1][j_cel - 1] == '*' ? alive++ : 0;
		matrix[i_cel - 1][j_cel] == '*' ? alive++ : 0;
	}

	//условие зарождения жизни
	if (alive == 3 && matrix[i_cel][j_cel] == '-')
	{
		next_matrix[i_cel][j_cel] = '*'; 
	}
	//условие сохранения жизни
	else if ((alive == 2 || alive == 3) && matrix[i_cel][j_cel] == '*')
	{
		next_matrix[i_cel][j_cel] = '*';
	}
	//в остальных случаях клетка умирает
	else
	{
		next_matrix[i_cel][j_cel] = '-';
	}
}

int main()
{
	std::ifstream init_file("in.txt"); //файл начального состояния игры
	if (!init_file.is_open())
	{
		std::cout << "Error. Init file not found";
		return 1;
	}
	int i_alive, j_alive; //строка и столбец живой клетки
	std::string kursor;
	int flag = 1; // используется при проверке 2 условия остановки игры (изменилось ли поле)


	init_file >> kursor;
	rows = std::stoi(kursor);
	init_file >> kursor;
	cols = std::stoi(kursor);

	char** matrix = new char* [rows]; //матрица, в которой хранится текущее состояние игры
	for (int i = 0; i < rows; ++i)
	{
		matrix[i] = new char[cols];
	}
	
	// начальное заполнение матрицы символом -
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			matrix[i][j] = '-';
		}
	}

	char** next_matrix = new char* [rows]; // матрица следующего состояния игры
	for (int i = 0; i < rows; ++i)
	{
		next_matrix[i] = new char[cols];
	}

	//ввод из файла живых клеток
	while (init_file >> kursor)
	{
		i_alive = std::stoi(kursor);
		init_file >> kursor;
		j_alive = std::stoi(kursor);
		matrix[i_alive][j_alive] = '*';
	}
	init_file.close();

	//копирование
	for (int i = 0; i < rows; ++i)
	{
		for(int j = 0; j < cols; ++j)
		{
			next_matrix[i][j] = matrix[i][j];
		}
	}
	

	while (get_status_of_game(matrix)) //пока есть живые клетки + вывод текущего состояния игры
	{
		std::cout << std::system("clear");
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{				
				be_live(matrix, next_matrix, i, j); //определение следующего состояния клетки с индексами i, j 

				//провекра условия - хотя бы одна клетка изменило своё состояние? Это проверка 2 условия остановки игры
				if (next_matrix[i][j] != matrix[i][j])
				{
					flag = 0;
				}
			}
		}

		//если ни одна из клеток не поменяла состояние, то игра заканчивается
		if (flag)
		{
			get_status_of_game(matrix); //вывод конечного состояния при остановке игры по 2 условию
			std::cout << "The world has stagnated. Game ower\n";
			break; // выход из основного цикла while и завершение игры
		}

		flag = 1; 

		//копирование
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				matrix[i][j] = next_matrix[i][j];
			}
		}
	}

	//очистка памяти
	for (int i = 0; i < rows; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;

	for (int i = 0; i < rows; ++i)
	{
		delete[] next_matrix[i];
	}
	delete[] next_matrix;

	return 0;
}
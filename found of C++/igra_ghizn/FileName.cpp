#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
//#include <unistd.h>


int cols;
int rows;

// ������� ������� ����, ����� ��������� � ���-�� ����� ������ � ��������� �������, ���� �� ����� ������
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
	
	// �������� �������, ���� �� ����� ������ (�������� 1 ������� ��������� ����)
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


//�������, ������������ ��������� ��������� ������ � ��������� i_cel, j_cel
void be_live(char** matrix, char** next_matrix, int i_cel, int j_cel)
{
	int alive = 0; //����� ����� ������� ������


	// ������������ ���� ��� ����� ������
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

	//������������ ������� � ������ ������� ���� ��� ����� �����
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

	//������������ ����� � ������ ������� ���� ��� ����� �����
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
	
	//�������� �������� ������ ����
	if (i_cel == 0 && j_cel == 0)
	{
		matrix[i_cel][j_cel + 1] == '*' ? alive++ : 0;
		matrix[i_cel + 1][j_cel] == '*' ? alive++ : 0;
		matrix[i_cel + 1][j_cel + 1] == '*' ? alive++ : 0;
	}
	//�������� �������� ������� ����
	if (i_cel == 0 && j_cel == cols - 1)
	{
		matrix[i_cel][j_cel - 1] == '*' ? alive++ : 0;
		matrix[i_cel + 1][j_cel - 1] == '*' ? alive++ : 0;
		matrix[i_cel + 1][j_cel] == '*' ? alive++ : 0;
	}
	//�������� ������� ������ ����
	if (i_cel == rows - 1 && j_cel == 0)
	{
		matrix[i_cel - 1][j_cel] == '*' ? alive++ : 0;
		matrix[i_cel - 1][j_cel + 1] == '*' ? alive++ : 0;
		matrix[i_cel][j_cel + 1] == '*' ? alive++ : 0;
	}
	//�������� ������� ������� ����
	if (i_cel == rows - 1 && j_cel == cols - 1)
	{
		matrix[i_cel][j_cel - 1] == '*' ? alive++ : 0;
		matrix[i_cel - 1][j_cel - 1] == '*' ? alive++ : 0;
		matrix[i_cel - 1][j_cel] == '*' ? alive++ : 0;
	}

	//������� ���������� �����
	if (alive == 3 && matrix[i_cel][j_cel] == '-')
	{
		next_matrix[i_cel][j_cel] = '*'; 
	}
	//������� ���������� �����
	else if ((alive == 2 || alive == 3) && matrix[i_cel][j_cel] == '*')
	{
		next_matrix[i_cel][j_cel] = '*';
	}
	//� ��������� ������� ������ �������
	else
	{
		next_matrix[i_cel][j_cel] = '-';
	}
}

int main()
{
	std::ifstream init_file("in.txt"); //���� ���������� ��������� ����
	if (!init_file.is_open())
	{
		std::cout << "Error. Init file not found";
		return 1;
	}
	int i_alive, j_alive; //������ � ������� ����� ������
	std::string kursor;
	int flag = 1; // ������������ ��� �������� 2 ������� ��������� ���� (���������� �� ����)


	init_file >> kursor;
	rows = std::stoi(kursor);
	init_file >> kursor;
	cols = std::stoi(kursor);

	char** matrix = new char* [rows]; //�������, � ������� �������� ������� ��������� ����
	for (int i = 0; i < rows; ++i)
	{
		matrix[i] = new char[cols];
	}
	
	// ��������� ���������� ������� �������� -
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			matrix[i][j] = '-';
		}
	}

	char** next_matrix = new char* [rows]; // ������� ���������� ��������� ����
	for (int i = 0; i < rows; ++i)
	{
		next_matrix[i] = new char[cols];
	}

	//���� �� ����� ����� ������
	while (init_file >> kursor)
	{
		i_alive = std::stoi(kursor);
		init_file >> kursor;
		j_alive = std::stoi(kursor);
		matrix[i_alive][j_alive] = '*';
	}
	init_file.close();

	//�����������
	for (int i = 0; i < rows; ++i)
	{
		for(int j = 0; j < cols; ++j)
		{
			next_matrix[i][j] = matrix[i][j];
		}
	}
	

	while (get_status_of_game(matrix)) //���� ���� ����� ������ + ����� �������� ��������� ����
	{
		std::cout << std::system("clear");
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{				
				be_live(matrix, next_matrix, i, j); //����������� ���������� ��������� ������ � ��������� i, j 

				//�������� ������� - ���� �� ���� ������ �������� ��� ���������? ��� �������� 2 ������� ��������� ����
				if (next_matrix[i][j] != matrix[i][j])
				{
					flag = 0;
				}
			}
		}

		//���� �� ���� �� ������ �� �������� ���������, �� ���� �������������
		if (flag)
		{
			get_status_of_game(matrix); //����� ��������� ��������� ��� ��������� ���� �� 2 �������
			std::cout << "The world has stagnated. Game ower\n";
			break; // ����� �� ��������� ����� while � ���������� ����
		}

		flag = 1; 

		//�����������
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				matrix[i][j] = next_matrix[i][j];
			}
		}
	}

	//������� ������
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
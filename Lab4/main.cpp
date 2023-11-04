#include"Header.h"

int main() {

	bool flag = true;
	bool subflag = true;
	bool answer_direction;
	bool answer_multify;
	int answer_direction_checker = 0;
	int answer_multify_checker = 0;
	int general_choise;
	int sub_choise;
	int size;
	std::vector<std::vector<int>> matrix;
	std::vector<std::vector<int>> matrix_res;
	std::vector<edge> edges;

	while (flag)
	{

		std::cout << "\nMenu:\n0.Set matrix\n1.Set direction\n2.Set multification\n3.Calculate incidence matrix\n4.Print starting matrix\n5.Print result matrix\n6.End program" << std::endl;

		std::cout << "\nEnter choise: ";
		std::cin >> general_choise;

		switch (general_choise)
		{
		case(0):

			if (answer_direction_checker == 0) { std::cout << "\nEnter is matrix directed firstly!" << std::endl; break; }
			if (answer_multify_checker == 0) { std::cout << "\nEnter is matrix multified firstly!" << std::endl; break;}

			do {
				std::cout << "\nEnter size of matrix: ";
				std::cin >> size;
			} while (size < 1);

			matrix = matrix_creator(size, "\nEnter matrix:", answer_direction, answer_multify);

			break;

		case(1):

			while (subflag)
			{
				std::cout << "\nDirection menu:\n1.Directed\n2.Undirected\n3.Exit submenu" << std::endl;

				std::cout << "\nEnter choise: ";
				std::cin >> sub_choise;

				switch (sub_choise)
				{
				case(1):

					answer_direction_checker = 1;
					answer_direction = true;

					break;

				case(2):

					answer_direction_checker = 1;
					answer_direction = false;

					break;

				case(3):

					subflag = false;

					break;

				default:

					std::cout << "\nEnter correct choise!" << std::endl;

					break;
				}


			}

			subflag = true;

			break;

		case(2):

			while (subflag)
			{
				std::cout << "\nMultification menu:\n1.Multified\n2.Unmultified\n3.Exit submenu" << std::endl;

				std::cout << "\nEnter choise: ";
				std::cin >> sub_choise;

				switch (sub_choise)
				{
				case(1):

					answer_multify_checker = 1;
					answer_multify = true;

					break;

				case(2):

					answer_multify_checker = 1;
					answer_multify = false;

					break;

				case(3):

					subflag = false;

					break;

				default:

					std::cout << "\nEnter correct choise!" << std::endl;

					break;
				}


			}

			subflag = true;

			break;

		case(3):

			if (answer_direction_checker == 0) { std::cout << "\nEnter is matrix directed firstly!" << std::endl; break; }
			else if (matrix.empty()) { std::cout << "\nEnter matrix firstly!" << std::endl; break; }

			matrix_res = incidence_matrix_creator(matrix, edge_matrix(matrix, answer_direction), answer_direction);

			break;

		case(4):
			
			print_matrix(matrix, "\nStarting matrix:");

			break;

		case(5):

			print_matrix(matrix_res, "\nResult matrix:");

			break;

		case(6):

			flag = false;

			break;

		default:

			std::cout << "\nEnter correct choise!" << std::endl;

			break;
		}

	}

	std::cout << "\nEnd of program!";

	return 0;
}


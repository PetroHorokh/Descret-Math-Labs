#include"Header.h"

bool matrix_format_checker_is_not_directed(std::vector<std::vector<int>> matrix) {

	for (int i = 0; i < matrix.size() - 1; i++) {
		for (int j = i+1; j < matrix.size(); j++) {
			if (matrix[i][j] != matrix[j][i]) { std::cout << "Enter matrix correctly!" << std::endl; return false; }
		}
	}

	return true;
}

bool matrix_format_checker_is_not_multified(std::vector<std::vector<int>> matrix) {

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix.size(); j++) {
			if (matrix[i][j] > 1 || matrix[i][j] < 0) { std::cout << "Enter matrix correctly!" << std::endl; return false; }
		}
	}

	return true;

}

bool matrix_format_checker_is_not_pseudograph(std::vector<std::vector<int>> matrix) {
	for (int i = 0; i < matrix.size(); i++) {
		if (matrix[i][i] != 0) { std::cout << "Enter matrix correctly!" << std::endl; return false; }
	}
	return true;
}

std::vector<std::vector<int>> matrix_creator(int n, std::string msg, bool flag1, bool flag2) {

	std::vector<std::vector<int>> matrix_res;

	if (!flag1 && !flag2) {

		do {
			matrix_res.clear();

			std::cout << msg << std::endl;

			matrix_res = std::vector<std::vector<int>>(n);

			for (int i = 0; i < n; i++) {
				matrix_res[i] = std::vector<int>(n);
				for (int j = 0; j < n; j++) {
					std::cin >> matrix_res[i][j];
				}
			}
		} while (!matrix_format_checker_is_not_directed(matrix_res) || !matrix_format_checker_is_not_multified(matrix_res) || !matrix_format_checker_is_not_pseudograph(matrix_res));
	}
	else if (flag1 && !flag2) {

		do {
			matrix_res.clear();

			std::cout << msg << std::endl;

			matrix_res = std::vector<std::vector<int>>(n);

			for (int i = 0; i < n; i++) {
				matrix_res[i] = std::vector<int>(n);
				for (int j = 0; j < n; j++) {
					std::cin >> matrix_res[i][j];
				}
			}
		} while (!matrix_format_checker_is_not_multified(matrix_res) || !matrix_format_checker_is_not_pseudograph(matrix_res));
	}
	else if (!flag1 && flag2) {

		do {
			matrix_res.clear();

			std::cout << msg << std::endl;

			matrix_res = std::vector<std::vector<int>>(n);

			for (int i = 0; i < n; i++) {
				matrix_res[i] = std::vector<int>(n);
				for (int j = 0; j < n; j++) {
					std::cin >> matrix_res[i][j];
				}
			}
		} while (!matrix_format_checker_is_not_directed(matrix_res) || !matrix_format_checker_is_not_pseudograph(matrix_res));
	}
	else if (flag1 && flag2) {
		do {
			matrix_res.clear();

			std::cout << msg << std::endl;

			matrix_res = std::vector<std::vector<int>>(n);

			for (int i = 0; i < n; i++) {
				matrix_res[i] = std::vector<int>(n);
				for (int j = 0; j < n; j++) {
					std::cin >> matrix_res[i][j];
				}
			}
		} while (!matrix_format_checker_is_not_pseudograph(matrix_res));
	}

	return matrix_res;
}

void print_matrix(std::vector<std::vector<int>> matrix, std::string msg) {

	std::cout << msg << std::endl;

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
}

std::vector<edge> edge_matrix(std::vector<std::vector<int>> matrix, bool flag) {

	std::vector<edge> matrix_res;

	if (flag) {
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix.size(); j++) {
				if (matrix[i][j] != 0)
				{
					matrix_res.push_back(edge(i, j, matrix[i][j]));
				}
			}
		}
	}
	else {
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = i; j < matrix.size(); j++) {
				if (matrix[i][j] != 0)
				{
					matrix_res.push_back(edge(i, j, matrix[i][j]));
				}
			}
		}
	}
	

	return matrix_res;

}

int amount_of_edges(std::vector<edge> matrix) {

	int amount = 0;

	for (const auto elem : matrix) {
		amount += elem.amount_of_edges;
	}

	return amount;

}

std::vector<std::vector<int>> incidence_matrix_creator(std::vector<std::vector<int>> adjacency_matrix, std::vector<edge> edges, bool flag) {

	std::vector<std::vector<int>> matrix_res;

	matrix_res = std::vector<std::vector<int>>(adjacency_matrix.size());
	int total_amount_of_edges;

	if (flag) {
		total_amount_of_edges = amount_of_edges(edges);

		for (int i = 0; i < adjacency_matrix.size(); i++) {
			matrix_res[i] = std::vector<int>(total_amount_of_edges);
			for (int j = 0, n = 0; j < edges.size(); j++) {
					if (edges[j].from_node == i && edges[j].to_node == i) { for (int m = 0; m < edges[j].amount_of_edges; m++, n++) { matrix_res[i][n] = 2; } }
					else if (edges[j].from_node == i) { for (int m = 0; m < edges[j].amount_of_edges; m++, n++) { matrix_res[i][n] = 1; } }
					else if (edges[j].to_node == i) { for (int m = 0; m < edges[j].amount_of_edges; m++, n++) { matrix_res[i][n] = -1; } }
					else { n += edges[j].amount_of_edges; }
			}
		}
	}
	else{
		total_amount_of_edges = edges.size();

		for (int i = 0; i < adjacency_matrix.size(); i++) {
			matrix_res[i] = std::vector<int>(total_amount_of_edges);
			for (int j = 0; j < total_amount_of_edges; j++) {
				if (edges[j].from_node == i && edges[j].to_node == i) { matrix_res[i][j] = 2; }
				else if (edges[j].from_node == i || edges[j].to_node == i) { matrix_res[i][j] = 1; }
			}
		}
	}

	return matrix_res;

}
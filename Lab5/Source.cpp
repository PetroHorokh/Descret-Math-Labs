#include"Header.h"

std::vector<std::vector<int>> matrix_creator(int n, std::string msg) {

	std::vector<std::vector<int>> matrix_res;

	do {

		matrix_res.clear();

		std::cout << msg << std::endl;

		matrix_res = std::vector<std::vector<int>>(n);

		for (int i = 0; i < n; i++) {
			matrix_res[i] = std::vector<int>(n);
			for (int j = 0; j < n; j++) {
				int node;
				std::cin >> node;
				matrix_res[i][j] = node;
			}
		}

	} while (!format_checker(matrix_res));

	return matrix_res;
}

void print_matrix(std::vector<std::vector<int>> matrix, std::string msg) {
	std::cout << std::endl;
	std::cout << msg << std::endl;

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix[i].size(); j++) {
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << std::endl;
	}

	std::cout << std::endl;
}

bool format_checker(std::vector<std::vector<int>> matrix) {

	for (int i = 0; i < matrix.size(); i++) {
		if (matrix[i][0] != 0) return false;
		if (matrix[matrix.size()-1][i] != 0) return false;
		for (int j = 0; j < matrix.size(); j++) {
			if (matrix[i][j] < 0 || matrix[i][j] > 1) return false;
		}
	}

	return true;
}

graph graph_creator(std::vector<std::vector<int>> matrix)
{
	graph result;
	int weight;

	for (int i = 0; i < matrix.size(); i++) {
		for (int j = 0; j < matrix.size(); j++) {
			if (matrix[i][j] == 1) {
				do {
					std::cout << "Enter weight of edge " << 1+i << "-" << 1+j << " : ";
					std::cin >> weight;
				} while (weight < 1);
				result.edges.push_back(new edge(i, j, weight));
			}
		}
	}
	return result;
}

void graph_printer(graph graph_to_print) {

	std::cout << std::endl;

	for (auto elem : graph_to_print.edges) {
		std::cout << 1+elem->from_node << "-" << 1+elem->to_node << " weight: " << elem->weight << "; curent: " << elem->curent << std::endl;
	}
}

void stepA(graph start_graph, Path path_from_to, std::vector<int> visited, int n, int from_node)
{
	if (from_node == n - 1) {

		int min_weight = path_from_to.path[0]->weight - path_from_to.path[0]->curent;

		for (auto path_elem : path_from_to.path) {
			if (min_weight > (path_elem->weight - path_elem->curent)) min_weight = path_elem->weight - path_elem->curent;
		}

		for (auto path_elem : path_from_to.path) {
			path_elem->curent += min_weight;
		}

	}
	else {

		graph accesable_edges;

		for (auto path_elem : start_graph.edges) {
			if (path_elem->from_node == from_node && !(std::find(visited.begin(), visited.end(), path_elem->to_node) != visited.end()) && path_elem->weight != path_elem->curent)
			{
				accesable_edges.edges.push_back(path_elem);
			}
		}

		for (auto path_elem : accesable_edges.edges) {

			path_from_to.path.push_back(path_elem);
			visited.push_back(path_elem->to_node);

			stepA(start_graph, path_from_to, visited, n, path_elem->to_node);

			path_from_to.path.pop_back();
			visited.pop_back();
		}

	}
}

void stepB(graph start_graph, Path path, Path path_oposite, std::vector<int> visited, int n, int from_node) {

	if (from_node == n - 1) {

		int min_weight = path.path[0]->weight - path.path[0]->curent;

		for (auto path_elem : path.path) {
			if (min_weight > (path_elem->weight - path_elem->curent)) min_weight = path_elem->weight - path_elem->curent;
		}
		for (auto path_elem : path_oposite.path) {
			if (min_weight > path_elem->curent) min_weight = path_elem->curent;
		}
		for (auto path_elem : path.path) {
			path_elem->curent += min_weight;
		}
		for (auto path_elem : path_oposite.path) {
			path_elem->curent -= min_weight;
		}
	}
	else 
	{
		for (auto elem : start_graph.edges) {
			if (elem->from_node == from_node && elem->weight != elem->curent && !(std::find(visited.begin(), visited.end(), elem->to_node) != visited.end())) 
			{
				path.path.push_back(elem);
				visited.push_back(elem->to_node);

				stepB(start_graph, path, path_oposite, visited, n, elem->to_node);

				visited.pop_back();
				path.path.pop_back();
			}
			else if (elem->to_node == from_node && elem->curent > 0 && !(std::find(visited.begin(), visited.end(), elem->from_node) != visited.end()))
			{
				path_oposite.path.push_back(elem);
				visited.push_back(elem->from_node);

				stepB(start_graph, path, path_oposite, visited, n, elem->from_node);

				visited.pop_back();
				path_oposite.path.pop_back();
			}
		}
	}
}

void print_saturation(graph graph_to_print, int flow) {

	std::cout << std::endl;

	int start = 0, end = 0;
	for (auto elem : graph_to_print.edges) {
		//std::cout << 1 + elem->from_node << "-" << 1 + elem->to_node << " weight: " << elem->weight << "; curent: " << elem->curent << std::endl;
		if (elem->from_node == 0) {
			start += elem->curent;
		}
		else if (elem->to_node == flow) {
			end += elem->curent;
		}
	}
	std::cout << "Start is " << start << " and end is " << end << std::endl;
}
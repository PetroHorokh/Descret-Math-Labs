#include"Header.h"

int main() {

	int n;

	do {

		std::cout << "Enter amount of nodes in graph: ";
		std::cin >> n;

	} while (n < 1);

	std::vector<std::vector<int>> matrix = matrix_creator(n, "Enter matrix for graph:");

	graph res_graph = graph_creator(matrix);

	graph_printer(res_graph);

	Path new_path;
	std::vector<int> visited;

	visited.push_back(0);

	stepA(res_graph, new_path, visited, n, 0);

	graph_printer(res_graph);

	Path path;
	Path path_oposite;

	stepB(res_graph, path, path_oposite, visited, n, 0);

	graph_printer(res_graph);

	print_saturation(res_graph, n-1);

	std::cout << "End of program!";

	return 0;
}
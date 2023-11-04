struct edge
{
	int from_node;
	int to_node;
	int curent;
	int weight;

	edge(int _from_node, int _to_node, int _weight) { from_node = _from_node; to_node = _to_node; weight = _weight; curent = 0; }
};

struct graph
{
	std::vector<edge*> edges;
};

struct Path
{
	std::vector<edge*> path;
};

//
//struct path
//{
//	std::vector<path_node> path;
//	std::vector<path_node> reverse_path;
//
//	int min_curent;
//
//	void fint_min() {
//
//		min_curent = *path.front().curent;
//
//		for (const auto node : path) {
//			if (*node.curent < min_curent) min_curent = *node.curent;
//		}
//		for (const auto node : reverse_path) {
//			if (*node.curent < min_curent) min_curent = *node.curent;
//		}
//	}
//
//	void substract_min(std::vector<std::vector<int>>& matrix) {
//		for (auto& node : path) {
//			matrix[node.from_node][node.to_node] -= min_curent;
//		}
//		for (auto& node : reverse_path) {
//			matrix[node.from_node][node.to_node] += min_curent;
//		}
//	}
//};
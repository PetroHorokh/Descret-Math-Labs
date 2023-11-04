#pragma once
#include<iostream>
#include<vector>
#include<string>

struct edge
{
	int from_node;
	int to_node;
	int amount_of_edges;

	edge() { from_node = 0; to_node = 0; amount_of_edges = 0; }
	edge(int _from_node, int _to_node, int _amount_of_edges){ from_node = _from_node; to_node = _to_node; amount_of_edges = _amount_of_edges; }
};

std::vector<std::vector<int>> matrix_creator(int, std::string, bool, bool);
void print_matrix(std::vector<std::vector<int>>, std::string);
std::vector<edge> edge_matrix(std::vector<std::vector<int>>,bool);
int amount_of_edges(std::vector<edge>);
std::vector<std::vector<int>> incidence_matrix_creator(std::vector<std::vector<int>>, std::vector<edge>, bool);

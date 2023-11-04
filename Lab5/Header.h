#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "Struct.h"

std::vector<std::vector<int>> matrix_creator(int, std::string);
bool format_checker(std::vector<std::vector<int>>);
graph graph_creator(std::vector<std::vector<int>>);
void graph_printer(graph);
void stepA(graph, Path, std::vector<int>, int, int);
void stepB(graph, Path, Path, std::vector<int>, int, int);
void print_saturation(graph, int);
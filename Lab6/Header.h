#pragma once

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

bool is_number(string);
string enter_number(string);
vector<char> convert_string_to_vector(string);
void delete_repeats(vector<char>&);
bool is_binary(vector<char>&);
bool is_hexidecimal(vector<char>&);
vector<char> generate_notation(int);
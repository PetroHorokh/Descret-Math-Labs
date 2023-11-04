#include"Header.h"

string Enter_function(string msg) {
	
	string function_in_line;

	do {
		cout << msg;
		getline(cin,function_in_line);
	} while (!function_checker(function_in_line));

	return function_in_line;
}

bool function_checker(string function) {

	if (log2(function.size()) != (int)log2(function.size())) {
		return false;
	}

	for (auto elem : function) {
		if (elem > '1' || elem < '0') {
			return false;
		}
	}

	return true;

}

vector<string> zero_constituents(string function) {
	
	vector<string>zero_constituents;

	int size = log2(function.size());

	for (int i = 0; i < function.size(); i++) {
		if (function[i] == '0') {
			zero_constituents.push_back(constituent(i, size));
		}
	}

	return zero_constituents;
}

string constituent(int num, int size) {

	string n = string(size, '0');
	
	int i = 0;
	while (num != 0){
		n[i] = (char)(num % 2 + 48);
		num /= 2;
		i++;
	}

	reverse(n.begin(), n.end());

	return n;
}

void print_constituents(string msg,vector<string> constituents) {

	cout << msg << endl;

	for (auto elem : constituents) {
		for (int i = 0; i < elem.size(); i++) {
			if (elem[i] == '0' && i != elem.size()-1) {
				cout << "x" << i << " v ";
			}
			else if (elem[i] == '1' && i != elem.size() - 1) {
				cout << "x'" << i << " v ";
			}
			else if (elem[i] == '0' && i == elem.size() - 1) {
				cout << "x" << i;
			}
			else if (elem[i] == '1' && i == elem.size() - 1) {
				cout << "x'" << i;
			}
		}
		cout << endl;
	}

}
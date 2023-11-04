#include "Header.h"

bool is_number(string line) {
	if (line[0] == '0') {
		cout << "There is no number starting with 0!" << endl;
		return true;
	}

	for (auto elem : line) {
		if (isdigit(elem) || isalpha(elem)) {}
		else
		{
			cout << "Not correct grammatic!" << endl;
			return true;
		}
	}

	return false;
}

string enter_number(string msg) {

	string number;

	do {
		cout << msg;
		getline(cin, number);
	} while (is_number(number));

	return number;
}

vector<char> convert_string_to_vector(string line) {

	vector<char> vec;

	for (auto elem : line) {
		vec.push_back(elem);
	}

	sort(vec.begin(), vec.end());

	return vec;
}

void delete_repeats(vector<char>& vec) {
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
}

bool is_binary(vector<char>& vec) {

	vector<char> basis = generate_notation(2);

	if (vec.back() == 'b' || vec.back() == 'B') {
		vec.pop_back();
	}

	for (auto elem : vec) {
		if (find(basis.begin(), basis.end(), elem) == basis.end())
		{
			return false;
		}
	}

	return true;
}
bool is_hexidecimal(vector<char>& vec) {

	vector<char> basis = generate_notation(16);

	if (vec.back() == 'h' || vec.back() == 'H') {
		vec.pop_back();
	}

	for (auto elem : vec) {
		if (find(basis.begin(), basis.end(), elem) == basis.end())
		{
			return false;
		}
	}

	return true;
}

vector<char> generate_notation(int i) {

	vector<char> base;

	if (i > 62) {
		cout << "Notation with base " << i << " cannot be created, due to the lack of letters and digits in english alphabet!" << endl;
		return base;
	}

	for (char digit = '0'; digit < (char)(48 + ((i < 10) ? i : 10)); digit++) {
		base.push_back(digit);
	}

	i -= (i < 10) ? i : 10;

	for (int j = 0; j < i; j++) {
		base.push_back((char)('A' + j));
		base.push_back((char)('a' + j));
	}

	return base;
}
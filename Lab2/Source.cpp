#include<iostream>
#include<string>
#include<vector>

std::vector<std::string> permutation(std::string, int, int, int);

int main() {

	int bound;

	std::cout << "Warning! Bounds higher that 6 will show drastic lowering in speed due to program's complexity equals n! + o(n) (n - amount of elements)" << std::endl;

	do
	{
		std::cout << "Enter upper bound: ";
		std::cin >> bound;
	} while (bound < 0);

	std::vector<std::string> vec = permutation("", 0, 0, bound);

	int lim;

	do
	{
		std::cout << "Enter how much elemtns are you willing to print( if amount of permutations is smaller than entered number, than all permutations will be printed): ";
		std::cin >> lim;
	} while (lim < 0);

	for (int i = 0; i < vec.size() && i <= lim; i++) {
		std::cout << vec[i] << std::endl;
	}
}

std::vector<std::string> permutation(std::string str, int dig, int pos, int bound) {

	if (dig == bound) {
		if (str[0] != '0') {
			str.insert(pos, std::to_string(dig));
			std::vector<std::string> vec;

			vec.push_back(str);

			return vec;
		}
		
	}
	else {
		str.insert(pos, std::to_string(dig));

		std::vector<std::string> vec = {};

		for (int i = 0; i <= dig + 1; i++) {

			std::vector<std::string> vec_tmp = permutation(str, dig + 1, i, bound);

			vec.insert(vec.end(), vec_tmp.begin(), vec_tmp.end());
		}
		return vec;
	}

}
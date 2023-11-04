#include"Header.h"

int main()
{
	vector<char> number_in_vector = convert_string_to_vector(enter_number("Enter number to check: "));

	delete_repeats(number_in_vector);

	if (is_binary(number_in_vector)) {
		cout << "The number is binary in current grammatic!" << endl;
	}
	else if (is_hexidecimal(number_in_vector)) {
		cout << "The number is hexidecimal in current grammatic!" << endl;
	}
	else {
		cout << "The number is not of the current grammatic!" << endl;
	}

	cout << "End of program!";

	return 0;
}
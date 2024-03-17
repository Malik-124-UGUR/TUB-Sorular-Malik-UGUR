#include <iostream>
#include <fstream>	// Library of the file.
#include <string>
using namespace std;

// char to int ascii conversion..
int getAscii(char part_string) {
	return static_cast<int>(part_string);
}

// int to char ascii conversion..
char getSign(int part_int) {
	return static_cast<char>(part_int);
}

int main() {
	string row;
	char row_temp[] = "";
	int get_ascii;
	int crt_index;

	// Create dynamic array.
	int* array_shap = new int[93]();
	int max_value = 0;		// Was used for comparison.
	int ascii_value;

	// Open the file using the file location.
	ifstream file_100("Enter The File Location..");  // Please enter the file location.. !! IMPORTANT

	if (file_100.is_open()) {						// If file_100 is can be open

		// Read the file line by line
		while (getline(file_100, row)) {
			for (size_t i = 0; i < row.length(); i++) {
				get_ascii = getAscii(row[i]);

				// Increase the number in the array according to its location in ascii.
				crt_index = get_ascii - 33;
				array_shap[crt_index]++;
			}
		}
		file_100.close();
	}
	else {											// If file_100 is can not be open 
		cout << "File could not be opened...";
		return 1;
	}

	// Finding and printing part...

	// Print how many characters are in the entire file.
	for (int i = 0; i < 93; i++) {
		cout << array_shap[i] << " ";
	}
	cout << "\n";

	// Print whichever capital letters are used the most.
	cout << "Most frequently occurring capital letter: ";
	for (int i = 65 - 33; i < 91 - 33; i++) {
		if (max_value < array_shap[i]) {
			max_value = array_shap[i];
			ascii_value = i + 33;
		}
	}
	if (max_value == 0) {
		cout << "Not available";
	}

	else {
		cout << getSign(ascii_value) << " ( " << max_value << " )\n";
	}


	max_value = 0;

	// Write whichever lowercase letter is used more.
	cout << "Most frequently occurring lowercase letter: ";
	for (int i = 92 - 33; i < 123 - 33; i++) {
		if (max_value < array_shap[i]) {
			max_value = array_shap[i];
			ascii_value = i + 33;
		}
	}
	if (max_value == 0) {
		cout << "Not available";
	}
	else {
		cout << getSign(ascii_value) << " ( " << max_value << " )\n";
	}

	max_value = 0;

	// Write whichever of the other characters is used more.
	cout << "The other most mentioned character: ";
	for (int i = 33 - 33; i < 65 - 33; i++) {
		if (max_value < array_shap[i]) {
			max_value = array_shap[i];
			ascii_value = i + 33;
		}
	}

	for (int i = 91 - 33; i < 97 - 33; i++) {
		if (max_value < array_shap[i]) {
			max_value = array_shap[i];
			ascii_value = i + 33;
		}
	}
	if (max_value == 0) {
		cout << "Not available\n";
	}
	else {
		cout << getSign(ascii_value) << " ( " << max_value << " )\n";
	}

	// Release the array..
	delete[]array_shap;
}


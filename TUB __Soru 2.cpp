#include <iostream>
using namespace std;

int main() {
	int poly_deg;

	cout << "Enter Polynomial Degree: ";
	cin >> poly_deg;

	// Create dynamic array.
	int* temp_array = new int[poly_deg + 1]();

	if (temp_array != nullptr) {				// If temp_array is not empty (memory space is reserved)..

		// Get Values..
		for (int i = 0; i <= poly_deg; i++) {
			cout << "x*a^" << i << "// x how much:";
			cin >> temp_array[i];
		}

		// Take derivative..
		for (int i = poly_deg; 0 <= i; i--) {
			if (i - 1 >= 0) {
				cout << temp_array[i] * i << "a^" << i - 1 << "  ";
			}
		}
	}

	else {										// If the field is not allocated...
		cout << "Memory allocation failed!" << endl;
		return 1; // Exited with error code 1.
	}


	// Release the array..
	delete[] temp_array;
}

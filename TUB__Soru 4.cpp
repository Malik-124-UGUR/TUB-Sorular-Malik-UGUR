#include <iostream>
using namespace std;

int main() {
	int array_size = 20;

	// Create dynamic array.
											// 0, 1, 2, 3, 4, 5,  6, 7, 8, 9, 0,  1,  2,  3,  4, 5, 6, 7, 8,  9 
	int* bitonic_array = new int[array_size] { 3, 5, 8, 4, 5, 9, 10, 8, 5, 3, 4, 11, 13, 12, 10, 5, 2, 5, 8, 11 };
	int top_array[20];
	int top_distance = 0;
	int first_location, last_location;
	bool rise = true;
	int drop = true;

	int i = 0;
	int k = 0;

	// Find the bitonic points.
	for (int t = array_size; t - 2 >= 0; t--, i++) {
		int j = i + 1;
		if (bitonic_array[i] <= bitonic_array[j] && bitonic_array[i] <= bitonic_array[j + 1] && rise) {
			// Meaning point..

			//cout << "rise " << i << " point" << "\n";
			rise = false;
			drop = true;
			top_array[k] = i + 1;
			k++;
		}

		else if (bitonic_array[i] > bitonic_array[j] && bitonic_array[i] > bitonic_array[j + 1] && drop) {
			// Meaning point..

			// cout << "drop " << i << " point" << "\n";
			drop = false;
			rise = true;
		}
	}

	// Find the highest repetition.
	for (int t = 0; t <= k; t++) {
		if (top_distance < top_array[t + 1] - top_array[t]) {
			top_distance = top_array[t + 1] - top_array[t];
			first_location = top_array[t];
			last_location = top_array[t + 1];
		}
	}
	cout << "Length of longest bitonic subsequence: " << last_location - first_location + 1 << "\n";
	cout << "The position of this sequence is between " << first_location << " and " << last_location << ".\n";

	// Release the array..
	delete[] bitonic_array;
}

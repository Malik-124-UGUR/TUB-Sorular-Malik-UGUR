#include <iostream>
#include <fstream> // Library of the file.
using namespace std;

void writeFile(char* array) {
	int i = 0;
	char temp_array[] = "";
	ofstream file_100("file.txt");	// Open the file.txt file.
	if (file_100.is_open()) {		// If file_100 is can be open

		// Write from the begining.
		while (array[i] != '\0') {
			for (int j = 0; j < i; j++) {
				file_100 << array[j];
			}
			file_100 << "\n";
			i++;
		}

		// Write from the end.
		while (i >= 0) {
			for (int j = 0; j < i; j++) {
				file_100 << array[j];
			}
			file_100 << "\n";
			i--;
		}

		// if everything is gonno be okey...
		cout << "Everything is ready...";
		file_100.close();			// Close the file.txt file.
	}
	
	else {							// If file_100 is can not be open 
		cout << "File could not be opened...";
		return;	
	}

}
int main() {
	int i = 0;
	char array[] = "Cumhuriyetin100.YILIKutluOlsun";
	writeFile(array);
}


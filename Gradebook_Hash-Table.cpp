#include "HashMap.h"
#include "clearScreen.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;


int main(int argc, char * argv[]) {
	ofstream outputFile;
	string input;
	string fileName;
	char createNewFile;

	cout << endl << "Welcome to your gradebook" << endl;
	cout << "--------------------------" << endl;
	cout << "Do you wish to create a new gradebook file for a class (Y/N) ?" << endl;
	cin >> createNewFile;

	if (createNewFile == 'Y' || createNewFile == 'y') {
		cout << "Enter file name: ";
		cin >> fileName;

		outputFile.open(fileName.c_str());
		cout << "The file you created is " << fileName << endl;
		outputFile << "Student ID" << setw(15) << "Grade(s)" << endl;
		outputFile << "--------------" << setw(19) << "------------" << endl;
	}

	if (!outputFile)
	{
		cerr << "An error has occured opening the file";
		exit(1);
	}

	HashMap hash;
	int key, value;
	int choice;

	while (1) {
		cout << endl << endl;
		cout << "Gradebook options" << endl;
		cout << "--------------------------" << endl;
		cout << "1. Insert a grade into the gradebook" << endl;
		cout << "2. Search a students grade with their student ID" << endl;
		cout << "3. Delete a students grade with their student ID" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter the students grade: ";
			cin >> value;
			cout << "Enter the ID of the student, numbers only: ";
			cin >> key;
			outputFile << key;
			outputFile << value;
			hash.Insert(key, value);
			break;

		case 2:
			cout << "Enter the ID of the student to be searched: ";
			cin >> key;
			cout << "Grade(s) at student ID " << key << " : ";
			if (hash.Search(key) == -1) {
				cout << "No grade found at " << key << " ID" << endl;
				continue;
			}
			break;

		case 3:
			cout << "Enter the student ID number to delete their grade: ";
			cin >> key;
			hash.Remove(key);
			break;

		case 4:
			exit(1);

		default:
			cout << "\nEnter correct option\n";
		}
	}
	return 0;
}

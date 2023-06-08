//What to upload to blackboard :
//Upload your code, the.CPP file, with you name in it.
//Write then upload a one - page discussion concerning how 3rd generation programming languages are utilized 
//to work in conjunction with Operating Systems to perform tasks such as writing files to a disk, 
//creating folders, and setting folder and file access permissions.Additionally, discuss the memory requirements of 
//your program that are facilitated by the OS(e.g.– bytes to declare an integer, a string, etc.) and what role RAM
//plays in the execution of your program.

// Lab 01 – Files and Folders.cpp : This file contains the 'main' function.  Programexecution begins and ends there.//
#include <iostream>
#include <string>
#include <fstream>


//this ignores the warning for unsafe conditions by using the env variable
#pragma warning(disable : 4996)

#include <cstdlib>
using namespace std;

int main(){
	string name = "", street = "", city = "", state = "", currentUser = getenv("USERNAME");
	//dynamically find
	string filePath = "C:\\Users\\" + currentUser +"\\Documents\\StudentInfo.txt"; 
	int zipCode = 0;
	ofstream file;
	
	//retrieve data from user
	cout << "Enter your name: ";
	getline(cin, name);

	cout << "\n Enter your street address: ";
	getline(cin, street);

	cout << "\n Enter your state: ";
	getline(cin, state);

	cout << "\n Enter your city: ";
	getline(cin, city);
	
	cout << "\n Enter your zip code: ";
	cin >> zipCode;
	
	//open the file
	file.open(filePath);
	if (file.is_open()) {
		
		//insert information
		file << "Name: " << name << endl;
		file << "Street: " << street << endl;
		file << "State: " << state << endl;
		file << "City: " << city << endl;
		file << "zipCode: " << zipCode << endl;

		// close the file
		file.close();
		//tell me where it was written
		cout << "\nFile successfully written to: " << filePath << endl << endl;
	}

	//where we will read the data from
	ifstream readFromFile(filePath);
	string textFromFile;

	//read from file and display to console
	if (readFromFile.is_open()) {
		while (readFromFile) {
			getline(readFromFile, textFromFile);
			cout << textFromFile << endl;
		}
	}
}

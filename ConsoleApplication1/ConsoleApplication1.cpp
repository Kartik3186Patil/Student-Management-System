
#include <iostream>
using namespace std;
#include<memory>
#include<map>
#include<vector>
#include<string>
#include<unordered_map>
#include "StudentManager.h"
#include "StudentInfo.h"

int main()
{
	cout << " === Student Management System === " << endl;
	int choice;

	StudentInfo si;
	StudentManager sm;
	do {
		//Main menu
		cout << "1. Add Student" << endl;
		cout << "2. Remove Student" << endl;
		cout << "3. Update Student" << endl;
		cout << "4. Display All Students" << endl;
		cout << "5. Find Student by Id" << endl;
		cout << "6. Sort Students by Marks" << endl;
		cout << "7.Import from text file" << endl;
		cout << "8.Export to text file" << endl;
		cout << "9. Exit" << endl;
		cout << "==============================" << endl;
		cout << "Enter your choice number" << endl;
		
		cin >> choice;
		int id;
		string name;
		int marks;
		switch (choice) {
		case 1:
			cout << "Add student is called" << endl;
			cout << "Enter id :";
			cin >> (id);
			id = (int)id;
			cout << "Enter Name :";
			cin >> name;
			name = (string)name;
			cout << "Enter marks :";
			cin >> marks;
			marks = (int)marks;
			sm.saveStudent(id, (string)name, marks);

			break;

		case 2:
			cout << "Remove student method is called" << endl;
			cout << "Enter id :";
			cin >> id;
			id = (int)id;
			sm.removeStudent(id);

			break;

		case 3:
			cout << "Update student method is called " << endl;
			cout << "Enter id :";
			cin >> id;
			id = (int)id;
			cout << "Enter marks needs to be updated " << endl;
			cin >> marks;
			name = (string)name;
			sm.updateStudentMarks(id, marks);

			break;

		case 4:
			cout << "Display all students method is called" << endl;
			sm.displayAllStudents();

			break;

		case 5:
			cout << "Display student by Id is called" << endl;
			cout << "Enter id :";
			cin >> id;
			id = (int)id;
			sm.displayStudentById(id);

			break;

		case 6:
			cout << "Sorting of students based on marks is called" << endl;
			sm.sortStudentMarks();

			break;

		case 7:
			sm.importTextFile();
			cout << endl;
			cout << "File loaded successfully" << endl;
			cout << endl;
			break;

		case 8:
			sm.exportToTextFile();
			cout << "File created successfully" << endl;
			cout << endl;
			break;
			
		default:
			 cout << "Thank you ....Will see you again..." << endl;
			 return 0;
		}
	


		
	} while (choice > 0 and choice <9);
}
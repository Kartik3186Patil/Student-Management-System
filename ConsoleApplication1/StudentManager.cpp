#include "StudentManager.h"
#include <iostream>
#include <memory>
#include<iterator>
#include<algorithm>
#include<fstream>
#include<string>
#include <sstream>

using namespace std;

void StudentManager::saveStudent(int id, string name, int marks)
{
	cout << endl;
	StudentInfo newStudent(id,name,marks);
	for (auto& it : m_studentList) {
		if (it.first == id) {
			cout << "You cannot add this student with id " << id << " as it already exists in database " << endl;
			cout << "==============================" << endl;
			cout << endl;
			return;
		}
	}
	m_studentList.insert({ id,newStudent });
	cout << "Student with id " << id << " is inserted into database" << endl;
	cout << "==============================" << endl;
	cout << endl;
		
	
	
}
void StudentManager::displayAllStudents() {
	cout << endl;
	if (m_studentList.empty() == true) {
		cout << "No students are present in database..Sorry we can't display anything to you" << endl;
		cout << "==============================" << endl;
		cout << endl;
	}
	else {
		for (auto& it : m_studentList) {
			cout << "Information of student having id :" << it.first << " , Name: " << it.second.getName() << " , Marks:" << it.second.getMarks() << endl;
			cout << "==============================" << endl;
			cout << endl;
		}
	}
}
void StudentManager::displayStudentById(int id) {
	cout << endl;
	//map<int, StudentInfo> ::iterator it = m_studentList.find(id);
	for (auto& it : m_studentList) {
		if (it.first == id) {
			cout << "Information of student with id " << it.second.getId() << " , Name: " << it.second.getName() << " , Marks:" << it.second.getMarks() << endl;
			cout << "==============================" << endl;
			cout << endl;
			return;
		}
	}
	cout << "Student with id " << id << " does not exist in the database" << endl;
	cout << "==============================" << endl;
	cout << endl;
	
}
void StudentManager::removeStudent(int id) {
	cout << endl;
	map<int, StudentInfo> ::iterator it = m_studentList.find(id);
	if (it->first != NULL) {
		int kp = it->first;
		m_studentList.erase(it);
		cout << "Student with id " << kp << " is removed from the database" << endl;
		cout << "==============================" << endl;
		cout << endl;
	}
	else {
		cout << "No student to remove" << endl;
		cout << "==============================" << endl;
		cout << endl;
	}
}
void StudentManager::updateStudentMarks(int id,int marks) {
	cout << endl;
	map<int, StudentInfo> ::iterator it = m_studentList.find(id);
	int marksOld=0;
	/*int marksNew = 0;*/
	if (it != m_studentList.end()) {
		marksOld = it->second.getMarks();
		it->second.setMarks(id,marks);
		/*marksNew= it->second.getMarks();*/
		cout << "The marks of student with id " << id << " is updated as follow :" << endl;
		cout << "Original marks :" << marksOld << endl;
		cout << "Updated marks :" << marks << endl;
		cout << "==============================" << endl;
		cout << endl;

	}
	else {
		cout << "Student with id " << id << "does not exist in the database" << endl;
		cout << "==============================" << endl;
		cout << endl;
	}

}
void StudentManager::sortStudentMarks() {
	cout << endl;
	vector<pair<int,int>>vc;
	if (m_studentList.empty() == true) {
		cout << "Student Database is empty so no data to display" << endl;
		cout << "==============================" << endl;
		cout << endl;
		return;
	}
	for (auto& it : m_studentList) {
		vc.push_back({it.second.getMarks(),it.first});

	}
	sort(vc.begin(), vc.end(), greater<pair<int, int>>());
	cout << "The overall student's result is as follow:" << endl;
	for (int i = 0;i < vc.size();i++) {
		pair<int, int>p = vc.at(i);
		cout << "Student name :" << m_studentList.find(p.second)->second.getName() << " -- " << " Student marks " << p.first << endl;
		cout << "==============================" << endl;
		cout << endl;

	}

}
void StudentManager::exportToTextFile() {
	ofstream exportFile;
	exportFile.open("C:\\Users\\PTS-PC-62_USR02\\Desktop\\file.txt");
	for (auto& it : m_studentList) {
		exportFile  << it.first<<" " << it.second.getName()<<" " << it.second.getMarks() << endl;
	}
	exportFile.close();

}
void StudentManager::importTextFile() {
	ifstream importFile;
	int studentID=0;
	int studentMarks=0;
	string studentName="";
	string splitString="";
	int count=0;
	string arr[2];
	importFile.open("C:\\Users\\PTS-PC-62_USR02\\Desktop\\file.txt");
	StudentInfo stInfo;
	int studentCount = 0;
	int lineCount = 0;
	string line = "";
	while (getline(importFile, line) && !importFile.eof()) {
		string demoLine = line;
 		demoLine.erase(remove(demoLine.begin(), demoLine.end(), ' '), demoLine.end());
		if (demoLine.size() != 0) {
			stringstream ss(line);
			string strArr[3];
			while (ss >> splitString) {
				strArr[count] = splitString;
				count++;
			}
			studentID = stoi(strArr[0]);
			studentName = strArr[1];
			studentMarks = stoi(strArr[2]);
			count = 0;

			StudentInfo newStudent(studentID, studentName, studentMarks);
			m_studentList.insert({ studentID,newStudent });
			cout << "Student number " << studentID << " is added successfuly" << endl;
			cout << endl;
		}

		


	}
	importFile.close();
}
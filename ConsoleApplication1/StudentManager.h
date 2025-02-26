#include <map>
#include<unordered_map>
#include "StudentInfo.h"

using namespace std;

class StudentManager
{
private:
	map<int, StudentInfo> m_studentList;

public:
	void saveStudent(int id, string name, int marks);
	void displayAllStudents();
	void displayStudentById(int id);
	void removeStudent(int id);
	void updateStudentMarks(int id, int marks);
	void sortStudentMarks();
	void exportToTextFile();
	void importTextFile();
};



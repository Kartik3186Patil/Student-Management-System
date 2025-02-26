#include "StudentInfo.h"

StudentInfo::StudentInfo() {}
StudentInfo::StudentInfo(int id, string name, int marks) : m_id(id),m_name(name),m_marks(marks) {}
string StudentInfo::getName() {
	return m_name;
}
int StudentInfo::getId() {
	return m_id;
}
int StudentInfo::getMarks() {
	return m_marks;
}
void StudentInfo::setMarks(int id,int marks) {
	this->m_marks = marks;

}
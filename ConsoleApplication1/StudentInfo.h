#pragma once
using namespace std;
#include <string>
class StudentInfo
{
private:
	int m_id=0;
	string m_name="";
	int m_marks=0;

public : 
	StudentInfo();
	StudentInfo(int id, string name, int marks);
	string getName();
	int getId();
	int getMarks();
	void setMarks(int id,int marks);
	

};


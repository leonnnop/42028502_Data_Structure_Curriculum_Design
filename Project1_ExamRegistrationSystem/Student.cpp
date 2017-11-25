/**************************************************************************
Copyright:LiangChen
Author: LiangChen
Date:2017-9-27
Description:Storage structure of student's information
**************************************************************************/
#include "Student.h"

Student::Student(unsigned int examNum,string name,string sex,unsigned int age,string category)
	:examNum(examNum),name(name),sex(sex),age(age),category(category)
{
}


Student::~Student(void)
{
}

//************************************
// Method:    printInfo
// FullName:  Student::printInfo
// Access:    virtual public 
// Returns:   void
// Qualifier: Print information of 'this' student
//************************************
void Student::printInfo()
{
	cout<<this->examNum<<"\t"<<this->name<<"\t"<<this->sex<<"\t"<<this->age<<"\t"<<this->category<<endl;
}

//************************************
// Method:    itsMe
// FullName:  Student::itsMe
// Access:    virtual public 
// Returns:   bool
// Qualifier: Return true if there is a successful comparison of two items of data
// Parameter: int examNum
//************************************
bool Student::itsMe(int examNum)
{
	return this->examNum == examNum;
}

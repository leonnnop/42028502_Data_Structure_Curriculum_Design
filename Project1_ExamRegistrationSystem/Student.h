/**************************************************************************
Copyright:LiangChen
Author: LiangChen
Date:2017-9-27
Description:Storage structure of student's information
**************************************************************************/
#pragma once
#include<iostream>
#include<string>
using namespace std;

class Student
{
public:
	Student(unsigned int examNum,string name,string sex,unsigned int age,string category);
	virtual ~Student(void);
	virtual void printInfo();
	virtual bool itsMe(int examNum);
private:
	unsigned int examNum;
	string name;
	string sex;
	unsigned int age;
	string category;
};
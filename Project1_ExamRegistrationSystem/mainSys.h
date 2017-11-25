/**************************************************************************
Copyright:LiangChen
Author: LiangChen
Date:2017-9-27
Description:The main structure of the system,
			using linked list to organize data.
			This system provide Create-Read-Update-Delete ( CRUD) access
			to domain information.
**************************************************************************/
#pragma once
#include<iostream>
#include<string>
#include<list>
#include"mainSys.h"
#include"Student.h"
using namespace std;

class mainSys
{
public:
	bool startSys();
	void quitSys();
	void printFisWel();
	int initInfo();
	void printHeader();
	bool printMenu();	
	void queryInfo();
	void addInfo();
	void modiInfo();
	void deleteInfo();
	void statisInfo();
private:
	list<Student> storage;
	int stuNum;
};
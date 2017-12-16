/**************************************************************************
Copyright:LiangChen
Author: LiangChen
Date:2017-9-27
Description:test the system
**************************************************************************/

#include<iostream>
#include"stdlib.h"
#include "JosephGameSystem.h"
using namespace std;
#define maxsize 100//the max number of people

int main()
{
	JosephGameSystem josephus;
	josephus.startSystem();

	system("pause");
	return 0;
}


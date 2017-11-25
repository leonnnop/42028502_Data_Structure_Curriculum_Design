/**************************************************************************
Copyright:LiangChen
Author: LiangChen
Date:2017-9-27
Description:To test the availability and correctness of the system
**************************************************************************/
#include<iostream>
#include"mainSys.h"
#include<Windows.h>
int main(void)
{
	mainSys mySystem;

	//Receiving value returned from function, and true means normal operation
	bool quit = mySystem.startSys();

	if (quit)
	{
		mySystem.quitSys();
	}
	else
	{
		cerr << "系统异常退出，请重启。" << endl;
	}

	system("pause");
	return 0;
}
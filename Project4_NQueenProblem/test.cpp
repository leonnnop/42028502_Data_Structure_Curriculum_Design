/**************************************************************************
Copyright:LiangChen
Author: LiangChen
Date:2017-9-27
Description:测试系统功能
**************************************************************************/
#include <iostream>
#include "NQueenProblem.h"
using namespace std;

int main()
{
	int n;
	cout << "现有N*N的棋盘，放入N个皇后，要求所有皇后不在同一行、列或同一斜线上！" << endl; cout << endl;
	cout << "请输入皇后个数：";
	cin >> n;
	NQueenProblem * mainSys = new NQueenProblem(n);
	cout << endl << "皇后摆法：";

	mainSys->setX((int *)malloc(sizeof(int)*n));
	mainSys->NQueen();
	cout << endl << "共有" << mainSys->getSum() << "种解法!" << endl;

	system("pause");
	return 0;
}

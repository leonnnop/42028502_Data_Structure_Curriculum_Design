/**************************************************************************
Copyright:LiangChen
Author: LiangChen
Date:2017-9-27
Description:����ϵͳ����
**************************************************************************/
#include <iostream>
#include "NQueenProblem.h"
using namespace std;

int main()
{
	int n;
	cout << "����N*N�����̣�����N���ʺ�Ҫ�����лʺ���ͬһ�С��л�ͬһб���ϣ�" << endl; cout << endl;
	cout << "������ʺ������";
	cin >> n;
	NQueenProblem * mainSys = new NQueenProblem(n);
	cout << endl << "�ʺ�ڷ���";

	mainSys->setX((int *)malloc(sizeof(int)*n));
	mainSys->NQueen();
	cout << endl << "����" << mainSys->getSum() << "�ֽⷨ!" << endl;

	system("pause");
	return 0;
}

/**************************************************************************
Copyright:LiangChen
Author: LiangChen
Date:2017-9-27
Description:ͨ�����ѽ��N�ʺ���������߼�������
**************************************************************************/
#pragma once
#include <iostream>
using namespace std;
class NQueenProblem
{
public:
	NQueenProblem(int n);
	virtual ~NQueenProblem();
	void NQueen();
	int getSum();
	void setX(int * inp);
private:
	//��¼��ǰ�ķ��÷���
	int * x;
	//�ʺ�ĸ���N�ͷ�����Ŀ
	int n;
	//������Ŀ
	int sum = 0;
	//��������ָʾ����һ�лʺ���÷����Ƿ�����Ҫ��
	int  Place(int r);
	//�û��ݹ���ȡ�ʺ���÷����ĵݹ鷽��
	void TraceBack(int r);
	//��ӡ��ǰ�ɹ��ķ��÷���
	void print();
};


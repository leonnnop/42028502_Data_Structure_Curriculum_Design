/**************************************************************************
Copyright:LiangChen
Author: LiangChen
Date:2017-9-27
Description:通过深搜解决N皇后问题的主逻辑函数。
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
	//记录当前的放置方案
	int * x;
	//皇后的个数N和方案数目
	int n;
	//方案数目
	int sum = 0;
	//检查参数所指示的这一行皇后放置方案是否满足要求
	int  Place(int r);
	//用户递归求取皇后放置方案的递归方法
	void TraceBack(int r);
	//打印当前成功的放置方案
	void print();
};


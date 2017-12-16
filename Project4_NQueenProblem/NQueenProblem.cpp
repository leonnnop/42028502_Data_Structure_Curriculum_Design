/**************************************************************************
Copyright:LiangChen
Author: LiangChen
Date:2017-9-27
Description:通过深搜解决N皇后问题的主逻辑函数。
**************************************************************************/
#include "NQueenProblem.h"

NQueenProblem::NQueenProblem(int n):n(n)
{
}


NQueenProblem::~NQueenProblem()
{
}

int NQueenProblem::Place(int r)
{
	for (int i = 0; i < r; i++) {
		if (x[r] == x[i] || abs(r - i) == abs(x[r] - x[i]))
			return 0;
	}
	return 1;
}

void NQueenProblem::TraceBack(int r)
{
	if (r >= n) {
		sum++;
		print();
	}
	else {
		for (int i = 0; i < n; i++) {
			x[r] = i;
			if (Place(r)) TraceBack(r + 1);
		}
	}
}

void NQueenProblem::print()
{
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j == x[i]) cout << "X ";
			else cout << "0 ";
		}
		cout << endl;
	}
}

int NQueenProblem::getSum()
{
	return sum;
}

void NQueenProblem::setX(int * inp)
{
	x = inp;
}

void NQueenProblem::NQueen()
{
	TraceBack(0);
}

/**************************************************************************
Copyright:LiangChen
Author: LiangChen
Date:2017-9-27
Description:���Թ�ϵͳ������������������㷨ʵ���Զ�Ѱ·����¼·��
**************************************************************************/
#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
#define  MAPSIZE 7
using namespace std;

typedef pair<int, int> path_node;

enum kindOfRoad
{
	Wall = 0,
	Road,
	MYWAY,
};

class MazeGameSys
{
public:
	MazeGameSys();
	virtual ~MazeGameSys();
	void startSys();

private:
	bool DFS(path_node point);
	void printMap();
	void printPath();

private:
	vector<int> directionX;//˳ʱ����������
	vector<int> directionY;
	bool visited[7][7];
	bool root[7][7];
	int mazeMap[7][7] =
	{
		{ 0,0,0,0,0,0,0, },
		{ 0,1,0,1,1,1,0, },
		{ 0,1,0,1,0,0,0, },
		{ 0,1,1,1,0,1,0, },
		{ 0,1,0,1,1,1,0, },
		{ 0,1,0,1,0,1,0, },
		{ 0,0,0,0,0,0,0, },
	};
	vector<path_node> path;
	path_node start;
	path_node myend;
};


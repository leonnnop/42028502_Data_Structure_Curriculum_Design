/**************************************************************************
Copyright:LiangChen
Author: LiangChen
Date:2017-9-27
Description:走迷宫系统，采用深度优先搜索算法实现自动寻路并记录路径
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
	vector<int> directionX;//顺时针上右下左
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


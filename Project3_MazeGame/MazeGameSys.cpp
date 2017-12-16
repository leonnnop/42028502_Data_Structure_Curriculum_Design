/**************************************************************************
Copyright:LiangChen
Author: LiangChen
Date:2017-9-27
Description:走迷宫系统，采用深度优先搜索算法实现自动寻路并记录路径
**************************************************************************/
#include "MazeGameSys.h"



MazeGameSys::MazeGameSys()
{
	directionX = { 0,1,0,-1 };//顺时针上右下左
	directionY = { 1,0,-1,0 };
	memset(visited, false, sizeof(visited));
	memset(root, false, sizeof(root));
	start = make_pair(1, 1);//开始点坐标
	myend = make_pair(5, 5);//终止点坐标
}


MazeGameSys::~MazeGameSys()
{
}

//************************************
// Method:    startSys
// FullName:  MazeGameSys::startSys
// Access:    public 
// Returns:   void
// Qualifier: 初始化系统
//************************************
void MazeGameSys::startSys()
{
	directionX.shrink_to_fit();
	directionY.shrink_to_fit();
	root[myend.first][myend.second] = true;
	DFS(start);
	printMap();
	cout << "迷宫路径：" << endl;
	printPath();
}

//************************************
// Method:    DFS
// FullName:  MazeGameSys::DFS
// Access:    private 
// Returns:   bool
// Qualifier: 深搜算法实现
// Parameter: path_node point
//************************************
bool MazeGameSys::DFS(path_node point)
{

	if (point.first == myend.first && point.second == myend.second)
	{
		return true;
	}

	root[point.first][point.second] = true;
	visited[point.first][point.second] = true;

	//path.push_back(point);//其实放在这里和放在下面都是正确的！
	//区别在第一个也就是起点有没有入队列！所以printPath中i的初始值不一样。
	bool result = false;

	for (int i = 0; i < directionX.size(); i++)
	{
		int dx = point.first + directionX[i];
		int dy = point.second + directionY[i];

		//如果没有超出范围并且没有访问过，并且不是墙即可以访问，那么走上去
		if ((dx > 0) && (dx < 6) && (dy > 0) && (dy < 6) &&
			(!visited[dx][dy]) && (mazeMap[dx][dy] != Wall))
		{
			path.push_back(make_pair(dx, dy));
			result = DFS(make_pair(dx, dy));
			if (result)
			{
				return true;
			}
			else
			{
				root[dx][dy] = false;
				path.pop_back();
			}
		}
	}

	return result;
}

//************************************
// Method:    printMap
// FullName:  MazeGameSys::printMap
// Access:    private 
// Returns:   void
// Qualifier: 打印地图
//************************************
void MazeGameSys::printMap()
{
	cout << "迷宫地图：" << endl;
	int lineNum = 0;
	int columnNum = 0;
	cout << "\t";

	for (int i = -1; i < MAPSIZE; i++)
	{
		for (int j = -1; j < MAPSIZE; j++)
		{
			if (i == -1)
			{
				if (j == MAPSIZE - 1)
				{
					break;
				}
				cout << columnNum << "列\t";
				columnNum++;
			}
			else
			{
				if (j == -1)
				{
					cout << lineNum << "行\t";
					lineNum++;
				}
				else
				{
					if (mazeMap[i][j] == Wall)
					{
						cout << "#\t";
					}
					else if ((mazeMap[i][j] == Road) && (root[i][j]))
					{
						cout << "x\t";
					}
					else
					{
						cout << "0\t";
					}
				}
			}
		}
		cout << endl;
	}
}

//************************************
// Method:    printPath
// FullName:  MazeGameSys::printPath
// Access:    private 
// Returns:   void
// Qualifier: 打印路径，要求在深搜寻路后调用
//************************************
void MazeGameSys::printPath()
{
	cout << "<" << start.first << "," << start.second << ">";
	for (int i = 0; i < path.size(); i++)
	{
		cout << " ---> <" << path[i].first << "," << path[i].second << ">";
	}
	cout << endl;
}

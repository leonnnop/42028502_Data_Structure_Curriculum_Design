/**************************************************************************
Copyright:LiangChen
Author: LiangChen
Date:2017-9-27
Description:���Թ�ϵͳ������������������㷨ʵ���Զ�Ѱ·����¼·��
**************************************************************************/
#include "MazeGameSys.h"



MazeGameSys::MazeGameSys()
{
	directionX = { 0,1,0,-1 };//˳ʱ����������
	directionY = { 1,0,-1,0 };
	memset(visited, false, sizeof(visited));
	memset(root, false, sizeof(root));
	start = make_pair(1, 1);//��ʼ������
	myend = make_pair(5, 5);//��ֹ������
}


MazeGameSys::~MazeGameSys()
{
}

//************************************
// Method:    startSys
// FullName:  MazeGameSys::startSys
// Access:    public 
// Returns:   void
// Qualifier: ��ʼ��ϵͳ
//************************************
void MazeGameSys::startSys()
{
	directionX.shrink_to_fit();
	directionY.shrink_to_fit();
	root[myend.first][myend.second] = true;
	DFS(start);
	printMap();
	cout << "�Թ�·����" << endl;
	printPath();
}

//************************************
// Method:    DFS
// FullName:  MazeGameSys::DFS
// Access:    private 
// Returns:   bool
// Qualifier: �����㷨ʵ��
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

	//path.push_back(point);//��ʵ��������ͷ������涼����ȷ�ģ�
	//�����ڵ�һ��Ҳ���������û������У�����printPath��i�ĳ�ʼֵ��һ����
	bool result = false;

	for (int i = 0; i < directionX.size(); i++)
	{
		int dx = point.first + directionX[i];
		int dy = point.second + directionY[i];

		//���û�г�����Χ����û�з��ʹ������Ҳ���ǽ�����Է��ʣ���ô����ȥ
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
// Qualifier: ��ӡ��ͼ
//************************************
void MazeGameSys::printMap()
{
	cout << "�Թ���ͼ��" << endl;
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
				cout << columnNum << "��\t";
				columnNum++;
			}
			else
			{
				if (j == -1)
				{
					cout << lineNum << "��\t";
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
// Qualifier: ��ӡ·����Ҫ��������Ѱ·�����
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

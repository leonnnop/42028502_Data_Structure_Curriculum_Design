/**************************************************************************
Copyright:LiangChen
Author: LiangChen
Date:2017-9-27
Description:This realizes the features of the main system ,
			using a single-cycle linked list to simulate the game process.
**************************************************************************/

#include "JosephGameSystem.h"



JosephGameSystem::JosephGameSystem()
{
	head = new Node;
	head->number = 1;
	head->next = head;
	rear = head;
}


JosephGameSystem::~JosephGameSystem()
{
}

//************************************
// Method:    CreateJosephuRing
// FullName:  JosephGameSystem::CreateJosephuRing
// Access:    private 
// Returns:   void
// Qualifier: Create a linked list with N node
// Parameter: int N the total number of the crews
//************************************
void JosephGameSystem::CreateJosephuRing(int N)
{
	totalNum = N;
	currentNum = N;
	for (int i = 2; i <= totalNum; i++)
	{
		Node * temp = new Node;
		temp->number = i;
		temp->next = head;
		rear->next = temp;
		rear = temp;
	}
}

//************************************
// Method:    show
// FullName:  JosephGameSystem::show
// Access:    private 
// Returns:   void
// Qualifier: print the linked-list
//************************************
void JosephGameSystem::show()
{
	cout << endl;
	cout << "最后剩下：" << "\t" << currentNum << "人" << "\t" << endl;
	cout << "剩余的死者位置为：" << head->number << "\t";
	Node * temp = head->next;
	while (temp != head)
	{
		cout << temp->number << "\t";
		temp = temp->next;
	}
}

//************************************
// Method:    Joseph
// FullName:  JosephGameSystem::Joseph
// Access:    private 
// Returns:   void
// Qualifier: count from zero to M,every time it reaches M,remove this crew,and count from zero again.
// Parameter: int S the start position of the game
// Parameter: int M death number
// Parameter: int K the number of remaining people
//************************************
void JosephGameSystem::Joseph(int S, int M, int K)
{
	Node * q = head;
	Node * pre = rear;
	int num = 0;

	for (int i = 1; i < S; i++)
	{
		q = q->next;
		pre = pre->next;
	}

	while (currentNum != K)
	{
		for (int i = 0; i < M - 1; i++)
		{
			q = q->next;
			pre = pre->next;
		}
		if (q == head)
		{
			head = head->next;
		}
		else if (q == rear)
		{
			rear = pre;
		}
		num++;
		cout << "第" << num << "个死者的位置是：" << "\t" << q->number << endl;
		pre->next = q->next;//remove the crew
		delete q;
		q = pre->next;
		currentNum--;
	}

}

//************************************
// Method:    startSystem
// FullName:  JosephGameSystem::startSystem
// Access:    public 
// Returns:   void
// Qualifier: start the system and the game
//************************************
void JosephGameSystem::startSystem()
{
	cout << "假如N个旅客排成一个环形，依次顺序编号1, 2, …, N。从某个指定的第S号开始。沿环计数，每数到第M个人就让器出列，且从下一个人开始重新计数，继续进行下去。这个过程一直进行到剩下K个旅客为止。" << endl;
	cout << "请输入生死游戏的总人数N：";
	cin >> N;
	cout << "请输入游戏开始的位置S：\t";
	cin >> S;
	cout << "请输入死亡数字M：\t";
	cin >> M;
	cout << "请输入剩余的生者人数K：\t";
	cin >> K;

	while (K > maxsize || K < 0)
	{
		cout << "超出范围,请重新输入: ";
		cin >> K;
		cout << endl;
	}

	cout << endl << endl;
	CreateJosephuRing(N);
	Joseph(S, M, K);
	show();
}

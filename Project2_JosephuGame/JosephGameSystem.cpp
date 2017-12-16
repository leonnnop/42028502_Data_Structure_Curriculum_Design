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
	cout << "���ʣ�£�" << "\t" << currentNum << "��" << "\t" << endl;
	cout << "ʣ�������λ��Ϊ��" << head->number << "\t";
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
		cout << "��" << num << "�����ߵ�λ���ǣ�" << "\t" << q->number << endl;
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
	cout << "����N���ÿ��ų�һ�����Σ�����˳����1, 2, ��, N����ĳ��ָ���ĵ�S�ſ�ʼ���ػ�������ÿ������M���˾��������У��Ҵ���һ���˿�ʼ���¼���������������ȥ���������һֱ���е�ʣ��K���ÿ�Ϊֹ��" << endl;
	cout << "������������Ϸ��������N��";
	cin >> N;
	cout << "��������Ϸ��ʼ��λ��S��\t";
	cin >> S;
	cout << "��������������M��\t";
	cin >> M;
	cout << "������ʣ�����������K��\t";
	cin >> K;

	while (K > maxsize || K < 0)
	{
		cout << "������Χ,����������: ";
		cin >> K;
		cout << endl;
	}

	cout << endl << endl;
	CreateJosephuRing(N);
	Joseph(S, M, K);
	show();
}

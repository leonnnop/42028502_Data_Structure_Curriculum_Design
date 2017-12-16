/**************************************************************************
Copyright:LiangChen
Author: LiangChen
Date:2017-9-27
Description:This realizes the features of the main system , 
			using a single-cycle linked list to simulate the game process.
**************************************************************************/
#pragma once
#include<iostream>
#include"stdlib.h"
using namespace std;
#define maxsize 100//the max number of people

struct Node
{
	int number;//the number of the current person
	Node * next;
};

class JosephGameSystem
{
public:
	JosephGameSystem();
	virtual ~JosephGameSystem();
	void startSystem();
private:
	void CreateJosephuRing(int N);
	void show();
	void Joseph(int S, int M, int K);
	//the total number of the crews
	int N;
	//the start position of the game
	int S;
	//death number
	int M;
	//the number of remaining people
	int K;
	Node * head;
	Node * rear;
	int totalNum;
	int currentNum;
};


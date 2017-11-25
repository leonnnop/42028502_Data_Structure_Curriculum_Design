/**************************************************************************
Copyright:LiangChen
Author: LiangChen
Date:2017-9-27
Description:The main structure of the system,
		    using linked list to organize data.
			This system provide Create-Read-Update-Delete ( CRUD) access 
			to domain information.
**************************************************************************/
#include"mainSys.h"
#include"Student.h"

enum operations
{
	QUIT,
	INSERT,
	DELETE,
	SEARCH,
	MODIFY,
	STATISTIC,
};

//************************************
// Method:    startSys
// FullName:  mainSys::startSys
// Access:    public 
// Returns:   bool
// Qualifier: The main loop that can receive a command and process the order
//************************************
bool mainSys::startSys()
{
	printFisWel();
	stuNum = initInfo();
	printMenu();
	int operationNum;
	while (true)
	{
		cout << "请选择您要进行的操作：";
		cin >> operationNum;
		switch (operationNum)
		{
		case INSERT:
			this->addInfo();
			break;
		case DELETE:
			this->deleteInfo();
			break;
		case SEARCH:
			this->queryInfo();
			break;
		case MODIFY:
			this->modiInfo();
			break;
		case STATISTIC:
			this->printMenu();
			break; 
		case QUIT:
			return true;
			break;
		default:
			cout << "错误操作码！请重新输入！" << endl;
			break;
		}
	}

	return true;
}

//************************************
// Method:    quitSys
// FullName:  mainSys::quitSys
// Access:    public 
// Returns:   void
// Qualifier: To quit the system
//************************************
void mainSys::quitSys()
{
	cout << "感谢使用本系统！" << endl;
	storage.clear();
}

//************************************
// Method:    printFisWel
// FullName:  mainSys::printFisWel
// Access:    public 
// Returns:   void
// Qualifier: Print welcome sentences
//************************************
void mainSys::printFisWel()
{
	cout << "欢迎使用本考生信息系统！您是初次使用！" << endl;
	cout << "首先请建立考生信息系统！" << endl;
}

//************************************
// Method:    initInfo
// FullName:  mainSys::initInfo
// Access:    public 
// Returns:   int
// Qualifier: Initial information
//************************************
int mainSys::initInfo()
{
	int num;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
	cout << "请输入考生人数：";//用不用考虑用户瞎几把输入？？？                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
	cin >> num;
	cout << "请依次输入考生的考号，姓名，性别，年龄及报考类别！" << endl;
	unsigned int examNum;
	string name;
	unsigned int age;
	string category;
	string sex;
	for (int i = 0; i < num; i++)
	{
		cin >> examNum >> name >> sex >> age >> category;
		storage.push_back(Student(examNum, name, sex, age, category));
	}

	if (storage.size() != num)
	{
		cout << "信息录入存在错误!" << endl;
		storage.clear();
		return 0;
	}

	return num;
}

//************************************
// Method:    printHeader
// FullName:  mainSys::printHeader
// Access:    public 
// Returns:   void
// Qualifier: Print the header
//************************************
void mainSys::printHeader()
{
	cout << "考号\t姓名\t性别\t年龄\t报考类别" << endl;
}

//************************************
// Method:    printMenu
// FullName:  mainSys::printMenu
// Access:    public 
// Returns:   bool
// Qualifier: Print the order menu
//************************************
bool mainSys::printMenu()
{
	printHeader();
	this->statisInfo();
	cout << "请选择您要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作）" << endl;

	return true;
}

//************************************
// Method:    queryInfo
// FullName:  mainSys::queryInfo
// Access:    public 
// Returns:   void
// Qualifier: Information query module
//************************************
void mainSys::queryInfo()
{
	int examNum;
	bool flag = false;
	cout << "请输入要查找的考生的考号：";
	cin >> examNum;
	for (auto &stu : storage)
	{
		if (stu.itsMe(examNum))
		{
			printHeader();
			stu.printInfo();
			flag = true;
			break;
		}
	}
	if (!flag)
	{
		cout << "输入的考号有误，查询失败！" << endl;
	}

}

//************************************
// Method:    addInfo
// FullName:  mainSys::addInfo
// Access:    public 
// Returns:   void
// Qualifier: Information addition module
//************************************
void mainSys::addInfo()
{
	cout << "请依次输入考生的考号，姓名，性别，年龄及报考类别！" << endl;
	unsigned int examNum;
	string name;
	unsigned int age;
	string category;
	string sex;
	cin >> examNum >> name >> sex >> age >> category;
	storage.push_back(Student(examNum, name, sex, age, category));
	cout << "添加成功！" << endl;
	this->statisInfo();
}

//************************************
// Method:    modiInfo
// FullName:  mainSys::modiInfo
// Access:    public 
// Returns:   void
// Qualifier: Information modification module
//************************************
void mainSys::modiInfo()
{ 
	int examNum;
	bool flag = false;
	cout << "请输入要修改的考生的考号：";
	cin >> examNum;
	for (auto i = storage.begin(); i != storage.end(); i++)
	{
		if ((*i).itsMe(examNum))
		{
			storage.erase(i);
			cout << "请依次输入考生的新的考号，姓名，性别，年龄及报考类别！" << endl;
			unsigned int examNum;
			string name;
			unsigned int age;
			string category;
			string sex;
			cin >> examNum >> name >> sex >> age >> category;
			storage.push_back(Student(examNum, name, sex, age, category));
			cout << "修改成功！" << endl;
			this->statisInfo();
			flag = true;
			break;
		}
	}

	if (!flag)
	{
		cout << "输入的考号有误，修改失败！" << endl;
	}
	
}

//************************************
// Method:    deleteInfo
// FullName:  mainSys::deleteInfo
// Access:    public 
// Returns:   void
// Qualifier: Information deletion module
//************************************
void mainSys::deleteInfo()
{
	int examNum;
	bool flag = false;
	cout << "请输入要删除的考生的考号：";
	cin >> examNum;
	for (auto i = storage.begin(); i != storage.end(); i++)
	{
		if ((*i).itsMe(examNum))
		{
			storage.erase(i);
			cout << "删除成功！" << endl;
			this->statisInfo();
			flag = true;
			break;
		}
	}
	if (!flag)
	{
		cout << "输入的考号有误，删除失败！" << endl;
	}
}

//************************************
// Method:    statisInfo
// FullName:  mainSys::statisInfo
// Access:    public 
// Returns:   void
// Qualifier: Print information of per students
//************************************
void mainSys::statisInfo()
{
	auto i = storage.begin();
	while (i != storage.end())
	{
		(*i).printInfo();
		i++;
	}
	cout << endl;
}




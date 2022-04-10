#include<iostream>
#include<string>
using namespace std;

//// 私有变量设置及获取值
//
//class CPeople {  
//private:
//	int m_nAge;		
//protected:
//	bool m_bSex;
//public:
//	string m_strName;
//	void show() {	
//		cout << m_strName << endl;
//		cout << m_bSex << endl;
//		cout << m_nAge << endl;
//	}
//
//	//对于私有变量，可以提供一个接口（构造一个公有的函数）去设置及获取值。
//	void SetAge(int age) {
//		m_nAge = age;
//	}
//	int GetAge() {
//		return m_nAge;
//	}
//	//如果私有变量众多，每个都要构造两个函数去设置和获取则很麻烦，所以需要构造函数，这是类中的一个特殊函数，如果类中不写，则编译器会提供一个默认的无参的构造函数(函数名是当前类名，没有返回值)，如果写的话则写的作为构造函数，编译器不再提供了。
//};
//
//
//int main() {
//
//	//CPeople people;	
//	////people.m_nAge = 10;
//	////people.m_bSex = true;
//	//people.m_strName = "小明";
//	//people.show();
//
//	CPeople* pPeo = new CPeople;
//	pPeo->m_strName = "小李";
//
//	pPeo->SetAge(18);
//	cout << pPeo->GetAge() << endl;
//
//	pPeo->show();
//
//	system("pause");
//	return 0;
//}


////函数名为当前类名，没有返回值，参数可以有也可以没有
////构造函数:用来初始化类成员变量，定义对象时会自动调用。可以有多个构造函数，是函数重载的关系。定义对象最终只执行某一个构造函数。
////析构函数（用于回收空间）：和构造函数是对应关系，是用来释放成员申请空间的，函数名为~类名，析构函数只能有一个，析构函数无参数，无返回值。
//
//class CTest
//{
//public:
//	int m_nAge;
//	int m_nSex;
//	int* m_p;
//	CTest() {//无参的构造函数
//		m_nAge = 10;
//		m_p = new int(10);
//	}
//	CTest(int age) {//有参的构造函数
//		m_nAge = age;
//	}
//	CTest(int age, int sex)
//	{
//		m_nAge = age;
//		m_nSex = sex;
//	}
//	//析构函数
//	~CTest() 
//	{
//		cout << "~CTest" << endl;
//		if (m_p) {
//			delete m_p;
//			m_p = NULL;
//		}//对象生命周期结束时，先执行析构函数，再释放对象的栈区的空间
//	}
//protected:
//private:
//};
//
//int main() {
//	//CTest tst;//调用无参的构造函数
//	//cout << tst.m_nAge << endl;
//
//	//CTest tst2(12);//调用有参的构造函数
//	//cout << tst2.m_nAge << endl;
//
//	//CTest* pTst = new CTest(12, 1);
//	//cout << pTst->m_nAge << endl;
//	//cout << pTst->m_nSex << endl;
//
//	//delete pTst; //new了就要delete 释放时会自动调用析构函数
//	//pTst = NULL;
//
//	{
//		CTest tst;
//	}//到括号自动释放 释放时也会自动调用析构函数
//
//	system("pause");
//	return 0;
//}



///*
//练习：
//封装一个CDate类：
//成员属性为年、月、日
//成员方法为构造、析构、显示日期（Display）、设置日期差（SetDate）…等
//一个CDate对象可以用三个整数表示年、月、日（2021.3.3）来初始化，而且可以对日期的设置进行合法性校验，要求实现CDate类的成员。
//*/
//
//
//class CDate {
//public:
//	int m_nYear;
//	int m_nMonth;
//	int m_nDay;
//public:
//	CDate() {
//		m_nYear = 1970;
//		m_nMonth = 1;
//		m_nDay = 1;
//	}
//	~CDate() {
//		m_nYear = 0;//有指针的话必须写，没有指针可以不写，但是严格上都要写，置成当前类型的初始值
//		m_nMonth = 0;
//		m_nDay = 0;
//	}
//public:
//	void Display() {
//		cout << m_nYear << "-" << m_nMonth << "-" << m_nDay << endl;
//	}
//	void SetDate(int year, int month, int day) {
//		if (year >= 1970 && year <= 2099)
//		{
//			m_nYear = year;
//		}
//		if (month >= 1 && month <= 12)
//		{
//			m_nMonth = month;
//		}
//		if (day >= 1 && day <= 30)
//		{
//			m_nDay = day;
//		}
//	}
//};
//
//int main() {
//	CDate date;
//
//	date.Display();
//
//	date.SetDate(2021, 5, 21); 
//	
//	date.Display();
//
//	system("pause");
//	return 0;
//}



////封装链表
//
///*
//C++中struct结构体和class类的区别
//1.类的默认访问修饰符是私有private的 结构体的默认访问修饰符是公有public的
//2.类的默认继承方式是私有privat的 结构体的默认继承方式是公有public的
//*/
//
//struct Node {
//	int val;
//	Node* pNext;
//	Node(int v) {
//		val = v;
//		pNext = NULL;
//	}
//};
//
//class MyList
//{
//public:
//	Node* m_pHead;
//	Node* m_pEnd;
//	int m_nLen;//链表长度 节点个数
//public:
//	MyList() {
//		m_pHead = NULL;
//		m_pEnd = NULL;
//		m_nLen = 0;
//	}
//	~MyList() {//析构是生命周期结束了所以这里应该遍历链表删除节点
//		Node* pTemp = NULL;
//		while (m_pHead) {
//			pTemp = m_pHead;
//			m_pHead = m_pHead->pNext;
//			delete pTemp;
//			pTemp = NULL;
//		}
//		m_pHead = NULL;
//		m_pEnd = NULL;
//		m_nLen = 0;
//	}
//public:
//	void PushBack(int v) {
//		//Node* pTemp = new Node;//报错：没有默认的构造函数，原因是结构体中写了构造函数，因此系统不再提供默认的构造函数，而是采用写的有参的构造函数
//		Node* pTemp = new Node(v);
//
//		if (m_pHead){
//			m_pEnd->pNext = pTemp;
//			m_pEnd = m_pEnd->pNext;
//		}
//		else {
//			m_pHead = pTemp;
//			m_pEnd = pTemp;
//		}
//		m_nLen++;
//
//	}
//
//	void show() {
//		Node* pTemp = m_pHead;
//		while (pTemp) {
//			cout << pTemp->val << "	";
//			pTemp = pTemp->pNext;
//		}
//		cout << endl;
//	}
//
//	void PopFront() {//头删除
//		if (m_pHead)
//		{
//			Node* pTemp = m_pHead;
//			if (m_pHead == m_pEnd) 
//			{
//				//delete pTemp;
//				//pTemp = NULL;
//				m_pHead = NULL;
//				m_pEnd = NULL;
//			} 
//			else
//			{
//				m_pHead = m_pHead->pNext;
//				//delete pTemp;
//				//pTemp = NULL;
//			}
//			delete pTemp;
//			pTemp = NULL;
//			m_nLen--;
//		}
//	}
//
//protected:
//private:
//};
//
//
//
//int main() {
//	MyList lst;
//
//	lst.PushBack(1);
//	lst.PushBack(2);
//	lst.PushBack(3);
//	lst.PushBack(4);
//
//	lst.show();
//
//	lst.PopFront();
//	lst.show();
//	lst.PopFront();
//	lst.show();	
//
//	system("pause");
//	return 0;
//}
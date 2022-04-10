#include<iostream>
#include<string>
using namespace std;

/*

//const

int main() {
	
	int a = 10;
	a = 20;
	int* p = &a;

	const int b = 20;
	//b = 10;//会报错，b为常量，一旦定义就必须初始化且之后无法再进行修改
	//int* p2 = &b;//const int类型的值不能用于初始化int类型的实体
	const int* p2 = &b;//const:不能通过指针去修改指向的空间里的值
	p2 = &a;//但可以指向别的空间
	const int* p3 = &a;
	//*p3 = 4;//const:不能通过指针去修改指向的空间里的值

	int* const p5 = &a;//p5一旦定义就必须初始化且之后无法再进行修改
	//p5 = &b;//一旦定义了指向了一个具体的空间，就不能再指向其他的空间

	system("pause");
	return 0;
}

*/



//引用

/*

int main() {

	int a = 10;
	int& b = a;  //定义引用，b是名字，引用的类型需要和被引用的一致

	cout << b << endl;

	a = 12;

	cout << a << endl;
	cout << b << endl;

	//int& c;  //定义引用时必须初始化

	system("pause");
	return 0;
}

*/

/*
1.定义指针可以NULL，但引用不可以为NULL，定义时必须初始化
2.有空的指针，但是没有空的引用
3.指针占用空间，引用不占用额外的空间
*/



//三种传递

/*

//值传递
void show(int a) 
{
	cout << a << endl;
}

//地址传递
void show(int* p) 
{
	cout << *p << endl;
}

//引用传递
void play(int& b) 
{
	 cout << b << endl;
	 b = 12;
}

int main(){

	int a = 10;
	show(a);	//值传递
	show(&a);	//地址传递
	play(a);	//引用传递
	cout << a << endl;

	system("pause");
	return 0;
}

*/

//链表

/*

struct Node {
	int val;
	Node* pNext;
};

//void PushBack(Node** pH, Node** pE, int v)  
//{  
//	Node* pNode = new Node;
//	pNode->val = v;
//	pNode->pNext = NULL;
//
//	if (*pH)		 //链表不为空
//	{
//		(*pE)->pNext = pNode;
//		(*pE) = pNode;
//	} 
//	else		     //链表为空
//	{
//		(*pH) = pNode;
//		(*pE) = pNode;
//	}

		//shift+Alt 可以列选中

//}

void PushBack(Node*& pH, Node*& pE, int v)
{
	Node* pNode = new Node;
	pNode->val = v;
	pNode->pNext = NULL;

	if (pH)		 //链表不为空
	{
		(pE)->pNext = pNode;
		(pE) = pNode;
	} 
	else		     //链表为空
	{
		(pH) = pNode;
		(pE) = pNode;
	}
}

void Show(Node* pH) 
{
	if (pH)
	{
		while (pH) 
		{
			cout << pH->val << endl;
			pH = pH->pNext;
		}
	}
}

int main() 
{
	Node* pHead = NULL;
	Node* pEnd = NULL;

	//PushBack(&pHead, &pEnd, 1);
	//PushBack(&pHead, &pEnd, 2);
	//PushBack(&pHead, &pEnd, 3);
	//PushBack(&pHead, &pEnd, 4);

	PushBack(pHead, pEnd, 1);
	PushBack(pHead, pEnd, 2);
	PushBack(pHead, pEnd, 3);
	PushBack(pHead, pEnd, 4);

	Show(pHead);

	system("pause");
	return 0;
}

*/


/*
C 数据和算法 关联性不强
C++ 将完成某一功能的数据 算法 封装起来形成一个类 关联性强

类：数据和算法的集合，是抽象的(不是具体的，不占用内存空间，只是表明是一个类)
对象：定义一个类的实例（变量），是具体的（占用内存空间）
*/



//类的成员变量
//
//class CPeople{  //类的定义  类名一半以C开头
//	int m_nAge;		//成员变量一般以m_开头
//	bool m_bSex; 
//	string m_strName;
//
//	void show() {	//成员函数中可以直接使用上述变量
//		cout << m_strName << endl;
//		cout << m_bSex << endl;
//		cout << m_nAge << endl;
//	}
//};
//
//
//int main() {
//
//	//CPeople people;	//定义对象
//	//people.m_nAge = 10;
//	//people.m_bSex = true;
//	//people.m_strName = "小明";
//
//	//报错：无法访问，因此需要访问修饰符
//
//	system("pause");
//	return 0;
//}
//
//
//如果不写string的头文件,变量申明所用到string时不会报错,因为string作为关键字是存在于编译器中的,但如果变量用到了string头文件的函数,就会报错。
//class CPeople{  
//	string m_strName;	//不用string头文件不报错
//
//	void show() {	
//		cout << m_strName << endl;	//不用string头文件会报错
//	}
//};



////类的访问修饰符
//
///*
//访问修饰符：
//public:公共的,类内类外都可以用
//protected:保护的,类内可以,子类也可以
//private:私有的,只能在类内使用
//*/
//
//class CPeople {  //类的定义  类名一半以C开头
//private:
//	int m_nAge;		//成员变量一般以m_开头
//protected:
//	bool m_bSex;
//public:
//	string m_strName;
//	void show() {	//成员函数中可以直接使用上述变量
//		cout << m_strName << endl;
//		cout << m_bSex << endl;
//		cout << m_nAge << endl;
//	}
//};
//
//
//int main() {
//
//	//CPeople people;	//定义对象  类的变量和函数都必须通过对象来用
//	////people.m_nAge = 10;
//	////people.m_bSex = true;
//	//people.m_strName = "小明";
//	//people.show();
//
//	//定义对象的另一种方式
//	CPeople* pPeo = new CPeople;
//	pPeo->m_strName = "小李";
//	pPeo->show();
//
//	system("pause");
//	return 0;
//}
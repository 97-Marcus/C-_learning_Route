#include <iostream>
using namespace std;

/*

//	多态:	相同的行为方式导致了不同的行为结果，即为多态性。在程序上，也就是同一行语句展现了多种不同的表现形态。
//			父类指针可以指向任何继承于该类的子类，且具有子类的行为方式，多种子类具有多种形态，由父类指针进行统一管理，父类指针具有多种形态。

//多态产生的条件：1. 必须有继承关系存在（父类、子类）；2. 父类的指针指向子类的对象；3. 子类必须重写父类的虚函数

//重写：子类中存在和父类函数一模一样（函数名 参数列表 返回值 都相同）的虚函数

class CFather
{
public:
	//void show() {
	//	cout << "void show()" << endl;
	//}

	virtual void show() {//	virtual：虚函数的关键字
		cout << "void show()" << endl;
	}
protected:
private:
};

//class CSon1 :CFather	//默认继承是私有的
class CSon1 :public CFather
{
public:
	void show() {
		cout << "CSon1 show()" << endl;
	}
protected:
private:
};

class CSon2 :public CFather
{
public:
	void show(int a) {	//这个就不能算是重写 其参数列表和父类不一样
		cout << "CSon2 show()" << endl;
	}
protected:
private:
};

int main() {

	CFather* pFather = new CSon1;
	pFather->show();

	CFather* pFather1 = new CSon2;
	pFather1->show();

	system("pause");
	return 0;
}

*/



//
////多态原理
//
//
//class CTest {
//public:
//	int m_a;
//	int m_b;
//public:
//	CTest() {
//		cout << "CTest" << endl;
//
//	}
//public:
//	virtual void show() {
//		cout << "void show()" << endl;
//	}
//	virtual void play() {
//		cout << "void play()" << endl;
//	}
//	void code() {
//		cout << "void code()" << endl;
//	}
//};
//
////	一个类中的虚函数由一个虚函数列表进行管理，该虚函数列表为一个数组，数组的每个元素是一个函数指针，函数指针指向虚函数，虚函数指针将在构造初始化列表中进行初始化，指向虚函数列表，虚函数指针是属于对象的，只有定义对象了才会存在。
////	在调用虚函数时，需要使用虚函数指针（指向虚函数列表）来遍历虚函数列表，进行查找对应的函数指针，然后用函数指针去调用具体的虚函数。
////	虚函数列表属于类，编译期便存在
////	__vfptr  虚函数指针; vftable	虚函数列表
//
//int main() {
//
//	cout << sizeof(CTest) << endl;
//	//空类大小输出为占位1，类中有1个虚函数后输出4，有2个虚函数也输出4，有2个虚函数＋1个正常函数的情况下依然大小输出为4
//	//说明：普通函数不影响类的大小；类中存在1个或多个虚函数时，定义对象时分配的空间将多出4个字节。
//
//	/*CTest tst1;
//
//	tst1.play();
//	tst1.code();*/
//
//	CTest* pTst = NULL;	//空类指针
//	pTst->code();	//直接通过类指针调用普通函数
//	//pTst->play();	//该句无法编译通过 因为没有对象亦没有虚函数指针 无法通过空类指针调用虚函数
//					
//					//可作如下修改：
//	CTest tst2;
//	CTest* pTst1 = &tst2;
//	pTst1->play();
//
//	cout << sizeof(CTest) << endl;
//
//	CTest tst;
//	cout << &tst << endl;	
//	cout << &tst.m_a << endl;	//首地址和m_a的地址差4，实际上就是虚函数指针的大小（虚函数指针在定义对象的空间的前4个字节）	
//	cout << &tst.m_b << endl;
//
//
//	system("pause");
//	return 0;
//}

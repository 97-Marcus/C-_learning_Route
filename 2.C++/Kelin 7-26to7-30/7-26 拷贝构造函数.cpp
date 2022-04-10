//#include <iostream>
//using namespace std;
//
//class CTest
//{
//public:
//	int m_a;
//	int* m_p;
//
//public:
//
//	CTest() {
//		m_a = 10;
//		m_p = new int(20);
//	}
//
//	CTest(int a) {
//		m_a = a;
//	}
//
//	//	空类中编译器会提供一个默认的特殊的构造函数：拷贝构造函数
//	//	拷贝构造函数 函数名 当前类名 参数const 当前类的引用
//	// 	拷贝构造函数在用当前类的一个对象给另一个对象初始化的时候时被调用
//	//	参数中对象给this对象成员依次初始化
//	
//	//	CTest(const CTest& tst) {
//	//		this->m_a = tst.m_a;
//	//	}
//
//
//	~CTest() {
//		if (m_p) {
//			delete m_p;
//			m_p = NULL;
//		}
//		//	默认拷贝构造函数的严重问题：浅拷贝问题
//		//	浅拷贝问题的两点：
//		//	1.如果类中成员存在指针变量且new分配空间，调用拷贝构造函数的时候是值拷贝（地址拷贝）的过程，因此在析构回收空间时，同一个地址空间会被delete多次，导致程序崩溃。
//	}
//
//};
//
//
//int main() {
//
//	//CTest tst(10);
//	//CTest tst1(tst);
//	//cout << tst1.m_a << endl;
//
//	CTest tst;
//	CTest tst1(tst);
//
//	*tst1.m_p = 50;
//	cout << *tst.m_p << endl;	
//					//2.多个对象指针指向同一个空间，其一个对象修改里面的值，其他对象使用后的值是修改后的。
//					//如果实际确实需要多个对象共享，也不建议使用该方式，可以使用static静态成员变量
//
//	system("pause");
//	return 0;
//}


////解决浅拷贝问题：深拷贝
//
//
//#include <iostream>
//using namespace std;
//
//class CTest
//{
//public:
//	int m_a;
//	int* m_p;
//public:
//	CTest() {
//		m_a = 10;
//		m_p = new int(20);
//	}
//	CTest(int a) {
//		m_a = 20;
//		m_p = NULL;
//	}
//	CTest(const CTest& tst) {
//		this->m_a = tst.m_a;
//		if (tst.m_p)
//		{
//			this->m_p = new int(*tst.m_p);
//		}	//两个对象的m_p是new的不同地址，存的值是一样的
//		else {
//			this->m_p = NULL;
//		}
//	}
//	~CTest() {
//		if (m_p) {
//			delete m_p;
//			m_p = NULL;
//	}
//
//};
//
//
//int main() {
//
//	CTest tst1;
//	CTest tst2(tst1);
//
//	CTest tst3(10);
//	CTest tst4(tst3);
//
//	system("pause");
//	return 0;
//}
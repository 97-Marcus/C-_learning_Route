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
//	CTest() {
//		m_a = 10;
//		m_p = NULL;
//	}
//	CTest(int a) {
//		m_a = a;
//		m_p = new int(30);
//	}
//
//	int operator=(int a) {
//		m_a = a;
//		return m_a;
//	}
//
//	//	编译期提供的默认的重载等号操作符 operator= 
//	//	参数为const CTest& tst 返回值为const CTest&
//	/*const CTest& operator=(const CTest& tst) {
//		this->m_a = tst.m_a;
//		return *this;
//	}*/
//	//	当前类的一个对象给另一个对象赋值的时候进行调用
//	//	参数中对象给this对象成员依次赋值
//	//	也存在浅拷贝问题，解决方法还是深拷贝
//
//	const CTest& operator=(const CTest& tst) {
//		this->m_a = tst.m_a;
//		if (tst.m_p)	
//		{
//			if (this->m_p) //this->m_p不一定有空间所以还要再判断
//			{
//				*this->m_p = *tst.m_p;
//			}
//			else {
//				this->m_p = new int(*tst.m_p);
//			}
//		}
//		else {
//			if (this->m_p)
//			{
//				delete this->m_p;
//				this->m_p = NULL;
//				//其实tst.m_p没有空间也是NULL，所以写this->m_p = tst.m_p也可以~
//			}
//			else {
//				this->m_p = tst.m_p;//两都没有空间 两都是空
//			}
//		}
//		return *this;
//	}
//
//	~CTest() {
//		if (m_p) 
//		{
//			delete m_p;
//			m_p = NULL;
//		}
//	}
//};
//
//int main() {
//	//CTest tst1;
//	//CTest tst2;
//	//tst2 = tst1 = 10;
//
//	//CTest tst;
//	//CTest tst3;
//	//CTest tst4;
//	//tst4 = tst3 = tst;
//
//	CTest tst1;
//	CTest tst2;		//都调用默认无参的构造，则m_p都是空，走的是this->m_p = tst.m_p;
//	tst1 = tst2;
//
//	CTest tst3(20);
//	tst2 = tst3;	//有参的给无参的，走的是this->m_p = new int(*tst.m_p);
//
//	CTest tst4(40);
//	tst4 = tst3;	//都有空间，走的是*this->m_p = *tst.m_p;
//
//	CTest tst5;
//	tst5 = tst4;	//无空间的给有空间的赋值，走的是delete this->m_p;this->m_p = NULL;
//
//	system("pause");
//	return 0;
//}
//
////空类中默认的函数（4个）
////1.默认无参构造函数
////2.默认析构函数
////3.默认拷贝构造函数
////4.默认operator=（重载等号操作符）
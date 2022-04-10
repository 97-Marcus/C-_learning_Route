//#include <iostream>
//using namespace std;

//
//class CTest {
//public:
//	const int m_a;
//	int m_b;
//	//初始化参数列表：真正的初始化
//	CTest() :m_a(10), m_b(30) {
//		//m_a = 10;	
//		//报错 此处为赋值 不是初始化 而const定义的是常量 所以不是可以修改的左值
//		//m_b = 20;//普通变量可以这样初始化，也可以通过初始化参数列表进行真正的初始化，那么此处也可以等于是赋值
//	}//无参情况
//
//	//有参的初始化参数列表
//	//初始化参数列表的初始化顺序：并不是写在参数列表中的顺序，而是变量在类中定义的顺序，也就是m_a,m_b
//	//
//
//	//CTest(int a) :m_a(m_b), m_b(a) {	//m_a没有初始化
//	//	//用m_b去初始化m_a,但m_b的定义在m_a后，因此无法完成该初始化
//	//}
//
//	//CTest(int a) :m_a(a), m_b(m_a) {
//
//	//}
//
//	//const int show() {//返回值为常量（const int）
//	//	
//	//}
//
//	void play(/*CTest* const this*/) {
//	
//	}
//
//	//const成员函数（常成员函数):注意const要加在参数列表后面
//	//常函数中可以使用 但不能修改
//	int show (/* const CTest* const this */)const {
//		//const修饰的是this指针，普通函数的this指针为CTest* const this，而常函数的为const CTest* const this
//		cout << m_a << endl;
//		cout << m_b << endl;
//
//		//m_a = 20;
//		//m_b = 20;
//		//通过常量对象进行访问，因此无法修改
//
//		return 0;
//	}
//};
//
//int main() {
//
//	//CTest tst(20);
//	//cout << tst.m_a << endl;
//	//cout << tst.m_b << endl;
//
//	CTest tst;
//	tst.show();//普通对象可以调用普通函数和常函数
//
//	//const CTest* const pp = &tst;	//指针的安全级别升级操作，是允许的
//	//pp->m_a = 10;	//m_a无法修改，因为pp指针被const修饰了，也就是常函数隐含的const CTest* const this
//
//	const CTest tst1;//常量对象：只能调用常函数，不可以调用普通函数
//	tst1.show();
//
//	//tst1.play();		//报错，无法调用
//	//CTest* const p2 = &tst1;		//报错，为指针的安全级别降级操作，这是不被允许的
//
//	system("pause");
//	return 0;
//}
//
//
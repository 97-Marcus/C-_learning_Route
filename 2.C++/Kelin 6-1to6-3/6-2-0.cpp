//#include <iostream>
//using namespace std; 
//
//#include"6-2-0.h"
//
//int CTest::m_c = 60;
//
//void show(int a) {
//	cout << "show" << a << endl;
//}
//
////int c = 30;
//
//
//CTest::CTest():m_b(20){
//	m_a = 10;
//};
//CTest::~CTest() {
//
//};
//void CTest::show() {
//	cout << m_a << endl;
//	cout << m_b << endl;
//	cout << m_c << endl;
//};
//
//void CTest::play() {	//静态成员函数（声明于头文件，在源文件中实现时）的实现需要去掉静态关键字statuc
//	cout << "static play" << endl;
//}
//
//void CTest::code()const {	//常函数（声明于头文件，在源文件中实现时）在源文件中定义需要保留关键字const
//	cout << "const code" << endl;
//}
//
//void CTest::run() {		//虚函数（声明于头文件，在源文件中实现时）的实现需要去掉virtual关键字
//	cout << "virtual run" << endl;
//}
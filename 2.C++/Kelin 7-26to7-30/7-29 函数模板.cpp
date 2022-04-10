//#include<iostream>
//#include<typeinfo>
//using namespace std;
//
////	template:定义模板的关键字
////	typename:定义模板类型的关键字
////	TT:通用的类型，在调用函数进行使用的时候会根据所给的参数类型自动匹配
////	<typename TT>:模板的参数列表,需要多个参数的话就加逗号继续写，比如template<typename TT,typename KK>
////	PS:要紧挨着需要使用函数模板的函数（上下行，中间尽量别写乱七八糟的东西）
////	   如果函数声明和定义是分开的，那么函数模板的那句话在声明和定义的部分都要加上。
//
//template<typename TT>
//TT Add(TT a, TT b) {
//	TT c = a + b;
//	return c;
//}
//
//template<typename TT,typename KK>
//TT Add(TT a, TT b, KK d) {
//	TT c = a + b;
//	return c;
//}
//
////double Add(double a, double b) {
////	return a + b;
////}
//
//
//template<typename TT>
//void show(TT a, int b = 10);
//
//
////函数体加了模板但函数内无，无法自动推导TT的类型~，所以要指定类型
//template<typename TT=int>
//TT show1() {
//	cout << "show1" << endl;
//	return 0;
//}
////	c++98编译失败（仅允许在类模板上使用默认模板参数），但目前c++11已经解除该限制，C++11支持了函数模板的默认模板参数，此处可以编译通过。
////  PS:尽管C++11支持了函数模板的默认模板参数，不过在语法上，两者还是存在区别：类模板在为多个默认模板参数声明指定默认值时，必须遵照“从右往左”的规则进行指定。而这个规则对函数模板来说并不是必须的~对于函数模板来说，默认模板参数的位置则比较随意~
//
////	如果能够从函数实参中推导出类型的话，那么默认模板参数就不会被使用，反之，默认模板参数则可能会被使用。
//
////C++98的解决方式：
////template<typename TT>
////TT show1() {
////	cout << "show1" << endl;
////	return 0;
////}
////
////调用时在函数后面加上<默认的参数类型>使用，如：show1<int>();
//
////函数内加了模板 但函数体无 无法自动推导TT的类型~，所以要指定类型，调用时在函数后面加上<默认的参数类型>使用
//
//template<typename TT>
//void show2(int a) {
//	TT c = 30;
//	cout << "show2" << c << endl;
//}
//
//template<typename TT>
//void show3(TT a) {
//	TT c = a;
//	cout << "show3" << c << endl;
//}
//
//template<typename TT, typename KK>
//void show4(TT a) {
//	TT c = a;
//	KK d = 10;
//	cout << "show4" << c << d << endl;
//}
//
//int main() {
//
//	int a = 10, b = 20;
//	cout << Add(a, b) << endl;
//
//	double c = 10.1, d = 10.2;
//	cout << Add(c, d) << endl;
//
//	Add(a, b, d);//此时根据参数匹配，TT就会是int类型，KK是double类型~
//	
//	char k = 50;
//	show(k, 20);
//
//	show1();
//	//RTTI 动态类型识别
//	//cout << typeid(show1<int>()).name() << endl;
//	//cout << typeid(show1<char>()).name() << endl;
//	
//	show2<double>(48);
//	show3(48);	//默认推导是int类型 但想用别的类型来存 也可以用<类型>的方式
//	show3<char>(48);
//
//	//show4<char>(48);	
//	//报错，函数模板参数列表多个，那类型也就需要指定多个~如下：
//	show4<char, double>(48);	
//
//	system("pause");
//	return 0;
//} 
//
//template<typename TT>
//void show(TT a, int b) {
//	cout << a << endl;
//	cout << b << endl;
//}
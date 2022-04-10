//#include <iostream>
//using namespace std;
//#include <typeinfo>
//
//
////从右往左依次指定，不能间断
////如果类模板参数列表都已经默认指定，如：template<typename TT = int,typename KK = int>，那么如果函数调用时不想使用默认要重新指定的话，要么两个都重新指定，要么重新指定KK，不会出现指定TT而KK默认的情况，因为从右往左依次指定，不能间断。
//
////template<typename TT,typename KK = int>
//template<typename TT=int, typename KK = double>
//class CTest
//{
//public:
//	TT m_a;
//	KK m_k;
//public:
//	CTest() {
//		m_a = 10;
//	}
//	CTest(TT t,KK k) {
//		m_a = t;
//		m_k = k;
//	}
//public:
//	void show(TT tt) {
//		TT t = 20;
//		cout << t << "	" << typeid(t).name() << endl;
//		cout << tt << "	" << typeid(tt).name() << endl;
//	}
//	void get() {
//		cout << m_a << "	" << typeid(m_a).name() << endl;
//		cout << m_k << "	" << typeid(m_k).name() << endl;
//	}
//	void play();
//	void play1(TT t, KK k);
//
//	template<typename MM>
//	void Test(MM mm) {
//		MM m = 30;
//		cout << m << "	" << mm << "	" << typeid(m).name() << endl;
//	}
//	
//	template<typename HH>
//	void Test1() {
//		HH hh = 20;
//		cout << hh << "	" << typeid(hh).name() << endl;
//	}
//
//	template<typename NN>
//	void Name(TT t, KK k);
//	
//};
//
//
////void CTest::play() {					//报错：缺少类模板的参数列表
////void CTest<int,double>::play() {		
////	cout << m_a << "	" << typeid(m_a).name() << endl;
////	cout << m_k << "	" << typeid(m_k).name() << endl;
////}
//
//
////不能在类外部的类模板成员声明上指定默认的模板参数类型
////template<typename TT = int, typename KK = double>
//template<typename TT , typename KK>
//void CTest<TT,KK>::play() {
//	cout << m_a << "	" << typeid(m_a).name() << endl;
//	cout << m_k << "	" << typeid(m_k).name() << endl;
//}
//
//template<typename TT, typename KK>
//void CTest<TT, KK>::play1(TT t, KK k) {
//	cout << m_a+t << "	" << typeid(m_a).name() << endl;
//	cout << m_k+k << "	" << typeid(m_k).name() << endl;
//}
//
////类模板＋函数模板时 注意模板声明的顺序
//template<typename TT, typename KK>
//template<typename NN>
//void CTest<TT, KK>::Name(TT t, KK k) {
//
//	NN n = 50;
//	cout << m_a << "	" << typeid(m_a).name() << endl;
//	cout << m_k << "	" << typeid(m_k).name() << endl;
//	cout << n << "	" << typeid(n).name() << endl;
//
//}
//
//int main() {
//
//	////CTest tst;	
//	////报错：因为不知道TT的类型，所以用类创建对象时也无法确定空间
//
//	//CTest<int> tst;
//	////能明显看出类似于list<int> lst;	
//	////实际上封装好的list也是一个模板类~
//
//	//cout << tst.m_a << endl;
//	//tst.show(10);
//
//	//CTest<double,char> tst2(3.14,'A');
//	//tst2.get();
//
//	//CTest<double> tst2(3.14, 5);
//	//tst2.get();
//
//	//CTest<double,long> tst2(3.14, 10);	
//	////指定了那就用指定的，没指定就用默认的
//	//tst2.get();
//	
//	CTest< > tst(20, 3.14);
//			//类模板参数列表多个，此时想要都用默认的时候注意要加< >,如果不加也无法编译通过
//	tst.get();
//	tst.play();
//
//	CTest<char, int> tst2('A', 30);
//	tst2.play();	
//	//报错：void CTest<char, int>::play()	，该函数没有实现，实际上我们所实现的只有void CTest<int, double>::play()	，那么如何让play函数具备拓展复用性？
//	//解决方法：在play函数上加上函数模板，注意该处的参数列表不要设置默认类型噢~
//
//	CTest<char, int> tst3('A', 30);
//	tst3.play1('0', 20);
//	tst3.Test(10);
//	tst3.Test1<long>();
//	tst3.Name<long>('0',5);
//
//	system("pause");
//	return 0;
//}
//#include <iostream>
//using namespace std;
//#include <typeinfo>
//
//
////������������ָ�������ܼ��
////�����ģ������б��Ѿ�Ĭ��ָ�����磺template<typename TT = int,typename KK = int>����ô�����������ʱ����ʹ��Ĭ��Ҫ����ָ���Ļ���Ҫô����������ָ����Ҫô����ָ��KK���������ָ��TT��KKĬ�ϵ��������Ϊ������������ָ�������ܼ�ϡ�
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
////void CTest::play() {					//����ȱ����ģ��Ĳ����б�
////void CTest<int,double>::play() {		
////	cout << m_a << "	" << typeid(m_a).name() << endl;
////	cout << m_k << "	" << typeid(m_k).name() << endl;
////}
//
//
////���������ⲿ����ģ���Ա������ָ��Ĭ�ϵ�ģ���������
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
////��ģ�士����ģ��ʱ ע��ģ��������˳��
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
//	////������Ϊ��֪��TT�����ͣ��������ഴ������ʱҲ�޷�ȷ���ռ�
//
//	//CTest<int> tst;
//	////�����Կ���������list<int> lst;	
//	////ʵ���Ϸ�װ�õ�listҲ��һ��ģ����~
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
//	////ָ�����Ǿ���ָ���ģ�ûָ������Ĭ�ϵ�
//	//tst2.get();
//	
//	CTest< > tst(20, 3.14);
//			//��ģ������б�������ʱ��Ҫ����Ĭ�ϵ�ʱ��ע��Ҫ��< >,�������Ҳ�޷�����ͨ��
//	tst.get();
//	tst.play();
//
//	CTest<char, int> tst2('A', 30);
//	tst2.play();	
//	//����void CTest<char, int>::play()	���ú���û��ʵ�֣�ʵ����������ʵ�ֵ�ֻ��void CTest<int, double>::play()	����ô�����play�����߱���չ�����ԣ�
//	//�����������play�����ϼ��Ϻ���ģ�壬ע��ô��Ĳ����б�Ҫ����Ĭ��������~
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
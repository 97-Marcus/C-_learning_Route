//#include <iostream>
//using namespace std;
//#include <typeinfo>
//
//template<typename TT>
//class CTestAA
//{
//public:
//	TT m_T;
//public:
//	CTestAA() {
//		m_T = 20;
//	}
//};
//
//template<typename KK>
//class CTestBB
//{
//public:
//	CTestAA<KK> m_a;
//};
//
//template<typename MM,typename NN>
//class CTestCC 
//{
//public:
//	MM m_m;
//	NN m_n;
//
//	CTestCC(MM m, NN n) {
//		m_m = m;
//		m_n = n;
//	}
//};
//
//int main() {
//
//	CTestBB<int> tstBB;
//	cout << tstBB.m_a.m_T << "	" << typeid(tstBB.m_a.m_T).name() << "	" << typeid(tstBB.m_a).name() << endl;
//
//	CTestAA<int>	aa;
//	CTestCC<CTestAA<int>, int> tstCC(aa,10);
//	cout << tstCC.m_m.m_T << "	" << typeid(tstCC.m_m.m_T).name() << "	" << tstCC.m_n << "	" << typeid(tstCC.m_n).name() << endl;
//
//	system("pause");
//	return 0;
//}



//	STL: Standard Template Library	±ê×¼Ä£°å¿â
//	Áù×é¼þ£º	1. ÈÝÆ÷	Containers(sequenceÐòÁÐ/associative¹ØÁª)
//			2. µü´úÆ÷ Iterators
//			3. Ëã·¨ Algorithms
//			4. ÈÝÆ÷ÊÊÅäÆ÷ Container Adapters
//			5. ·ÖÅäÆ÷/¿Õ¼äÊÊÅäÆ÷ Allocators
//			6. ·Âº¯Êý Function Objects
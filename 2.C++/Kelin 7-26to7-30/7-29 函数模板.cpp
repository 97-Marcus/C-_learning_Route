//#include<iostream>
//#include<typeinfo>
//using namespace std;
//
////	template:����ģ��Ĺؼ���
////	typename:����ģ�����͵Ĺؼ���
////	TT:ͨ�õ����ͣ��ڵ��ú�������ʹ�õ�ʱ�����������Ĳ��������Զ�ƥ��
////	<typename TT>:ģ��Ĳ����б�,��Ҫ��������Ļ��ͼӶ��ż���д������template<typename TT,typename KK>
////	PS:Ҫ��������Ҫʹ�ú���ģ��ĺ����������У��м価����д���߰���Ķ�����
////	   ������������Ͷ����Ƿֿ��ģ���ô����ģ����Ǿ仰�������Ͷ���Ĳ��ֶ�Ҫ���ϡ�
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
////���������ģ�嵫�������ޣ��޷��Զ��Ƶ�TT������~������Ҫָ������
//template<typename TT=int>
//TT show1() {
//	cout << "show1" << endl;
//	return 0;
//}
////	c++98����ʧ�ܣ�����������ģ����ʹ��Ĭ��ģ�����������Ŀǰc++11�Ѿ���������ƣ�C++11֧���˺���ģ���Ĭ��ģ��������˴����Ա���ͨ����
////  PS:����C++11֧���˺���ģ���Ĭ��ģ��������������﷨�ϣ����߻��Ǵ���������ģ����Ϊ���Ĭ��ģ���������ָ��Ĭ��ֵʱ���������ա��������󡱵Ĺ������ָ�������������Ժ���ģ����˵�����Ǳ����~���ں���ģ����˵��Ĭ��ģ�������λ����Ƚ�����~
//
////	����ܹ��Ӻ���ʵ�����Ƶ������͵Ļ�����ôĬ��ģ������Ͳ��ᱻʹ�ã���֮��Ĭ��ģ���������ܻᱻʹ�á�
//
////C++98�Ľ����ʽ��
////template<typename TT>
////TT show1() {
////	cout << "show1" << endl;
////	return 0;
////}
////
////����ʱ�ں����������<Ĭ�ϵĲ�������>ʹ�ã��磺show1<int>();
//
////�����ڼ���ģ�� ���������� �޷��Զ��Ƶ�TT������~������Ҫָ�����ͣ�����ʱ�ں����������<Ĭ�ϵĲ�������>ʹ��
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
//	Add(a, b, d);//��ʱ���ݲ���ƥ�䣬TT�ͻ���int���ͣ�KK��double����~
//	
//	char k = 50;
//	show(k, 20);
//
//	show1();
//	//RTTI ��̬����ʶ��
//	//cout << typeid(show1<int>()).name() << endl;
//	//cout << typeid(show1<char>()).name() << endl;
//	
//	show2<double>(48);
//	show3(48);	//Ĭ���Ƶ���int���� �����ñ���������� Ҳ������<����>�ķ�ʽ
//	show3<char>(48);
//
//	//show4<char>(48);	
//	//��������ģ������б�����������Ҳ����Ҫָ�����~���£�
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
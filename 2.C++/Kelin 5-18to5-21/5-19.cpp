#include <iostream>
using namespace std;

//struct AA 
//{
//};

////new-detele
//int main()
//{
//
//	/*
//
//	// C�����е�malloc��̬����ռ䣬���ڶ�������Ŀռ䣬������*void����Ҫ������͵Ļ���ǿ��ת��
//	int* p1 = (int*)malloc(sizeof(int));
//	*p1 = 10;
//	cout << *p1 << endl;
//
//	free(p1);
//	p1 = NULL;
//
//	// C++�е�new��Ҳ���ڶ�������Ŀռ䣬new��ʲô�����򷵻�ʲô���͵�ָ��
//	int* p2 = new int;
//	*p2 = 20;
//	cout << *p2 << endl;
//
//	delete p2;
//	p2 = NULL;
//
//	//new����ʱ
//	int i = 0;
//	int* p1 = new int[4];	//���ص���������Ԫ�صĵ�ַ��������������ĵ�ַ
//	for (i = 0; i < 4; i++)
//	{
//		p1[i] = i;
//	}
//
//	for (i = 0; i < 4; i++)
//	{
//		cout << p1[i] << endl;
//	}
//
//	delete []p1;	//ɾ������ʱҪ����[]
//
//	*/
//
//	/*
//
//	//��ϰ��
//	//	1. new ����ָ��
//		int* (*p1) = new int*;
//	//	2. new ����ָ�� ����
//		int* (*p2) = new int* [4];
//	//	3. new ��������ָ��
//		int(*(*p3))[4] = new (int(*)[4]);
//		//��������
//		//int arr[4] = { 0,1,2,3 };
//		//int(*p4)[4] = &arr;
//		//p3 = &p4;
//
//		//cout << (*(*p3))[0] << endl;
//		//cout << (*(*p3))[1] << endl;
//		//cout << (*(*p3))[2] << endl;
//		//cout << (*(*p3))[3] << endl;
//
//	//	4. new ��ά����
//		int(*p5)[2] = new int[4][2];
//	//	5. new �ṹ��
//		AA* p6 = new AA;
//
//	*/
//
//
//
//	/*
//	
//	int a = 10;
//	cout << a << endl;
//
//	int b = 20;
//	cout << b << endl;
//
//	//int i = 0;
//	for (int i = 0; i < 10; i++)//�ֲ��ı���i��ֻ�ڸ�forѭ������Ч
//	{
//		cout << i << endl;
//	}
//
//	int arr[4] = { 0,1,2,3 };
//	for (int i = 0; i < 4; i++)	//�ֲ��ı���i��ֻ�ڸ�forѭ������Ч
//	{
//		cout << arr[i] << endl;
//	}
//
//	for (int val : arr) //for ѭ�����Ż�
//	{ 
//		cout << val << endl;
//	}
//
//
//	/*
//	
//	BOOL b = TRUE;  //������typedef int TRUE/FALSE 
//					//�� #define TRUE  1
//	cout << sizeof(b) << endl;//4���ֽ�(int����)
//
//	bool c = true;  //bool true false ��Ϊ�ؼ���
//	cout << sizeof(c) << endl;//1���ֽ�
//
//	*/
//
//	system("pause");
//	return 0;
//}



////string����
//
//#include<iostream>
//#include<string>
//using namespace std;
//
//void show(const char* p) 
//{
//	cout << p << endl;
//}
//
//int main() {
//
//	/*
//	//�ַ��������ֳ�ʼ������
//	char szChar[10] = "123123123";
//	char* pChar = "123123123";
//
//	//szChar = "asdasdasd";
//	//szCharʵ����ָ�����ַ����ĵ�ַ�����ܹ�ֱ�ӶԵ�ַ���и�ֵ�����������ַ������ƺ�������ȫ�ģ�
//	strcpy_s(szChar, 10, "asdasdads");
//	pChar = "asdasdasd";
//	//pCharָ����һ���µ��ַ�������ԭ����
//
//	//new �ַ�����
//	char* p2 = new char[10];
//	//p2 = "asdasdasd";
//	//�﷨���޴��󣬵��ǳ�����delete new��p2ʱ�����
//	//ָ����һ���µ��ַ��������Ǹո�������ַ����飬ɾ��ʱҲ��ɾ�����µ��ַ�������������ʱ���ַ�����
//	strcpy_s(p2, 10, "asdasdads");
//
//	delete []p2;
//	*/
//
//	//cout<<szChar<<"     "<<pChar<<endl;
//
//
//	
//	
//	string str = "asdasd";
//	cout << str << endl;
//
//	//string str;
//
//	str = "123123";		//����ֱ���޸�
//	cout << str << endl;
//
//	string str2 = str;	//����ֱ��ʹ��
//	cout << str2 << endl;
//
//	string str3 = str2 + "00000" + str;		//�������üӺŽ���ƴ��
//	cout << str3 << endl;
//	str3 = str2 + "00000" + str;			//�޸�ʱҲ���Խ���ƴ��
//	cout << str3 << endl;
//	str3 += "11111";
//	cout << str3 << endl;
//
//	string str4 = str3.substr(2, 6);
//	cout << str4 << endl;
//	//�ַ����Ľ�ȡ(��2��ʼ��ȡ6���ַ�)	  
//	//substr�����������������±꣬��ȡ������
//
//	//string str4;
//	//str4.c_str();
//
//	show(str4.c_str());  //��str4ת����const char *
//
//	
//
//
//	/*
//	
//	//C++�п���ֱ����str1==str2���ַ������ݽ����жϵ�C���Բ��У�C���ж��ǵ�ַ�������ַ������ݣ�
//	string str1 = "123";
//	string str2 = "456";
//	string str3 = "456";
//
//	if (str1 == str2) {
//		cout << "str1 == str2" << endl;
//	}
//	else {
//		cout << "str1 != str2" << endl;
//
//	}
//	if (str3 == str2) {
//		cout << "str3 == str2" << endl;
//	}
//	else {
//		cout << "str3 != str2" << endl;
//
//	}
//	*/
//
//	system("pause");
//		return 0;
//}

//
//#include <iostream>
//using namespace std;
//
////������Ĭ��ֵ�����������������ָ�������ܼ��
//
////����:�����Ͷ���ֿ�ʱ��������Ĭ��ֵֻ��������д����Ҫ�ڶ�����д��������ֿ��Ļ�ֱ��д����
//void show(int a, int c = 10, int b = 20);
//
////����
//void show(int a, int c, int b) {
//	cout << a << endl;
//}
//
////�����������Ҫ�ֿ������
//void show();
//void play() 
//{
//	show();
//}
//
//void show() 
//{
//	play();
//}
//
////�������أ�����ͬ��������֮�£���������ͬ�������б�ͬ�����������ͼ��������
//
//int Add(int a, int b) 
//{
//	return a + b;
//}
//
//int Add(int a, int b, int c) 
//{
//	return a + b + c;
//}
//
//namespace AA 
//{
//	double Add(double a, double b) //����������Add����ͬһ������
//	{
//		return a + b;
//	}
//}
//
//int main() {
//
//	show(2, 30, 40);
//
//	system("pause");
//	return 0;
//}
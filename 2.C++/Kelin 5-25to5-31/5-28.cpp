//#include <iostream>
//using namespace std;


/*
//�̳е��ŵ㣺�������й����ĳ�Ա��ȡ�������γɸ��࣬������������ʹ�ø����еĹ�����Ա������˴���ĸ����Լ���չ��

class People
{
public:
	void play() {
		cout << "play" << endl;
	}
protected:
private:
};

class CYellowPeople :public People
{
public:
protected:
private:
};

class CWritePeople :public People
{
public:
protected:
private:
};

class CBlackPeople :public People
{
public:
protected:
private:
};

class CBluePeople :public People
{
public:
protected:
private:
};

int main() {

	CYellowPeople people1;
	people1.play();
	CWritePeople people2;
	people2.play();
	CBlackPeople people3;
	people3.play();
	CBluePeople people4;
	people4.play();

	system("pause");
	return 0;
}

*/

//���ּ̳з�ʽ

//�ṹ����������
//1.Ĭ�ϵķ������η���ͬ	����˽�еģ��ṹ���ǹ�����; 
//2.Ĭ�ϵļ̳з�ʽ��ͬ		����˽�м̳У��ṹ���ǹ��м̳С�

//class CFather 
//{
//public:
//	int m_pub;
//
//	CFather() {
//		m_pub = 10;
//		m_pro = 11;
//		m_pri = 12;
//	}
//protected:
//	int m_pro;
//private:
//	int m_pri;
//};
//
//class CSon :public CFather 
//{
//public:
//	void show() {
//		cout << m_pub << endl;
//		cout << m_pro << endl;
//		// cout << m_pri << endl;	
//		// �����޷�����˽�г�Ա��˵��public�̳з�ʽ�£������е�˽�г�Ա�������еı�����ʽΪ���ɷ���
//	}
//protected:
//private:
//};
//
//class CSonSon :public CSon
//{
//public:
//	void play() {
//		cout << "m_pro" << endl;	//������������Ȼ����ʹ�� ˵��m_pro�Ǳ�����
//	}
//protected:
//private:
//};
//
//int main() {
//
//	CSon son;
//	son.m_pub = 13;
//	// son.m_pro = 14;
//	// �����޷����ʱ�������Ա�������ڿ��Է��ʣ������ⲻ�ɷ���
//
//	system("pause");
//	return 0;
//}

//class CFather
//{
//public:
//	int m_pub;
//
//	CFather() {
//		m_pub = 10;
//		m_pro = 11;
//		m_pri = 12;
//	}
//protected:
//	int m_pro;
//private:
//	int m_pri;
//};
//
//class CSon :protected CFather
//{
//public:
//	void show() {
//		cout << m_pub << endl;
//		cout << m_pro << endl;
//		// cout << m_pri << endl;	
//		// �����޷�����˽�г�Ա��˵��protected�̳з�ʽ�£������е�˽�г�Ա�������еı�����ʽΪ���ɷ���
//	}
//protected:
//private:
//};
//
//class CSonSon :protected CSon
//{
//public:
//	void play() {
//		cout << "m_pro" << endl;	//  ������������Ȼ����ʹ�� ˵��m_pro�Ǳ�����
//		cout << "m_pub" << endl;	//	������������Ȼ����ʹ�� ˵��m_pub�Ǳ�����
//	}
//protected:
//private:
//};
//
//int main() {
//
//	CSon son;
//	// son.m_pub = 13;
//	// �����޷����ʣ������ڿ��Է��ʣ������ⲻ�ɷ���
//	// son.m_pro = 14;
//	// �����޷����ʱ�������Ա�������ڿ��Է��ʣ������ⲻ�ɷ���
//
//	CSonSon sonson;
//	sonson.play();
//
//	system("pause");
//	return 0;
//}

//class CFather
//{
//public:
//	int m_pub;
//
//	CFather() {
//		m_pub = 10;
//		m_pro = 11;
//		m_pri = 12;
//	}
//protected:
//	int m_pro;
//private:
//	int m_pri;
//};
//
//class CSon :private CFather
//{
//public:
//	void show() {
//		cout << m_pub << endl;
//		cout << m_pro << endl;
//		// cout << m_pri << endl;	
//		// �����޷�����˽�г�Ա��˵��protected�̳з�ʽ�£������е�˽�г�Ա�������еı�����ʽΪ���ɷ���
//	}
//protected:
//private:
//};
//
//class CSonSon :private CSon
//{
//public:
//	void play() {
//		//cout << "m_pro" << endl;	//  ���������в��ɷ��� ˵��m_pro��˽�е�
//		//cout << "m_pub" << endl;	//  ���������в��ɷ��� ˵��m_pub��˽�е�
//	}
//protected:
//private:
//};
//
//int main() {
//
//	CSon son;
//	// son.m_pub = 13;
//	// �����޷����ʣ������ڿ��Է��ʣ������ⲻ�ɷ���
//	// son.m_pro = 14;
//	// �����޷����ʱ�������Ա�������ڿ��Է��ʣ������ⲻ�ɷ���
//
//	system("pause");
//	return 0;
//}
//

/*

//�̳��µĹ��������

class CFather {
public:
	int m_a;
	//CFather() {
	//	m_a = 10;
	//	cout << "CFather" << endl;
	//}
	CFather(int a) {
		m_a = a;
		cout << "CFather(int a)" << endl;
	}
	~CFather() {
		cout << "~~CFather" << endl;
	}
};

class Cson :public CFather {
public:
	//Cson() :CFather() {	//�̳����޲εĹ��캯��
	//	cout << "CSon" << endl;
	//}
	Cson(int a) :CFather(a) {	//ע��̳����вεĹ��캯����ν��д���
		cout << "CSon" << endl;
	}
	~Cson() {
		cout << "~~CSon" << endl;
	}
};

int main() {

	//{
	//Cson son;
	//cout << son.m_a << endl;
	//}

	{
		Cson son(111);
		cout << son.m_a << endl;
	}

	system("pause");
	return 0;
}


*/




//�����ָ��

// class CFather{
// public:
//	int m_fa;
//
//	void Show(/* CFather * const this */){
//		cout<<this<<endl;
//		cout<<"Show()"<<endl;
//	}
//};
//
//
// class CSon:public CFather{
//};
//
//
//int main() {
//	CSon son ;
//	cout<<&son<<endl;
//	son.Show();
//
//	//�������ָ��ָ������Ķ���
//	CFather* pFa = &son;
//	cout << &pFa << endl;//&pFa�������  pfa���ָ����׵�ַ  ������pfa������ŵ�son�ĵ�ַ
//	cout << &*pFa << endl;//&*pFa�����pfa������ŵ�����Ҳ����son�ĵ�ַ ���Ժ�&son���������һ��
//
//	//�����������ָ��ָ����Ķ���
//	//CFather fa;
//	//CSon *pSon = &fa;
//
//	system("pause");
//	return 0;
//}

/*

//�����������ָ��ָ������Ķ�����һ���ԣ�ȷʵ�����˴��븴���ԣ�����ʹ�ø����еĹ��г�Ա
//����Ҳ�����������������⣺���������ȥ���ø����������еĹ����أ���̬�����������⣬���忴������̬�Ĳ��֡�

class People {
public:
	void play() { 
		cout << "play" << endl;
	}
};

class CYellowPeople : public People {
public:
	void show() {
	
	}
};

class CWhitePeople : public People {
public:
};

void GetPlay(People* peo) {
	peo->play();
	//peo->show();	�޷����ã�Ҳ������Ҫ������������⣺���������ȥ���ø����������еĹ����أ�
}

int main() {

	CYellowPeople yePoe;
	GetPlay(&yePoe);

	CWhitePeople whPeo;
	GetPlay(&whPeo);

	system("pause");
	return 0;
}


*/


//
////���Ա����ָ��
//
//
//class CFather
//{
//public:
//	void show(int a, int b, int c) {
//		cout << "show(int a, int b, int c)" << endl;
//	}
//protected:
//private:
//};
//
//class CTest:public CFather
//{
//public:
//	void show(int a) {
//		cout << "show(int a)" << endl;
//	}
//
//	void show(int a, int b) {
//		cout << "show(int a, int b)" << endl;
//	}
//protected:
//private:
//};
//
//
//void play() {
//	cout << "play" << endl;
//}
//
//void (*p_fun)() = &play;	//	����ָ��	p_fun��һ������
//
//typedef void (*P_FUN)();	//	P_FUN��һ������
//typedef void (*P_FUN1)(int a, int b);
//
//void GetPlay(P_FUN p_fun) {
//	(*p_fun)();
//}
//
////����ָ��ĺô���
////��ʵ��ͬһ���ܵĲ�ͬģ��ͳһ��ʶ����������ṹ������������ά���������˴���ĸ����Լ���չ�ԣ����ڷֲ���ƣ�����ϵͳ���󣬽��ʹ�����϶�
//
//int main() {
//
//	CTest tst;
//	tst.show(1);
//	tst.show(1,2);//	ͬһ������ Ҳ�Ǻ������صĹ�ϵ ���Ը��ݲ����Զ�ʶ��
//
//	//tst.show(1, 2, 3);//	����û�����غ�������3������	��Ҳ����˵�޷����ݲ�������ʶ���ˣ������Ǻ�������
//	tst.CFather::show(1, 2, 3);//	��Ҫָ����������������ʶ���Ӧ�ĺ���
//	//���أ��������������ͬ������
//
//	play();
//	(*p_fun)();	//	�������
//
//	P_FUN p_fun1 = &play;
//	(*p_fun1)();
//
//	//P_FUN1 p_fun2 = &CTest::show;	//��������ʼ�������޷��ӡ�overloaded - function��ת��Ϊ��P_FUN1��
//									//Ҳ������Ҫ�������Ա����ָ����
//
//	/*play();
//	CTest tst;
//	tst.CTest::show(1, 2);*/	//���Կ��� tst.CTest:: ��һ��������������ͨ������ͬ�ĵط�
//
//	//���CTest::������
//	//::*	���ڶ������Ա����ָ��  ��::&��������������������Էֿ� ��ҪдTest::��*P_FUN1��
//	//���Ա����ָ�룺���������⣬����ָ�����Ա������һ�������ָ��
//	typedef void (CTest::*P_FUN2)(int a, int b);
//	P_FUN2 p_fun2 = &CTest::show;
//	//(*p_fun2)(1, 2);//�����������Ƿ�	û�н��tst.������ thisָ��û��ָ����� Ϊ��������� ��Ҫ�������
//	
//	//���tst.������
//	//.*	�ö���ȥ�������Ա����ָ�� ��.*��������������������Էֿ�
//	CTest tst2;
//	(tst2.*p_fun2)(1, 2);
//
//	//->*	��ָ�����new�Ķ���ȥ�������Ա����ָ�� ��->*��������������������Էֿ�
//	CTest* pTst = new CTest;
//	(pTst->*p_fun2)(3, 4);
//
//	GetPlay(&play);
//
//	system("pause");
//	return 0;
//}
//


//class People {
//public:
//	void play() {
//		cout << "play" << endl;
//	}
//};
//
//class CYellowPeople : public People {
//public:
//	void play() {
//		cout << "CYellowPeople play" << endl;
//	}
//};
//
//class CWhitePeople : public People {
//public:
//	void play() {
//		cout << "CWhitePeople play" << endl;
//	}
//};
//
//typedef void (People::* P_FUN1)();
//
//void GetPlay(People* peo, P_FUN1 p_fun) {
//	(peo->*p_fun)();
//}
//
//int main() {
//
//	P_FUN1 p_fun = (P_FUN1)&CYellowPeople::play;	//(P_FUN1) ʹ����ǿ��ת��
//	People* pPeople = new CYellowPeople;
//	(pPeople->*p_fun)();
//
//	GetPlay(pPeople, (P_FUN1)&CWhitePeople::play);
//
//	system("pause");
//	return 0;
//}
//

//#include <iostream>
//using namespace std;


/*
//继承的优点：将子类中公共的成员提取出来，形成父类，如此来子类可以使用父类中的公共成员，提高了代码的复用性及拓展性

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

//三种继承方式

//结构体和类的区别：
//1.默认的访问修饰符不同	类是私有的，结构体是公共的; 
//2.默认的继承方式不同		类是私有继承，结构体是公有继承。

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
//		// 报错：无法访问私有成员，说明public继承方式下，父类中的私有成员在子类中的表现形式为不可访问
//	}
//protected:
//private:
//};
//
//class CSonSon :public CSon
//{
//public:
//	void play() {
//		cout << "m_pro" << endl;	//在孙子类中依然可以使用 说明m_pro是保护的
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
//	// 报错：无法访问被保护成员，在类内可以访问，在类外不可访问
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
//		// 报错：无法访问私有成员，说明protected继承方式下，父类中的私有成员在子类中的表现形式为不可访问
//	}
//protected:
//private:
//};
//
//class CSonSon :protected CSon
//{
//public:
//	void play() {
//		cout << "m_pro" << endl;	//  在孙子类中依然可以使用 说明m_pro是保护的
//		cout << "m_pub" << endl;	//	在孙子类中依然可以使用 说明m_pub是保护的
//	}
//protected:
//private:
//};
//
//int main() {
//
//	CSon son;
//	// son.m_pub = 13;
//	// 报错：无法访问，在类内可以访问，在类外不可访问
//	// son.m_pro = 14;
//	// 报错：无法访问被保护成员，在类内可以访问，在类外不可访问
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
//		// 报错：无法访问私有成员，说明protected继承方式下，父类中的私有成员在子类中的表现形式为不可访问
//	}
//protected:
//private:
//};
//
//class CSonSon :private CSon
//{
//public:
//	void play() {
//		//cout << "m_pro" << endl;	//  在孙子类中不可访问 说明m_pro是私有的
//		//cout << "m_pub" << endl;	//  在孙子类中不可访问 说明m_pub是私有的
//	}
//protected:
//private:
//};
//
//int main() {
//
//	CSon son;
//	// son.m_pub = 13;
//	// 报错：无法访问，在类内可以访问，在类外不可访问
//	// son.m_pro = 14;
//	// 报错：无法访问被保护成员，在类内可以访问，在类外不可访问
//
//	system("pause");
//	return 0;
//}
//

/*

//继承下的构造和析构

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
	//Cson() :CFather() {	//继承下无参的构造函数
	//	cout << "CSon" << endl;
	//}
	Cson(int a) :CFather(a) {	//注意继承下有参的构造函数如何进行传参
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




//父类的指针

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
//	//允许父类的指针指向子类的对象
//	CFather* pFa = &son;
//	cout << &pFa << endl;//&pFa输出的是  pfa这个指针的首地址  而不是pfa里所存放的son的地址
//	cout << &*pFa << endl;//&*pFa输出了pfa里所存放的内容也就是son的地址 所以和&son的输出内容一样
//
//	//不允许子类的指针指向父类的对象
//	//CFather fa;
//	//CSon *pSon = &fa;
//
//	system("pause");
//	return 0;
//}

/*

//由于允许父类的指针指向子类的对象这一特性，确实提升了代码复用性，可以使用父类中的公有成员
//但其也存在仍须提升的问题：如何令父类可以去调用各子类中特有的功能呢？多态将解决这个问题，具体看后续多态的部分。

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
	//peo->show();	无法调用，也就是需要提升解决的问题：如何令父类可以去调用各子类中特有的功能呢？
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
////类成员函数指针
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
//void (*p_fun)() = &play;	//	函数指针	p_fun是一个变量
//
//typedef void (*P_FUN)();	//	P_FUN是一个类型
//typedef void (*P_FUN1)(int a, int b);
//
//void GetPlay(P_FUN p_fun) {
//	(*p_fun)();
//}
//
////函数指针的好处：
////将实现同一功能的不同模块统一标识起来，代码结构更加清晰易于维护，提升了代码的复用性及拓展性，便于分层设计，利于系统抽象，降低代码耦合度
//
//int main() {
//
//	CTest tst;
//	tst.show(1);
//	tst.show(1,2);//	同一个类中 也是函数重载的关系 可以根据参数自动识别
//
//	//tst.show(1, 2, 3);//	报错：没有重载函数接受3个参数	，也就是说无法根据参数进行识别了，不再是函数重载
//	tst.CFather::show(1, 2, 3);//	需要指定父类的作用域进行识别对应的函数
//	//隐藏：父类和子类中有同名函数
//
//	play();
//	(*p_fun)();	//	间接引用
//
//	P_FUN p_fun1 = &play;
//	(*p_fun1)();
//
//	//P_FUN1 p_fun2 = &CTest::show;	//报错：“初始化”：无法从“overloaded - function”转换为“P_FUN1”
//									//也就是需要定义类成员函数指针了
//
//	/*play();
//	CTest tst;
//	tst.CTest::show(1, 2);*/	//可以看出 tst.CTest:: 这一部分是区别于普通函数不同的地方
//
//	//解决CTest::的问题
//	//::*	用于定义类成员函数指针  “::&”是整体操作符，不可以分开 不要写Test::（*P_FUN1）
//	//类成员函数指针：定义在类外，可以指向类成员函数的一个特殊的指针
//	typedef void (CTest::*P_FUN2)(int a, int b);
//	P_FUN2 p_fun2 = &CTest::show;
//	//(*p_fun2)(1, 2);//报错：操作数非法	没有解决tst.的问题 this指针没有指向对象 为解决该问题 需要定义对象
//	
//	//解决tst.的问题
//	//.*	用对象去调用类成员函数指针 “.*”是整体操作符，不可以分开
//	CTest tst2;
//	(tst2.*p_fun2)(1, 2);
//
//	//->*	用指针对象（new的对象）去调用类成员函数指针 “->*”是整体操作符，不可以分开
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
//	P_FUN1 p_fun = (P_FUN1)&CYellowPeople::play;	//(P_FUN1) 使用了强制转换
//	People* pPeople = new CYellowPeople;
//	(pPeople->*p_fun)();
//
//	GetPlay(pPeople, (P_FUN1)&CWhitePeople::play);
//
//	system("pause");
//	return 0;
//}
//

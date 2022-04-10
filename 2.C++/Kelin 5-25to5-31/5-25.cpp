//#include <iostream>
//using namespace std;

/*

class CTest
{
public:
	CTest() {
		cout << "CTest()" << endl;
	}
	~CTest() {
		cout << "~CTest()" << endl;
	}
protected:
private:
};

CTest tst2;	//3. 全局对象 程序启动自动为对象分配空间，直到程序结束生命周期结束（看什么时候调用析构函数）

static CTest tst3;	//4. 静态全局对象 程序启动自动为对象分配空间，直到程序结束生命周期结束（看什么时候调用析构函数）

//全局对象和静态全局对象的区别：作用范围不同，静态全局对象为文件作用域，全局对象为整个项目工程。也就是说在两个源文件中，不可以重复定义两个名字类型一样的全局对象，但可以重复定义两个名字类型一样的静态全局对象

CTest* ptst = NULL;
void show() {
	static CTest tst;//生命周期 无论调用几次该函数，其都在第一次调用该函数的时候创建对象，直到程序结束，在内存中只有一份
	ptst = &tst;//取出tst的地址放在ptst这个指针里
}//无论运行多少遍这个函数，tst对象的地址都不会变

//5. 临时对象(少用)
CTest GetTest() {
	CTest tst;
	return tst;
}

int main() {

	//cout << "-------------------" << endl;
	//CTest tst;	//1. 局部对象（栈区），只在当前函数内生效，生命周期在函数结束时结束
	//
	//CTest* pTst = new CTest;	//2. new对象，生命周期需要delete才会结束

	////show();

	////CTest tst();
	////调用无参构造时不要这样写，有时候编译器会误认为这是函数说明，应写：Ctest tst;
	//
	//cout << "-------------------" << endl;
	//CTest(2);//临时对象（匿名对象） 其生命周期只有当前这一行，遇到这一行的；后就会被回收
	//cout << "-------------------" << endl;

	cout << "-------------------" << endl;
	GetTest();
	cout << "-------------------" << endl;

	system("pause");
	return 0;
}

*/


/*
//类的初步认识

class Ctest {
public:
	int m_a;
public:
	Ctest(int a) {
		m_a = a;
	}
	~Ctest() {
	
	}
	void show() {
	
	}
	void play() {
	
	}
};

int main() {

	//Ctest tst;
	//cout << sizeof(tst) << endl;
	//cout << sizeof(Ctest) << endl;	
	////空类定义的对象的大小输出1  起到占位的作用，标识该对象在内存空间是真实存在的

	//Ctest tst;
	//cout << sizeof(tst) << endl;
	//cout << sizeof(Ctest) << endl;
	////类中有int后，不再需要占位了，因为int的4个字节本身已经存在了，所以该大小输出为4而非5，不再需要加上占位的1
	////类中写了两个空函数后依然输出4，能说明类成员属性占用对象的内存空间，定义对象时存在；类成员函数不占用对象的内存空间，其占用的是应用程序的内存空间，在编译期就存在（程序启用之前，嵌入在exe程序文件内）

	Ctest tst1(1);
	Ctest tst2(2);
	//断点调试中局部变量表中可以看到tst1中m_a是1，tst2中m_a是2，说明类成员属性中，两个对象在两个不同的内存空间中存在两份，也就是说多个对象存在多份，几个对象存在几份，但类成员函数并非如此，其属于类，不属于对象，因此只有一份

	system("pause");
	return 0;
}

*/




////this指针
//
//class Ctest {
//public:
//	int m_a;
//public:
//	Ctest(int a) {
//		m_a = a;
//	}
//
//	//this 指针 : CTest* const this;
//	//类中非静态成员函数中有一个默认的隐含的参，this指针
//	//this 指针：用于连接成员属性和成员方法的桥梁，哪个对象调用了函数this指针就指向哪个对象
//	void show(/* CTest* const this */) {
//		cout << m_a << endl;
//		//cout << this->m_a << endl;
//	}
//
//	void play(/* CTest* const this */) {
//		cout << "play()" << endl;
//		//cout << m_a << endl;
//	}
//
//};
//
//int main() {
//
//	//Ctest tst1(1);
//	//tst1.show();//将tst1这一对象的地址给this，然后对应输出this的m_a也就是tst1这一对象内定义的m_a的值为1
//	//Ctest tst2(2);
//	//tst2.show();//将tst2这一对象的地址给this，然后对应输出this的m_a也就是tst2这一对象内定义的m_a的值为2
//
//	Ctest* p = NULL;
//	//p->m_a = 10;	//程序崩溃
//	p->play();	//没有对象，此时this指针为NULL，调用play这一函数时如果没有使用到成员变量m_a则可正常运行，但如果使用到m_a则程序崩溃，说明this这一指针确实链接了对象（成员变量）和该函数（成员方法）
//
//
//	system("pause");
//	return 0;
//}
//


/*

//静态成员属性

class CTest {
public:
	static int m_a;
	int m_b;
	CTest() {
		cout << m_a << endl;
		//m_a = 20;	//赋值
	}//	构造函数在创建对象的时候去执行，因此m_a = 10的初始化要等定义了对象再去初始化，但这与“静态成员属性不属于对象，属于类”相违背。而实际上此处并非初始化，而是初始化之后的一个赋值。

	//变量初始化指的是变量在定义的时候的赋值，而m_a这个变量作为staitc的静态成员属性，静态成员属性编译器就存在了，同时需要在类外进行初始化，因此等代码跑到m_a = 20这一行时，由于m_a已经定义初始化为20了，所以这一行只能是修改m_a的赋值

	void Show() {
		cout << m_a << endl;	//this->m_a
		cout << m_b << endl;	//this->m_b
		this;
		CTest::play();
	}

	//静态成员函数
	//和普通函数一样，编译期就存在，属于类并只有一份，但两者最大的区别在于this指针
	//和静态成员变量一样，可以用对象去使用，也可通过类名作用域去使用
	static void play() {
		cout << "void play()" << endl;
		cout << m_a << endl;
		//cout << m_b << endl;//报错：对非静态成员CTest::m_b的非法引用
		//原因：静态成员函数在编译期就存在，不需要通过对象，但m_b此时根本不存在
		//this;//报错：this只能用于非静态成员函数的内部，也就是说，静态成员函数没有隐藏的this指针
		
	}
};

//类型 类名即作用域::变量名 = 初始化值
int CTest::m_a = 10;	//类外初始化，如果有多个类中都有m_a需要定义，那么需要作用域来区分，所以定义的时候需要有类名~

int main() {

	//CTest tst;//定义对象时触发了构造函数，此时报错：无法解析外部符号m_a，也就是说m_a声明了但没有定义。而其不属于对象，所以应该在类外进行定义。（int CTest::m_a = 10;）

	//cout << sizeof(CTest) << endl;	//输出1：说明依然占位，则静态成员属性不属于对象，属于类
	//cout << CTest::m_a << endl;	//由于静态成员属性不属于对象，属于类，因此可以直接通过类名作用域来使用这一成员，比如CTest::m_a，当然以对象使用也可以，如下：cout<<tst.m_a<<endl;

	//CTest tst1;
	//cout << tst1.m_a << endl;
	//tst1.m_a = 12;
	//CTest tst2;
	//cout << tst2.m_a << endl;
	////所有对象共享该静态成员变量，也就是说，其中一个对象改了后，其他的也会改

	CTest tst;
	tst.play();
	CTest::play();

	system("pause");
	return 0;
}

*/
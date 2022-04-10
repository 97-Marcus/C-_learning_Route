////	头文件：变量、函数、类型声明、类的定义、宏
//
//
//void show(int a);	//函数的声明
//
////int a;		//	根据在内存中是否申请空间来确定其为声明还是定义 
//			//	该句为变量的定义
////int b = 10;			//	定义并初始化
//
////extern int c;			//	变量的声明
////extern int c = 30;	//	定义
//
//class CTest
//{
//public:
//	int m_a;
//	const int m_b;
//	//const一旦定义就不能修改，所以要去设置其初始值时应该在参数列表里设置
//	static int m_c;
//	//类外初始化，编译期就存在，不属于对象
//public:
//	CTest();
//	~CTest();
//	void show();//	类成员函数的声明
//	static void play();
//	void code()const;	//	常函数
//	virtual void run();	//	虚函数
//protected:
//private:
//};
//
////int CTest::m_c = 60;	//报错：多重定义
//						//原因：这个头文件在6-2.cpp和6-2-1.cpp都被include了一次，所以m_c被定义了两次，重定义了，说明静态的这个定义最好是不要定义在头文件中，应该放到源文件里进行初始化
//#include <iostream>
//using namespace std;

//
//
////继承关系下多态发生的原理
//
//class CFather
//{
//public:
//	CFather() {
//		cout << "father" << endl;
//	}
//	virtual void show() {
//		cout << "CFather::show" << endl;
//	}
//	virtual void code() {
//		cout << "CFather::code" << endl;
//	}
//protected:
//private:
//};
//
//class CSon :public CFather
//{
//public:
//	CSon() {
//		cout << "son" << endl;
//	}
//	virtual void play() {
//		cout << "CSon::play" << endl;
//	}
//	/*virtual*/ void show() {	
//		//覆盖：子类的虚函数重写了父类的虚函数，在虚函数列表中会替换掉父类的虚函数
//		//同时，由于子类重写父类的虚函数，子类前无论加不加虚函数关键字virtual，该子类函数均为虚函数
//		cout << "CSon::show" << endl;
//	}
//protected:
//private:
//};	//继承关系下，子类不但继承父类成员，还会继承父类的虚函数列表
//
//int main() {
//
//	//CFather* pFa = new CSon;
//	////new的是哪个子类，那么vfptr（虚函数指针）最终就指向哪个子类的虚函数列表
//
//	//pFa->show();
//	////pFa->play();	//无法使用，play并非CFather的成员
//
//	//CSon* pSon = new CSon;
//	//pSon->play();
//
//	//除了上述方式，还可以通过手动遍历数组来实现以虚函数指针调用虚函数
//	CFather* pFa = new CSon;	//父类指针指向new的子类的对象
//	//(int*)pFa：以int（同为4个字节）强制转换成new的子类的前四位，也就是虚函数指针
//	//(*(int*)pFa):间接引用(int*)pFa，虚函数指针指向虚函数列表的首地址
//	//(int*)(*(int*)pFa):以int（同为4个字节）强制转换成虚函数列表的前四位，也就是第一个虚函数的指针
//	//(((int*)(*(int*)pFa)) + 0):偏移0后(取第0个元素)间接引用，也就是取到第一个元素【0】里的值，也就是第一个虚函数指针，指向的第一个虚函数
//	typedef void(*P_FUN)();//定义一个函数指针
//	P_FUN p_fun1 = (P_FUN) * (((int*)(*(int*)pFa)) + 0);
//	P_FUN p_fun2 = (P_FUN) * (((int*)(*(int*)pFa)) + 1);//获取虚函数列表第二个元素【1】
//	P_FUN p_fun3 = (P_FUN) * (((int*)(*(int*)pFa)) + 2);//获取虚函数列表第三个元素【2】
//	(*p_fun1)();
//	(*p_fun2)();
//	(*p_fun3)();
//
//	system("pause");
//	return 0;
//}
//
//
//
//

//
//
////虚析构
//
//class CFather
//{
//public:
//	CFather(){
//		cout << "father" << endl;
//	}
//	virtual ~CFather() {		//	虚析构
//		cout << "~father" << endl;
//	}
//protected:
//private:
//};
//
//class CSon :public CFather
//{
//public:
//	CSon() {
//		cout << "son" << endl;
//	}
//	~CSon() {
//		cout << "~son" << endl;
//	}
//protected:
//private:
//};
//
//void Fun(CFather* pFa) {
//	delete pFa;//	此处无法进行强转，因为根本不知道其指向的是哪个子类，因此还是无法执行子类的析构.
//}
//
//int main() {
//	//CSon* pson = new CSon;
//	//delete pson;
//	//pson = NULL;
//	//	父类构造 子类构造 子类析构 父类析构
//
//	//CFather* pFather = new CSon;
//	//delete pFather;
//	//pFather = NULL;
//	//	父类构造 子类构造 父类析构
//	//	delete pFather销毁的是父类的空间 是按照父类类型进行删除的 所以和子类析构没有关系
//	//	利用强转：	delete (CSon*)pFather;	//	父类构造 子类构造 子类析构 父类析构	
//	//	但该方式比较勉强，如果是void Fun(CFather* pFa)处的情况则无法完成要求，子类的析构还是执行不了，子类构造new了空间，如果不执行析构的话会造成空间浪费，所以要想办法执行子类的析构，故采用虚析构
//
//	//	虚析构是虚函数，因此调用时流程和虚函数一样，需要虚函数指针，遍历虚函数列表，此时虚函数列表内的析构函数实际上为子类的析构函数，因此，之所以能够调用子类的析构函数，其本质原理是多态行为的发生
//
//	//	虚函数列表内的析构函数实际上为子类的析构函数的原因如下：
//				//覆盖：子类的虚函数重写了父类的虚函数，在虚函数列表中会替换掉父类的虚函数
//				//同时，由于子类重写父类的虚函数，子类前无论加不加虚函数关键字virtual，该子类函数均为虚函数
//	//	因此虚函数列表里是子类的析构，而程序后面还会走父类的析构，这个部分就不再是走虚函数列表的原因了，而是因为父类类型指针本身要去删除其所占用的父类的空间
//
//	CFather* pFather = new CSon;
//	delete pFather;
//
//
//	system("pause");
//	return 0;
//}
//


//	多态的缺点：
//	1.	效率较低(正常的函数直接调用，但虚函数要指针遍历虚函数列表……)
//	2.	占用额外空间（每定义一个对象虚函数指针占多4字节，每个类的虚函数列表也占用空间……）
//	3.	安全性隐患（可以通过某些方法调用访问私有的虚函数，私有的虚函数也在虚函数列表里……例：P_FUN p_fun1 = (P_FUN) * (((int*)(*(int*)pFa)) + 0)）



////纯虚函数
//
//class CFather
//{
//public:
//	virtual void play() = 0;//纯虚函数
//		//以前面三种人，每种人有不同玩法为例，如果父类中的玩没有公共的可以实现的部分（or父类play函数不需要实现），需要各个子类的人种中有各自的玩法，此时可以将父类中设置为纯虚函数。
//protected:
//private:
//};
//
//class CSon:public CFather
//{
//public:
//	virtual void play() {
//		cout << "play" << endl;
//	}
//protected:
//private:
//};
//
//int main() {
//
//	CSon son;	//在CSon中没有函数的情况下会报错：纯虚函数没有替代项
//				//说明：子类必须重写父类的纯虚函数，纯虚函数必须在子类中实现，父类无法实现
//	son.play();
//
//	//CFather father;	
//	//不允许使用抽象类类型定义对象，也就是说有纯虚函数的CFather类是抽象类，抽象类是不允许定义对象的。
//	//抽象类：类中存在纯虚函数	VS	接口类：类中虚函数都是纯虚函数（接口类当然也不允许定义对象）
//
//	system("pause");
//	return 0;
//}
//

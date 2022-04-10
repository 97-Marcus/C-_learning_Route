#include <iostream>
using namespace std;

//	设计模式

//	单例模式：
//	1.	当前类 有且只有 一个实例(对象) 
//						----->类外不能定义对象 只能使用类内定义的一个对象
//	2.	能够自主创建这个实例（而不是调用者去创建实例）
//	3.	向全局开放这个实例

////	懒汉式：要用到的时候再去创建唯一实例（时间换空间的做法，节省空间但消耗时间）
//
//class CObject
//{
//public:
//	int m_a;
//private:	//私有的 -----> 类外不能定义对象
//	//static int ObjCount;	//计数器	
//	static CObject* m_pObjec;
//private:
//	CObject() {
//		m_a = 10;
//	}
//	CObject(const CObject& obj) {
//		this->m_a = obj.m_a;
//	}
//	~CObject() {
//	
//	}	//PS：编译器提供的默认的是公有的~
//public:
//	static CObject* GetInstance() 	
//		//设置一个接口 -----> 类外可以使用类内的唯一对象
//		//					(static 可以不通过对象进行调用)
//		//采用CObject* -----> 指针的形式通过地址来来使用 
//		//不建议采用CObject -----> 因为临时对象有可能对程序造成一定影响
//	{	
//		//if (ObjCount >= 1) 
//		if (m_pObjec) 
//		{
//			//return NULL;
//			return m_pObjec;
//		}
//		//ObjCount++;
//		m_pObjec = new CObject;	
//				//单线程下无问题，但多线程会出现问题，其解决方法是在前后加一个锁，造成阻塞等待，只有一个线程能进36-40行
//		return m_pObjec;
//	}
//	static void Destory(CObject*& p) {
//		if (m_pObjec) {
//			delete m_pObjec;
//			m_pObjec = NULL;
//		}
//		p = NULL;
//	}
//};
//
////int CObject::ObjCount = 0;	//静态成员类外初始化
//CObject* CObject::m_pObjec = NULL;
////两个静态成员的作用都是为了去建议有没有创建多个对象，所以可以进行优化，注释掉ObjCount，将if判断中的内容进行修改，看m_pObjec是否为空即可
//
//int main() {
//
//	//CObject* pObject1 = CObject::GetInstance();
//	//CObject* pObject2 = CObject::GetInstance();	
//			//	情况：pObject1和pObject2分别具有不同的地址
//			//	问题1：可以多次调用GetInstance以获得多个对象……
//			//	改进方法：加一个计数器以统计当前实例有多少个对象	见行12及27-31行
//
//			//	改进后情况：pObject1具有地址，pObject2为NULL
//			//	问题2：违反“向全局开放这个实例”，pObject1和pObject2应该获取到相同地址才对
//			//	改进方法：利用ObjCount进行置0
//
//	CObject* pObject1 = CObject::GetInstance();
//	//	ObjCount = 0;
//	CObject* pObject2 = CObject::GetInstance();
//
//			//	此时pObject1和pObject2分别具有不同的地址…说明还是有问题
//			//	解决方法：ObjCount不能是全局变量，换成类内私有的静态成员变量，静态成员变量在类外进行初始化，此时ObjCount在目前函数内就不能使用了。
//	
//			//	但问题仍未解决，如何让其满足“1.	当前类 有且只有 一个实例(对象)”且满足“3.	向全局开放这个实例”？也就是说满足一对多的形式。
//			//	41行的if (ObjCount >= 1) { return NULL; }这个部分就存在问题，不能返回空。一对多的形式可以借助静态成员变量来实现。
//
//	//CObject obj1 = *pObject1;	
//			//obj1的地址和pObject1/pObject2的地址不同，说明还是可以创建多个对象…
//			//此处实际为对象给对象初始化，其调用的是拷贝构造函数
//			//解决方法：将析构函数写为私有的，那么obj1生命周期结束时无法调用析构，则该句无法正常运行会报错。（但实际上，拷贝构造也可以解决这个问题，但尽量把拷贝构造和析构都加上）
//
//	//CObject* pobj3 = new CObject(*pObject1);	
//	//delete pobj3;	//虽然78行没有报错 但是delete调用析构时还是会报错
//			//但如果不使用delete，78行依然可以正常运行，pobj3对象的地址不同于pObject1，违反了单例模式，其解决方法是：将拷贝构造也加上到私有的。
//
//	pObject1->m_a = 20;
//	cout << pObject2->m_a << endl;
//
//	//delete pObject1;
//			//问题:该实例最终销毁时由于析构私有，所以无法删除，所以还需要提供一个删除的方法。
//
//	//CObject::Destory();	
//	//cout << pObject2->m_a << endl;
//			//类成员的指针确实置空了，但pObject1和pObject2没有被置空，只是pObject1和pObject2无法再使用里面的成员了（输出的不是想要的二值…）。
//			//解决方式：Destory函数加入一个参数
//
//	CObject::Destory(pObject1);	
//	CObject::Destory(pObject2);
//
//	if (pObject2)
//	{
//		cout << pObject2->m_a << endl;
//	}
//
//	system("pause");
//	return 0;
//}





////	饥汉式：	不管用与否，程序创建之初就把唯一实例创建出来（空间换时间的做法）
//
//class CObject
//{
//public:
//	int m_a;
//private:
//	static CObject* m_pObjec;
//private:
//	CObject() {
//		m_a = 10;
//	}
//	CObject(const CObject& obj) {
//		this->m_a = obj.m_a;
//	}
//	~CObject() {
//	
//	}
//public:
//	static CObject* GetInstance() {
//		return m_pObjec;
//	}
//};
//
//CObject* CObject::m_pObjec = new CObject;
//
//int main(){
//
//	CObject* p1 = CObject::GetInstance();
//	CObject* p2 = CObject::GetInstance();
//
//	p1->m_a = 30;
//	cout << p2->m_a << endl;
//
//	system("pause");
//	return 0;
//}



////	模板方法模式：
//
////	将不变的流程（步骤）和可变的实现（细节）分开，
////	将公共的流程抽离到父类形成模板，
////	具体的实现利用多态在子类中完成实现。
//
//class CPeople
//{
//public:
//	virtual void EatBehavior() = 0;
//
//	virtual void EatSytle() = 0;
//
//	void eat() {
//		cout << "1.盛一碗饭" << endl;
//		EatBehavior();
//		EatSytle();
//		cout << "4.放嘴里嚼" << endl;
//		cout << "5.吞肚子里" << endl;
//		cout << "6.吃完饭了" << endl;
//	}
//};
//
//class CChina:public CPeople
//{
//public:
//	void EatBehavior() {
//		cout << "2.端起来碗" << endl;
//	}
//	void EatSytle() {
//		cout << "3.筷子扒拉" << endl;
//	}
//	//void eat() {
//	//	cout << "1.盛一碗饭" << endl;
//	//	EatBehavior();
//	//	EatSytle();
//	//	cout << "4.放嘴里嚼" << endl;
//	//	cout << "5.吞肚子里" << endl;
//	//	cout << "6.吃完饭了" << endl;
//	//}
//};
//
//class CAmerican :public CPeople
//{
//public:
//	void EatBehavior() {
//		cout << "2.嘴靠上去" << endl;
//	}
//	void EatSytle() {
//		cout << "3.刀叉扒拉" << endl;
//	}
//	//void eat() {
//	//	cout << "1.盛一碗饭" << endl;
//	//	EatBehavior();
//	//	EatSytle();
//	//	cout << "4.放嘴里嚼" << endl;
//	//	cout << "5.吞肚子里" << endl;
//	//	cout << "6.吃完饭了" << endl;
//	//}
//};
//
//class CIndian :public CPeople
//{
//public:
//	void EatBehavior() {
//		cout << "2.嘴靠上去" << endl;
//	}
//	void EatSytle() {
//		cout << "3.用手抓饭" << endl;
//	}
//	//void eat() {
//	//	cout << "1.盛一碗饭" << endl;
//	//	EatBehavior();
//	//	EatSytle();
//	//	cout << "4.放嘴里嚼" << endl;
//	//	cout << "5.吞肚子里" << endl;
//	//	cout << "6.吃完饭了" << endl;
//	//}
//};
//
//int main() {
//
//	CPeople* pPeo1 = new CChina;
//	pPeo1->eat();
//
//	CPeople* pPeo2 = new CAmerican;
//	pPeo2->eat();
//
//	CPeople* pPeo3 = new CIndian;
//	pPeo3->eat();
//
//	system("pause");
//	return 0;
//}

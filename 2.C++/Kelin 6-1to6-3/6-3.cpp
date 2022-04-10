//#include <iostream>
//using namespace std;



////重载操作符：
////本质上是函数,告诉编译器遇到这个操作符时去调用对应函数来执行操作符的功能，一般需要有返回值，方便和后续操作符继续操作，例56行
//
////类内重载：一般情况下对象在操作符左边，代表用这个对象去调用操作符函数
//
//class CTest
//{
//public:
//	int m_a;
//	CTest() {
//		m_a = 10;
//	}
//
//	//void operator+(int a) {
//	//	m_a + a;
//	//}
//	//tst + 10;		重载+这个符号
//	//类内重载，有一个默认的隐藏参数this，对应tst，后面还需要一个int类型的参数对应10
//	//注意：也就是说后面用+重载操作符时，使用顺序要和参数匹配，tst和int的顺序不可以调换
//
//	int operator+(int a) {
//		return m_a + a;
//	}
//
//	int operator=(int a) {
//		this->m_a = a;
//		return m_a;
//	}
//
//	int operator+=(int a) {
//		this->m_a += a;
//		return m_a;
//	}
//
//	int operator++() {	//左++，先加后返回
//		return ++this->m_a;
//	}
//
//	int operator++(int) {	//右++，返回+之前的
//		return this->m_a++;
//	}
//
//protected:
//private:
//};
//
//int main() {
//	CTest tst;
//	CTest tst1;
//	tst + 10;	//	CTest类型和int类型，类型不匹配无法相加。
//				//	实际此处想进行的操作是将m_a+10，那么此处可以用到重载操作符
//	int a = tst1 + (tst + 10);	//tst+10不是int类型而是一个void，也就是说需要给上面+的重载操作符函数（18-20行被注释部分）设置返回值
//
//	cout << a << endl;
//
//	CTest tst2;
//	tst2 = tst1 + (tst + 10);   // =操作符也需要重载，才能完成给tst2这个类赋值为30的操作
//	cout << tst2.m_a << endl;
//
//	//除了使用+和=去调用，也可以手动去调用函数，如下：
//	//tst1.operator+(12);
//
//	CTest tst3;
//	tst3 = tst1.operator+(12);
//	cout << tst3.m_a << endl;
//
//	CTest tst4;
//	CTest tst5;
//	tst5 = tst4 += 20;
//	cout << tst4.m_a << endl;	
//	cout << tst5.m_a << endl;
//
//	CTest tst6;
//	CTest tst7;
//	tst7 = ++tst6;
//	cout << tst7.m_a << endl;
//
//	CTest tst8;
//	CTest tst9;
//	tst9 = tst8++;
//	cout << tst9.m_a << endl;//右++是返回+之前的，所以是10
//
//	system("pause");
//	return 0;
//}


//类外重载：需要注意与类内重载的冲突问题

//tst + 10可以使用类内重载，但如果是10 + tst，那么由于类内函数this默认指针居第一位，所以类内重载无法完成，此时便需要类外重载了
//
//class CTest
//{
//public:
//	int m_a;
//	CTest() {
//		m_a = 10;
//	}
//};
//
//int operator+(int a, CTest& tst) {
//	return a + tst.m_a;
//}
//
////int operator+(CTest& tst, int a) {
////	return a + tst.m_a;
////}	
//
////	如果类内类外都其设置了重载函数，那么main中用到对应重载符时会报错：“多个运算符+与这些操作数匹配”，也就是说多个重载函数都符合要求，系统不知道应该调用哪个，此时需要仅保留一个，将其他的删除即可
//
//int operator++(CTest& tst) {	//左++，先加后返回
//	return ++tst.m_a;
//	}
//
//int operator++(CTest& tst,int) {	//右++，返回+之前的值
//	return tst.m_a++;
//}
//
//ostream& operator<<(ostream& os, CTest& tst) {
//	os << tst.m_a;
//	return os;
//}	//输出
//
//istream& operator>>(istream& is, CTest& tst) {
//	is >> tst.m_a;
//	return is;
//}	//输入
//
//int main() {
//	CTest tst;
//	int a = 10 + tst;
//	cout << a << endl;
//
//	cout << ++tst.m_a << endl;
//	cout << tst.m_a++ << endl;
//
//	cout << tst << endl;	
//	//<<也是重载符，但是其重载的是int类型，本句是CTest类型所以会报错，那么自己可以手动写一个能重载输出CTest类型的操作符
//	//cout是ostream类型的，所以重载函数应该具备两个参数，一个是ostream，一个是CTest类型的，同时应该使用类外重载，因为类内的重载函数需要拿对象来调用，而此处使用cout进行调用
//
//	cin >> tst;
//	cout << tst << endl;
//
//	system("pause");
//	return 0;
//}


//重载操作符函数：
//不可以改变原有操作符使用方法；
// //例如：+是a+b，左右各一个参数，因此重载操作符函数中参数的设定就只可以有两个，如果有隐藏的this指针作为参数，那么参数设定就只能再有一个（例18-20行）
//参数不能指定默认值；
// //例如：int operator+(int a = 10)
//也不可以改变优先级和结合性；



////迭代器概念引入
//
//struct Node {
//	int val;
//	Node* pNext;
//	Node(int v) {
//		val = v;
//		pNext = NULL;
//	}
//};
//
//// 迭代器
//class CMyIterator {
//public:
//	Node* pTemp;
//public:
//	CMyIterator() {
//		pTemp = NULL;
//	}
//	CMyIterator(Node* pH) {
//		pTemp = pH;
//	}
//public:
//	bool operator==(Node* pNode) {
//		return pTemp == pNode ? true : false;
//	}
//	bool operator!=(Node* pNode) {
//		return pTemp != pNode ? true : false;
//	}
//	Node* operator=(Node* pNode) {
//		pTemp = pNode;
//		return pTemp;
//	}
//	int operator*() {
//		if (pTemp) {
//			return pTemp->val;
//		}
//		return -1;
//	}
//	Node* operator++() {		//左++
//		pTemp = pTemp->pNext;
//		return pTemp;
//	}
//	Node* operator++(int) {		//右++
//		Node* pT = pTemp;
//		pTemp = pTemp->pNext;
//		return pT;
//	}
//};
//
//class MyList
//{
//public:
//	Node* m_pHead;
//	Node* m_pEnd;
//	int m_nLen;//链表长度 节点个数
//public:
//	MyList() {
//		m_pHead = NULL;
//		m_pEnd = NULL;
//		m_nLen = 0;
//	}
//	~MyList() {//析构是生命周期结束了所以这里应该遍历链表删除节点
//		Node* pTemp = NULL;
//		while (m_pHead) {
//			pTemp = m_pHead;
//			m_pHead = m_pHead->pNext;
//			delete pTemp;
//			pTemp = NULL;
//		}
//		m_pHead = NULL;
//		m_pEnd = NULL;
//		m_nLen = 0;
//	}
//public:
//	void PushBack(int v) {
//		//Node* pTemp = new Node;//报错：没有默认的构造函数，原因是结构体中写了构造函数，因此系统不再提供默认的构造函数，而是采用写的有参的构造函数
//		Node* pTemp = new Node(v);
//
//		if (m_pHead) {
//			m_pEnd->pNext = pTemp;
//			m_pEnd = m_pEnd->pNext;
//		}
//		else {
//			m_pHead = pTemp;
//			m_pEnd = pTemp;
//		}
//		m_nLen++;
//
//	}
//
//	void show() {
//		//Node* pTemp = m_pHead;
//		//	//Node* pTemp = NULL;
//		//	//pTemp = m_pHead;
//		//while (pTemp) {
//		//	cout << pTemp->val << "	";
//		//	pTemp = pTemp->pNext;
//		//}
//
//		CMyIterator ite;
//		ite = m_pHead;
//
//		while (ite != NULL) {
//			cout << *ite << "   ";
//			++ite;	//此处用左++或者右++都一样，因为没有用到函数返回值
//					//如果是int a = ++ite或者int a = ite++则不同，是把不同的返回值赋值给了a，但ite的值都是+1了
//		}
//		cout << endl;
//	}
//};
//
//
//int main() {
//	MyList lst;
//
//	lst.PushBack(1);
//	lst.PushBack(2);
//	lst.PushBack(3);
//	lst.PushBack(4);
//
//	lst.show();
//
//	system("pause");
//	return 0;
//}

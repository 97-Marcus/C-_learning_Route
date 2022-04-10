//#include <iostream>
//#include <list>
//#include <algorithm>
//using namespace std;
//
//void Show(int a) {
//	cout << a << "	";
//}	//for_each 函数的第三个参数的函数
//
//int main() {
//	list<int> lst;		//定义一个链表	
//	lst.push_back(1);
//	lst.push_back(2);
//	lst.push_back(3);	//尾添加，注意类型要和定义链表< >内的类型一致
//
//	lst.push_front(0);	//头添加
//	lst.push_front(-1);
//	lst.push_front(-2);
//
//
//	//链表的两种遍历方式
//
//	//定义迭代器
//	list<int>::iterator ite = lst.begin();
//	//iterator 本质上也是一个类，可以当作指针用
//	//lst.begin() 返回头节点，此句为返回头节点的迭代器
//
//	while (ite != lst.end())	//循环遍历链表
//	{
//		cout << *ite << endl;
//		ite++;
//	}
//	
//	//引入头文件algorithm，利用::for_each函数
//	::for_each(lst.begin(), lst.end(), &Show);
//	cout << endl;
//	//::for_each 这个函数只负责遍历，其第三个参数的函数才是进行实际操作的（想干啥自己写就行）
//	//第三个参数函数的返回值及函数名无要求，但其参数有要求，参数必须为一个且为返回链表中每一个节点的元素，也就是必须和链表类型相匹配
//
//	lst.pop_back();		//尾删除
//	::for_each(lst.begin(), lst.end(), &Show);
//	cout << endl;
//
//	lst.pop_front();	//头删除
//	::for_each(lst.begin(), lst.end(), &Show);
//	cout << endl;
//
//	list<int>::iterator ite1 = ++lst.begin();	//头的下一个，也就是第二个
//	list<int>::iterator ite2 = lst.insert(ite1, 5);
//	//lst.insert(ite1, 5);	//指定位置插入
//							//第一个参数为指向插入位置的迭代器，第二个为插入的内容
//							//将插入到迭代器位置之前，也就是插入内容将被放置在迭代器位置上
//							//返回新插入的节点的迭代器
//	::for_each(lst.begin(), lst.end(), &Show);
//	cout << endl;
//	cout << *ite2 << endl;
//
//	//lst.erase(ite2);	//指定位置删除，其参数为删除位置的迭代器
//	//::for_each(lst.begin(), lst.end(), &Show);
//	//cout << endl;
//	//cout << *ite2 << endl;	//程序崩溃，删除了该迭代器指向的节点后，该迭代器还是会指向原来那份空间，但那份空间已经被回收了，因此非法访问。
//	//erase返回值返回的是当前节点的下一个节点，所以解决上述问题的方式是拿迭代器接一下就行啦，如下：
//	ite2 = lst.erase(ite2);
//	::for_each(lst.begin(), lst.end(), &Show);
//	cout << endl;
//	cout << *ite2 << endl;
//
//	cout << lst.front() << endl;
//	// begin返回的是头节点的迭代器，front是直接返回头节点的内容，该句等同于：
//	list<int>::iterator ite3 = lst.begin();
//	cout << *ite3 <<endl;
//
//	cout << lst.back() << endl;	// 同理于front，back是直接返回尾节点的内容
//	//list<int>::iterator ite4 = lst.end();	//程序崩溃，end所返回的并不是尾节点，而是结尾标志，也就是尾节点的下一个
//	list<int>::iterator ite4 = lst.end();
//	--ite4;
//	cout << *ite4 << endl;
//
//	//::find(lst.begin(), lst.end(), 3);//三个参数：从哪个范围找，找哪个值
//									  //返回值是找到节点的迭代器
//	//list<int>::iterator ite5 = ::find(lst.begin(), lst.end(), 3);
//	//cout << *ite5 << endl;	//程序崩溃，因为没有3，没有找到，所以迭代器返回的是这个区间内的最后一个，也就是end，结尾标志，尾节点的下一个，因此会崩溃
//
//	list<int>::iterator ite5 = ::find(lst.begin(), lst.end(), 1);
//	cout << *ite5 << endl;
//
//	system("pause");
//	return 0;
//}

//
//#include <iostream>
//#include <list>
//#include <algorithm>
//using namespace std;
//
//struct Node
//{
//	int m_a;
//	int m_b;
//	Node() {
//		m_a = 10;
//		m_b = 20;
//	}
//};	//尽量不要值传递，最好通过引用和地址
//
//void Show(Node* p) {
//	cout << p->m_a << "	" << p->m_b << "	";
//}
//
//int main() {
//
//	list<Node*> lst1;
//	Node* p1 = new Node;
//	lst1.push_back(p1);
//
//	Node* p2 = new Node;
//	p2->m_a = 30;
//	p2->m_b = 40;
//	lst1.push_back(p2);
//
//	list<Node*>::iterator ite = lst1.begin();
//	while (ite != lst1.end()) 
//	{
//		cout << (*ite)->m_a << "	" << (*ite)->m_b << "	";
//		ite++;
//	}
//	cout << endl;
//
//	::for_each(lst1.begin(), lst1.end(), &Show);
//	cout << endl;
//
//	system("pause");
//	return 0;
//}
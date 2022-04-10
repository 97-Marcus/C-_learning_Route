//#include <iostream>
//using namespace std;
//#include <list>
//#include <algorithm>
//
////list
//
//
//bool rule(int a, int b) {
//	return a > b;
//}
//
//void show(int a) {
//	cout << a << "  ";
//}
//
//int main() {
//	
//	list<int> lst;
//	lst.push_back(1);
//	lst.push_back(8);
//	lst.push_back(8);
//	lst.push_back(5);
//	lst.push_back(3);
//	lst.sort();
//	//lst.sort(&rule);
//
//	//::for_each(lst.begin(), lst.end(), &show); cout << endl;
//
//	//lst.remove(3);		//移除固定的值
//	//::for_each(lst.begin(), lst.end(), &show); cout << endl;
//
//	//lst.unique();		//连续且相同 只保留一个
//	//::for_each(lst.begin(), lst.end(), &show); cout << endl;
//
//	//lst.sort();			//默认升序，可通过设定规则确认升序降序
//	//::for_each(lst.begin(), lst.end(), &show); cout << endl;
//
//	//lst.reverse();		//翻转
//	//::for_each(lst.begin(), lst.end(), &show); cout << endl;
//
//	//lst.sort(&rule);	//指定规则降序排序
//	//::for_each(lst.begin(), lst.end(), &show); cout << endl;
//
//	list<int> lst2;
//	lst2.push_back(60);
//	lst2.push_back(20);
//	lst2.push_back(50);
//	lst2.sort();
//	//lst2.sort(&rule);
//
//	//::for_each(lst2.begin(), lst2.end(), &show); cout << endl;
//
//	//lst.splice(++lst.begin(), lst2);	//整个
//	//::for_each(lst.begin(), lst.end(), &show); cout << endl;
//	//::for_each(lst2.begin(), lst2.end(), &show); cout << endl;	//lst2插入到lst后，lst2重载为空~ 所以该行输出无内容
//	
//	//lst.splice(++lst.begin(), lst2, ++lst2.begin());	//20
//	//::for_each(lst.begin(), lst.end(), &show); cout << endl;
//	//::for_each(lst2.begin(), lst2.end(), &show); cout << endl;
//
//	//lst.splice(++lst.begin(), lst2, ++lst2.begin(), lst2.end());	//20，50
//	//::for_each(lst.begin(), lst.end(), &show); cout << endl;
//	//::for_each(lst2.begin(), lst2.end(), &show); cout << endl;
//
//	//lst.splice(++lst.begin(), lst, --lst.end());	//结尾的1插入到首8的后面
//	//::for_each(lst.begin(), lst.end(), &show); cout << endl;
//	//::for_each(lst2.begin(), lst2.end(), &show); cout << endl;
//
//	//lst.push_back(8);
//	//lst.push_back(5);
//	//lst.push_back(3);
//	//::for_each(lst.begin(), lst.end(), &show); cout << endl;
//	//8 5 1 8 5 3
//
//	//lst.splice(++lst.begin(), lst, ++(++lst.begin()), lst.end());	
//	//// 1 8 5 3插入到8后面
//	//::for_each(lst.begin(), lst.end(), &show); cout << endl;
//	//::for_each(lst2.begin(), lst2.end(), &show); cout << endl;
//
//	//lst.splice(++lst.begin(), lst, lst.begin(), --lst.end());	
//	//			//不报错但实际上会出现错误，也就是说范围不能是整个原链表~
//	//::for_each(lst.begin(), lst.end(), &show); cout << endl;
//	//::for_each(lst2.begin(), lst2.end(), &show); cout << endl;
//
//	//lst.merge(lst2);	
//	//			//两个list的内容都必须先经过递增排序，该函数是合并两个链表整体进行排序，默认的是递增~也可以指定降序，如果降序的话那么两个list的内容先需要经过降序排序
//	//::for_each(lst.begin(), lst.end(), &show); cout << endl;
//
//	//lst.merge(lst2, &rule);
//	//::for_each(lst.begin(), lst.end(), &show); cout << endl;
//
//	lst.swap(lst2);		//交换两链表内的元素 写法一~
//	swap(lst, lst2);	//写法二~
//	::for_each(lst.begin(), lst.end(), &show); cout << endl;
//	::for_each(lst2.begin(), lst2.end(), &show); cout << endl;
//
//	system("pause");
//	return 0;
//}


//
//#include <iostream>
//using namespace std;
//#include <vector>
//#include <algorithm>
//
//
//
////vector 动态数组
//
//void show(int a) {
//	cout << a << "	";
//}
//
//int main() {
//	
//	//vector<int> vec;	//	size<=容量
//	//cout << vec.size() << "	" << vec.capacity() << endl;	// 0 0
//
//	//vector<int> vec(2);	//	构造元素的数量但未给出初始化的值，因此默认是0
//	//cout << vec.size() << "	" << vec.capacity() << endl;	// 2 2
//	//vector<int>::iterator ite = vec.begin();
//	//while (ite != vec.end())
//	//{
//	//	cout << *ite << "	";
//	//	ite++;
//	//}cout << endl;	// 0 0
//
//	vector<int> vec(2, 4);	//	构造元素的数量并给出初始化的值4
//	cout << vec.size() << "	" << vec.capacity() << endl;	// 2 2
//	vector<int>::iterator ite = vec.begin();
//	while (ite != vec.end())	//遍历 方法1
//	{
//		cout << *ite << "	";
//		ite++;
//	}cout << endl;	// 4 4
//
//	vec.push_back(1);
//	vec.push_back(2);
//	vec.push_back(3);
//
//	for (int i = 0; i < vec.size(); i++)	//遍历 方法2
//	{
//		cout << vec[i] << "	";
//	}cout << endl;	
//
//	::for_each(vec.begin(), vec.end(), &show);	//遍历 方法3
//	cout << endl;
//
//	cout << vec.size() << "	" << vec.capacity() << endl;	
//		// 5 6	
//		//为什么是6不是5？其容量的扩充有其自己的规则，不是加一个元素就加一个容量噢~
//
//	//cout << vec.front() << endl;
//	//cout << vec.back() << endl;
//
//	//vec.pop_back();
//	//::for_each(vec.begin(), vec.end(), &show);
//	//cout << endl;
//	//cout << vec.size() << "	" << vec.capacity() << endl;	
//	//	//	4 6
//	//	//	删除尾部的元素时，其容量不会变化
//
//	////只有pop_back尾删除和push_back尾添加~没有pop_front之类的噢
//
//	//vec.insert(++vec.begin(), 5);	//4后加5
//	//::for_each(vec.begin(), vec.end(), &show);
//	//cout << endl;
//
//	//vec.insert(++vec.begin(), 2, 9);	//4后加2个9
//	//::for_each(vec.begin(), vec.end(), &show);
//	//cout << endl;
//
//	//vec.erase(vec.begin());	//删除第一个元素
//	//::for_each(vec.begin(), vec.end(), &show);
//	//cout << endl;
//
//	vector<int>::iterator ite1 = ++vec.begin();		//ite1指向4
//	//vec.erase(ite1);	
//	//ite1还是指向原位置，但4被删除，后面的1往前移，所以ite1指向的是1，和链表不同，链表节点删除后，指向的ite必须要用东西接一下，否则就遗失了，但此处无须用东西接，其还是指向那个位置
//	ite1 = vec.erase(ite1);//手贱想要接一下也会是一样的结果，还是1~
//	::for_each(vec.begin(), vec.end(), &show);
//	cout << endl;
//
//	vec.clear();	//size=0，但容量不变噢！
//	cout << vec.size() << "	" << vec.capacity() << endl;
//
//	//Iterator find(起始位置，结束位置，查找的元素值)	//找到指定的值的位置
//	//PS:不是vector的成员而是c++提供的一个函数噢！
//	//另外，vector内部也没有提供像链表一样的sort排序的功能，但是算法中提供::sort()函数。
//
//	vector<int>* pVec = new vector<int>(2, 3);	
//			//这样new也是被允许哒，不过这个在堆区啦，上面那些是在栈区的噢~
//	cout << pVec->size() << "	" << pVec->capacity() << endl;
//
//	system("pause");
//	return 0;
//}



//#include <iostream>
//using namespace std;
//#include <deque>
//#include <algorithm>
//#include <list>
//#include <vector>
//
//void show(int a) {
//	cout << a << "	";
//}
//
//int main() {
//
//	deque<int> de;
//	de.push_back(3);
//	de.push_back(6);
//	de.push_back(2);
//	de.push_back(5);
//	de.push_back(9);
//
//	//遍历的几种方式~
//	for (int i = 0; i < de.size(); i++) 
//	{
//		cout << de[i] << "	";
//	}cout << endl;
//
//	::for_each(de.begin(), de.end(), &show);
//	cout << endl;
//
//	de.push_front(1);
//	de.push_front(2);
//	
//	deque<int>::iterator ite = de.begin();
//	while (ite != de.end())
//	{
//		cout << *ite << "	";
//		ite++;
//		//ite += 2;
//	}cout << endl;
//
//	//list<int> lst;
//	//lst.begin() += 2;	//list没有重载+=  所以报错  可以利用advance解决（迭代器加~）
//	//vector<int>	vec;
//	//vec.begin() += 2;	//vector重载了+=
//
//	ite = de.begin();				//ite 指向头
//	//::advance(ite, 3);			//ite 偏移3
//	//::advance(ite, de.size() - 1);//ite 偏移到最后一个元素
//	//::advance(ite, de.size);		//出界~ 报错了噢
//	cout << *ite << endl;
//
//
//	for (int val : de)
//	{
//		cout << val << "	";
//	}cout << endl;
//
//	cout << endl;
//	de.pop_back();
//	::for_each(de.begin(), de.end(), &show);
//	cout << endl;
//	de.pop_front();
//	::for_each(de.begin(), de.end(), &show);
//	cout << endl;
//
//	cout << "size:" << de.size() << endl;
//
//	de.insert(++de.begin(), 10);
//	::for_each(de.begin(), de.end(), &show);
//	cout << endl;
//
//	cout << "size:" << de.size() << endl;
//
//	de.erase(++de.begin());
//	::for_each(de.begin(), de.end(), &show);
//	cout << endl;
//
//	cout << "size:" << de.size() << endl;
//
//	de.resize(de.size() + 2);
//	cout << "size:" << de.size() << endl;
//	::for_each(de.begin(), de.end(), &show);
//	cout << endl;
//
//	de.resize(de.size() - 4);
//	cout << "size:" << de.size() << endl;
//	::for_each(de.begin(), de.end(), &show);
//	cout << endl;
//	
//	de.clear();
//	cout << "size:" << de.size() << endl;
//	::for_each(de.begin(), de.end(), &show);
//	cout << endl;
//
//	system("pause");
//	return 0;
//}
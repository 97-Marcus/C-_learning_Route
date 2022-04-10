//#include <iostream>
//using namespace std;
//#include <list>
//#include <string>
//#include <map>
//#include <algorithm>
//
//int main() {
//
//	list<int> lst;
//	lst.push_back(1);
//	lst.push_back(2);
//	lst.push_back(3);
//	lst.push_back(4);
//
//	////正向遍历/正向迭代器
//	//list<int>::iterator ite1 = lst.begin();
//	//while (ite1 != lst.end())
//	//{
//	//	cout << *ite1 << "	";
//	//	ite1++;
//	//}cout << endl;
//
//	////反向遍历/正向迭代器
//	//list<int>::iterator ite2 = --lst.end();	//end指向的是结尾的下一个 所以要--
//	//while (ite2 != lst.begin())	//begin是第一个 所以后面要补一条输出第一个的cout << *ite2
//	//{
//	//	cout << *ite2 << "	";
//	//	ite2--;
//	//}cout << *ite2 << endl;
//
//	//反向遍历/反向迭代器
//	list<int>::reverse_iterator ite3 = lst.rbegin();
//						//reverse 倒置 rbegin 倒置的头
//						//iterator 正向迭代器 
//						//reverse_iterator 反向迭代器
//	while (ite3 != lst.rend())		//rbegin指向尾，rend指向头的前一个
//	{
//		cout << *ite3 << "	";
//		if ((*ite3) == 2)
//		{
//			//lst.erase(ite3);	//ite3是反向的迭代器 不可以和正向迭代器一样操作
//			//lst.erase(ite3.base());		//反向变正向 后移一位 此时删除的是3而不是2
//			lst.erase(--ite3.base());
//			break;
//		}
//		ite3++;
//	}cout << endl;
//
//	list<int>::iterator ite2 = --lst.end();	//end指向的是结尾的下一个 所以要--
//	while (ite2 != lst.begin())	//begin是第一个 所以后面要补一条输出第一个的cout << *ite2
//	{
//		cout << *ite2 << "	";
//		ite2--;
//	}cout << *ite2 << endl;
//
//	system("pause");
//	return 0;
//}
//#include<iostream>
//#include<map>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//
////	如何确定是关联性容器还是序列性容器？
////	序列性容器：元素跟插入的时间和地点，有固定的位置。
////	关联性容器：元素的位置和插入无关，有其特定的排列顺序
//
//
//void show(pair<string, int>  pr) {
//	cout << pr.first << "   " << pr.second << endl;
//}
//
//int main() {
//	map<string, int> mm;
//	mm["DD"] = 100;
//	mm["CC"] = 200;
//	mm["UU"] = 300;
//	mm["SS"] = 400;
//
//	//遍历		//根据键值自动排序~
//	map<string, int>::iterator ite = mm.begin();
//	while (ite != mm.end()) {
//		cout << (*ite).first << "   " << (*ite).second << endl;
//		ite++;
//	}
//	::for_each(mm.begin(), mm.end(), &show);
//
//	//通过键值找到实值  不再像序列性容器一样去遍历再查找~
//	cout << mm["DD"] << endl;
//	//cout << mm["OO"] << endl;   // 不存在则输出0	  查找效率（log2n  2为底n的对数）
//								//注意！此处mm["OO"]如果没有，那么就会自动加一个"OO" 0
//
//	if (mm["DD"]) {
//		cout << mm["DD"] << endl;
//	}
//	else {
//		cout << "不存在" << endl;
//	}
//
//	//if (mm["OO"]) {			//注意！此处mm["OO"]如果没有，那么就会自动加一个"OO" 0
//	//	cout << mm["OO"] << endl;
//	//}
//	//else {
//	//	cout << "不存在" << endl;
//	//}
//
//	map<string, int>::iterator ite1 = mm.find("CC");
//	cout << (*ite1).first << "   " << (*ite1).second << endl;	//两种写法~	
//	cout << ite1->first << "   " << ite1->second << endl;
//
//	map<string, int>::iterator ite2 = mm.find("OO");	//找不到OO 会返回一个指向end()的迭代器
//	if (ite2 != mm.end()) 
//	{
//		cout << (*ite2).first << "   " << (*ite2).second << endl;
//		cout << ite2->first << "   " << ite2->second << endl;
//	}
//
//	cout << endl;
//	::for_each(mm.begin(), mm.end(), &show);
//	cout << endl;
//	pair<string, int>  pr1("II", 600);
//	mm.insert(pr1);
//	::for_each(mm.begin(), mm.end(), &show);
//
//	cout << endl;
//	pair<string, int>  pr2("PP", 500);
//	mm.insert(mm.begin(), pr2);			//依然会自动按照键值排序，和给定的mm.begin()位置没有关系
//										//mm.begin()只是给出的一个起始搜索的位置（可以提高程序的效率），但该位置并不一定是真正元素插入的位置
//	::for_each(mm.begin(), mm.end(), &show);
//
//	cout << endl;
//	map<string, int>::iterator ite3	= mm.find("II");
//	mm.erase("II");
//	::for_each(mm.begin(), mm.end(), &show);
//
//	cout << endl;
//	if (mm.count("PP")) {
//		cout << mm["PP"] << endl;
//	}
//	else {
//		cout << "不存在" << endl;
//	}
//	cout << endl;
//
//	if (mm.count("II")) {
//		cout << mm["II"] << endl;
//	}
//	else {
//		cout << "不存在" << endl;
//	}
//	cout << endl;
//
//	cout << mm.size() << endl;
//	cout << endl;
//
//	::for_each(mm.begin(), mm.end(), &show);
//	cout << endl;
//
//	//map<string, int>::iterator ite4 = mm.lower_bound("UU");	//返回大于等于该键值的迭代器  有UU 返回UU 
//	map<string, int>::iterator ite4 = mm.lower_bound("EE");	//返回大于等于该键值的迭代器  没有EE 返回EE后面的有的键值 此处有CC DD UU SS PP 所以返回PP
//	cout << ite4->first << "   " << ite4->second << endl;
//
//	cout << endl;
//	map<string, int>::iterator ite5 = mm.upper_bound("PP");		//返回大于该键值的迭代器 CC DD PP SS UU 所以此处返回SS	
//	cout << ite5->first << "   " << ite5->second << endl;
//
//	cout << endl;
//	mm["SS"] = 5000;
//	::for_each(mm.begin(), mm.end(), &show);
//
//	cout << endl;
//	map<string, int>::iterator ite6 = mm.find("SS");
//	//ite6->first = "MM";	//不可以改键值！！只可以改实值！！
//	ite6->second = 1;
//	::for_each(mm.begin(), mm.end(), &show);
//
//}
//
//	
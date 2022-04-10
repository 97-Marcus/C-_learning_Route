//#include <iostream>
//using namespace std;
//#include <list>
//#include <string>
//#include <map>
//#include <algorithm>
//
////struct Bus
////{
////	string m_station;
////	int m_bus;
////	Bus(string& s, int bus) {
////		m_station = s;
////		m_bus = bus;
////	}
////};
//
////左值引用VS右值引用
////左值是在等号左边的变量，相当于string str1 = "服装城";中的str1
////右值是等号右边的值，相当于string str1 = "服装城"的"服装城"、string("黑大")
////&就是左值 &&就是右值
////Bus(string & s, int bus)，这里的s因为只有一个&，所以他只能引用左值，就是str1这种：string str1 = "服装城";Bus bus1(str1, 111);，如果引用右值就会报错，说类型不匹配
////如果改成这样Bus(string && s, int bus)，这里的s前面有两个&，所以他只能引用右值，就是string("黑大")这种：Bus bus1(string("黑大"), 111);
//
//void show(pair<string, int> pr) {
//	cout << pr.first << "	" << pr.second << endl;
//}
//
//int main() {
//
//	//————————————————————————一对一站点 list方法——————————————————————————
//	//list<Bus> lst;
//	//string str1 = "服装城";
//	//string str2 = "黑大";
//	//string str3 = "哈理工";
//	//Bus bus1(str1, 111);
//	//Bus bus2(str2, 122);
//	//Bus bus3(str3, 133);
//	//lst.push_back(bus1);
//	//lst.push_back(bus2);
//	//lst.push_back(bus3);
//
//	//string ss;
//	//cout << "请输入要查询的站点" << endl;
//	//cin >> ss;
//
//	//list<Bus>::iterator ite1 = lst.begin();
//	//while (ite1 != lst.end()) 
//	//{
//	//	if ((*ite1).m_station == ss) 
//	//	{
//	//		cout << (*ite1).m_bus << endl;
//	//		break;
//	//	}
//	//	ite1++;
//	//}
//
//	//————————————————————————一对一站点  map方法——————————————————————————
//	//map<string, int> mm;
//	//mm["服装城"] = 111;
//	//mm["黑大"] = 122;
//	//mm["哈理工"] = 133;
//
//	//string ss;
//	//cout << "请输入要查询的站点" << endl;
//	//cin >> ss;
//	////cout << mm[ss] << endl;	//如果查询的站点不存在会自动加int=0的相应站点
//	////::for_each(mm.begin(), mm.end(), &show);
//
//	////优化
//	//if (mm.count(ss)) 
//	//{
//	//	cout << mm[ss] << endl;
//	//}
//	//else {
//	//	cout << "站点不存在" << endl;
//	//}
//	//::for_each(mm.begin(),mm.end(),&show);
//	
//	//——————————————————————一对多站点 list-map方法————————————————————————
//	map<string, list<int>> mm;
//
//	list<int> lst1;
//	lst1.push_back(111);
//	lst1.push_back(122);
//	lst1.push_back(133);
//	mm["服装城"] = lst1;
//
//	list<int> lst2;
//	lst2.push_back(211);
//	lst2.push_back(222);
//	lst2.push_back(233);
//	mm["黑大"] = lst2;
//
//	list<int> lst3;
//	lst3.push_back(311);
//	lst3.push_back(322);
//	lst3.push_back(333);
//	mm["哈理工"] = lst3;
//
//	string ss;
//	cout << "请输入要查询的站点" << endl;
//	cin >> ss;
//
//	if (mm.count(ss)) 
//	{
//		list<int>::iterator ite2 = mm[ss].begin();
//		while (ite2 != mm[ss].end())
//		{
//			cout << *ite2 << "	";
//			ite2++;
//		}cout << endl;
//	}
//	else {
//		cout << "站点不存在" << endl;
//	}
//
//	system("pause");
//	return 0;
//}
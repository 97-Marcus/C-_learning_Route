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
////��ֵ����VS��ֵ����
////��ֵ���ڵȺ���ߵı������൱��string str1 = "��װ��";�е�str1
////��ֵ�ǵȺ��ұߵ�ֵ���൱��string str1 = "��װ��"��"��װ��"��string("�ڴ�")
////&������ֵ &&������ֵ
////Bus(string & s, int bus)�������s��Ϊֻ��һ��&��������ֻ��������ֵ������str1���֣�string str1 = "��װ��";Bus bus1(str1, 111);�����������ֵ�ͻᱨ��˵���Ͳ�ƥ��
////����ĳ�����Bus(string && s, int bus)�������sǰ��������&��������ֻ��������ֵ������string("�ڴ�")���֣�Bus bus1(string("�ڴ�"), 111);
//
//void show(pair<string, int> pr) {
//	cout << pr.first << "	" << pr.second << endl;
//}
//
//int main() {
//
//	//������������������������������������������������һ��һվ�� list��������������������������������������������������������
//	//list<Bus> lst;
//	//string str1 = "��װ��";
//	//string str2 = "�ڴ�";
//	//string str3 = "����";
//	//Bus bus1(str1, 111);
//	//Bus bus2(str2, 122);
//	//Bus bus3(str3, 133);
//	//lst.push_back(bus1);
//	//lst.push_back(bus2);
//	//lst.push_back(bus3);
//
//	//string ss;
//	//cout << "������Ҫ��ѯ��վ��" << endl;
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
//	//������������������������������������������������һ��һվ��  map��������������������������������������������������������
//	//map<string, int> mm;
//	//mm["��װ��"] = 111;
//	//mm["�ڴ�"] = 122;
//	//mm["����"] = 133;
//
//	//string ss;
//	//cout << "������Ҫ��ѯ��վ��" << endl;
//	//cin >> ss;
//	////cout << mm[ss] << endl;	//�����ѯ��վ�㲻���ڻ��Զ���int=0����Ӧվ��
//	////::for_each(mm.begin(), mm.end(), &show);
//
//	////�Ż�
//	//if (mm.count(ss)) 
//	//{
//	//	cout << mm[ss] << endl;
//	//}
//	//else {
//	//	cout << "վ�㲻����" << endl;
//	//}
//	//::for_each(mm.begin(),mm.end(),&show);
//	
//	//��������������������������������������������һ�Զ�վ�� list-map����������������������������������������������������
//	map<string, list<int>> mm;
//
//	list<int> lst1;
//	lst1.push_back(111);
//	lst1.push_back(122);
//	lst1.push_back(133);
//	mm["��װ��"] = lst1;
//
//	list<int> lst2;
//	lst2.push_back(211);
//	lst2.push_back(222);
//	lst2.push_back(233);
//	mm["�ڴ�"] = lst2;
//
//	list<int> lst3;
//	lst3.push_back(311);
//	lst3.push_back(322);
//	lst3.push_back(333);
//	mm["����"] = lst3;
//
//	string ss;
//	cout << "������Ҫ��ѯ��վ��" << endl;
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
//		cout << "վ�㲻����" << endl;
//	}
//
//	system("pause");
//	return 0;
//}
//#include<iostream>
//#include<map>
//#include<string>
//#include<algorithm>
//using namespace std;
//
//
////	���ȷ���ǹ�������������������������
////	������������Ԫ�ظ������ʱ��͵ص㣬�й̶���λ�á�
////	������������Ԫ�ص�λ�úͲ����޹أ������ض�������˳��
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
//	//����		//���ݼ�ֵ�Զ�����~
//	map<string, int>::iterator ite = mm.begin();
//	while (ite != mm.end()) {
//		cout << (*ite).first << "   " << (*ite).second << endl;
//		ite++;
//	}
//	::for_each(mm.begin(), mm.end(), &show);
//
//	//ͨ����ֵ�ҵ�ʵֵ  ����������������һ��ȥ�����ٲ���~
//	cout << mm["DD"] << endl;
//	//cout << mm["OO"] << endl;   // �����������0	  ����Ч�ʣ�log2n  2Ϊ��n�Ķ�����
//								//ע�⣡�˴�mm["OO"]���û�У���ô�ͻ��Զ���һ��"OO" 0
//
//	if (mm["DD"]) {
//		cout << mm["DD"] << endl;
//	}
//	else {
//		cout << "������" << endl;
//	}
//
//	//if (mm["OO"]) {			//ע�⣡�˴�mm["OO"]���û�У���ô�ͻ��Զ���һ��"OO" 0
//	//	cout << mm["OO"] << endl;
//	//}
//	//else {
//	//	cout << "������" << endl;
//	//}
//
//	map<string, int>::iterator ite1 = mm.find("CC");
//	cout << (*ite1).first << "   " << (*ite1).second << endl;	//����д��~	
//	cout << ite1->first << "   " << ite1->second << endl;
//
//	map<string, int>::iterator ite2 = mm.find("OO");	//�Ҳ���OO �᷵��һ��ָ��end()�ĵ�����
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
//	mm.insert(mm.begin(), pr2);			//��Ȼ���Զ����ռ�ֵ���򣬺͸�����mm.begin()λ��û�й�ϵ
//										//mm.begin()ֻ�Ǹ�����һ����ʼ������λ�ã�������߳����Ч�ʣ�������λ�ò���һ��������Ԫ�ز����λ��
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
//		cout << "������" << endl;
//	}
//	cout << endl;
//
//	if (mm.count("II")) {
//		cout << mm["II"] << endl;
//	}
//	else {
//		cout << "������" << endl;
//	}
//	cout << endl;
//
//	cout << mm.size() << endl;
//	cout << endl;
//
//	::for_each(mm.begin(), mm.end(), &show);
//	cout << endl;
//
//	//map<string, int>::iterator ite4 = mm.lower_bound("UU");	//���ش��ڵ��ڸü�ֵ�ĵ�����  ��UU ����UU 
//	map<string, int>::iterator ite4 = mm.lower_bound("EE");	//���ش��ڵ��ڸü�ֵ�ĵ�����  û��EE ����EE������еļ�ֵ �˴���CC DD UU SS PP ���Է���PP
//	cout << ite4->first << "   " << ite4->second << endl;
//
//	cout << endl;
//	map<string, int>::iterator ite5 = mm.upper_bound("PP");		//���ش��ڸü�ֵ�ĵ����� CC DD PP SS UU ���Դ˴�����SS	
//	cout << ite5->first << "   " << ite5->second << endl;
//
//	cout << endl;
//	mm["SS"] = 5000;
//	::for_each(mm.begin(), mm.end(), &show);
//
//	cout << endl;
//	map<string, int>::iterator ite6 = mm.find("SS");
//	//ite6->first = "MM";	//�����Ըļ�ֵ����ֻ���Ը�ʵֵ����
//	ite6->second = 1;
//	::for_each(mm.begin(), mm.end(), &show);
//
//}
//
//	
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
//	////�������/���������
//	//list<int>::iterator ite1 = lst.begin();
//	//while (ite1 != lst.end())
//	//{
//	//	cout << *ite1 << "	";
//	//	ite1++;
//	//}cout << endl;
//
//	////�������/���������
//	//list<int>::iterator ite2 = --lst.end();	//endָ����ǽ�β����һ�� ����Ҫ--
//	//while (ite2 != lst.begin())	//begin�ǵ�һ�� ���Ժ���Ҫ��һ�������һ����cout << *ite2
//	//{
//	//	cout << *ite2 << "	";
//	//	ite2--;
//	//}cout << *ite2 << endl;
//
//	//�������/���������
//	list<int>::reverse_iterator ite3 = lst.rbegin();
//						//reverse ���� rbegin ���õ�ͷ
//						//iterator ��������� 
//						//reverse_iterator ���������
//	while (ite3 != lst.rend())		//rbeginָ��β��rendָ��ͷ��ǰһ��
//	{
//		cout << *ite3 << "	";
//		if ((*ite3) == 2)
//		{
//			//lst.erase(ite3);	//ite3�Ƿ���ĵ����� �����Ժ����������һ������
//			//lst.erase(ite3.base());		//��������� ����һλ ��ʱɾ������3������2
//			lst.erase(--ite3.base());
//			break;
//		}
//		ite3++;
//	}cout << endl;
//
//	list<int>::iterator ite2 = --lst.end();	//endָ����ǽ�β����һ�� ����Ҫ--
//	while (ite2 != lst.begin())	//begin�ǵ�һ�� ���Ժ���Ҫ��һ�������һ����cout << *ite2
//	{
//		cout << *ite2 << "	";
//		ite2--;
//	}cout << *ite2 << endl;
//
//	system("pause");
//	return 0;
//}
//#include <iostream>
//#include <list>
//#include <algorithm>
//using namespace std;
//
//void Show(int a) {
//	cout << a << "	";
//}	//for_each �����ĵ����������ĺ���
//
//int main() {
//	list<int> lst;		//����һ������	
//	lst.push_back(1);
//	lst.push_back(2);
//	lst.push_back(3);	//β��ӣ�ע������Ҫ�Ͷ�������< >�ڵ�����һ��
//
//	lst.push_front(0);	//ͷ���
//	lst.push_front(-1);
//	lst.push_front(-2);
//
//
//	//��������ֱ�����ʽ
//
//	//���������
//	list<int>::iterator ite = lst.begin();
//	//iterator ������Ҳ��һ���࣬���Ե���ָ����
//	//lst.begin() ����ͷ�ڵ㣬�˾�Ϊ����ͷ�ڵ�ĵ�����
//
//	while (ite != lst.end())	//ѭ����������
//	{
//		cout << *ite << endl;
//		ite++;
//	}
//	
//	//����ͷ�ļ�algorithm������::for_each����
//	::for_each(lst.begin(), lst.end(), &Show);
//	cout << endl;
//	//::for_each �������ֻ���������������������ĺ������ǽ���ʵ�ʲ����ģ����ɶ�Լ�д���У�
//	//���������������ķ���ֵ����������Ҫ�󣬵��������Ҫ�󣬲�������Ϊһ����Ϊ����������ÿһ���ڵ��Ԫ�أ�Ҳ���Ǳ��������������ƥ��
//
//	lst.pop_back();		//βɾ��
//	::for_each(lst.begin(), lst.end(), &Show);
//	cout << endl;
//
//	lst.pop_front();	//ͷɾ��
//	::for_each(lst.begin(), lst.end(), &Show);
//	cout << endl;
//
//	list<int>::iterator ite1 = ++lst.begin();	//ͷ����һ����Ҳ���ǵڶ���
//	list<int>::iterator ite2 = lst.insert(ite1, 5);
//	//lst.insert(ite1, 5);	//ָ��λ�ò���
//							//��һ������Ϊָ�����λ�õĵ��������ڶ���Ϊ���������
//							//�����뵽������λ��֮ǰ��Ҳ���ǲ������ݽ��������ڵ�����λ����
//							//�����²���Ľڵ�ĵ�����
//	::for_each(lst.begin(), lst.end(), &Show);
//	cout << endl;
//	cout << *ite2 << endl;
//
//	//lst.erase(ite2);	//ָ��λ��ɾ���������Ϊɾ��λ�õĵ�����
//	//::for_each(lst.begin(), lst.end(), &Show);
//	//cout << endl;
//	//cout << *ite2 << endl;	//���������ɾ���˸õ�����ָ��Ľڵ�󣬸õ��������ǻ�ָ��ԭ���Ƿݿռ䣬���Ƿݿռ��Ѿ��������ˣ���˷Ƿ����ʡ�
//	//erase����ֵ���ص��ǵ�ǰ�ڵ����һ���ڵ㣬���Խ����������ķ�ʽ���õ�������һ�¾����������£�
//	ite2 = lst.erase(ite2);
//	::for_each(lst.begin(), lst.end(), &Show);
//	cout << endl;
//	cout << *ite2 << endl;
//
//	cout << lst.front() << endl;
//	// begin���ص���ͷ�ڵ�ĵ�������front��ֱ�ӷ���ͷ�ڵ�����ݣ��þ��ͬ�ڣ�
//	list<int>::iterator ite3 = lst.begin();
//	cout << *ite3 <<endl;
//
//	cout << lst.back() << endl;	// ͬ����front��back��ֱ�ӷ���β�ڵ������
//	//list<int>::iterator ite4 = lst.end();	//���������end�����صĲ�����β�ڵ㣬���ǽ�β��־��Ҳ����β�ڵ����һ��
//	list<int>::iterator ite4 = lst.end();
//	--ite4;
//	cout << *ite4 << endl;
//
//	//::find(lst.begin(), lst.end(), 3);//�������������ĸ���Χ�ң����ĸ�ֵ
//									  //����ֵ���ҵ��ڵ�ĵ�����
//	//list<int>::iterator ite5 = ::find(lst.begin(), lst.end(), 3);
//	//cout << *ite5 << endl;	//�����������Ϊû��3��û���ҵ������Ե��������ص�����������ڵ����һ����Ҳ����end����β��־��β�ڵ����һ������˻����
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
//};	//������Ҫֵ���ݣ����ͨ�����ú͵�ַ
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
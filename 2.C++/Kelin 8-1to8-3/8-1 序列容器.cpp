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
//	//lst.remove(3);		//�Ƴ��̶���ֵ
//	//::for_each(lst.begin(), lst.end(), &show); cout << endl;
//
//	//lst.unique();		//��������ͬ ֻ����һ��
//	//::for_each(lst.begin(), lst.end(), &show); cout << endl;
//
//	//lst.sort();			//Ĭ�����򣬿�ͨ���趨����ȷ��������
//	//::for_each(lst.begin(), lst.end(), &show); cout << endl;
//
//	//lst.reverse();		//��ת
//	//::for_each(lst.begin(), lst.end(), &show); cout << endl;
//
//	//lst.sort(&rule);	//ָ������������
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
//	//lst.splice(++lst.begin(), lst2);	//����
//	//::for_each(lst.begin(), lst.end(), &show); cout << endl;
//	//::for_each(lst2.begin(), lst2.end(), &show); cout << endl;	//lst2���뵽lst��lst2����Ϊ��~ ���Ը������������
//	
//	//lst.splice(++lst.begin(), lst2, ++lst2.begin());	//20
//	//::for_each(lst.begin(), lst.end(), &show); cout << endl;
//	//::for_each(lst2.begin(), lst2.end(), &show); cout << endl;
//
//	//lst.splice(++lst.begin(), lst2, ++lst2.begin(), lst2.end());	//20��50
//	//::for_each(lst.begin(), lst.end(), &show); cout << endl;
//	//::for_each(lst2.begin(), lst2.end(), &show); cout << endl;
//
//	//lst.splice(++lst.begin(), lst, --lst.end());	//��β��1���뵽��8�ĺ���
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
//	//// 1 8 5 3���뵽8����
//	//::for_each(lst.begin(), lst.end(), &show); cout << endl;
//	//::for_each(lst2.begin(), lst2.end(), &show); cout << endl;
//
//	//lst.splice(++lst.begin(), lst, lst.begin(), --lst.end());	
//	//			//������ʵ���ϻ���ִ���Ҳ����˵��Χ����������ԭ����~
//	//::for_each(lst.begin(), lst.end(), &show); cout << endl;
//	//::for_each(lst2.begin(), lst2.end(), &show); cout << endl;
//
//	//lst.merge(lst2);	
//	//			//����list�����ݶ������Ⱦ����������򣬸ú����Ǻϲ��������������������Ĭ�ϵ��ǵ���~Ҳ����ָ�������������Ļ���ô����list����������Ҫ������������
//	//::for_each(lst.begin(), lst.end(), &show); cout << endl;
//
//	//lst.merge(lst2, &rule);
//	//::for_each(lst.begin(), lst.end(), &show); cout << endl;
//
//	lst.swap(lst2);		//�����������ڵ�Ԫ�� д��һ~
//	swap(lst, lst2);	//д����~
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
////vector ��̬����
//
//void show(int a) {
//	cout << a << "	";
//}
//
//int main() {
//	
//	//vector<int> vec;	//	size<=����
//	//cout << vec.size() << "	" << vec.capacity() << endl;	// 0 0
//
//	//vector<int> vec(2);	//	����Ԫ�ص�������δ������ʼ����ֵ�����Ĭ����0
//	//cout << vec.size() << "	" << vec.capacity() << endl;	// 2 2
//	//vector<int>::iterator ite = vec.begin();
//	//while (ite != vec.end())
//	//{
//	//	cout << *ite << "	";
//	//	ite++;
//	//}cout << endl;	// 0 0
//
//	vector<int> vec(2, 4);	//	����Ԫ�ص�������������ʼ����ֵ4
//	cout << vec.size() << "	" << vec.capacity() << endl;	// 2 2
//	vector<int>::iterator ite = vec.begin();
//	while (ite != vec.end())	//���� ����1
//	{
//		cout << *ite << "	";
//		ite++;
//	}cout << endl;	// 4 4
//
//	vec.push_back(1);
//	vec.push_back(2);
//	vec.push_back(3);
//
//	for (int i = 0; i < vec.size(); i++)	//���� ����2
//	{
//		cout << vec[i] << "	";
//	}cout << endl;	
//
//	::for_each(vec.begin(), vec.end(), &show);	//���� ����3
//	cout << endl;
//
//	cout << vec.size() << "	" << vec.capacity() << endl;	
//		// 5 6	
//		//Ϊʲô��6����5�������������������Լ��Ĺ��򣬲��Ǽ�һ��Ԫ�ؾͼ�һ��������~
//
//	//cout << vec.front() << endl;
//	//cout << vec.back() << endl;
//
//	//vec.pop_back();
//	//::for_each(vec.begin(), vec.end(), &show);
//	//cout << endl;
//	//cout << vec.size() << "	" << vec.capacity() << endl;	
//	//	//	4 6
//	//	//	ɾ��β����Ԫ��ʱ������������仯
//
//	////ֻ��pop_backβɾ����push_backβ���~û��pop_front֮�����
//
//	//vec.insert(++vec.begin(), 5);	//4���5
//	//::for_each(vec.begin(), vec.end(), &show);
//	//cout << endl;
//
//	//vec.insert(++vec.begin(), 2, 9);	//4���2��9
//	//::for_each(vec.begin(), vec.end(), &show);
//	//cout << endl;
//
//	//vec.erase(vec.begin());	//ɾ����һ��Ԫ��
//	//::for_each(vec.begin(), vec.end(), &show);
//	//cout << endl;
//
//	vector<int>::iterator ite1 = ++vec.begin();		//ite1ָ��4
//	//vec.erase(ite1);	
//	//ite1����ָ��ԭλ�ã���4��ɾ���������1��ǰ�ƣ�����ite1ָ�����1��������ͬ������ڵ�ɾ����ָ���ite����Ҫ�ö�����һ�£��������ʧ�ˣ����˴������ö����ӣ��仹��ָ���Ǹ�λ��
//	ite1 = vec.erase(ite1);//�ּ���Ҫ��һ��Ҳ����һ���Ľ��������1~
//	::for_each(vec.begin(), vec.end(), &show);
//	cout << endl;
//
//	vec.clear();	//size=0�������������ޣ�
//	cout << vec.size() << "	" << vec.capacity() << endl;
//
//	//Iterator find(��ʼλ�ã�����λ�ã����ҵ�Ԫ��ֵ)	//�ҵ�ָ����ֵ��λ��
//	//PS:����vector�ĳ�Ա����c++�ṩ��һ�������ޣ�
//	//���⣬vector�ڲ�Ҳû���ṩ������һ����sort����Ĺ��ܣ������㷨���ṩ::sort()������
//
//	vector<int>* pVec = new vector<int>(2, 3);	
//			//����newҲ�Ǳ������գ���������ڶ�������������Щ����ջ������~
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
//	//�����ļ��ַ�ʽ~
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
//	//lst.begin() += 2;	//listû������+=  ���Ա���  ��������advance�������������~��
//	//vector<int>	vec;
//	//vec.begin() += 2;	//vector������+=
//
//	ite = de.begin();				//ite ָ��ͷ
//	//::advance(ite, 3);			//ite ƫ��3
//	//::advance(ite, de.size() - 1);//ite ƫ�Ƶ����һ��Ԫ��
//	//::advance(ite, de.size);		//����~ ��������
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
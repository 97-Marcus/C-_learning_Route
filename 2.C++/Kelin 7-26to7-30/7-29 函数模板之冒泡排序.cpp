//#include<iostream>
//using namespace std;
//#include <algorithm>
//#include <list>
//
//template<typename TT>
//bool rule(TT a, TT b)
//{
//	return a < b;
//}
//
//bool rule1(int a, int b)
//{
//	return a > b;
//}
//
//bool rule2(double a, double b)
//{
//	return a > b;
//}
//
//template<typename TT>
//void BubbleSort(TT* pArr, int length, bool(*p_fun)(TT, TT)) {
//	if (pArr == NULL || length <= 0) {
//		return;
//	}
//	for (int i = 0; i < length - 1; i++)
//	{
//		for (int j = 0; j < length - 1 - i; j++)
//		{
//			//if (pArr[j] < pArr[j + 1])	//�Ӵ�С
//			//if (pArr[j] > pArr[j + 1])	//��С����
//			if ((*p_fun)(pArr[j], pArr[j + 1])) 
//			{
//				TT temp = pArr[j];
//				pArr[j] = pArr[j + 1];
//				pArr[j + 1] = temp;
//			}
//		}
//	}
//}
//
////void show(int a) {	//������ÿ�������ֵ������~
////
////}
////
////list<int> lst;
////lst.push_back(1);
////lst.push_back(2);
////::for_each(lst.begin(), lst.end(), &show);
//////::for_eachע��Ҫʹ��ͷ�ļ�#include <algorithm>��~
//////�κ��������������� ͷ β �Լ�ָ��д�ĺ������ο���˼������дð�����������ܴﵽ�ܹ��Լ�ѡ���ǴӴ�С���Ǵ�С�����������~
//
//
//int main() {
//
//	int arr[10] = { 2,7,8,1,0,9,6,3,4,5 };
//
//	BubbleSort(arr, 10, &rule<int>);
//	for (int val : arr)	//	��arr����ȡ��Ԫ�ط���val�������Ч��������Խ��
//						//	������Խ�缴��arr[i]������i��ֵ��������Ĵ�С��
//	{
//		cout << val << "	";
//	}cout << endl;
//
//	BubbleSort(arr, 10, &rule1);
//	for (int val : arr)
//	{
//		cout << val << "	";
//	}cout << endl;
//
//
//	double arr1[10] = { 2.2,7.7,8.8,1.1,0.1,9.9,6.6,3.3,4.4,5.5 };
//
//	BubbleSort(arr1, 10, &rule);
//	for (double val : arr1)
//	{
//		cout << val << "	";
//	}cout << endl;
//
//	BubbleSort(arr1, 10, &rule2) ;
//	for (double val : arr1)
//	{
//		cout << val << "	";
//	}cout << endl;
//
//	system("pause");
//	return 0;
//}
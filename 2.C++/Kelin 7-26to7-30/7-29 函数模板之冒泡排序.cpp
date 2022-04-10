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
//			//if (pArr[j] < pArr[j + 1])	//从大到小
//			//if (pArr[j] > pArr[j + 1])	//从小到大
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
////void show(int a) {	//参数是每个结点里值的类型~
////
////}
////
////list<int> lst;
////lst.push_back(1);
////lst.push_back(2);
////::for_each(lst.begin(), lst.end(), &show);
//////::for_each注意要使用头文件#include <algorithm>噢~
//////次函数的三个参数是 头 尾 自己指定写的函数，参考该思想来改写冒泡排序，以求能达到能够自己选择是从大到小还是从小到大进行排序~
//
//
//int main() {
//
//	int arr[10] = { 2,7,8,1,0,9,6,3,4,5 };
//
//	BubbleSort(arr, 10, &rule<int>);
//	for (int val : arr)	//	从arr里面取出元素放在val里，可以有效避免数组越界
//						//	（数组越界即：arr[i]，但是i的值大于数组的大小）
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
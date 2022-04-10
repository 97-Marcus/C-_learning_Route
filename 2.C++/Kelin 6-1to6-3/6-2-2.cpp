//#include <iostream>
//using namespace std;
//#include "6-2-2.h"
//#include "test.h"
//
////	宏：替换，在编译前就完成了替换工作
//
//int main() {
//	
//	//for (int i = 0; i < N; i++) 
//	//{
//	//	cout << i << endl;
//	//}
//
//	AA(8)
//
//	cout << 2 << endl;	//此句子的2为重载操作符函数的参数
//						//此句将把2这个参数赋到对应函数参数int类型去
//	BB(2)				//此句却是跳转赋到字符串类型去了，因此#的作用是将参数转换为字符串
//	BB("2")				//把"2"这个当作整体作为字符串输出了
//
//	CC(CTest1)
//	CC(CTest2)
//
//	system("pause");
//	return 0;
//}
//#include <iostream>
//using namespace std;
//#include "AA.h"
//#include "BB.h"
//
//int main(){
//	CAA aa;	//报错：class类型CAA重定义
//			//原因：头文件6-2-1.h引入了两遍
//			//解决方式：ifndef define endif(利用宏解决头文件重复包含的问题)
//			//宏的缺点：	1.一般宏用的都是文件名而文件名可能会重，将会导致部分头文件引入失败内容被屏蔽
//			//			2.内核是一个判断，所以多文件多判断情况下效率并不高
//			//解决方式2：pragma once(直接告诉编译器，当前文件只包含一次)
//	CBB bb;
//
//	system("pause");
//	return 0;
//}
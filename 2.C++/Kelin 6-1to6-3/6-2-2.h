//#pragma once
//
//
//#define N 10
//
//#define AA(PARAM) \
//for (int i = 0; i < PARAM; i++) \
//{ \
//cout << i << endl; \
//}
//
////	\ 在宏中的作用是用来连接下一行，最后一行通常不用加，该连接符\后不可以有任何东西（空格 注释 任何内容都不可以）
//
//
////  # ： 将参数转换为字符串
//
//#define BB(PARAM) \
//	cout<<#PARAM<<endl;
//
////  ##： 连接符用于以下情况（一段代码要用多次仅改变少数部分）
//
//#define CC(THIS_CLASS)\
//	THIS_CLASS tst##THIS_CLASS;\
//	tst##THIS_CLASS.show();
//// CTest1 tst1;
//// tst1.show();
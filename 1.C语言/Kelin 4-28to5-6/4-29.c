#include <stdio.h>
#include <stdlib.h>



//双向链表
//
//typedef struct Node 
//{
//	int id;
//	struct Node* pNext;
//	struct Node* pLast;
//}List;
//
//void Addnode(List** ppHead, List** ppend, int id);
//
//int main() 
//{
//	List* pHead = NULL;
//	List* pEnd = NULL;
//
//	Addnode(&pHead, &pEnd, 1);
//	Addnode(&pHead, &pEnd, 2);
//	Addnode(&pHead, &pEnd, 3);
//	Addnode(&pHead, &pEnd, 4);
//
//	return 0;
//}
//
//void Addnode(List** ppHead, List** ppend, int id) 
//{
//	List* pTemp = (List*)malloc(sizeof(List));
//	pTemp->id = id;
//	pTemp->pLast = NULL;
//	pTemp->pNext = NULL;
//
//	if (NULL == *ppHead) 
//	{
//		*ppHead = pTemp;
//	}
//	else 
//	{
//		(*ppend)->pNext = pTemp;
//		pTemp->pLast = *ppend;
//	}
//	*ppend = pTemp;
//
//}


//队列	queue	先进先出FIFO（First IN First OUT）
//栈		stack	先进后出FILO（First IN Last OUT）
//
//typedef struct Node 
//{
//	int id;
//	struct Node* p;
//}Stack;
//
//void Push(Stack** ppTop, int id);
//Stack *Pop(Stack** ppTop);
//
//int main() 
//{
//	Stack* pTop = NULL;
//	Stack* pOut = NULL;
//
//	Push(&pTop, 1);
//	Push(&pTop, 2);	
//	Push(&pTop, 3);
//	Push(&pTop, 4);
//	
//	pOut = Pop(&pTop);
//	//此时1234均出栈，如果只需要单个出栈，那么给pOut中的p赋空就行了。
//
//	return 0;
//}
//
//void Push(Stack** ppTop, int id)
//{
//	Stack* pTemp = (Stack*)malloc(sizeof(Stack));
//	pTemp->id = id;
//	pTemp->p = NULL;
//
//	//if (NULL == *ppTop) 
//	//{
//	//	*ppTop = pTemp;
//	//}
//	//else
//	//{
//		pTemp->p = *ppTop;
//		*ppTop = pTemp;
//	//}
//}
//
//
////出栈：不是删除 是把这个节点拿出来给调用者进行操作
//Stack *Pop(Stack** ppTop) 
//{
//	Stack* pMark = NULL;
//	if (*ppTop != NULL) 
//	{
//		pMark = *ppTop;
//		*ppTop = (*ppTop)->p;
//	}
//	return pMark;
//}




//返回一个数的阶乘
//
//int JieCheng(int n);
//
//int main() 
//{
//	printf("%d\n",JieCheng(6));
//}
//
//int JieCheng(int n) 
//{
//	int i;
//	int value = 1;
//
//	for (i = 1; i <= n; i++) 
//	{
//		value *= i;
//	}
//	return value;
//}
//




//递归:向下传递任务，向上传导结果。特点：自己调用自己。

//int FAC(int n);
//
//int main()
//{
//	printf("%d\n", FAC(5));
//	return 0;
//}
//
//int FAC(int n) 
//{
//	if (1 == n) 
//	{
//		return 1;
//	}
//	return n * FAC(n - 1);
//}




//斐波那契数列
// 1	2	3	4	5	6	7	8
// 1	1	2	3	5	8	13	21
//
//int Fibonacci(int n);
//int Fibonacci1(int n);
//
//int main()
//{
//	printf("%d\n", Fibonacci(40));	//递归方法：浪费空间
//	printf("%d\n", Fibonacci1(40));	//循环方法：只有指令
//}
//
//int Fibonacci(int n)
//{
//	if (1 == n || 2 == n)
//	{
//		return 1;
//	}
//	return Fibonacci(n - 1) + Fibonacci(n - 2);
//}
//
//int Fibonacci1(int n) 
//{
//	int i;
//	int V1 = 1;
//	int V2 = 1;
//	int V3;
//
//	if (1 == n || 2 == n) 
//	{
//		return 1;
//	}
//
//	for (i = 3; i <= n; i++) 
//	{
//		V3 = V1 + V2;
//		V1 = V2;
//		V2 = V3;
//	}
//	return V3;
//}


//用递归实现strlen：计算字符串的长度

//int MYstrlen(char* str);
//
//int main() 
//{
//	printf("%d\n", MYstrlen("abc"));
//	return 0;
//}
//
//int MYstrlen(char* str) 
//{
//	if (*str == '\0') 
//	{
//		return 0;
//	}
//	return MYstrlen(str + 1) + 1;
//}

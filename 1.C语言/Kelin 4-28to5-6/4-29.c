#include <stdio.h>
#include <stdlib.h>



//˫������
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


//����	queue	�Ƚ��ȳ�FIFO��First IN First OUT��
//ջ		stack	�Ƚ����FILO��First IN Last OUT��
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
//	//��ʱ1234����ջ�����ֻ��Ҫ������ջ����ô��pOut�е�p���վ����ˡ�
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
////��ջ������ɾ�� �ǰ�����ڵ��ó����������߽��в���
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




//����һ�����Ľ׳�
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




//�ݹ�:���´����������ϴ���������ص㣺�Լ������Լ���

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




//쳲���������
// 1	2	3	4	5	6	7	8
// 1	1	2	3	5	8	13	21
//
//int Fibonacci(int n);
//int Fibonacci1(int n);
//
//int main()
//{
//	printf("%d\n", Fibonacci(40));	//�ݹ鷽�����˷ѿռ�
//	printf("%d\n", Fibonacci1(40));	//ѭ��������ֻ��ָ��
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


//�õݹ�ʵ��strlen�������ַ����ĳ���

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

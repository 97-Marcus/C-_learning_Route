#include <stdio.h>
#include <stdlib.h>

//�������

 //typedef struct Node
 //{
 //	int id;
 //	struct Node* pNext;
 //}List;
 //
 //void AddNode(List** ppHead, List** ppEnd, int id);
 //void InsertNode(List** ppHead, List** ppEnd, List* pNode, int id);
 //
 //int main()
 //{
 //	List* pHead = NULL;
 //	List* pEnd = NULL;
 //	List a = { 6,NULL };
 //
 //	AddNode(&pHead, &pEnd, 1);
 //	AddNode(&pHead, &pEnd, 2);
 //	AddNode(&pHead, &pEnd, 3);
 //	AddNode(&pHead, &pEnd, 4);
 //
 //	InsertNode(&pHead, &pEnd, &a, 5);
 //
 //	while (pHead != NULL)
 //	{
 //		printf("%d\n", pHead->id);
 //		pHead = pHead->pNext;
 //	}
 //
 //	return 0;
 //}
 //
 //void AddNode(List** ppHead, List** ppEnd, int id)
 //{
 //	List* pTemp = (List*)malloc(sizeof(List));
 //	pTemp->id = id;
 //	pTemp->pNext = NULL;
 //
 //	if (NULL == *ppHead)
 //	{
 //		*ppHead = pTemp;
 //	}
 //	else
 //	{
 //		(*ppEnd)->pNext = pTemp;
 //	}
 //	*ppEnd = pTemp;
 //}
 //
 //void InsertNode(List** ppHead, List** ppEnd, List* pNode, int id)
 //{
 //	List* pMark = *ppHead;
 ///*��ĳ����������˵����Ϊ�Ѿ��жϹ�ͷ���룬�ұ�ָ����Ϊ���м���������ģ����Բ²���Զ���Ϊͷ������һ����������һ������ģ������������ж��м����ʱ��������Ҫ�ҵ����ǲ���λ�õ�ǰһ���ڵ㣬��ô�������Ϊͷ�ڵ����һ������ô��������Ҫ�ڵڶ����ڵ�ǰ����ʱ�����Ǿ��޷��õ��ڶ����ڵ��ǰһ����Ҳ����ͷ�ڵ���*/
 //
 //	//1.ͷ����   (�����id��ֵΪͷ���id�����ݣ���ô��ʱif����������Ϊ�棬Ҳ�����жϳ�����ͷ����-)
 //	if ((*ppHead)->id == id)
 //	{
 //		//�����ڵ����һ��ָ��ͷ�ڵ�
 //		//�������������û�нڵ㣬����Ψһһ���ڵ㣬��ô�½ڵ��ָ������NULLû�����⣬Ҳ����˵����д��	pNode->pNext = NULL;����������������нڵ㣬��Ҫ����½ڵ���뵽��ǰ�棬��ô�½ڵ��ָ�����Ӧ��ָ��ԭ����ͷָ�루Ҳ���Ǳ����ָ��ͷ�ڵ��ָ�룩
 //		pNode->pNext = *ppHead;
 //		//ͷָ��ָ�������Ľڵ�
 //		//�������Ψһһ���ڵ㣬��ôͷָ���βָ�붼ָ��ýڵ㣬������ǲ��뵽��һ���ڵ�֮ǰ�Ľڵ㣬��ôͷָ���Ӧ��ָ������µĽڵ�
 //		*ppHead = pNode;
 //		return;
 //	}
 //
 //	//�м���� 
 //	//��������
 //	//while (pMark != NULL)
 //	/*���ѭ������ΪpMark != NULL����ô��pMarkΪ4�Žڵ�ʱ��pMark->pNext�ǲ����ڵģ���ôҲ�Ͳ�����pMark->pNext->id�����Գ�����bug*/
 //	//��ȷѭ������������ʾ��
 //	while (pMark->pNext != NULL)
 //	{
 //		//�ñ��ͣ�ڲ���λ�õ�ǰһ���ڵ���
 //		if (pMark->pNext->id == id)
 //		{
 //			//�����ڵ����һ��ָ���ǵ���һ��
 //			//�����ڵ��ָ����ű�ǽڵ��ָ����Ҳ���Ǳ�ǵ���һ�����ĵ�ַ
 //			pNode->pNext = pMark->pNext;
 //			//��ǵ���һ��ָ�������ڵ�
 //			//��ǽڵ��ָ����������ڵ�ĵ�ַ
 //			pMark->pNext = pNode;
 //			return;
 //		}
 //		pMark = pMark->pNext;
 //	}
 //
 //	//β����
 //	(*ppEnd)->pNext = pNode;
 //	//β�ڵ����һ��ָ�������ڵ�//����β�ڵ��ָ����������ڵ�ĵ�ַ
 //	*ppEnd = pNode;
 //	//��Ϊ���ܺ�������Ҫ���½����뵽�����β����������Ҫβָ�룬Ҳ���Ǳ������е�ppEnd������ʼ��ָ�������β�ڵ㣬�Ա��ܹ����½����뵽�����β����
 //	//��˱�����˼Ϊβָ��ָ�������ڵ�����Ϊβ�ڵ�
 //}

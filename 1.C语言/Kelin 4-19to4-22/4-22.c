#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//����ɾ��

/*

typedef struct Node {
	int id;
	struct Node* pNext;
}List;

void AddNote(List** pHead1, List** pEnd1, int id);
void DeleteNote(List** pHead1, List** pEnd1, int id);

int main() 
{
	List* pHead = NULL;
	List* pEnd = NULL;

	AddNote(&pHead, &pEnd, 1);
	AddNote(&pHead, &pEnd, 2);
	AddNote(&pHead, &pEnd, 3);
	AddNote(&pHead, &pEnd, 4);

	DeleteNote(&pHead, &pEnd, 4);

	while (pHead != NULL) 
	{
		printf("%d\n", pHead->id);
		pHead = pHead->pNext;//��
	}

	return 0;
}

void AddNote(List** pHead1, List** pEnd1, int id) 
{
	List* pTemp = (List*)malloc(sizeof(List));

	pTemp->id = id;
	pTemp->pNext = NULL;
	//�����и��յĻ�����ô��ֵ���ڱ���ʱ�޷���������pHead=pNext!=NULLʱ��������

	if (NULL == *pHead1)
	{
		*pHead1 = pTemp;
	}
	else
	{
		(*pEnd1)->pNext = pTemp;
	}
	*pEnd1 = pTemp;
}


void DeleteNote(List** pHead1, List** pEnd1, int id) 
{
	List* pDelete = NULL;
	List* pMark = *pHead1;

	//ͷɾ��
		//ֱ��ɾ��ͷ�ڵ�Ļ���2�Žڵ��Ҳ�����
		//����ͷָ����ָ��2�Žڵ���ɾ��ͷ�ڵ�Ļ��������������Ҳ���ͷ�ڵ�ģ�������Ҫһ��ɾ����ǡ�
	if ((*pHead1)->id == id)
	{
		//ɾ�����ָ��ͷ�ڵ�
		pDelete = *pHead1;
		//ͷָ��ָ��ͷ�ڵ����һ��
		*pHead1 = (*pHead1)->pNext;
		//�ͷ�ɾ�����
		free(pHead1);
		pHead1 = NULL;
		//�ͷ����Ժ����ָ�벻���������������ָ�뼰��������Ȼ���ڣ�Ҫ���ղſ�����ȫ����Ӱ��
		return;//��������
	}

	//�м�ɾ��
	while (pMark->pNext != NULL) 		//��������
	{
		//�������ͣ��ɾ���ڵ��ǰһ���ڵ���
		if (pMark->pNext->id == id) 
		{
			//ɾ�����ָ�������ǵ���һ��
			pDelete = pMark->pNext;
			//������ǵ���һ��ָ�������ǵ���һ������һ��
			pMark->pNext = pMark->pNext->pNext;
			//�ͷ�ɾ�����
			free(pDelete);
			pDelete = NULL;
			//�ж�ɾ�����Ƿ���β�ڵ�
			if (pMark->pNext == NULL) 
			{
				*pEnd1 = pMark;
			}
			//βɾ��
			//�м�ɾ������ɾ��β�ڵ㣬����βָ����Ȼָ��ɾ���Ľڵ㣬������Ҫ��һ���ж����Ƿ�Ϊβ�ڵ�
		    //����ǵ���һ����NULL���Ƿǿռ��ɣ����NULL����β�ڵ㣬��ô��βָ��ָ���ǽڵ㼴��
			return;
		}
		pMark = pMark->pNext;
	}	
}
*/




//����� int rand (void);
//ʵ���ϣ�rand() �����������������α��������Ǹ���һ����ֵ����ĳ����ʽ��������ģ������ֵ���ǳ�֮Ϊ�����ӡ�.
//������ÿ�����������ʱ������ģ�����һ������������Ժ����Ͳ��ٱ仯�ˣ�
//Ҳ����˵��ÿ������������Ժ����Ӿ��Ƕ�ֵ�ˣ����Ը��ݹ�ʽ��������Ľ����Ҳ�������ɵ�����������ǹ̶��ġ�
//���ǿ���ͨ�� srand() ���������¡����֡�:void srand (unsigned int seed);
//��ʵ�ʿ����У�������ʱ����Ϊ������ֻҪÿ�β��ֵ�ʱ�䲻ͬ����ô���ɵ����ӾͲ�ͬ�����յ������Ҳ�Ͳ�ͬ��
//ʹ�� <time.h> ͷ�ļ��е� time() �������ɵõ���ǰ��ʱ�䣨��ȷ���룩����������������
//srand((unsigned)time(NULL));

/*
 
int main()
{
	
	//printf("%d\n",time(NULL)/60/60/24/365);

	srand((unsigned int)time(NULL));

	printf("%d\n",rand() % 10);			//0-9
	printf("%d\n",rand() %10 + 11);		//11-20 - 11    0 - 9
	printf("%d\n",rand() % 6 + 12);		//12-17   - 12   0 - 5
	printf("%d\n",rand());

	//���Ҫ�涨�����ޣ����磺int a = rand() % 51 + 13;    //����13~63�������
    //ȡģ��ȡ�࣬rand()%51�ǲ��� 0~50 �������������+13��֤ a ��Сֻ���� 13�������� 50+13=63��

	//Ҳ����˵��Ҫ�跶Χ����Ϊ��max��min������ôֻ�� rand%(max-min+1)+min ���ɡ�
	
	return 0;
}

*/
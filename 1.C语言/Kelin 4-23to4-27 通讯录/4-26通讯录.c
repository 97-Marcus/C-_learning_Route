
/*

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Note {
    int id;
    char* name;
    char* tel;
    struct Note* pNext;
}List;

typedef struct PAGE
{
    int OnePageInfo;	//ÿҳ��ʾ������
    int CurrentPage;	//��ǰҳ
    int TotalPage;		//��ҳ��
    int TotalInfo;		//������

}Page;

List* GetNote();
void AddNote(List** ppHead, List** ppEnd, List* pNode);
int GetID();
char* GetName();
char* GetTel();
void InitInfo(List** ppHead, List** ppEnd, int n);
Page* GetPage(List* pHead, int n);
void ShowInfo(List* pHead, Page* pPage);
void ShowMenu(Page* pPage);
void TurnPage(List* pHead, Page* pPage);
char GetKey();
void Browse(List* pHead);


int main()
{
    List* pHead = NULL;
    List* pEnd = NULL;
    char c;

    InitInfo(&pHead, &pEnd, 101);

    while (1)
    {
        printf("1.�鿴ͨѶ¼\n");
        printf("2.�����Ϣ\n");
        printf("3.��ѯ��Ϣ\n");
        printf("4.ɾ����Ϣ\n");
        printf("5.�޸���Ϣ\n");
        printf("q.�˳�\n");

        c = GetKey();

        switch (c)
        {
        case '1':
            Browse(pHead);
            break;
        case 'q':
            return 0;
            break;
        }
    }
    return 0;
}

List* GetNote()
{
    List* pTemp = (List*)malloc(sizeof(List));
    if (NULL == pTemp)
    {
        printf("error\n");
        exit(-1);
    }//�ж��Ƿ�����ɹ�
    pTemp->id = GetId();
    pTemp->name = GetName();
    pTemp->tel = GetTel();
    pTemp->pNext = NULL;

    return pTemp;
}

void AddNote(List** ppHead, List** ppEnd, List* pNode)
{
    if (NULL == *ppHead)
    {
        *ppHead = pNode;
    }
    else
    {
        (*ppEnd)->pNext = pNode;
    }
    *ppEnd = pNode;
}

int GetId()
{
    static int id = 1;

    return id++;
}

char* GetName()
{
    char* str = (char*)malloc(6);
    int i;

    for (i = 0; i < 5; i++)
    {
        str[i] = rand() % 26 + 'a';
    }
    str[i] = '\0';

    return str;
}

char* GetTel()
{
    char* str = (char*)malloc(12);
    int i;

    switch (rand() % 4)
    {
    case 0:
        str[0] = '1';
        str[1] = '3';
        str[2] = '3';
        break;
    case 1:
        strcpy_s(str, 12, "155");
        break;
    case 2:
        strcpy_s(str, 12, "177");
        break;
    case 3:
        strcpy_s(str, 12, "188");
        break;
    }

    for (i = 3; i < 11; i++)
    {
        str[i] = rand() % 10 + '0';
    }
    str[i] = '\0';

    return str;
}

void InitInfo(List** ppHead, List** ppEnd, int n)
{
    int i;

    srand((unsigned int)time(NULL));
    //һ������£�һ������ֻ��һ�����ӣ�������ӿ��ܻᵼ�³���һ����rand

    for (i = 0; i < 100; i++)
    {
        AddNote(ppHead, ppEnd, GetNote());
        //�����	srand((unsigned int)time(NULL));�ֱ�д��char* GetName();��char* GetTel();��
        //��ôÿ���������name��telʱ������������һ�����ӣ������(unsigned int)time(NULL)ǿ��ת����õ������ֺ�֮ǰ�����������һ������ôrand���������ͻ�һ����
    }
}

Page* GetPage(List* pHead, int n)
{
    Page* pPage = (Page*)malloc(sizeof(Page));
    pPage->CurrentPage = 0;
    pPage->OnePageInfo = n;
    pPage->TotalPage = 0;
    pPage->TotalInfo = 0;

    while (pHead != NULL)
    {
        pPage->TotalInfo++;
        pHead = pHead->pNext;
    }

    if (pPage->TotalInfo % pPage->OnePageInfo == 0)
    {
        pPage->TotalPage = pPage->TotalInfo / pPage->OnePageInfo;
    }
    else
    {
        pPage->TotalPage = pPage->TotalInfo / pPage->OnePageInfo + 1;
    }

    //Ҳ����ʹ����Ŀ�����
    //pPage->TotalPage = pPage->TotalInfo % pPage->OnePageInfo == 0 
    //? pPage->TotalInfo / pPage->OnePageInfo
    //: pPage->TotalInfo / pPage->OnePageInfo + 1;

    return pPage;
}

void ShowInfo(List* pHead, Page* pPage)
{
    int begin = (pPage->CurrentPage - 1) * pPage->OnePageInfo + 1;
    int end = pPage->CurrentPage * pPage->OnePageInfo;
    //begin��endΪȷ����ʾ�ķ�Χ��begin����һ�ֽⷨΪend-ÿҳ��ʾ������
    int count = 0;

    while (pHead != NULL)
    {
        count++;
        if (count >= begin && count <= end)
        {
            printf("%d  %s  %s\n", pHead->id, pHead->name, pHead->tel);
        }
        pHead = pHead->pNext;
    }
}

void ShowMenu(Page* pPage)
{
    printf("��ǰ��%dҳ  ��%dҳ  ��%d��  w��һҳ  s��һҳ  b����\n", pPage->CurrentPage, pPage->TotalPage, pPage->TotalInfo);
}


void TurnPage(List* pHead, Page* pPage)
{
    char c = 's';

    while (1)
    {
        switch (c)
        {
        case 'w':
            if (pPage->CurrentPage > 1)//����1��--����ֹ����ָ���ҳ��
            {
                pPage->CurrentPage--;
                ShowInfo(pHead, pPage);
                ShowMenu(pPage);
            }
            else
            {
                printf("�Ѿ��ǵ�һҳ��\n");
            }
            break;
        case 's':
            if (pPage->CurrentPage < pPage->TotalPage)//С����ҳ����++����ֹ����ֳ�ҳ���
            {
                pPage->CurrentPage++;
                ShowInfo(pHead, pPage);
                ShowMenu(pPage);
            }
            else
            {
                printf("�Ѿ������һҳ��\n");
            }
            break;
        case 'b':
            return;//����
            break;
        default:
            printf("������\n");
            break;
        }

        c = GetKey();//���ַ���������\nɸ��
    }
}

char GetKey()
{
    char c;
    char z;
    int bFlag = 1;
	 //�����������scanf����ô�����������\n
	 //����ͨ��bFlag�ı�ǣ�ʹ������ε�һ���Ƿ���\n������ѭ�����Դﵽ�õ����ݵ�Ŀ��

    while ((c = getchar()) != '\n' || 1 == bFlag)
    {
        z = c;
        bFlag = 0;
    }

    return z;
}

void Browse(List* pHead)//���⼸����ҳ��ʾ����غ�����װ����
{
    Page* pPage = GetPage(pHead, 10);
    TurnPage(pHead, pPage);
    free(pPage);//��Ҫ�ͷŵ�GetPage��������Ŀռ䣬����ÿ����������ʱ������һ��GetPage������ռ�úܶ�ռ䡣
    pPage = NULL;//�ͷ�ֻ�Ǵ�����������ó�ȥ�����ǻ�ɢ�����ڴ�ռ䣬������Ҫ������������
}

*/
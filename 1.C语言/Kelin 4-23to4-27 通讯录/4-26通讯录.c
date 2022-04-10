
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
    int OnePageInfo;	//每页显示多少条
    int CurrentPage;	//当前页
    int TotalPage;		//总页数
    int TotalInfo;		//总条数

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
        printf("1.查看通讯录\n");
        printf("2.添加信息\n");
        printf("3.查询信息\n");
        printf("4.删除信息\n");
        printf("5.修改信息\n");
        printf("q.退出\n");

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
    }//判断是否申请成功
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
    //一般情况下，一个程序只埋一个种子，多个种子可能会导致出现一样的rand

    for (i = 0; i < 100; i++)
    {
        AddNote(ppHead, ppEnd, GetNote());
        //如果将	srand((unsigned int)time(NULL));分别写到char* GetName();和char* GetTel();中
        //那么每次随机生成name和tel时都会重新设置一次种子，而如果(unsigned int)time(NULL)强制转换后得到的数字和之前的种子里的数一样，那么rand产生的数就会一样。
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

    //也可以使用三目运算符
    //pPage->TotalPage = pPage->TotalInfo % pPage->OnePageInfo == 0 
    //? pPage->TotalInfo / pPage->OnePageInfo
    //: pPage->TotalInfo / pPage->OnePageInfo + 1;

    return pPage;
}

void ShowInfo(List* pHead, Page* pPage)
{
    int begin = (pPage->CurrentPage - 1) * pPage->OnePageInfo + 1;
    int end = pPage->CurrentPage * pPage->OnePageInfo;
    //begin至end为确定显示的范围，begin还有一种解法为end-每页显示的条数
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
    printf("当前第%d页  共%d页  共%d条  w上一页  s下一页  b返回\n", pPage->CurrentPage, pPage->TotalPage, pPage->TotalInfo);
}


void TurnPage(List* pHead, Page* pPage)
{
    char c = 's';

    while (1)
    {
        switch (c)
        {
        case 'w':
            if (pPage->CurrentPage > 1)//大于1才--，防止其出现负数页码
            {
                pPage->CurrentPage--;
                ShowInfo(pHead, pPage);
                ShowMenu(pPage);
            }
            else
            {
                printf("已经是第一页了\n");
            }
            break;
        case 's':
            if (pPage->CurrentPage < pPage->TotalPage)//小于总页数才++，防止其出现超页情况
            {
                pPage->CurrentPage++;
                ShowInfo(pHead, pPage);
                ShowMenu(pPage);
            }
            else
            {
                printf("已经是最后一页了\n");
            }
            break;
        case 'b':
            return;//返回
            break;
        default:
            printf("按错了\n");
            break;
        }

        c = GetKey();//将字符缓冲区的\n筛掉
    }
}

char GetKey()
{
    char c;
    char z;
    int bFlag = 1;
	 //如果程序中有scanf，那么可能有遗落的\n
	 //可以通过bFlag的标记，使无论如何第一个是否是\n都进入循环，以达到得到数据的目的

    while ((c = getchar()) != '\n' || 1 == bFlag)
    {
        z = c;
        bFlag = 0;
    }

    return z;
}

void Browse(List* pHead)//将这几个分页显示的相关函数封装起来
{
    Page* pPage = GetPage(pHead, 10);
    TurnPage(pHead, pPage);
    free(pPage);//需要释放掉GetPage中所申请的空间，否则每次生成链表时都进入一次GetPage，申请占用很多空间。
    pPage = NULL;//释放只是从这个程序中拿出去，但是还散落在内存空间，所以需要情况上面的内容
}

*/
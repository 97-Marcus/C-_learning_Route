//#include<stdio.h> #include<stdlib.h> #include<string.h>
//void welcome();//	��ӭ�û�ʹ��
//int denglu1(struct student s[], int i);//	ѧ����½
//int denglu2();//	����Ա��½
//struct book* creatbook();//	�����������ļ��е�ͼ����Ϣд������
//int inputchoice();//	ѡ��˵�
//int inputchoice1();//	ѧ��ѡ��˵�
//int inputchoice2();//	����Աѡ��˵�
//void pmenu(struct book* head);//	ѧ��������ѡ��˵�
//void menu2(struct book* head);//	����Ա������ѡ��˵�
//
//struct book* addbook(struct book* head);//	���ͼ����Ϣ
//int chashu(struct book* head, char m[20]);//		���ҷ�����Ƿ����  struct book *insert1(struct book * head,struct book *p);//	���ӽӵ�void printbook(struct book * head);//	ͼ�����
//int putchoice();//	ѡ���������
//void chaname1(struct book* head);//		����������void chaprice(struct book * head);//		���۸����void chacnum(struct book * head);//	������Ų���
//void chazuozhe(struct book* head);//	����������ѯͼ����Ϣ
//void chatime(struct book* head);//			������ʱ�����void chapress(struct book * head);//				�����������void sortbook(struct book * head);//				�� �� ѡ �� void shuming(struct book * head);//			��ͼ������ void ptime(struct book * head);//	������ʱ������void price1(struct book * head);//		��ͼ��۸���
//void fenleihao(struct book* head);//	��ͼ��������
//void zuo1(struct book* head);//	������������
//void pre1(struct book* head);//	������������
//struct book* shanchubook(struct book* head);//	ɾ��ͼ����Ϣ
//void fprint(struct book* head);//	��������д���ļ���
//void xiugai(struct book* head);//	�޸�ͼ����Ϣ
//void printbook1(struct book* head);//	���ȫ��ͼ����Ϣ
//int chacun(struct book* head, char m[20]);//	���ҿ�����Ƿ�Ϊ	0 int jige();//	����ļ��пͻ��ĸ���
//int xcz(struct book* head, char cnum[20]);//	�ѿ���ͼ��Ŀ������һ
//int xcz1(struct book* head, char cnum[20]);//	�ѿ���ͼ��Ŀ������һvoid backbook(struct student s[],int i,struct book * head);//	���麯��void borrowbook(struct student s[],int i,struct book * head);//		���麯��
//void xmima(struct student s[], int i);//	�޸�����
//void xwj(struct student s[], int i);//	���޸ĺ������д���ļ�
//void oneself(struct student s[], int i);//	�鿴������Ϣ
//int jie(char cnum[20], int i, struct student s[], char mnum[20]);//	��ѯ�Ƿ����
//int huan(int i, struct student s[], char mnum[20]);//	�����ѯ�Ƿ����ͼ����Ϣ�ṹ�壺
//struct book {
//	char bookname[20];//	����
//	char ename[20];//	����
//	char cnum[20];//	ͼ�����ż�ͼ���ţ���������ͼ��Ψһ����
//	char pubpress[20];//		������char pubtime[20];//	����ʱ��int price;//	�۸�
//	int zc;//	�ֿ��
//
//	int xc;//	�ܿ��
//	struct book* next;//	��������ͼ����Ϣ
//};
//int denglu2()//	����Ա��½ϵͳ
//{
//	FILE* fp; struct xinxi {
//		char mnum[20];//	����Ա��½�˺�
//		char mima[20];//	����Ա��¼����
//	}temp;
//	char mnum[20], mima[20]; int m, n, i;
//	for (i = 0; i < 3; i++)
//	{
//		printf("	�������ʺ� :");
//		scanf("%s", mnum);
//		printf("	���������� :");
//		scanf("%s", mima); if ((fp = fopen("2.txt", "r")) == NULL) {
//			printf("Can not open the file!"); exit(0);
//		}
//		while (!feof(fp))
//		{
//			fscanf(fp, "%s%s", temp.mnum, temp.mima); m = strcmp(temp.mnum, mnum); n = strcmp(temp.mima, mima); if (m == 0 && n == 0)
//				return 1;
//		}
//		fclose(fp);
//	}
//	return i;
//}
//int inputchoice2()//	����Ա����ѡ��ģ�飬����Ա�����й���
//{
//	int mychoice;
//	printf("1.	ͼ���ѯ \n2. ͼ������ \n3. ���ȫ��ͼ�� \n4. ���ͼ�� \n5. ɾ��ͼ��\n6. �޸�ͼ�� \n0. �˳�\n");
//	printf("\ninput your choice:"); scanf("%d", &mychoice); return mychoice;
//}
//3��struct book * creatbook() {
//
//	FILE* fp;
//	struct book* head, * tail, * p; int size = sizeof(struct book);
//	char bookname[20], ename[20], cnum[20], pubpress[20], pubtime[20];
//	int price, zc, xc; head = tail = NULL;
//	if ((fp = fopen("book.txt", "r")) == NULL) {
//		printf("Can not open the file!"); exit(0);
//	}
//	fscanf(fp, "%s%s%s%s%s%d%d%d", bookname, ename, cnum, pubpress, pubtime
//		, &price, &zc, &xc); while (!feof(fp)) {
//
//		p = (struct book*)malloc(size); strcpy(p->bookname, bookname); strcpy(p->ename, ename); strcpy(p->cnum, cnum);
//		strcpy(p->pubpress, pubpress); strcpy(p->pubtime, pubtime);
//		p->price = price;
//		p->zc = zc; p->xc = xc;
//		if (head == NULL) head = p;
//		else
//			tail->next = p;
//		tail = p;
//
//		fscanf(fp, "%s%s%s%s%s%d%d%d", bookname, ename, cnum, pubpress, pubtime
//			, &price, &zc, &xc);
//	}
//	fclose(fp);
//	tail->next = NULL; return head;
//}
//struct book* addbook(struct book* head)//	���ͼ����Ϣ
//{
//	FILE* fp; struct book* p;
//	int size = sizeof(struct book);
//	char bookname[20];//	����char ename[20];//		����char cnum[20];//	�����
//
//	char pubpress[20];//	������
//	char pubtime[20];//	����ʱ��
//	int price, zc, xc;//	�۸��ܿ�棬�ֿ��
//	int n, i;
//	printf("	������Ѿ������ϣ��뽫�����������Ϊ	0�� л л �� �� :\n"); printf("1.	������ӣ� ���������û�д����ļ���		\n2. ������ӣ� ��������
//		���д�� \n");
//		printf("	�������� :");
//	scanf("%d", &i); switch (i) {
//	case 1:
//		printf("	������ͼ������ :"); scanf("%s", cnum);
//		n = chashu(head, cnum); if (n == 1)
//		{
//			printf("	������ķ�����Ѵ���	, ���������� !\n"); return head;
//		}
//		while (strcmp(cnum, "0") != 0)
//		{
//			n = chashu(head, cnum); if (n == 1)
//			{
//				printf("	ͼ��ķ�����Ѵ��� , ���������룡 "); return head;
//			}
//			p = (struct book*)malloc(size);
//
//			strcpy(p->cnum, cnum); printf("	������ͼ���� :");
//			scanf("%s", bookname);
//			strcpy(p->bookname, bookname); printf("	������������ :");
//			scanf("%s", ename); strcpy(p->ename, ename);
//			printf("	����������� :"); scanf("%s", pubpress);
//			strcpy(p->pubpress, pubpress); printf("	���������ʱ�� :");
//			scanf("%s", pubtime);
//			strcpy(p->pubtime, pubtime); printf("	������۸� :");
//			scanf("%d", &price);
//
//			p->price = price;
//			printf("	�������ܿ���� :");
//			scanf("%d", &zc); p->zc = zc;
//			printf("	�������ֿ���� :");
//			scanf("%d", &xc); p->xc = xc;
//			head = insert1(head, p, cnum); printf("	������ͼ������ :");
//			scanf("%s", cnum);
//
//
//
//	case 2:
//
//		}
//		break;
//
//		if ((fp = fopen("book1.txt", "r")) == NULL)
//		{
//			printf("File do not open!"); exit(0);
//		}
//		while (!feof(fp))
//		{
//			p = (struct book*)malloc(size); fscanf(fp, "%s", bookname); strcpy(p->bookname, bookname); fscanf(fp, "%s", ename);
//			strcpy(p->ename, ename); fscanf(fp, "%s", cnum); strcpy(p->cnum, cnum); n = chashu(head, cnum); if (n == 1)
//			{
//				printf("	ͼ��ķ�����Ѵ��� , ���������룡 "); return head;
//			}
//			fscanf(fp, "%s%s%d%d%d", pubpress, pubtime, &price, &zc, &xc); strcpy(p->pubpress, pubpress);
//			strcpy(p->pubtime, pubtime); p->price = price;
//			p->zc = zc;
//			p->xc = xc; head = insert1(head, p, cnum);
//		}
//	break; default:
//		printf("	������� !\n");
//
//		break;
//	}
//	return head;
//}
//int chashu(struct book* head, char m[20])//	����ͼ���Ƿ����
//{
//	int flag = 0;
//	struct book* p = NULL; if (head == NULL)
//		return -1;//	����Ӹ�ͼ��
//	else
//		p = head;
//	while (p != NULL)
//	{
//		if (strcmp(p->cnum, m) == 0) flag = 1;
//		p = p->next;
//	}
//	if (flag == 1)
//		return 1;//	������Ӹ�ͼ��
//
//	else
//
//}
//
//
//return -1;
//
//struct	book* insert1(struct	book* head, struct	book* ptr, char	cnum[20])//
//	���ӽӵ�
//{
//	struct book* p, * p1, * p2; p2 = head;
//	p = ptr;
//	if (head == NULL)
//	{
//
//
//
//	}
//	else
//	{
//
//		head = p1;
//		p1->next = NULL;
//
//
//
//		while ((strcmp(p->cnum, p2->cnum) > 0) && (p2->next != NULL))
//		{
//
//			p1 = p2; p2 = p2->next;
//		}
//		if (strcmp(p->cnum, p2->cnum) <= 0)
//		{
//			if (head == p2)
//
//
//			else
//
//				head = p;
//
//			p1->next = p;
//
//
//		}
//		else
//		{
//
//
//		}
//	}
//
//	p->next = p2;
//
//
//
//	p2->next = p;
//	p->next = NULL;
//
//	return head;
//}
//int putchoice()//	ѡ���������
//{
//	int mychoice;
//	printf("\n\t\t\t1.		���������� \n\t\t\t2.	���۸���� \n\t\t\t3.	������Ų��� \n\t\t\t4.	�����߲��� \n\t\t\t5.	��ʱ����� \n\t\t\t6.	�����������\n\t\t\t0.�˳�\n\n");
//		printf("	�������ѯ��� :"); scanf("%d", &mychoice); return mychoice;
//}
//void chaname1(struct book* head)//	����������
//{
//
//	struct book* p; char shuname[20]; int flag = 0;
//	p = head;
//	printf("	������Ҫ���ҵ����� :"); scanf("%s", shuname);
//	printf("\n");
//	printf("	���ҽ������ \n");
//	printf("	ͼ����\t	����\t	�����\t	������\t	����ʱ�� \t	�۸�\t	�ܿ��\t
//		�ֿ��\n");;
//		while (p != NULL) {
//			if (strcmp(shuname, p->bookname) == 0)
//			{
//
//				printf("%s\t%s\t%s\t%s\t%s\t\t%d\t%d\t%d\t", p->bookname, p->ename, p->cnum, p->pubpress, p->pubtime, p->price, p->zc, p->xc);
//				printf("\n"); flag = 1;
//
//
//			}
//			p = p->next;
//		}
//	if (flag == 0)
//		printf("	δ�ҵ���Ҫ�ҵ��飬���ʵ������	!\n");
//}
//void sortbook(struct book* head)//	����ѡ��
//{
//	int i;
//	printf("\n\t\t\t1-	��ͼ��������	\n\t\t\t2-	������ʱ������	\n\t\t\t3-	��ͼ�� �۸� ���� \n\t\t\t4 - ��ͼ ��� ��� ���� \n\t\t\t5 - ���� ��������	\n\t\t\t6 - ������������ \n\t\t\t0 - ȡ��������� \n\n"); printf("		��������ѡ���ѡ�� :");
//		scanf("%d", &i); switch (i) {
//		case 0:
//		break; case 1:
//			shuming(head); //	��ͼ��������
//		break; case 2:
//			ptime(head); //	������ʱ������
//		break; case 3:
//			price1(head); //	������۸�����
//		break; case 4:
//			fenleihao(head); //	��ͼ����������
//		break; case 5:
//			zuo1(head); //	��ͼ����������
//		break; case 6:
//			pre1(head); //	������������
//		default:
//			printf("	������������ !\n"); break;
//	}
//}
//���У�ֻ�������۸���������ʡȥ��
//void price1(struct book* head)//	��ͼ��۸�����
//{
//	struct book* a[100], * p, * p1, * temp;
//
//	int i, k, index, n = 0; char ch; p1 = head;
//	for (p = head; p; p = p->next) n++;
//	for (i = 0; i < n; i++) {
//		a[i] = p1; p1 = p1->next;
//	}
//	for (k = 0; k < n - 1; k++) {
//		index = k; for (i = k + 1; i < n; i++) {
//			if (a[i]->price < a[index]->price) index = i;
//		}
//		temp = a[index]; a[index] = a[k]; a[k] = temp;
//	}
//	printf("	����ɹ� !\n");
//	printf("	�Ƿ���ʾ������ ?(y/n)\n"); scanf("%s", &ch);
//	switch (ch) {
//	case 'n':
//	break; case 'y':
//		printf("	ͼ����\t	����\t	�����\t	������\t	����ʱ�� \t	�۸�\t	�ܿ��\t	�ֿ��\n");
//		for (i = 0; i < n; i++) {
//			printf("%s\t%s\t%s\t%s\t%s\t\t%d\t%d\t%d\n", a[i]->bookname, a[i]->
//				ename, a[i]->cnum, a[i]->pubpress, a[i]->pubtime, a[i]->price, a[i].zc.a[i
//				].xc);
//		}
//	break; default:
//		printf("	������������ !\n");
//		break;
//	}
//}
//ɾ����Ϣģ�飺
//struct book* shanchubook(struct book* head)//	ɾ��ͼ����Ϣ
//{
//	char num[20];
//	struct book* ptr1, * ptr2, * p;
//
//	printf("	������ͼ������ :"); scanf("%s", num);
//
//	p = head; while (p != NULL) {
//		if (strcmp(p->cnum, num) == 0) break;
//		p = p->next;
//	} if (p == NULL) {
//		printf("	û���ҵ��úŵ�ͼ�� !\n");
//
//	}
//	else
//	{
//
//
//
//
//		while (head != NULL && head->next == NULL)
//		{
//
//			if (strcmp(head->cnum, num) == 0)
//			{
//				ptr2 = head; head = head->next; free(ptr2);
//			}
//		}
//		if (head == NULL)
//		{
//			return NULL;
//		}
//		ptr1 = head; ptr2 = head->next; while (ptr2 != NULL)
//		{
//			if (strcmp(ptr2->cnum, num) == 0)
//			{
//
//
//
//			}
//			else
//
//				ptr1->next = ptr2->next; free(ptr2);
//
//
//			ptr1 = ptr2;
//
//			ptr2 = ptr1->next;
//		}
//	}
//	return head;
//}
//�޸�ͼ����Ϣģ�飺
//
//void xiugai(struct book* head)//	�޸�ͼ����Ϣ
//{
//	int i;
//	char cnum[20]; struct book* p;
//	printf("	������Ҫ�޸ĵ�ͼ������	:");
//	scanf("%s", cnum); p = head; while (p != NULL) {
//		if (strcmp(p->cnum, cnum) == 0) break;
//		p = p->next;
//	} if (p == NULL) {
//		printf("	û���ҵ��úŵ�ͼ�� !\n");
//	}
//	else {
//		printf("1-	����� \n2-	ͼ���� \n3- ������ \n4- ������ \n5- ����ʱ��		\n6 - �۸�\7 - �޸�ȫ�� \n0 - �����޸� \n"); case 1:
//			printf("	�������·���� :");
//		scanf("%s", p->cnum); fprint(head);
//		printf("	�޸ĳɹ� !\n");
//		break;
//	}
//	�޸�ͼ����Ϣֻ����һ���֣���������ӣ�ɾ�����������޸ĺ󣬶���Ҫ��������д���ļ�������������ˣ���Ҫ��������ĺ�����
//		void fprint(struct book* head)//	��������д���ļ���
//	{
//		FILE* fp; struct book* p;
//		if ((fp = fopen("book.txt", "w")) == NULL) {
//			printf("File open error!\n"); exit(0);
//		}
//		for (p = head; p != NULL; p = p->next) {
//			fprintf(fp, "%s\t%s\t%s\t%s\t%s\t%d\t%d\t%d\n", p->bookname, p->enam
//				e, p->cnum, p->pubpress, p->pubtime, p->price, p->zc, p->xc);
//		}
//		fclose(fp);
//	}
//	�����ͼ����Ϣʱ����Ҫ���������
//		void printbook1(struct book* head)//	���ȫ��ͼ����Ϣ
//	{
//
//		struct book* p; if (head == NULL) {
//			printf(""); return;
//		}
//		printf("	ȫ��ͼ����Ϣ���� \n");
//		printf("	����\t	����\t	�����\t	������ \t	����ʱ�� \t	�۸�\t	�ܿ�� \t
//			�ֿ��\n");
//			for (p = head; p != NULL; p = p->next) printf("%s\t%s\t%s\t%s\t%s\t\t%d\t%d\t%d\n", p->bookname, p->ename,
//				p->cnum, p->pubpress, p->pubtime, p->price, p->zc, p->xc);
//	}
//	void pmenu(struct book* head, struct student s[])
//	{
//		int choice, m;
//
//		m = jige(); while ((choice = inputchoice1()) != 0)
//		{
//			switch (choice) {
//			case 1:
//				if (head == NULL) {
//					printf("	ͼ��ݹ���ϵͳ���� �����޷����������� �����������鷳���������Ǹ�� !\n");
//					break;
//				}
//				else
//					printbook(head);//	ͼ���ѯ
//			break; case 2:
//				if (head == NULL) {
//					printf("	ͼ��ݹ���ϵͳ���� �����޷����������� �����������鷳���������Ǹ�� !\n");
//					break;
//				}
//				else
//					sortbook(head);//	ͼ������
//			break; case 3:
//				if (head == NULL) {
//					printf("	ͼ��ݹ���ϵͳ���������޷����������������������鷳���������Ǹ�� !\n");
//					break;
//				}
//
//				else
//					printbook1(head);//	���ȫ��ͼ����Ϣ
//			break; case 4:
//				borrowbook(s, m, head);//	����
//			break; case 5:
//				backbook(s, m, head);//	����
//			break; case 6:
//				xmima(s, m);//	�޸�����
//			break; case 7:
//				oneself(s, m);//	�鿴��������
//				break;
//
//			default:
//				printf("	������� \n"); break;
//			}
//		}
//	}
//	�����뻹��ģ�飺
//		void borrowbook(struct student s[], int i, struct book* head)
//	{
//		int m, n, t, p, flag = 0, p1;
//		char mnum[20], mima[20], cnum[20], bookname[20]; if (i > 100)
//			printf("	���������������ֲ��ܽ���	!\n");
//
//		else
//		{
//
//
//
//			printf("	�������ʺ� :");
//			scanf("%s", mnum);
//			printf("	���������� :");
//			scanf("%s", mima); for (t = 0; t < i; t++)
//			{
//				if (strcmp(s[t].mnum, mnum) == 0 && strcmp(s[t].mima, mima) == 0)
//				{
//
//					printf("	������ͼ��ķ���� :"); scanf("%s", cnum); p1 = huan(i, s, mnum);
//					if (p1 == 1)
//					{
//
//						m = chashu(head, cnum);//	��֤����ͼ���Ƿ����
//						if (m == 1)
//						{
//							n = chacun(head, cnum);//	��֤����ͼ���Ƿ��ڿ�
//							if (n == 1)
//							{
//								strcpy(s[t].num, cnum);
//								printf("	���������� :"); scanf("%s", bookname); strcpy(s[t].book, bookname); xwj(s, i);
//								p = xcz(head, cnum);//	�ѿ������ 1
//								if (p == -1)
//									printf("	����ʧ�� !\n");
//
//
//
//
//
//
//							}
//							else
//							{
//
//						else
//						{
//
//
//						}
//
//
//
//						printf("	����ɹ� !\n"); flag = 1;
//
//
//
//							}
//						}
//						else
//						{
//
//							printf("	���鲻�ڿ� !\n"); flag = 1;
//
//
//
//						}
//					}
//					else
//					{
//
//						printf("	���鲻���� !\n"); flag = 1;
//
//
//
//						��!\n");
//
//							flag = 1;
//						printf("	���ѽ��飬�����ٽ裬�뻹����ٽ裬лл��
//
//					}
//				}
//
//
//
//			}
//			if (flag == 0)
//				printf("	�˺Ż��������� !\n");
//		}
//
//	}
//	����������޸ģ�
//		void xmima(struct student s[], int i)
//	{
//		int m, flag = 0;
//		char mnum[20], mima[20], a[20]; printf("	�������ʺ� :");
//		scanf("%s", mnum);
//		printf("	���������� :");
//		scanf("%s", mima); for (m = 0; m < i; m++)
//		{
//			if (strcmp(s[m].mnum, mnum) == 0 && strcmp(s[m].mima, mima) == 0) {
//				printf("	������������ :");
//				scanf("%s", a);
//
//				strcpy(s[m].mima, a);
//				xwj(s, i);//	���޸ĺ������д���ļ�
//
//
//
//
//				flag = 1;
//			}
//		}
//		if (flag == 0)
//			printf("	�˺Ż�������� !\n");
//	}
//	������Ϣ�Ĳ�ѯ��
//		void oneself(struct student s[], int i)
//	{
//		int m, f = 0;
//		char mnum[20], mima[20]; printf("	�������ʺ� :");
//		scanf("%s", mnum);
//		printf("	���������� :");
//		scanf("%s", mima); for (m = 0; m < i; m++)
//		{
//			if (strcmp(s[m].mnum, mnum) == 0 && strcmp(s[m].mima, mima) == 0)
//			{
//				f = 1;
//				printf("	���ĸ����������� :\n");
//				printf("	����\t	�ʺ�\t	����\t	������\t	�����\t	�绰\t	�༶\n"); printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\n", s[m].name, s[m].mnum, s[m].mi
//					ma, s[m].book, s[m].num, s[m].tel, s[m].pclass);
//
//			}
//		}
//		if (f == 0)
//			printf("	����������˺Ŵ�����˶Ժ���������	!\n");
//	}
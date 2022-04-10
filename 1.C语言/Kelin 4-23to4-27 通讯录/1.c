//#include<stdio.h> #include<stdlib.h> #include<string.h>
//void welcome();//	欢迎用户使用
//int denglu1(struct student s[], int i);//	学生登陆
//int denglu2();//	管理员登陆
//struct book* creatbook();//	创建链表，将文件中的图书信息写入链表
//int inputchoice();//	选择菜单
//int inputchoice1();//	学生选择菜单
//int inputchoice2();//	管理员选择菜单
//void pmenu(struct book* head);//	学生主功能选择菜单
//void menu2(struct book* head);//	管理员主功能选择菜单
//
//struct book* addbook(struct book* head);//	添加图书信息
//int chashu(struct book* head, char m[20]);//		查找分类号是否存在  struct book *insert1(struct book * head,struct book *p);//	增加接点void printbook(struct book * head);//	图书查找
//int putchoice();//	选择查找内容
//void chaname1(struct book* head);//		按书名查找void chaprice(struct book * head);//		按价格查找void chacnum(struct book * head);//	按分类号查找
//void chazuozhe(struct book* head);//	按作者名查询图书信息
//void chatime(struct book* head);//			按出版时间查找void chapress(struct book * head);//				按出版社查找void sortbook(struct book * head);//				排 序 选 择 void shuming(struct book * head);//			按图书名排 void ptime(struct book * head);//	按出版时间排序void price1(struct book * head);//		按图书价格排
//void fenleihao(struct book* head);//	按图书编号排序
//void zuo1(struct book* head);//	按作者名排序
//void pre1(struct book* head);//	按出版社排序
//struct book* shanchubook(struct book* head);//	删除图书信息
//void fprint(struct book* head);//	将新链表写入文件中
//void xiugai(struct book* head);//	修改图书信息
//void printbook1(struct book* head);//	浏览全部图书信息
//int chacun(struct book* head, char m[20]);//	查找库存量是否为	0 int jige();//	求出文件中客户的个数
//int xcz(struct book* head, char cnum[20]);//	把库内图书的库存量减一
//int xcz1(struct book* head, char cnum[20]);//	把库内图书的库存量加一void backbook(struct student s[],int i,struct book * head);//	还书函数void borrowbook(struct student s[],int i,struct book * head);//		借书函数
//void xmima(struct student s[], int i);//	修改密码
//void xwj(struct student s[], int i);//	将修改后的数组写入文件
//void oneself(struct student s[], int i);//	查看个人信息
//int jie(char cnum[20], int i, struct student s[], char mnum[20]);//	查询是否借书
//int huan(int i, struct student s[], char mnum[20]);//	借书查询是否借书图书信息结构体：
//struct book {
//	char bookname[20];//	书名
//	char ename[20];//	作者
//	char cnum[20];//	图书分类号即图书编号，区别其余图书唯一特征
//	char pubpress[20];//		出版社char pubtime[20];//	出版时间int price;//	价格
//	int zc;//	现库存
//
//	int xc;//	总库存
//	struct book* next;//	用链表建立图书信息
//};
//int denglu2()//	管理员登陆系统
//{
//	FILE* fp; struct xinxi {
//		char mnum[20];//	管理员登陆账号
//		char mima[20];//	管理员登录密码
//	}temp;
//	char mnum[20], mima[20]; int m, n, i;
//	for (i = 0; i < 3; i++)
//	{
//		printf("	请输入帐号 :");
//		scanf("%s", mnum);
//		printf("	请输入密码 :");
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
//int inputchoice2()//	管理员功能选择模块，管理员的所有功能
//{
//	int mychoice;
//	printf("1.	图书查询 \n2. 图书排序 \n3. 浏览全部图书 \n4. 添加图书 \n5. 删除图书\n6. 修改图书 \n0. 退出\n");
//	printf("\ninput your choice:"); scanf("%d", &mychoice); return mychoice;
//}
//3、struct book * creatbook() {
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
//struct book* addbook(struct book* head)//	添加图书信息
//{
//	FILE* fp; struct book* p;
//	int size = sizeof(struct book);
//	char bookname[20];//	书名char ename[20];//		作者char cnum[20];//	分类号
//
//	char pubpress[20];//	出版社
//	char pubtime[20];//	出版时间
//	int price, zc, xc;//	价格，总库存，现库存
//	int n, i;
//	printf("	如果您已经添加完毕，请将分类号数输入为	0， 谢 谢 合 作 :\n"); printf("1.	少量添加， 所添加内容没有存在文件中		\n2. 批量添加， 内容在文
//		件中存放 \n");
//		printf("	请输入编号 :");
//	scanf("%d", &i); switch (i) {
//	case 1:
//		printf("	请输入图书分类号 :"); scanf("%s", cnum);
//		n = chashu(head, cnum); if (n == 1)
//		{
//			printf("	您输入的分类号已存在	, 请重新输入 !\n"); return head;
//		}
//		while (strcmp(cnum, "0") != 0)
//		{
//			n = chashu(head, cnum); if (n == 1)
//			{
//				printf("	图书的分类号已存在 , 请重新输入！ "); return head;
//			}
//			p = (struct book*)malloc(size);
//
//			strcpy(p->cnum, cnum); printf("	请输入图书名 :");
//			scanf("%s", bookname);
//			strcpy(p->bookname, bookname); printf("	请输入作者名 :");
//			scanf("%s", ename); strcpy(p->ename, ename);
//			printf("	请输入出版社 :"); scanf("%s", pubpress);
//			strcpy(p->pubpress, pubpress); printf("	请输入出版时间 :");
//			scanf("%s", pubtime);
//			strcpy(p->pubtime, pubtime); printf("	请输入价格 :");
//			scanf("%d", &price);
//
//			p->price = price;
//			printf("	请输入总库存量 :");
//			scanf("%d", &zc); p->zc = zc;
//			printf("	请输入现库存量 :");
//			scanf("%d", &xc); p->xc = xc;
//			head = insert1(head, p, cnum); printf("	请输入图书分类号 :");
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
//				printf("	图书的分类号已存在 , 请重新输入！ "); return head;
//			}
//			fscanf(fp, "%s%s%d%d%d", pubpress, pubtime, &price, &zc, &xc); strcpy(p->pubpress, pubpress);
//			strcpy(p->pubtime, pubtime); p->price = price;
//			p->zc = zc;
//			p->xc = xc; head = insert1(head, p, cnum);
//		}
//	break; default:
//		printf("	输入错误 !\n");
//
//		break;
//	}
//	return head;
//}
//int chashu(struct book* head, char m[20])//	查找图书是否存在
//{
//	int flag = 0;
//	struct book* p = NULL; if (head == NULL)
//		return -1;//	可添加该图书
//	else
//		p = head;
//	while (p != NULL)
//	{
//		if (strcmp(p->cnum, m) == 0) flag = 1;
//		p = p->next;
//	}
//	if (flag == 1)
//		return 1;//	不可添加该图书
//
//	else
//
//}
//
//
//return -1;
//
//struct	book* insert1(struct	book* head, struct	book* ptr, char	cnum[20])//
//	增加接点
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
//int putchoice()//	选择查找内容
//{
//	int mychoice;
//	printf("\n\t\t\t1.		按书名查找 \n\t\t\t2.	按价格查找 \n\t\t\t3.	按分类号查找 \n\t\t\t4.	按作者查找 \n\t\t\t5.	按时间查找 \n\t\t\t6.	按出版社查找\n\t\t\t0.退出\n\n");
//		printf("	请输入查询编号 :"); scanf("%d", &mychoice); return mychoice;
//}
//void chaname1(struct book* head)//	按书名查找
//{
//
//	struct book* p; char shuname[20]; int flag = 0;
//	p = head;
//	printf("	请输入要查找的书名 :"); scanf("%s", shuname);
//	printf("\n");
//	printf("	查找结果如下 \n");
//	printf("	图书名\t	作者\t	分类号\t	出版社\t	出版时间 \t	价格\t	总库存\t
//		现库存\n");;
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
//		printf("	未找到你要找的书，请核实后再输	!\n");
//}
//void sortbook(struct book* head)//	排序选择
//{
//	int i;
//	printf("\n\t\t\t1-	按图书名排序	\n\t\t\t2-	按出版时间排序	\n\t\t\t3-	按图书 价格 排序 \n\t\t\t4 - 按图 书分 类号 排序 \n\t\t\t5 - 按作 者名排序	\n\t\t\t6 - 按出版社排序 \n\t\t\t0 - 取消排序操作 \n\n"); printf("		请输入您选择的选择 :");
//		scanf("%d", &i); switch (i) {
//		case 0:
//		break; case 1:
//			shuming(head); //	按图书名排序
//		break; case 2:
//			ptime(head); //	按出版时间排序
//		break; case 3:
//			price1(head); //	按出版价格排序
//		break; case 4:
//			fenleihao(head); //	按图书分类号排序
//		break; case 5:
//			zuo1(head); //	按图书作者排序
//		break; case 6:
//			pre1(head); //	按出版社排序
//		default:
//			printf("	您的输入有误 !\n"); break;
//	}
//}
//其中，只给出按价格排序，其余省去。
//void price1(struct book* head)//	按图书价格排序
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
//	printf("	排序成功 !\n");
//	printf("	是否显示排序结果 ?(y/n)\n"); scanf("%s", &ch);
//	switch (ch) {
//	case 'n':
//	break; case 'y':
//		printf("	图书名\t	作者\t	分类号\t	出版社\t	出版时间 \t	价格\t	总库存\t	现库存\n");
//		for (i = 0; i < n; i++) {
//			printf("%s\t%s\t%s\t%s\t%s\t\t%d\t%d\t%d\n", a[i]->bookname, a[i]->
//				ename, a[i]->cnum, a[i]->pubpress, a[i]->pubtime, a[i]->price, a[i].zc.a[i
//				].xc);
//		}
//	break; default:
//		printf("	您的输入有误 !\n");
//		break;
//	}
//}
//删除信息模块：
//struct book* shanchubook(struct book* head)//	删除图书信息
//{
//	char num[20];
//	struct book* ptr1, * ptr2, * p;
//
//	printf("	请输入图书分类号 :"); scanf("%s", num);
//
//	p = head; while (p != NULL) {
//		if (strcmp(p->cnum, num) == 0) break;
//		p = p->next;
//	} if (p == NULL) {
//		printf("	没有找到该号的图书 !\n");
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
//修改图书信息模块：
//
//void xiugai(struct book* head)//	修改图书信息
//{
//	int i;
//	char cnum[20]; struct book* p;
//	printf("	请输入要修改的图书分类号	:");
//	scanf("%s", cnum); p = head; while (p != NULL) {
//		if (strcmp(p->cnum, cnum) == 0) break;
//		p = p->next;
//	} if (p == NULL) {
//		printf("	没有找到该号的图书 !\n");
//	}
//	else {
//		printf("1-	分类号 \n2-	图书名 \n3- 作者名 \n4- 出版社 \n5- 出版时间		\n6 - 价格\7 - 修改全部 \n0 - 放弃修改 \n"); case 1:
//			printf("	请输入新分类号 :");
//		scanf("%s", p->cnum); fprint(head);
//		printf("	修改成功 !\n");
//		break;
//	}
//	修改图书信息只给出一部分，无论在添加，删除，还是在修改后，都需要将新链表写入文件保存起来，因此，就要调用下面的函数：
//		void fprint(struct book* head)//	将新链表写入文件中
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
//	而浏览图书信息时就需要浏览函数：
//		void printbook1(struct book* head)//	浏览全部图书信息
//	{
//
//		struct book* p; if (head == NULL) {
//			printf(""); return;
//		}
//		printf("	全部图书信息如下 \n");
//		printf("	书名\t	作者\t	分类号\t	出版社 \t	出版时间 \t	价格\t	总库存 \t
//			现库存\n");
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
//					printf("	图书馆管理系统出错， 现在无法正常操作， 给您带来的麻烦，我们深表歉意 !\n");
//					break;
//				}
//				else
//					printbook(head);//	图书查询
//			break; case 2:
//				if (head == NULL) {
//					printf("	图书馆管理系统出错， 现在无法正常操作， 给您带来的麻烦，我们深表歉意 !\n");
//					break;
//				}
//				else
//					sortbook(head);//	图书排序
//			break; case 3:
//				if (head == NULL) {
//					printf("	图书馆管理系统出错，现在无法正常操作，给您带来的麻烦，我们深表歉意 !\n");
//					break;
//				}
//
//				else
//					printbook1(head);//	浏览全部图书信息
//			break; case 4:
//				borrowbook(s, m, head);//	借书
//			break; case 5:
//				backbook(s, m, head);//	还书
//			break; case 6:
//				xmima(s, m);//	修改密码
//			break; case 7:
//				oneself(s, m);//	查看个人资料
//				break;
//
//			default:
//				printf("	输入错误！ \n"); break;
//			}
//		}
//	}
//	借书与还书模块：
//		void borrowbook(struct student s[], int i, struct book* head)
//	{
//		int m, n, t, p, flag = 0, p1;
//		char mnum[20], mima[20], cnum[20], bookname[20]; if (i > 100)
//			printf("	借书人数已满，现不能借书	!\n");
//
//		else
//		{
//
//
//
//			printf("	请输入帐号 :");
//			scanf("%s", mnum);
//			printf("	请输入密码 :");
//			scanf("%s", mima); for (t = 0; t < i; t++)
//			{
//				if (strcmp(s[t].mnum, mnum) == 0 && strcmp(s[t].mima, mima) == 0)
//				{
//
//					printf("	请输入图书的分类号 :"); scanf("%s", cnum); p1 = huan(i, s, mnum);
//					if (p1 == 1)
//					{
//
//						m = chashu(head, cnum);//	验证所借图书是否存在
//						if (m == 1)
//						{
//							n = chacun(head, cnum);//	验证所借图书是否在库
//							if (n == 1)
//							{
//								strcpy(s[t].num, cnum);
//								printf("	请输入书名 :"); scanf("%s", bookname); strcpy(s[t].book, bookname); xwj(s, i);
//								p = xcz(head, cnum);//	把库存量减 1
//								if (p == -1)
//									printf("	借书失败 !\n");
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
//						printf("	借书成功 !\n"); flag = 1;
//
//
//
//							}
//						}
//						else
//						{
//
//							printf("	该书不在库 !\n"); flag = 1;
//
//
//
//						}
//					}
//					else
//					{
//
//						printf("	该书不存在 !\n"); flag = 1;
//
//
//
//						作!\n");
//
//							flag = 1;
//						printf("	您已借书，不能再借，请还书后再借，谢谢合
//
//					}
//				}
//
//
//
//			}
//			if (flag == 0)
//				printf("	账号或密码有误 !\n");
//		}
//
//	}
//	个人密码的修改：
//		void xmima(struct student s[], int i)
//	{
//		int m, flag = 0;
//		char mnum[20], mima[20], a[20]; printf("	请输入帐号 :");
//		scanf("%s", mnum);
//		printf("	请输入密码 :");
//		scanf("%s", mima); for (m = 0; m < i; m++)
//		{
//			if (strcmp(s[m].mnum, mnum) == 0 && strcmp(s[m].mima, mima) == 0) {
//				printf("	请输入新密码 :");
//				scanf("%s", a);
//
//				strcpy(s[m].mima, a);
//				xwj(s, i);//	将修改后的数组写入文件
//
//
//
//
//				flag = 1;
//			}
//		}
//		if (flag == 0)
//			printf("	账号或密码错误 !\n");
//	}
//	个人信息的查询：
//		void oneself(struct student s[], int i)
//	{
//		int m, f = 0;
//		char mnum[20], mima[20]; printf("	请输入帐号 :");
//		scanf("%s", mnum);
//		printf("	请输入密码 :");
//		scanf("%s", mima); for (m = 0; m < i; m++)
//		{
//			if (strcmp(s[m].mnum, mnum) == 0 && strcmp(s[m].mima, mima) == 0)
//			{
//				f = 1;
//				printf("	您的个人资料如下 :\n");
//				printf("	姓名\t	帐号\t	密码\t	借书名\t	分类号\t	电话\t	班级\n"); printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\n", s[m].name, s[m].mnum, s[m].mi
//					ma, s[m].book, s[m].num, s[m].tel, s[m].pclass);
//
//			}
//		}
//		if (f == 0)
//			printf("	您的密码或账号错误，请核对后重新输入	!\n");
//	}
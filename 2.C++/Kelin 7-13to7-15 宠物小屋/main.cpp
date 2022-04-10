#include "People.h"
#include "House.h"
#include "Def_config.h"
#include "Dog.h"
#include "Cat.h"
#include "Snake.h"

#include <sstream>
#include <iostream>
using namespace std;

#define DEF_BUY_ANIMAL_PART(ANI_CLASS,ANI_KIND)\
		pAni = new ANI_CLASS;\
		GetAnimalAttr(Animalname, color, age);\
		pAni->InitAnimal(Animalname, color, age);\
		pPeople->BuyAnimal(pAni, ANI_KIND);

void GetAnimalAttr(string& Animalname, string& color, int &age) {
	cout << "请输入动物信息：1.名字 2.颜色 3.年龄（例：小娃 白 5）" << endl;
	string AnimalAttr;
	getline(cin, AnimalAttr);

	stringstream ss(AnimalAttr);
	string s;
	int i = 0;
	while (ss >> s)
	{
		switch (i)
		{
		case 0: {
			Animalname = s;
		}
			  break;
		case 1: {
			color = s;
		}
			  break;
		case 2: {
			age = atoi(s.c_str());//字符串转int类型
		}
			  break;
		}
		i++;
	}//以空格为标记点 遍历三次 依次把名字 颜色 年龄获取到
}

void showHelp() {

	cout << CMD_BUY_ANIMAL_DOG << ":买狗" << endl;
	cout << CMD_BUY_ANIMAL_CAT << ":买猫" << endl;
	cout << CMD_BUY_ANIMAL_SNAKE << ":买蛇" << endl;
	cout << CMD_PROGRAM_QUIT << ":退出程序" << endl;
	cout << CMD_LOOK_ANIMAL << ":查看动物信息" << endl;
	cout << CMD_KILL_ANIMAL << ":杀死动物" << endl;
	cout << CMD_DESTORY_CAGE << ":销毁笼子及笼内动物" << endl;
	cout << CMD_PLAYWITH_ANIMAL << ":和动物玩耍" << endl;
	cout << CMD_SHOW_PEOPLE << ":展示人物信息" << endl;
	cout << CMD_HELP << ":帮助文档" << endl;

}

int main(){
	
	CPeople* pPeople = new CPeople;
	CHouse* pHouse = new CHouse;

	string name = "小红";
	pPeople->InitPeople(name, PEOPLE_MONEY);

	string cmd;
	showHelp();

	while (1)
	{
		//cin >> cmd;	// cmd只会读取到buy，空格后的内容没有读取到，可以尝试用getline解决该问题
		//getline(cin, cmd);	//第三个参数不给的话默认'\n'结束

							//问题：第二次循环到getline的时候，由于缓冲区有第一次cin没获取的\n，所以第二次getline时程序无法cin，直接获取缓冲区的\n，因此后面不会进入任何一个if，直接空循环一次再回到getline（此时为第三次，缓冲区为空，cin……，也就是说该代码在循环偶数次情况下均无法正常cin）

							//解决方式：利用cin.sync();//清除缓冲区
		cin.sync();
		getline(cin, cmd);

		//———————————————————————————— 退出————————————————————————————

		if (CMD_PROGRAM_QUIT == cmd)
		{
			break;
		}
		//——————————————————————————————————————————————————————————————

		//———————————————————————————— 帮助—————————————————————————————

		if (CMD_HELP == cmd)
		{
			showHelp();
		}
		//——————————————————————————————————————————————————————————————

		//—————————————————————人机交互 买动物 安置动物—————————————————————
		{
			CAnimal* pAni = NULL;
			string Animalname;
			string color;
			int age;

			if (CMD_BUY_ANIMAL_CAT == cmd)
			{
				cout << "买猫咪~" << endl;
				DEF_BUY_ANIMAL_PART(CCat, ANIMAL_KIDN_CAT);
			}
			else if (CMD_BUY_ANIMAL_DOG == cmd)
			{
				cout << "买狗狗~" << endl;
				DEF_BUY_ANIMAL_PART(CDog, ANIMAL_KIDN_DOG);
			}
			else if (CMD_BUY_ANIMAL_SNAKE == cmd)
			{
				cout << "买小蛇~" << endl;
				DEF_BUY_ANIMAL_PART(CSnake, ANIMAL_KIDN_SNAKE);
			}

			//安置动物

			if (pAni)//判断有没有动物，是否购买成功了
			{
				//建笼子
				CCage* pCage = pPeople->CreateCage();
				//装笼子
				pPeople->PushAnimal(pCage, pAni);
				//笼子放到房子里
				pPeople->PushCage(pHouse, pCage);
			}
		}
		//——————————————————————————————————————————————————————————————

		//——————————————————————————查看动物——————————————————————————————
		if (CMD_LOOK_ANIMAL == cmd) 
		{
			int id = 0;
			cout << "请输入查看笼子的ID（id==0：代表查看所有动物）" << endl;
			cin >> id;
			pPeople->LookAnimal(pHouse, id);
		}
		//——————————————————————————————————————————————————————————————

		int id = 0;

		//——————————————————————————杀死动物——————————————————————————————
		if (CMD_KILL_ANIMAL == cmd) 
		{
			cout << "请输入需要杀死动物的所属笼子ID" << endl;
			cin >> id;
			pPeople->KillAnimal(pHouse, id);
		}
		//——————————————————————————————————————————————————————————————

		//——————————————————————————销毁笼子————————————————————————————sshow
		if (CMD_DESTORY_CAGE == cmd)
		{
			cout << "请输入需要销毁的笼子ID" << endl;
			cin >> id;
			pPeople->DestoryCage(pHouse, id);
		}
		//——————————————————————————————————————————————————————————————

		//——————————————————————————和动物玩——————————————————————————————
		if (CMD_PLAYWITH_ANIMAL == cmd)
		{
			cout << "请输入想一起玩耍的动物所属笼子ID" << endl;
			cin >> id;
			pPeople->PlayWithAniamal(pHouse, id);
		}
		//——————————————————————————————————————————————————————————————

		//——————————————————————————人物信息——————————————————————————————
		if (CMD_SHOW_PEOPLE == cmd)
		{
			pPeople->ShowPeople();
		}
		//——————————————————————————————————————————————————————————————
	}

	//回收人、屋子的空间~(笼子和动物已经在屋子的析构里写了，所有不用再删啦)
	delete pPeople;
	pPeople = NULL;
	delete pHouse;
	pHouse = NULL;

	return 0;
}
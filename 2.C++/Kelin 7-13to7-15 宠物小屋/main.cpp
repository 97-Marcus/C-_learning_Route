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
	cout << "�����붯����Ϣ��1.���� 2.��ɫ 3.���䣨����С�� �� 5��" << endl;
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
			age = atoi(s.c_str());//�ַ���תint����
		}
			  break;
		}
		i++;
	}//�Կո�Ϊ��ǵ� �������� ���ΰ����� ��ɫ �����ȡ��
}

void showHelp() {

	cout << CMD_BUY_ANIMAL_DOG << ":��" << endl;
	cout << CMD_BUY_ANIMAL_CAT << ":��è" << endl;
	cout << CMD_BUY_ANIMAL_SNAKE << ":����" << endl;
	cout << CMD_PROGRAM_QUIT << ":�˳�����" << endl;
	cout << CMD_LOOK_ANIMAL << ":�鿴������Ϣ" << endl;
	cout << CMD_KILL_ANIMAL << ":ɱ������" << endl;
	cout << CMD_DESTORY_CAGE << ":�������Ӽ����ڶ���" << endl;
	cout << CMD_PLAYWITH_ANIMAL << ":�Ͷ�����ˣ" << endl;
	cout << CMD_SHOW_PEOPLE << ":չʾ������Ϣ" << endl;
	cout << CMD_HELP << ":�����ĵ�" << endl;

}

int main(){
	
	CPeople* pPeople = new CPeople;
	CHouse* pHouse = new CHouse;

	string name = "С��";
	pPeople->InitPeople(name, PEOPLE_MONEY);

	string cmd;
	showHelp();

	while (1)
	{
		//cin >> cmd;	// cmdֻ���ȡ��buy���ո�������û�ж�ȡ�������Գ�����getline���������
		//getline(cin, cmd);	//���������������Ļ�Ĭ��'\n'����

							//���⣺�ڶ���ѭ����getline��ʱ�����ڻ������е�һ��cinû��ȡ��\n�����Եڶ���getlineʱ�����޷�cin��ֱ�ӻ�ȡ��������\n����˺��治������κ�һ��if��ֱ�ӿ�ѭ��һ���ٻص�getline����ʱΪ�����Σ�������Ϊ�գ�cin������Ҳ����˵�ô�����ѭ��ż��������¾��޷�����cin��

							//�����ʽ������cin.sync();//���������
		cin.sync();
		getline(cin, cmd);

		//�������������������������������������������������������� �˳���������������������������������������������������������

		if (CMD_PROGRAM_QUIT == cmd)
		{
			break;
		}
		//����������������������������������������������������������������������������������������������������������������������������

		//�������������������������������������������������������� ��������������������������������������������������������������

		if (CMD_HELP == cmd)
		{
			showHelp();
		}
		//����������������������������������������������������������������������������������������������������������������������������

		//�������������������������������������������˻����� ���� ���ö������������������������������������������
		{
			CAnimal* pAni = NULL;
			string Animalname;
			string color;
			int age;

			if (CMD_BUY_ANIMAL_CAT == cmd)
			{
				cout << "��è��~" << endl;
				DEF_BUY_ANIMAL_PART(CCat, ANIMAL_KIDN_CAT);
			}
			else if (CMD_BUY_ANIMAL_DOG == cmd)
			{
				cout << "�򹷹�~" << endl;
				DEF_BUY_ANIMAL_PART(CDog, ANIMAL_KIDN_DOG);
			}
			else if (CMD_BUY_ANIMAL_SNAKE == cmd)
			{
				cout << "��С��~" << endl;
				DEF_BUY_ANIMAL_PART(CSnake, ANIMAL_KIDN_SNAKE);
			}

			//���ö���

			if (pAni)//�ж���û�ж���Ƿ���ɹ���
			{
				//������
				CCage* pCage = pPeople->CreateCage();
				//װ����
				pPeople->PushAnimal(pCage, pAni);
				//���ӷŵ�������
				pPeople->PushCage(pHouse, pCage);
			}
		}
		//����������������������������������������������������������������������������������������������������������������������������

		//�����������������������������������������������������鿴�������������������������������������������������������������
		if (CMD_LOOK_ANIMAL == cmd) 
		{
			int id = 0;
			cout << "������鿴���ӵ�ID��id==0������鿴���ж��" << endl;
			cin >> id;
			pPeople->LookAnimal(pHouse, id);
		}
		//����������������������������������������������������������������������������������������������������������������������������

		int id = 0;

		//����������������������������������������������������ɱ���������������������������������������������������������������
		if (CMD_KILL_ANIMAL == cmd) 
		{
			cout << "��������Ҫɱ���������������ID" << endl;
			cin >> id;
			pPeople->KillAnimal(pHouse, id);
		}
		//����������������������������������������������������������������������������������������������������������������������������

		//�����������������������������������������������������������ӡ�������������������������������������������������������sshow
		if (CMD_DESTORY_CAGE == cmd)
		{
			cout << "��������Ҫ���ٵ�����ID" << endl;
			cin >> id;
			pPeople->DestoryCage(pHouse, id);
		}
		//����������������������������������������������������������������������������������������������������������������������������

		//�����������������������������������������������������Ͷ����桪����������������������������������������������������������
		if (CMD_PLAYWITH_ANIMAL == cmd)
		{
			cout << "��������һ����ˣ�Ķ�����������ID" << endl;
			cin >> id;
			pPeople->PlayWithAniamal(pHouse, id);
		}
		//����������������������������������������������������������������������������������������������������������������������������

		//����������������������������������������������������������Ϣ������������������������������������������������������������
		if (CMD_SHOW_PEOPLE == cmd)
		{
			pPeople->ShowPeople();
		}
		//����������������������������������������������������������������������������������������������������������������������������
	}

	//�����ˡ����ӵĿռ�~(���ӺͶ����Ѿ������ӵ�������д�ˣ����в�����ɾ��)
	delete pPeople;
	pPeople = NULL;
	delete pHouse;
	pHouse = NULL;

	return 0;
}
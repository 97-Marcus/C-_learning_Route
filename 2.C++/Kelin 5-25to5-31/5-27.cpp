//#include <iostream>
//using namespace std;


/*
//��֮��ĺ����ϵ

class CFriend {
public:
	void play() {
		cout << "�Ϻţ���������" << endl;
	}

};

class CComputer {
public:
	void Complie() {
		cout << "���ڱ������ѽ~" << endl;
	}

};

class CHand {
public:
	void Move() {
		cout << "�� �ƶ���" << endl;
	}

};

class CPeople {
public:
	CHand m_hand;
	CFriend* m_pFriend;

	CPeople() {
		m_pFriend = NULL;
	}
	~CPeople() {
		
	}

	void Clap() {
		m_hand.Move();
		cout << "������ 123 123 12333333" << endl;
	}
	void Code(CComputer* computer) {
		if (computer)
		{
			m_hand.Move();
			cout << "д������ ����ž��" << endl;
			computer->Complie();
			cout << "���ɿ�ִ�г���" << endl;
		}
	}

	void SetFriend(CFriend *pFriend) {
		m_pFriend = pFriend;
	
	}

	void PlayGame() {
		if (m_pFriend)
		{
			m_pFriend->play();
			cout << "��ɱ��" << endl;
		}
		else {
			cout << "���Ѳ������ˣ��¶��Լ�����" << endl;
		}
	}

};

class CFamily {
public:
	CPeople* m_pPeople[10];
	CFamily() {
		for (int i = 0; i < 10; i++) 
		{
			m_pPeople[i] = NULL;
		}
	}
	~CFamily() {
		for (int i = 0; i < 10; i++)
		{
			if (m_pPeople[i])
			{
				delete m_pPeople[i];
				m_pPeople[i] = NULL;
			}
		}
	}

	void PushPeople(CPeople* pPeople) {
		for (int i = 0; i < 10; i++)
		{
			if (m_pPeople[i] == NULL) 
			{
				m_pPeople[i] = pPeople;
				return;	//	��дreturn�Ļ���һֱ��ӵ���ʮ��λ��Ϊֹ
			}
		}
	}

	void AllPeopleCode(CComputer* computer) {
		for (int i = 0; i < 10; i++) {
			if (m_pPeople[i])
			{
				m_pPeople[i]->Code(computer);
			}
		}
	
	}
};


int main() {
	
	//���ϡ�����������������������������������������������������������������������������������������
	CPeople people1;
	people1.Clap();
	//������������������������������������������������������������������������������������������������


	//����������������������������������������������������������������������������������������������
	CComputer* pComp = new CComputer;
	people1.Code(pComp);
	delete pComp;
	pComp = NULL;
	people1.Code(pComp);
	//������������������������������������������������������������������������������������������������
	

	//����������������������������������������������������������������������������������������������
	CFriend* pFriend = new CFriend;
	people1.SetFriend(pFriend);
	//people1.m_pFriend = pFriend;
	//��ͨ�����������ѣ�ֱ��ͨ����Ա������ֵ������Ҳ�ǿ��е�
	people1.PlayGame();
	
	delete pFriend;
	pFriend = NULL;
	people1.m_pFriend = NULL;//����û��

	people1.PlayGame();
	//������������������������������������������������������������������������������������������������


	//�ۺϡ�����������������������������������������������������������������������������������������
	CFamily Workfamily;
	CPeople* pPeople1 = new CPeople;
	CPeople* pPeople2 = new CPeople;

	Workfamily.PushPeople(pPeople1);
	Workfamily.PushPeople(pPeople2);
	
	CComputer* pComp1 = new CComputer;
	Workfamily.AllPeopleCode(pComp1);

	//������������������������������������������������������������������������������������������������


	system("pause");
	return 0;
}

*/


/*

//�̳�
//�������ʹ�ø����Ա��������Ա���Ժͳ�Ա������Ҳ���Ǳ����ͺ�����

class CFather	//���ࣨ���ࣩ
{
public:
	int m_father;
	long m_money;

	CFather() {
		m_father = 10;
		m_money = 30;
	}

	void ShowFather() {
		cout << "ShowFather" << endl;
	}

	void Show() {
		cout << "CFather::show" << endl;
	}

	void Play() {
		cout << "Play" << endl;
	}
protected:
private:
};

class CSon :public CFather	//���ࣨ�����ࣩ����ӣ��̳з�ʽ ��������
{
public:
	int m_son;
	long m_money;

	CSon() {
		m_son = 20;
		m_money = 40;
	}

	void ShowSon() {
		cout << "ShowSon" << endl;
	}

	void Show() {
		cout << "CSon::show" << endl;
	}
protected:
private:
};

int main() {

	CSon son;
	cout << son.m_father << endl;
	cout << son.m_son << endl;
	son.ShowFather();
	son.ShowSon();

	cout << son.m_money << endl;// �õ��������m_money
								// �൱��cout << son.Cson::m_money << endl;
	cout << son.CFather::m_money << endl;
								//	����͸����������������Ա����ôĬ��ʹ�õ�ǰ��ĳ�Ա�������Ҫʹ����һ�������Ҫдָ���������������򣩺�::,��������Ҳһ��

	son.Show();					//�൱��son.CSon::Show();
	son.CFather::Show();

	son.CSon::Play();
	son.CFather::Play();
	son.Play();
	//Playֻ�ڸ���CFather�д��ڣ�Cson������û�У���ʱǰ������������дCson����CFather���߲�д���ǿ��Ա�����ģ����ᱨ��


	cout << &son << endl;
	cout << &son.m_father << endl;
	cout << &son.CFather::m_money << endl;
	cout << &son.m_son << endl;
	cout << &son.CSon::m_money << endl;
	//�������ַ�����Կ����ڴ�ռ�����˳��
	//��������Ķ��󣬸����Ա���ڴ�ռ����λ
	//����λ��ʼ�����Ǹ���ĳ�Ա�б�->����ĳ�Ա�б�Ҳ��������˳��

	system("pause");
	return 0;
}

*/
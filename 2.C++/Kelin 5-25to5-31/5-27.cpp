//#include <iostream>
//using namespace std;


/*
//类之间的横向关系

class CFriend {
public:
	void play() {
		cout << "上号，开黑啦！" << endl;
	}

};

class CComputer {
public:
	void Complie() {
		cout << "正在编译代码呀~" << endl;
	}

};

class CHand {
public:
	void Move() {
		cout << "手 移动啦" << endl;
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
		cout << "鼓掌拉 123 123 12333333" << endl;
	}
	void Code(CComputer* computer) {
		if (computer)
		{
			m_hand.Move();
			cout << "写代码啦 劈里啪啦" << endl;
			computer->Complie();
			cout << "生成可执行程序" << endl;
		}
	}

	void SetFriend(CFriend *pFriend) {
		m_pFriend = pFriend;
	
	}

	void PlayGame() {
		if (m_pFriend)
		{
			m_pFriend->play();
			cout << "五杀！" << endl;
		}
		else {
			cout << "朋友不理我了，孤儿自己开黑" << endl;
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
				return;	//	不写return的话会一直添加到第十个位置为止
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
	
	//复合—————————————————————————————————————————————
	CPeople people1;
	people1.Clap();
	//————————————————————————————————————————————————


	//依赖—————————————————————————————————————————————
	CComputer* pComp = new CComputer;
	people1.Code(pComp);
	delete pComp;
	pComp = NULL;
	people1.Code(pComp);
	//————————————————————————————————————————————————
	

	//关联—————————————————————————————————————————————
	CFriend* pFriend = new CFriend;
	people1.SetFriend(pFriend);
	//people1.m_pFriend = pFriend;
	//不通过函数交朋友，直接通过成员变量赋值交朋友也是可行的
	people1.PlayGame();
	
	delete pFriend;
	pFriend = NULL;
	people1.m_pFriend = NULL;//朋友没了

	people1.PlayGame();
	//————————————————————————————————————————————————


	//聚合—————————————————————————————————————————————
	CFamily Workfamily;
	CPeople* pPeople1 = new CPeople;
	CPeople* pPeople2 = new CPeople;

	Workfamily.PushPeople(pPeople1);
	Workfamily.PushPeople(pPeople2);
	
	CComputer* pComp1 = new CComputer;
	Workfamily.AllPeopleCode(pComp1);

	//————————————————————————————————————————————————


	system("pause");
	return 0;
}

*/


/*

//继承
//子类可以使用父类成员（包括成员属性和成员方法，也就是变量和函数）

class CFather	//父类（基类）
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

class CSon :public CFather	//子类（派生类）后须加：继承方式 父类类名
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

	cout << son.m_money << endl;// 用的是子类的m_money
								// 相当于cout << son.Cson::m_money << endl;
	cout << son.CFather::m_money << endl;
								//	子类和父类中如果有重名成员，那么默认使用当前类的成员，如果需要使用另一个类的需要写指定的类名（作用域）和::,重名函数也一样

	son.Show();					//相当于son.CSon::Show();
	son.CFather::Show();

	son.CSon::Play();
	son.CFather::Play();
	son.Play();
	//Play只在父类CFather中存在，Cson子类中没有，此时前面作用域无论写Cson或者CFather或者不写都是可以被允许的，不会报错


	cout << &son << endl;
	cout << &son.m_father << endl;
	cout << &son.CFather::m_money << endl;
	cout << &son.m_son << endl;
	cout << &son.CSon::m_money << endl;
	//输出各地址，可以看出内存空间分配的顺序
	//定义子类的对象，父类成员在内存空间的首位
	//从首位开始依次是父类的成员列表->子类的成员列表，也就是如上顺序

	system("pause");
	return 0;
}

*/
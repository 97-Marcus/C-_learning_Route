#include <iostream>
using namespace std;

//	���ģʽ

//	����ģʽ��
//	1.	��ǰ�� ����ֻ�� һ��ʵ��(����) 
//						----->���ⲻ�ܶ������ ֻ��ʹ�����ڶ����һ������
//	2.	�ܹ������������ʵ���������ǵ�����ȥ����ʵ����
//	3.	��ȫ�ֿ������ʵ��

////	����ʽ��Ҫ�õ���ʱ����ȥ����Ψһʵ����ʱ�任�ռ����������ʡ�ռ䵫����ʱ�䣩
//
//class CObject
//{
//public:
//	int m_a;
//private:	//˽�е� -----> ���ⲻ�ܶ������
//	//static int ObjCount;	//������	
//	static CObject* m_pObjec;
//private:
//	CObject() {
//		m_a = 10;
//	}
//	CObject(const CObject& obj) {
//		this->m_a = obj.m_a;
//	}
//	~CObject() {
//	
//	}	//PS���������ṩ��Ĭ�ϵ��ǹ��е�~
//public:
//	static CObject* GetInstance() 	
//		//����һ���ӿ� -----> �������ʹ�����ڵ�Ψһ����
//		//					(static ���Բ�ͨ��������е���)
//		//����CObject* -----> ָ�����ʽͨ����ַ����ʹ�� 
//		//���������CObject -----> ��Ϊ��ʱ�����п��ܶԳ������һ��Ӱ��
//	{	
//		//if (ObjCount >= 1) 
//		if (m_pObjec) 
//		{
//			//return NULL;
//			return m_pObjec;
//		}
//		//ObjCount++;
//		m_pObjec = new CObject;	
//				//���߳��������⣬�����̻߳�������⣬������������ǰ���һ��������������ȴ���ֻ��һ���߳��ܽ�36-40��
//		return m_pObjec;
//	}
//	static void Destory(CObject*& p) {
//		if (m_pObjec) {
//			delete m_pObjec;
//			m_pObjec = NULL;
//		}
//		p = NULL;
//	}
//};
//
////int CObject::ObjCount = 0;	//��̬��Ա�����ʼ��
//CObject* CObject::m_pObjec = NULL;
////������̬��Ա�����ö���Ϊ��ȥ������û�д�������������Կ��Խ����Ż���ע�͵�ObjCount����if�ж��е����ݽ����޸ģ���m_pObjec�Ƿ�Ϊ�ռ���
//
//int main() {
//
//	//CObject* pObject1 = CObject::GetInstance();
//	//CObject* pObject2 = CObject::GetInstance();	
//			//	�����pObject1��pObject2�ֱ���в�ͬ�ĵ�ַ
//			//	����1�����Զ�ε���GetInstance�Ի�ö�����󡭡�
//			//	�Ľ���������һ����������ͳ�Ƶ�ǰʵ���ж��ٸ�����	����12��27-31��
//
//			//	�Ľ��������pObject1���е�ַ��pObject2ΪNULL
//			//	����2��Υ������ȫ�ֿ������ʵ������pObject1��pObject2Ӧ�û�ȡ����ͬ��ַ�Ŷ�
//			//	�Ľ�����������ObjCount������0
//
//	CObject* pObject1 = CObject::GetInstance();
//	//	ObjCount = 0;
//	CObject* pObject2 = CObject::GetInstance();
//
//			//	��ʱpObject1��pObject2�ֱ���в�ͬ�ĵ�ַ��˵������������
//			//	���������ObjCount������ȫ�ֱ�������������˽�еľ�̬��Ա��������̬��Ա������������г�ʼ������ʱObjCount��Ŀǰ�����ھͲ���ʹ���ˡ�
//	
//			//	��������δ���������������㡰1.	��ǰ�� ����ֻ�� һ��ʵ��(����)�������㡰3.	��ȫ�ֿ������ʵ������Ҳ����˵����һ�Զ����ʽ��
//			//	41�е�if (ObjCount >= 1) { return NULL; }������־ʹ������⣬���ܷ��ؿա�һ�Զ����ʽ���Խ�����̬��Ա������ʵ�֡�
//
//	//CObject obj1 = *pObject1;	
//			//obj1�ĵ�ַ��pObject1/pObject2�ĵ�ַ��ͬ��˵�����ǿ��Դ����������
//			//�˴�ʵ��Ϊ����������ʼ��������õ��ǿ������캯��
//			//�������������������дΪ˽�еģ���ôobj1�������ڽ���ʱ�޷�������������þ��޷��������лᱨ������ʵ���ϣ���������Ҳ���Խ��������⣬�������ѿ�����������������ϣ�
//
//	//CObject* pobj3 = new CObject(*pObject1);	
//	//delete pobj3;	//��Ȼ78��û�б��� ����delete��������ʱ���ǻᱨ��
//			//�������ʹ��delete��78����Ȼ�����������У�pobj3����ĵ�ַ��ͬ��pObject1��Υ���˵���ģʽ�����������ǣ�����������Ҳ���ϵ�˽�еġ�
//
//	pObject1->m_a = 20;
//	cout << pObject2->m_a << endl;
//
//	//delete pObject1;
//			//����:��ʵ����������ʱ��������˽�У������޷�ɾ�������Ի���Ҫ�ṩһ��ɾ���ķ�����
//
//	//CObject::Destory();	
//	//cout << pObject2->m_a << endl;
//			//���Ա��ָ��ȷʵ�ÿ��ˣ���pObject1��pObject2û�б��ÿգ�ֻ��pObject1��pObject2�޷���ʹ������ĳ�Ա�ˣ�����Ĳ�����Ҫ�Ķ�ֵ������
//			//�����ʽ��Destory��������һ������
//
//	CObject::Destory(pObject1);	
//	CObject::Destory(pObject2);
//
//	if (pObject2)
//	{
//		cout << pObject2->m_a << endl;
//	}
//
//	system("pause");
//	return 0;
//}





////	����ʽ��	��������񣬳��򴴽�֮���Ͱ�Ψһʵ�������������ռ任ʱ���������
//
//class CObject
//{
//public:
//	int m_a;
//private:
//	static CObject* m_pObjec;
//private:
//	CObject() {
//		m_a = 10;
//	}
//	CObject(const CObject& obj) {
//		this->m_a = obj.m_a;
//	}
//	~CObject() {
//	
//	}
//public:
//	static CObject* GetInstance() {
//		return m_pObjec;
//	}
//};
//
//CObject* CObject::m_pObjec = new CObject;
//
//int main(){
//
//	CObject* p1 = CObject::GetInstance();
//	CObject* p2 = CObject::GetInstance();
//
//	p1->m_a = 30;
//	cout << p2->m_a << endl;
//
//	system("pause");
//	return 0;
//}



////	ģ�巽��ģʽ��
//
////	����������̣����裩�Ϳɱ��ʵ�֣�ϸ�ڣ��ֿ���
////	�����������̳��뵽�����γ�ģ�壬
////	�����ʵ�����ö�̬�����������ʵ�֡�
//
//class CPeople
//{
//public:
//	virtual void EatBehavior() = 0;
//
//	virtual void EatSytle() = 0;
//
//	void eat() {
//		cout << "1.ʢһ�뷹" << endl;
//		EatBehavior();
//		EatSytle();
//		cout << "4.�������" << endl;
//		cout << "5.�̶�����" << endl;
//		cout << "6.���극��" << endl;
//	}
//};
//
//class CChina:public CPeople
//{
//public:
//	void EatBehavior() {
//		cout << "2.��������" << endl;
//	}
//	void EatSytle() {
//		cout << "3.���Ӱ���" << endl;
//	}
//	//void eat() {
//	//	cout << "1.ʢһ�뷹" << endl;
//	//	EatBehavior();
//	//	EatSytle();
//	//	cout << "4.�������" << endl;
//	//	cout << "5.�̶�����" << endl;
//	//	cout << "6.���극��" << endl;
//	//}
//};
//
//class CAmerican :public CPeople
//{
//public:
//	void EatBehavior() {
//		cout << "2.�쿿��ȥ" << endl;
//	}
//	void EatSytle() {
//		cout << "3.�������" << endl;
//	}
//	//void eat() {
//	//	cout << "1.ʢһ�뷹" << endl;
//	//	EatBehavior();
//	//	EatSytle();
//	//	cout << "4.�������" << endl;
//	//	cout << "5.�̶�����" << endl;
//	//	cout << "6.���극��" << endl;
//	//}
//};
//
//class CIndian :public CPeople
//{
//public:
//	void EatBehavior() {
//		cout << "2.�쿿��ȥ" << endl;
//	}
//	void EatSytle() {
//		cout << "3.����ץ��" << endl;
//	}
//	//void eat() {
//	//	cout << "1.ʢһ�뷹" << endl;
//	//	EatBehavior();
//	//	EatSytle();
//	//	cout << "4.�������" << endl;
//	//	cout << "5.�̶�����" << endl;
//	//	cout << "6.���극��" << endl;
//	//}
//};
//
//int main() {
//
//	CPeople* pPeo1 = new CChina;
//	pPeo1->eat();
//
//	CPeople* pPeo2 = new CAmerican;
//	pPeo2->eat();
//
//	CPeople* pPeo3 = new CIndian;
//	pPeo3->eat();
//
//	system("pause");
//	return 0;
//}

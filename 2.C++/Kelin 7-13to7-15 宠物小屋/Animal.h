#pragma once
#include <string>
using namespace std;

class CAnimal
{
public:
	CAnimal(void);
	virtual ~CAnimal(void);
public:
	int m_nAge;
	string m_strName;
	string m_strColor;
public:
	virtual void PlayAnimal() = 0;	//纯虚函数，抽象类，不可以定义对象
	void InitAnimal(string& name, string& color, int age);
	void ShowAnimal();
};

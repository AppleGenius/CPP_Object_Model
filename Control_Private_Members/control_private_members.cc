//ʹ��trick��Base class��private���Խ��в��ݣ����õľ���virtual Tables
#include <iostream>

using namespace std;

class Base{
private:
	virtual void f()
	{
		cout << "Base:: f()" << endl;
	}
};

class Derive:public Base{

};

typedef void(*Fun)(void);

int main(int argc, const char **argv)
{
	Derive d;
	//d.f();��������±���������ֹ����Ϊ
	Fun pFun = (Fun)*((int*)*(int*)(&d)+0);
	pFun();

	return 0;
}
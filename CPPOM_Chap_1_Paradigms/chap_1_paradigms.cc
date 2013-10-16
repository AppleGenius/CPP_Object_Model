//ʹ�ø����������ĺ���
//��ʹ��pointer��reference���и�ֵʱ��C++����������Ҫ���ʵ���clip
//���ָ��������֮��ĸ�ֵ����һ��Ҫ֪����׼ȷ����
#include <iostream>
#include <string>
using namespace std;

class Base{
public:
	Base(float x = 0.0f):_x(x){}
	virtual void foo(){ cout << "Base: Foo()!" <<endl; }
private:
	float _x;
};

class Derive:public Base{
public:
	Derive(float x = 1.0f, float y = 1.0f):Base(x), _y(y){}
	virtual void foo(){ cout << "Derive: Foo()!" <<endl; }
private:
	float _y;
};

int main(int argc, const char **argv)
{
	Derive d;
	//Base b;
	//b =d;
	Base &b = d;

	string s("123");
	cout << sizeof(s) << endl;
	cout << sizeof(string) << endl;  //20
	cout << sizeof(int) << endl;
	b.foo();
	return 0;
}
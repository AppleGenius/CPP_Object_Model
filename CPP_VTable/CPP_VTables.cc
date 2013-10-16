//��̽C++ Virtual Tables�ڴ沼�֣���ÿ��derived�����ǰ��Ϊ��
//������麯����ÿ�����ఴ�̳�˳����������ÿһ�������VTable��������
//���������麯���ĺ���ָ��
//��Vtable�����ּ�ģʽ������ʼ�֮��

#include <iostream>
#include <string>

using namespace std;

class Base{
public:
	virtual void f(){cout << "Base:f" << endl;};
	virtual void g(){cout << "Base:g" << endl;};
	virtual void h(){cout << "Base:h" << endl;};
};

typedef void(*Fun)(void);

int main(int argc, const char** argv[])
{
	Base b;

	Fun pFun = NULL;

	cout << "The virtual tables's address is :" << (int*)(&b) <<endl;
	cout << "The function f()'s address from the V-Table is :" << (int*)(int*)(&b) <<endl;

	//Invoke the first virtual function
	pFun = (Fun)*((int*)*(int*)(&b));
	pFun();

	return 0;
}
//��һ�̳� a-b-c
//������̳й�ϵ�У����࣬���࣬�����඼���Լ���һ����Ա������
//�����า���˸����f()�����������า���������g_child()���䳬���f()��
//�ڱ���������ʹ�õķ�����
//ʹ����һ��int** pVtab ����Ϊ���������ڴ沼�ֵ�ָ�룬��ʹ������һ�����������еĳ�Ա�������麯����
/////////////////////////////////////////////////////////////////////////////////////////
//Result:
//1���麯��������ǰ���λ�á�
//2����Ա����������̳к�����˳�����η��ں��档
//3���ڵ�һ�ļ̳��У���overwrite���麯�����麯�����еõ��˸��¡�
#include <iostream>
using namespace std;

class Parent{
public:
	int iparent;
	Parent():iparent(10){}
	virtual void f(){cout << "Parent:f()!" << endl;}
	virtual void g(){cout << "Parent:g()!" << endl;}
	virtual void h(){cout << "Parent:h()!" << endl;}
};

class Child:public Parent{
public:
	int ichild;
	Child():ichild(100){}
	virtual void f(){cout << "Child:f()!" << endl;}
	virtual void g_child(){cout << "Child:g_child()!" << endl;}
	virtual void h_child(){cout << "child:h_child()!" << endl;}
};

class GrandChild:public Child{
public:
	int igrandchild;
	GrandChild():igrandchild(1000){}
	virtual void f(){cout << "GrandChild:f()!" << endl;}
	virtual void g_child(){cout << "GrandChild:g_child()!" <<endl;}
	virtual void h_grandchild(){cout << "FrandChild:h_grandchild()!" << endl;}

};

typedef void(*Fun)(void);

int main(int argc, const char** argv)
{
	GrandChild gc;
	int** pVtable = (int**)&gc;

	cout << "[0] GrandChild:v_ptr->" <<endl;

	for (int i = 0; (Fun)pVtable[0][i] != NULL; ++i)
	{
		Fun pFun;
		pFun = (Fun)pVtable[0][i];
		cout << " [" << i << "] ";
		pFun();
	}

	cout << "[1] Parent.iparent = " << (int)pVtable[1] << endl;
	cout << "[2] Child.ichild = " << (int)pVtable[2] <<endl;
	cout << "[3] Grandchild.igrandchild = " << (int)pVtable[3] << endl;

	return 0;
}
//static��Ա����ȫ���ԣ�������ĳһ�����ڲ������ı��������ʼ����Ȼ�ڳ���ľ�̬�洢�����⽫����static
//��Ա����ȫ�ֿɼ���ȫ�֡�Ψһ�ԡ��������׳��ֱ����ǵ����⣬����Ҫ������ǣ�һ��һ������������
//���ڴ��ַ�����ֲ��䣬�Ҳ��ᱻ�ٴγ�ʼ��������ֻ�ᱻ����
#include <iostream>

using namespace std;

int* Add_Func(int i)
{
	static int temp = i;
	return &(++temp);
}

int main(int argc, const char ** argv[])
{
	int a = 1, b = 2;
	printf("The First number is :%d!\t The second number is :%d!\t\n", *Add_Func(a), *Add_Func(b));
	return 0;
}
#include<iostream>
using namespace std;

//������ҵ���߼�һ�� 
//�����Ͳ�����  ������

void swapint(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;

}

void swapdouble(char &a, char &b) {

	char tmp = a;
	a = b;
	b = tmp;
}

int main01() {
	int  x = 10;
	int y = 20;
	swapint(x, y);
	printf("x:%d, y:%d\n", x, y);

	char x1 = 'a';
	char y1 = 'c';
	swapdouble(x1, y1);
	printf("x1:%c, y1:%c\n", x1, y1);
	system("pause");

	return 0;
}

//���ͱ��
template <typename T>
void swaptmp(T &a,T &b) {
	T tmp = a;
	a = b;
	b = tmp;
	cout << "���Ǻ���ģ��" << endl;
}

int main02() {
	{
		//��ʾ����
		int a = 10;
		int b = 20;
		swaptmp<int>(a, b);
		cout << "a=" << a << "b=" << b << endl;

	}
	{
		//�Զ����͵��Ƶ�
		char x1 = 'a';
		char y1 = 'c';
		swaptmp(x1, y1);
		cout << "a=" << x1 << "b=" << y1 << endl;
		
	}



	system("pause");
	return 0;
}
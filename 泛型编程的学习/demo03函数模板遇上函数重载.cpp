#include<iostream>
using namespace std;

//������ҵ���߼�һ�� 
//�����Ͳ�����  ������

void swapint(int a, char  b) {
	int tmp = a;
	a = b;
	b = tmp;
	cout << "������ͨ�ĺ���"<<endl;
}

template<typename T>
void swapint(T A,T B) {


	cout << "���ú���ģ��" << endl;
}

int main31() {

	int a = 10;
	char b = 'a';
	swapint(a, b);
	swapint(b, a);//�������������ʽ���͵�ת��
	cout << endl;
	swapint(a, a);
	//����ģ����õ�ʵ�ʣ����͵Ĳ����������ϸ������ͽ��к���ƥ�䣬����������͵���ʽת��
	/*��������Զ�������ת��*/


	
	system("pause");
	return 0;
}
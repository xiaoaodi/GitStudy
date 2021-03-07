#include<iostream>
using namespace std;

//函数的业务逻辑一样 
//让类型参数化  方便编程

void swapint(int a, char  b) {
	int tmp = a;
	a = b;
	b = tmp;
	cout << "调用普通的函数"<<endl;
}

template<typename T>
void swapint(T A,T B) {


	cout << "调用函数模板" << endl;
}

int main31() {

	int a = 10;
	char b = 'a';
	swapint(a, b);
	swapint(b, a);//编译器会进行隐式类型的转化
	cout << endl;
	swapint(a, a);
	//函数模板调用的实质，类型的参数化，将严格按照类型进行函数匹配，不会进行类型的隐式转化
	/*不会进行自动的类型转化*/


	
	system("pause");
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;
#include "fstream"



void main91()
{
	char buf[] = "c:2aaaaaaafffaaaafff.txt";
	char* fname = buf;
	ofstream fout(fname, ios::app); //建一个 输出流对象 和文件关联;  
	if (!fout)
	{
		cout << "打开文件失败" << endl;
		return;
	}
	fout << "hello....111" << endl;
	fout << "hello....222" << endl;
	fout << "hello....333" << endl;
	fout.close();

	/*
	//读文件
	ifstream fin(fname); //建立一个输入流对象 和文件关联
	char ch;

	while (fin.get(ch))
	{
		cout <<ch ;
	}
	fin.close();
	*/

	cout << "hello..." << endl;
	system("pause");
	return;
}

class Teacher
{
public:
	Teacher()
	{
		age = 33;
		strcpy(name, "");
	}
	Teacher(int _age, char* _name)
	{
		age = _age;
		strcpy(name, _name);
	}
	void printT()
	{
		cout << "age:" << age << "name:" << name << endl;
	}
protected:
private:
	int	 age;
	char name[32];
};
void main()
{
	char buf[] = "c:/11a.dat";
	char *fname = buf;
	ofstream fout(fname, ios::binary); //建一个 输出流对象 和文件关联;  
	if (!fout)
	{
		cout << "打开文件失败" << endl;
		return;
	}

	char buf1[] = "t31";
	Teacher t1(31, buf1);
	Teacher t2(32, buf1);
	fout.write((char*)&t1, sizeof(Teacher));
	fout.write((char*)&t2, sizeof(Teacher));
	fout.close();


	//
	ifstream fin(fname); //建立一个输入流对象 和文件关联
	Teacher tmp;

	fin.read((char*)&tmp, sizeof(Teacher));
	tmp.printT();

	fin.read((char*)&tmp, sizeof(Teacher));
	tmp.printT();

	fin.close();


	system("pause");
}
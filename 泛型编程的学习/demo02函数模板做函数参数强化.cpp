#include<iostream>
using namespace std;

//函数模板的使用
template<typename T,typename T1>
int mySort(T* array, T1 size) {
	T tmp=0;
	if (array == NULL) {
		return -1;
	}
	for (int i = 0; i < size; i++){
		for (int j = i + 1; j < size; j++) {

			if (array[i] < array[j]) {

				tmp=array[i];
				array[i]=array[j];
				array[j]=tmp;
			}
		}
	}

	return 0;
}

template<typename t, typename t1>
int printshow(t* array, t1 size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << "   " ;
		
	}
	return 0;
}


int  main21() {
	int array[] = { 1,21,323,4234,2,10,23,13 };
	int  size = sizeof(array) / sizeof(array[0]);
	cout << size << endl;
	mySort(array, size);
	printshow(array, size);
	cout << "字符的排序结果"<<endl;
	char buf[] = "dasdadadfsfaswqeqf";
	int len = strlen(buf);
	mySort(buf, len);
	printshow(buf, len);

	system("pause");
	return 0;
}
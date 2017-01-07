//============================================================================
// Name        : hello.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Compare.h"

using namespace std;

//函数模板
template<class T>
void test(T t) {
	cout<<t + t<<endl;
}

//typename VS class

int main() {
	string str = "hh";
	test<string>(str);

	int i = 100;
	test<int>(i);

	Compare<int> comObj;

	int j = 200;

	int result = comObj.compare(i, j);

	cout<<result<<endl;

	return 0;
}

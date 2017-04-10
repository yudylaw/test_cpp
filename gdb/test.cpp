/*
 * test.cpp
 *
 *  Created on: 2017年4月8日
 *      Author: yudylaw
 */

#include <iostream>
#include "Person.h"

using namespace std;

void testArray() {
    int arr[10] = {1,2,3,0,0,1};
    cout<<"index of 1="<<arr[1]<<", index of 11="<<arr[11]<<endl;
}

int main() {
	cout<<"hello gdb"<<endl;
	string name = "yudy";
	int age = 100;
	Person *p = NULL;
	p->run();
//	Person person(20, name);
//	person.sayHello();
	testArray();
	return 0;
}




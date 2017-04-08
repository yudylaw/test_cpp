/*
 * test.cpp
 *
 *  Created on: 2017年4月8日
 *      Author: yudylaw
 */

#include <iostream>
#include "Person.h"

using namespace std;

int main() {
	cout<<"hello gdb"<<endl;
	string name = "yudy";
	Person person(20, name);
	person.sayHello();
	return 0;
}




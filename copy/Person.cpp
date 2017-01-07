/*
 * Person.cpp
 *
 *  Created on: 2017年1月7日
 *      Author: yudylaw
 */


#include "Person.h"

//拷贝赋值
Person& Person::operator=(const Person& p) {
	age = p.age;
	name = p.name;
	cout<<"copy person operator."<<endl;
	return *this;
}


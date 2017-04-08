/*
 * Person.h
 *
 *  Created on: 2017年1月7日
 *      Author: yudylaw
 */

#ifndef COPY_PERSON_H_
#define COPY_PERSON_H_

#include <iostream>

using namespace std;

class Person {

public:
	Person(int age, string &name) :age(age), name(name) {
		cout<<"person constructor."<<endl;
	}
	~Person() {
		cout<<"person destructor."<<endl;
	}
	//复制构造函数
	Person(const Person& p) :age(p.age), name(p.name) {
		cout<<"copy person constructor."<<endl;
	}

	//拷贝赋值
	Person& operator=(const Person& p);

	string toString() {
		string str = to_string(age) + "," + name;
		return str;
	}

	int sayHello();

private:
	int age;
	string name;
};



#endif /* COPY_PERSON_H_ */

/*
 * copy.cpp
 *
 *  Created on: 2017年1月7日
 *      Author: yudylaw
 */

#include <iostream>
#include "Person.h"

using namespace std;

int main() {

	string name1 = "p1";
	string name2 = "p2";

	Person p1(10, name1);
	Person p2(12, name2);

	cout<<p1.toString()<<endl;
	cout<<p2.toString()<<endl;

	Person p3(p1);//拷贝构造
	cout<<p3.toString()<<endl;

	Person p4 = p2;//拷贝构造
	cout<<p4.toString()<<endl;

	p2 = p1;//拷贝复制
	cout<<p2.toString()<<endl;

	cout<<"end of main."<<endl;

	return 0;
}


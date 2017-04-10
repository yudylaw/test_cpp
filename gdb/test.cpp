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

void mem() {
    int a;
    char b[128];
    //bool c;
    char* d=new char[128];
    int e;

    b[136] = '\0';
    b[137] = '\0';
    b[138] = '\0';
    b[139] = '\0';
    strcpy(d, "haha");
}

int get(int i){
    cout << i << endl;
    return i+1;
}
int Cal(int a, int b) {
    return a+b;
}

int main() {
	cout<<"hello gdb"<<endl;
	string name = "yudy";
	int age = 100;
	Person *p = NULL;
	p->run();
//	Person person(20, name);
//	person.sayHello();
//	testArray();
//	mem();
	int res = Cal(get(0), get(10));
	cout<<"res="<<res<<endl;
	return 0;
}




/*
 * main.cpp
 *
 *  Created on: Jun 12, 2016
 *      Author: yudylaw
 */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <signal.h>
#include "b64.h"
#include "aes.h"
#include <memory>
#include <utility>
#include <thread>
#include <stdarg.h>
#include <unordered_map>
#include <map>
#include <time.h>
#include "test.h"

#define BLOCK_SIZE 128

extern void testAge();

using namespace std;

class ClxBase
{
public:
    ClxBase() {cout << "constructor of ClxBase" <<endl;};
    virtual ~ClxBase() { cout << "destructor of ClxBase" <<endl;};

    virtual void DoSomething() { cout << "Do something in class ClxBase!" << endl; };
};

class ClxDerived : public ClxBase
{
public:
    ClxDerived() {cout << "constructor of ClxDerived" <<endl;};
    ~ClxDerived() { cout << "Output from the destructor of class ClxDerived!" << endl; };

    void DoSomething() { cout << "Do something in class ClxDerived!" << endl; };
};

void testBase64() {
	string str = "yudylaw";
	char* ch = b64_encode((unsigned char*) (str.c_str()), str.length());
	cout << ch << endl;
	string b64 = "eXVkeWxhdw==";
	unsigned char* ch2 = b64_decode(b64.c_str(), b64.length());
	cout << ch2 << endl;
}

void testAes() {

	uint8_t in[BLOCK_SIZE] = "yudylaw-1234567890-yyybadkkkwwww-1";

	unsigned char out[BLOCK_SIZE];

	aes128_cbc_encrypt(out, in);//out

	unsigned char out2[BLOCK_SIZE];

	aes128_cbc_decrypt(out2, out);

	for (int i=0;i < strlen((char*)out2);i++) {
		printf("%c", out2[i]);
	}

	cout<<""<<endl;

}

void testRand() {
	srand(time(NULL));
	int i = 10;
	while(i-- > 0) {
		int random = rand();
		printf("%d\n", random);
	}
}

void stop(int sig) {
	printf("i got signal %d\n" , sig);
	exit(0);
}

void testBase() {
	ClxBase *pTest = new ClxDerived;
	pTest->DoSomething();
	delete pTest;
}

inline string GetProvinceAdCode(string adCode) {
	if (adCode.length() == 6) {
		return adCode.substr(0, 2) + "0000";
	}
	return "";
}

//extern void test_et();
//extern int age;


void echo() {
	cout<<"echo"<<endl;
}

void testThread() {

	std::thread th(echo);//started

	th.join();//main thread waiting

}

void testSharedPtr() {
	std::shared_ptr<int> test;
	if (!test) {
		cout<<"shared_ptr test is null"<<endl;
	}
	if (!test.get()) {
		cout<<"shared_ptr test.get() return null"<<endl;
	}
}

void testMap() {
	std::unordered_map<string, int> statMap;
	statMap.insert(std::make_pair("yudy", 30));
	statMap.insert(std::make_pair("yudy2", 32));

	auto item = statMap.find("yudy");

	item->second = 100;

//	for (auto &item : statMap) {
//		item.second = item.second + 1;
//	}
//
	for (auto item : statMap) {
		cout<<item.second<<endl;
	}
}

void testSortMap() {
	std::map<int, int, greater<int>> adds;//降序
	adds.insert(make_pair(1, 10));
	adds.insert(make_pair(3, 20));
	adds.insert(make_pair(2, 30));
	adds.insert(make_pair(2, 30));

	for (auto kv : adds) {
		cout<<"key="<<kv.first<<", value="<<kv.second<<endl;
	}
}

void getTime() {
	struct tm tm_time;
	string str = "2016-10-20 22:00:35";
	string fmt = "%Y-%m-%d %H:%M:%S";
	strptime(str.c_str(), fmt.c_str(), &tm_time);
	time_t int_time = mktime(&tm_time);
//	cout<<int_time<<endl;
}

int main() {
	cout<<"hello cpp"<<endl;

	cout<<"main, age="<<AGE<<endl;

	AGE = 10000;//no effect

//	testAge();

//	testMap();

//	testSortMap();

	for (int i=0;i < 10000;i++) {
		getTime();
	}

//	testSharedPtr();

//	testThread();

//	int i = 0;
//
//	if (!i) {
//		cout<<"i="<<i<<endl;
//	}

//	test_et();
//
//	cout<<"age="<<age<<endl;
//
//	char version [16];
//
//	int n = snprintf(version, sizeof(version), "hellohellohellohellohello %d", 123);
//
//	cout<<"version="<<version<<", n="<<n<<endl;

//	std::shared_ptr<int> age(new int(100));
//	std::shared_ptr<int> age2 = age;//age.use_count() == 2
//	std::shared_ptr<int> age3(new int(123));
//
//	age = age3;//age.use_count() == 1, age3.use_count() == 2
//
//	cout<<age.use_count()<<endl;
//	cout<<age3.use_count()<<endl;
//	cout<<age2.use_count()<<endl;

//	std::move();

//	string adCode = GetProvinceAdCode("32010");
//	cout<<adCode<<endl;

//	testBase();
//	testBase64();

//	testAes();

//	testRand();

//	signal(SIGTERM , stop); //kill -15
//	signal(SIGINT , stop); //ctrl+c
//
//	while(true) {
//		cout<<"test"<<endl;
//		sleep(1);
//	}
}




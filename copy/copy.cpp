/*
 * copy.cpp
 *
 *  Created on: 2017年1月7日
 *      Author: yudylaw
 */

#include <iostream>
#include "math.h"
#include "Person.h"
#include <vector>
#include <random>

using namespace std;

void copy() {
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
}

void cal() {
	uint32_t vc = 12001;
	uint32_t lc = 1001;
	int32_t weight = -5;
	uint64_t ctime = 1484202894;
	//衰减0.5

	//比重项
	int likeCount = 20;
	int viewCount = 1;
	int HOT = 100;
	//限制项
	int decaySeconds = 7201;

	int hot = likeCount * lc / 10;
	cout<<"after lc, hot="<<hot<<endl;

	hot += viewCount * vc / 10;
	cout<<"after vc, hot="<<hot<<endl;

	if (weight > 0) {
		hot = hot*(weight + 1) + weight * HOT;
	}
	if (weight < 0) {
		hot = hot/(abs(weight) + 1) - abs(weight) * HOT;
	}
	cout<<"after weight, hot="<<hot<<endl;

	int decay = decaySeconds / 3600;
	if (decay > 0) {
		int s = pow(2, decay);
		hot = hot / s;
	}
	cout<<"after decay, hot="<<hot<<endl;
}

bool uidCmp(const int& uid1, const int& uid2) {
	return uid1 < uid2;
}

void test() {

	vector<int> uids = {12,10,3,22,1201};
	vector<int> uids2 = {1201, 222,120,3,22};
	vector<int> result(10);

	std::sort(uids.begin(), uids.end(), uidCmp);
	std::sort(uids2.begin(), uids2.end(), uidCmp);

	vector<int>::iterator it = std::set_difference(uids.begin(), uids.end(), uids2.begin(), uids2.end(), result.begin(), uidCmp);

	result.resize(it - result.begin());

	for (auto uid : result) {
		cout<<uid<<endl;
	}

}

void ramdom() {
    std::random_device rd;//种子
    std::mt19937 gen(rd());//引擎
    std::uniform_int_distribution<> dis(100, 1000);//分布
	cout << dis(gen) << endl;//随机数
}

int myrandom (int i) {
	return std::rand() % i;
}

void random_shuffle() {
	std::srand (unsigned (std::time(0)));
	std::vector<int> nums = {121,3,5,333,7,9,10};
	for (auto num : nums) {
		cout<<num<<endl;
	}
	std::random_shuffle(nums.begin(), nums.end(), myrandom);
	cout<<"after shuffle"<<endl;
	for (auto num : nums) {
		cout<<num<<endl;
	}
}

int main() {

//	cal();
//	test();
//	ramdom();
	random_shuffle();

	cout<<"end of main."<<endl;

	return 0;
}


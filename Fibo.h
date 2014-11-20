/*
 * Fibo.h
 *
 *  Created on: 2014-01-27
 *      Author: frye
 */

#ifndef FIBO_H_
#define FIBO_H_

#include <iostream>
using namespace std;

void fibo(int num){
	if (num==1) {
		cout<<1<<endl;
		return;
	}
	else if (num==2) {
		cout<<1<<" "<<1<<" "<<endl;
		return;
	}
	int first = 1;
	int second = 1;
	int i = 3;
//	cout<<1<<" "<<1<<" ";
	while (i<=num){
		int sum = first + second;
		first = second;
		second = sum;
		i++;
//		cout<<sum<<" ";
	}
	cout<<second<<endl;
}

int fibo2(int num){
	cout<<"fibo"<<num<<endl;
	if (num==1 || num==2)
		return 1;
	else return fibo2(num-1)+fibo2(num-2);
}

#endif /* FIBO_H_ */

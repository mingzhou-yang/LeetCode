/*
 * printLastLine.h
 *
 *  Created on: 2014-02-12
 *      Author: frye
 */

#ifndef PRINTLASTLINE_H_
#define PRINTLASTLINE_H_

#include <fstream>
#include <iostream>

using namespace std;

void printLastLine(string s){
	ifstream in;
    in.open(s.c_str());
    int i=0;
    int k=10;
    string *lines = new string[k];
    while(in.good()){
    	char *temp = new char[100];
    	in.getline(temp, 100);
    	lines[i%k] = temp;
    	i++;
    }
    for(int j=i-k; j<i;j++){
    	cout<<lines[j%10]<<endl;
    }
    in.close();
}

#endif /* PRINTLASTLINE_H_ */

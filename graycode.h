/*
 * graycode.h
 *
 *  Created on: 2014-04-26
 *      Author: frye
 */

#ifndef GRAYCODE_H_
#define GRAYCODE_H_

#include <vector>
using namespace std;

	vector<int> grayCode(int n) {
        vector<int> code;
        code.push_back(0);
        if (n==0) return code;
        code.push_back(1);
        for(int i=1;i<n;i++){
        	int high = 1<<i;
        	for(int j=code.size()-1;j>=0;j--)
        		code.push_back(high+code[j]);
        }
        return code;
    }

#endif /* GRAYCODE_H_ */

/*
 * CountAndSay.h
 *
 *  Created on: 2014-05-15
 *      Author: frye
 */

#ifndef COUNTANDSAY_H_
#define COUNTANDSAY_H_

#include "commonHeader.h"

	string countAndSay(int n) {
		if (n<1) return "";
		string preStr = "1";
		for(int i=1;i<n;i++){
			char preChar = preStr[0];
			int count = 1;
			string temp;
			for(unsigned int j=1;j<preStr.size();j++){
				if (preChar==preStr[j]) count++;
				else{
					string s1 = to_string(count);
					temp = temp + s1 + preChar;
					count = 1;
					preChar = preStr[j];
				}
			}
			string s1 = to_string(count);
			temp = temp + s1 + preChar;
			preStr = temp;
		}
		return preStr;
    }

#endif /* COUNTANDSAY_H_ */

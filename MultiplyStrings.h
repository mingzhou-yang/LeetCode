/*
 * MultiplyStrings.h
 *
 *  Created on: Nov 24, 2014
 *      Author: frye
 */

#ifndef MULTIPLYSTRINGS_H_
#define MULTIPLYSTRINGS_H_

#include "commonHeader.h"

	void reverseString(string &s){
		for(int i=0, j=(int)s.size()-1;i<j;i++, j--){
			char temp = s[i];
			s[i] = s[j];
			s[j] = temp;
		}
	}

    string multiply(string num1, string num2) {
    	string str(num1.size()+num2.size()+1, '0');
    	if (!num1.size() || !num2.size()) return "0";
    	bool negative = false;
    	if (num1[0]=='-') {negative = !negative; num1[0] = '0';}
    	if (num2[0]=='-') {negative = !negative; num2[0] = '0';}

    	reverseString(num1);
    	reverseString(num2);

    	for(int i=0;i<(int)num1.size();i++){
    		for(int j=0;j<(int)num2.size();j++){
    			int product = (num1[i]-'0')*(num2[j]-'0');
    			int carry = 0;
    			for(int k=0; product||carry; k++){
    				int digit = product % 10;
    				int digit2 = str[i+j+k] - '0';
    				int sum = digit + digit2 + carry;
    				if (sum>=10) {carry = 1; sum-=10;}
    				else carry = 0;
    				str[i+j+k]  = sum + '0';
    				product /= 10;
    			}
    		}
    	}
    	int pos;
    	for(pos=(int)str.size()-1;pos>=0&&str[pos]=='0';pos--) {}
    	if (pos==-1) return "0";
    	string ret = str.substr(0, pos+1);
    	reverseString(ret);
    	return (negative ? "-" : "") + ret;
    }



#endif /* MULTIPLYSTRINGS_H_ */

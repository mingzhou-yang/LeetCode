/*
 * AddBinary.h
 *
 *  Created on: 2014-06-13
 *      Author: frye
 */

#ifndef ADDBINARY_H_
#define ADDBINARY_H_

#include "commonHeader.h"

	string addBinary(string a, string b) {
		if (a.empty() && b.empty()) return "";
		if (a.empty()) return b;
		if (b.empty()) return a;
		string sum;
		int carry = 0, i, j;
		for(i=a.size()-1, j=b.size()-1; i>=0&&j>=0; i--, j--){
			int bit_a = a[i]-'0';
			int bit_b = b[j]-'0';
			int bitSum = bit_a + bit_b + carry;
			switch(bitSum){
			case 0:
				sum = "0"+sum;
				carry = 0;
				break;
			case 1:
				sum = "1"+sum;
				carry = 0;
				break;
			case 2:
				sum = "0"+sum;
				carry = 1;
				break;
			case 3:
				sum = "1"+sum;
				carry = 1;
				break;
			}
		}
		if(i<0&&j>=0){
			for(;j>=0;j--){
				int bit_b = b[j]-'0';
				int bitSum = bit_b+carry;
				switch(bitSum){
				case 0:
					sum = "0"+sum;
					carry = 0;
					break;
				case 1:
					sum = "1"+sum;
					carry = 0;
					break;
				case 2:
					sum = "0"+sum;
					carry = 1;
					break;
				}
			}
		}
		else if(i>=0&&j<0){
			for(;i>=0;i--){
				int bit_a = a[i]-'0';
				int bitSum = bit_a+carry;
				switch(bitSum){
				case 0:
					sum = "0"+sum;
					carry = 0;
					break;
				case 1:
					sum = "1"+sum;
					carry = 0;
					break;
				case 2:
					sum = "0"+sum;
					carry = 1;
					break;
				}
			}
		}
		if(i<0&&j<0&&carry==1) sum = "1"+sum;
		return sum;

    }

#endif /* ADDBINARY_H_ */

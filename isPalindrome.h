/*
 * isPalindrome.h
 *
 *  Created on: 2014-05-05
 *      Author: frye
 */

#ifndef ISPALINDROME_H_
#define ISPALINDROME_H_

#include "commonHeader.h"

	bool isPalindrome(int x) {
		if (x<0) return false;
		if (x<10) return true;
		int temp = 10;
		while(x/temp>9) temp = temp*10;

		int num = x;
		while(num>0){
			if (num%10!=num/temp) return false;
			num = num % temp;
			num /= 10;
			temp /= 100;
		}
		return true;
    }

#endif /* ISPALINDROME_H_ */

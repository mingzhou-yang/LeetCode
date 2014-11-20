/*
 * plusOne.h
 *
 *  Created on: 2014-04-29
 *      Author: frye
 */

#ifndef PLUSONE_H_
#define PLUSONE_H_

#include "commonHeader.h"

	vector<int> plusOne(vector<int> &digits) {
        int carry = 1;
        for(int i=digits.size()-1;i>=0;i--){
            if (digits[i]+carry==10){
                digits[i] = 0;
                carry = 1;
            }
            else{
                digits[i] += carry;
                carry = 0;
            }
        }
        if (carry==1) digits.insert(digits.begin(), 1);
        return digits;
    }

#endif /* PLUSONE_H_ */

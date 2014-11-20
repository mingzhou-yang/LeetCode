/*
 * Divide.h
 *
 *  Created on: Nov 19, 2014
 *      Author: frye
 */

#ifndef DIVIDE_H_
#define DIVIDE_H_

#include "commonHeader.h"

	int countBit(long int num){
        int counter = 0;
        while (num>0) {
            counter++;
            num = num>>1;
        }
        return counter;
    }

    int divide(int dividend, int divisor) {
        if (divisor==0) return 0;
        int sign = (divisor>0&&dividend>0)||(divisor<0&&dividend<0)?1:-1;
        long int a = abs(divisor);
        long int b = abs(dividend);
        long int ret = 0;
        long int sum = 0;
        for (int i=countBit(b)-countBit(a);i>=0;i--){
            if (sum+(a<<i)<=b){
                ret += (1<<i);
                sum += (a<<i);
            }
            if (sum==b) return sign==1?ret:-ret;
        }
        return sign==1?ret:-ret;
    }

#endif /* DIVIDE_H_ */

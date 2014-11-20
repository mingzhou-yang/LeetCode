/*
 * pow.h
 *
 *  Created on: 2014-06-05
 *      Author: frye
 */

#ifndef POW_H_
#define POW_H_

#include "commonHeader.h"

	double pow(double x, int n) {
        double res = 1;
        double temp = x;
        bool flag = false;
        if (n<0){
        	n = -n;
        	flag = true;
        }
        int m = n;
        if (n==0) return 1;

        while(m>0){
        	int mod = m%2;
        	res = mod==1?res*temp:res;
        	m /= 2;
        	temp = temp*temp;
        }
        if (flag) return 1.0/res;
        else return res;
    }

#endif /* POW_H_ */

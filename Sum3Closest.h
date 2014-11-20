/*
 * Sum3Closest.h
 *
 *  Created on: 2014-05-11
 *      Author: frye
 */

#ifndef SUM3CLOSEST_H_
#define SUM3CLOSEST_H_

#include <cmath>
#include "commonHeader.h"

	int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int close = num[0]+num[1]+num[2];
        for(unsigned int i=0;i<num.size()-2;i++){
        	int head = i+1, tail = num.size()-1;
        	while(head<tail){
        		int sum = num[i]+num[head]+num[tail];
        		int diff = sum-target;
        		if (diff==0) return target;
        		if (diff>0) tail--;
        		else head++;
        		if (abs(diff)<abs(close-target)) close = sum;
        	}
        }
        return close;
    }

#endif /* SUM3CLOSEST_H_ */

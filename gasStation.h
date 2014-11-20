/*
 * gasStation.h
 *
 *  Created on: Sep 23, 2014
 *      Author: frye
 */

#ifndef GASSTATION_H_
#define GASSTATION_H_

#include "commonHeader.h"

	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		vector<int> diff(gas.begin(), gas.end());
		for(unsigned int i=0;i<gas.size();i++)
			diff[i] = gas[i] - cost[i];
		int sum = 0, start = 0;
		for(unsigned int i=0;i<diff.size();i++){
			sum += diff[i];
			if (sum<0){
				start = i+1;
				sum = 0;
			}
		}
		if(start==diff.size()) return -1;
		else{
			for(int i=0;i<start;i++){
				sum += diff[i];
				if (sum<0) return -1;
			}
			return start;
		}
    }



#endif /* GASSTATION_H_ */

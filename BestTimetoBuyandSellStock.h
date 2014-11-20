/*
 * BestTimetoBuyandSellStock.h
 *
 *  Created on: Oct 5, 2014
 *      Author: frye
 */

#ifndef BESTTIMETOBUYANDSELLSTOCK_H_
#define BESTTIMETOBUYANDSELLSTOCK_H_

#include "commonHeader.h"

	int maxProfit(vector<int> &prices) {
		int size = prices.size();
		int *until = new int[size];
		int *after = new int[size+1];
		int start = prices[0], maxProfit = 0;
		for(int i=1;i<size;i++){
			if (prices[i]-start > maxProfit) maxProfit = prices[i]-start;
			if (prices[i] < start) start = prices[i];
			until[i] = maxProfit;
		}
		maxProfit = 0;
		start = prices[size-1];
		for(int i=size-2;i>=0;i--){
			if (start-prices[i] > maxProfit) maxProfit = start-prices[i];
			if (prices[i] > start) start = prices[i];
			after[i] = maxProfit;
		}
		maxProfit = 0;
		for(int i=0;i<size;i++) cout<<until[i]<<" ";
		cout<<endl;
		for(int i=0;i<size;i++) cout<<after[i]<<" ";
		cout<<endl;
		for(int i=0;i<size;i++){
			if (until[i]+after[i]>maxProfit) maxProfit = until[i]+after[i+1];
		}
		return maxProfit;
    }



#endif /* BESTTIMETOBUYANDSELLSTOCK_H_ */

/*
 * FindMinimumRotatedSortedArray.h
 *
 *  Created on: Nov 27, 2014
 *      Author: frye
 */

#ifndef FINDMINIMUMROTATEDSORTEDARRAY_H_
#define FINDMINIMUMROTATEDSORTEDARRAY_H_

#include "commonHeader.h"

/*	int findMinHelp(vector<int> &num, int left, int size){
		cout<<left<<" "<<size<<endl;
		if (size==1 || num[left] < num[left+size-1]) return num[left];
		if (size==2) return min(num[left], num[left+1]);
		int mid = left + size/2;
		if (num[mid-1]>num[mid]) return num[mid];
		if (num[left]>num[mid]) return findMinHelp(num, left, mid-left);
		else return findMinHelp(num, mid+1, left+size-mid-1);
	}

    int findMinNoneDuplicate(vector<int> &num) {
    	if (num.empty()) return 0;
    	return findMinHelp(num, 0, (int)num.size());
    }*/

    int findMin(vector<int> &num) {
    	int left = 0, right = (int)num.size()-1;
    	while(left<right){
    		if (num[left]<num[right]) return num[left];
    		int mid = (left+right)/2;
    		if (num[left]>num[mid]) right = mid;
    		else if(num[left]<num[mid]) left = mid;
    		else left++;
    	}
    	return num[left];
    }

    int findMin2(vector<int> &num) {
    	int left = 0, right = (int)num.size()-1;
    	while(left<right){
    		if (num[left]<num[right]) return num[left];
    		int mid = (left+right)/2;
    		if (num[left]>num[mid]) right = mid;
    		else if(num[left]<num[mid]) left = mid;
    		else left++;
    	}
    	return num[left];
    }


#endif /* FINDMINIMUMROTATEDSORTEDARRAY_H_ */

/*
 * PermutationSequence.h
 *
 *  Created on: Nov 6, 2014
 *      Author: frye
 */

#ifndef PERMUTATIONSEQUENCE_H_
#define PERMUTATIONSEQUENCE_H_

#include "commonHeader.h"

	int findNum(bool rec[], int n){
		for(int i=0,m=0;;i++){
			if (rec[i]&&m==n){
				rec[i] = false;
				return i+1;
			}
			if (rec[i]) m++;
		}
		return -1;
	}

    string getPermutation(int n, int k) {
    	if (n<=0) return "";
    	int *size = new int[n];
    	size[0] = 1;
    	for(int i=1;i<n;i++) size[i] = size[i-1] * i;
    	string ret(n, 'x');
    	bool *rec = new bool[n];
    	for(int i=0;i<n;i++) rec[i] = true;
    	int num = k;
    	for(int i=0;i<n-1;i++){
    		int temp = (num-1) / size[n-i-1];
    		int digit = findNum(rec, temp);
    		ret[i] = '0'+digit-0;
    		num = (num-1) % size[n-i-1]+1;
    	}
    	ret[n-1] = findNum(rec, 0)-0+'0';
    	return ret;
    }



#endif /* PERMUTATIONSEQUENCE_H_ */

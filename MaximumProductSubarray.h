/*
 * MaximumProductSubarray.h
 *
 *  Created on: Nov 19, 2014
 *      Author: frye
 */

#ifndef MAXIMUMPRODUCTSUBARRAY_H_
#define MAXIMUMPRODUCTSUBARRAY_H_

#include "commonHeader.h"

    int maxProduct(int A[], int n) {
    	if (n==0) return 0;
    	if (n==1) return A[0];
    	int max=INT_MIN;
    	int product=1;
    	int headNegative, tailNegative;
    	int preIndex=0;
    	for(int i=0;i<n;i++){
    		for(;i<n&&A[i]>0;i++) product *= A[i];
    		if (A[i]==0){
    			if (i==preIndex || product<0) product = 0;
    			if (max<product) max = product;
    			product = 1;
    			preIndex = i+1;
    			continue;
    		}
    		else headNegative = product*A[i];
    		for(;i<n&&A[i]!=0;i++){
    			if (A[i]<0) tailNegative = A[i];
    			else tailNegative *= A[i];
    			product *= A[i];
    		}
    		if (i>preIndex+1&&product<0)
    			product = headNegative<tailNegative?product/tailNegative:product/headNegative;
    		if (i<n&&A[i]==0) product = product>0?product:0;
    		if (max<product) max = product;
    		product = 1;
    		preIndex = i+1;
    	}
    	return max;
    }



#endif /* MAXIMUMPRODUCTSUBARRAY_H_ */

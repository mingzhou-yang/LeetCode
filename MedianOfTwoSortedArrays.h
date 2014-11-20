/*
 * MedianOfTwoSortedArrays.h
 *
 *  Created on: Nov 19, 2014
 *      Author: frye
 */

#ifndef MEDIANOFTWOSORTEDARRAYS_H_
#define MEDIANOFTWOSORTEDARRAYS_H_

#include "commonHeader.h"

    int getTarget(int A[], int m, int B[], int n, int target) {
        if (n>m) return getTarget(B,n,A,m,target);
        if (n==0) return A[target-1];
        else if (target==1) return min(A[0], B[0]);
        int i = min(target/2,m), j = min(target-i,n);
        if (A[i-1]>=B[j-1]) return getTarget(A,i,B+j,n-j,target-j);
        else return getTarget(A+i,m-i,B,j,target-i);
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int target = (m+n+2)/2;
        int res = getTarget(A,m,B,n,target);
        target = (m+n+1)/2;
        return (getTarget(A,m,B,n,target)+res)/2.0;
    }

#endif /* MEDIANOFTWOSORTEDARRAYS_H_ */

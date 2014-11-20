/*
 * TrapRainWater.h
 *
 *  Created on: 2014-05-07
 *      Author: frye
 */

#ifndef TRAPRAINWATER_H_
#define TRAPRAINWATER_H_

#include "commonHeader.h"

	int findPeak(int A[], int pos, int n){
		int i=pos+1;
//		while(A[i]<=A[i-1]&&i<n) i++;
		while(A[i]>=A[i-1]&&i<n) i++;
		return i-1;
	}

	int findNextFloor(int A[], int pos, int n){
		int i=pos+1;
		while(A[i]<=A[i-1]&&i<n) i++;
		return i-1;
	}

	int findNextPeak(int A[], int pos, int peak, int n){
		int i=pos+1;
		int max=i;
		while(i<n){
			if (A[i]>=A[peak]) return i;
			if (A[i]>A[max]) max = i;
			i++;
		}
		return max;
	}

	int trap(int A[], int n) {
		int i=0, sum=0;
		while(i<n){
			int peak = findPeak(A, i, n);
			int floor = findNextFloor(A, peak, n);
			int nextPeak = findNextPeak(A, floor, peak, n);
			if (nextPeak>=n) break;

			int boundary = A[peak]<A[nextPeak]?A[peak]:A[nextPeak];
			for(int j=peak+1;j<nextPeak;j++) sum += (boundary-A[j]);
			i = nextPeak;
		}
		return sum;
    }

#endif /* TRAPRAINWATER_H_ */

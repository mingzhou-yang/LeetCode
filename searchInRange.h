/*
 * searchInRange.h
 *
 *  Created on: 2014-05-11
 *      Author: frye
 */

#ifndef SEARCHINRANGE_H_
#define SEARCHINRANGE_H_

#include "commonHeader.h"

	int findHead(int A[], int start, int end, int target){
		int mid = (start+end)/2;
		if (A[end]<target || A[start]>target) return -1;
		if (A[mid]==target && A[mid-1]<target) return mid;
		else if (A[mid]<target) return findHead(A, mid+1, end, target);
		else return findHead(A, start, mid-1, target);
		return -1;
	}

	int findTail(int A[], int start, int end, int target){
		int mid = (start+end)/2;
		if (A[end]<target || A[start]>target) return -1;
		if (A[mid]==target && A[mid+1]>target) return mid;
		else if (A[mid]>target) return findTail(A, start, mid-1, target);
		else return findTail(A, mid+1, end, target);
		return -1;
	}

	vector<int> searchRange(int A[], int n, int target) {
		vector<int> ret;
		int head = A[0]==target?0:findHead(A, 0, n, target);
		int tail = A[n-1]==target?n-1:findTail(A, 0, n-1, target);
		ret.push_back(head);
		ret.push_back(tail);
		return ret;
    }

#endif /* SEARCHINRANGE_H_ */

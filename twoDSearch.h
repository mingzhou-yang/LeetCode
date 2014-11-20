/*
 * twoDSearch.h
 *
 *  Created on: 2014-04-29
 *      Author: frye
 */

#ifndef TWODSEARCH_H_
#define TWODSEARCH_H_

#include "commonHeader.h"

int search2d(vector<vector<int> > &matrix, int start, int end, int target){
	int mid = (start+end)/2;
	if (matrix[end][0]<=target) return end;
	if (matrix[mid][0]<=target && matrix[mid+1][0]>target) return mid;
	else if (matrix[mid][0]>target) return search2d(matrix, start, mid, target);
	else if (matrix[mid+1][0]<=target) return search2d(matrix, mid+1, end, target);
	return 0;
}

int search1d(vector<int> &matrix, int start, int end, int target){
	int mid = (start+end)/2;
	if (matrix[end]<target || matrix[start]>target) return -1;
	if (matrix[mid]==target) return target;
	else if (matrix[mid]>target) return search1d(matrix, start, mid-1, target);
	else return search1d(matrix, mid+1, end, target);
	return -1;
}

	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		int height = matrix.size()-1;
		int width = matrix[0].size()-1;
		if (matrix[0][0]>target || matrix[height][width]<target) return false;
		int line = search2d(matrix, 0, height, target);
		if (search1d(matrix[line], 0, width, target)==-1) return false;
		else return true;
    }

#endif /* TWODSEARCH_H_ */

/*
 * searchTotated.h
 *
 *  Created on: 2014-05-03
 *      Author: frye
 */

#ifndef SEARCHTOTATED_H_
#define SEARCHTOTATED_H_

		int divideSearch(int A[], int start, int end, int target) {
/*			if (start+2==end){
				if (A[start]==target) return start;
				if (A[start+1]==target) return start+1;
				else return -1;
			}*/
			if (start+1==end) return A[start]==target?start:-1;
			int mid = (start+end)/2;
			if (A[start]<=A[mid-1]){
				if (A[start]<=target && A[mid-1]>=target) return divideSearch(A, 0, mid, target);
				else return divideSearch(A, mid, end, target);
			}
			else{
				if (A[mid]<=target && A[end-1]>=target) return divideSearch(A, mid, end, target);
				else return divideSearch(A, start, mid, target);
			}
		}

	int search(int A[], int n, int target) {
		return divideSearch(A, 0, n, target);
    }

#endif /* SEARCHTOTATED_H_ */

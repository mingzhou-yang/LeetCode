/*
 * NextPermutation.h
 *
 *  Created on: 2014-06-17
 *      Author: frye
 */

#ifndef NEXTPERMUTATION_H_
#define NEXTPERMUTATION_H_

#include "commonHeader.h"

	void nextPermutation(vector<int> &num) {
		int len = num.size();
		if (len==0) return;
		int max = num.back();
		for(int i=len-2;i>=0;i--){
			if (num[i]>=max) max = num[i];
			else {
				for(int j=len-1;j>i;j--){
					if (num[j]>num[i]){
						int temp = num[j];
						num[j] = num[i];
						num[i] = temp;
						break;
					}
				}
				i++;
				for(int j=len-1;j>i;j--,i++){
					int temp = num[j];
					num[j] = num[i];
					num[i] = temp;
				}
				return;
			}
		}
		for(int i=0, j=len-1; j>i; i++, j--){
			int temp = num[j];
			num[j] = num[i];
			num[i] = temp;
		}
    }

#endif /* NEXTPERMUTATION_H_ */

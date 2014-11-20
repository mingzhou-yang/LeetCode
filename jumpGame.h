/*
 * jumpGame.h
 *
 *  Created on: 2014-05-09
 *      Author: frye
 */

#ifndef JUMPGAME_H_
#define JUMPGAME_H_

#include "commonHeader.h"

/*	bool canJump(int A[], int n) {
		if (n==1||A[0]>=n-1) return true;
		bool *canTable = new bool[n];
		for(int i=n-2;i>=0;i--){
			if (i+A[i]>=n-1) canTable[i] = true;
			else
				for(int j=0;j<A[i];j++)
					if (canTable[i+j]) {
						canTable[i] = true;
						break;
					}
		}
		return canTable[0];
    }*/

	bool canJump(int A[], int n) {
		int farthest = 0;
		for(int i=0;i<=farthest&&i<n;i++){
			if (i+A[i]>farthest) farthest = i+A[i];
			if (farthest>=n-1) return true;
		}
		return false;
	}

	int slowjump(int A[], int n) {
		if (n==0||n==1) return 0;
		int *num = new int[n];
		for(int i=1;i<n;i++) num[i] = n;
		for(int i=0;i<n;i++){
			for(int j=i;j<=i+A[i]&&j<n;j++){
				if (num[i]+1<num[j]) num[j] = num[i]+1;
			}
		}
		return num[n-1];
	}

	int jump(int A[], int n){
		if (n==0||n==1) return 0;
		int jumpnum = 0;
		int near=0, far=0;
		while(far<n-1){
			int newfar = 0;
			for(int i=near;i<=far;i++){
				if (i+A[i]>newfar) newfar = i+A[i];
			}
			near = far + 1;
			far = newfar;
			jumpnum++;
		}
		return jumpnum;
	}

#endif /* JUMPGAME_H_ */

/*
 * distinctSubsequences.h
 *
 *  Created on: Sep 25, 2014
 *      Author: frye
 */

#ifndef DISTINCTSUBSEQUENCES__H_
#define DISTINCTSUBSEQUENCES__H_

#include "commonHeader.h"

	int numDistinct(string S, string T, vector<vector<int>> &v, int startS, int startT) {
		if (S.size()-startS < T.size()-startT) return 0;
		if (T.size()<=startT) return 1;
		for(int i=startS;i<=S.size()-T.size()+startT;i++){
			if(S[i]==T[startT]){
				if (v[i+1][startT]==-1) v[i+1][startT] = numDistinct(S, T, v, i+1, startT);
				if (v[i+1][startT+1]==-1) v[i+1][startT+1] = numDistinct(S, T, v, i+1, startT+1);
				return  v[i+1][startT]+v[i+1][startT+1];
			}
		}
		return 0;
    }

	int numDistinct(string S, string T) {
		vector<int> temp(T.size()+1, -1);
		vector<vector<int>> v(S.size()+1, temp);
		return numDistinct(S, T, v, 0, 0);
	}



#endif /* DISTINCTSUBSEQUENCES__H_ */

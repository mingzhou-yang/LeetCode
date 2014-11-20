/*
 * editDistance.h
 *
 *  Created on: 2014-06-17
 *      Author: frye
 */

#ifndef EDITDISTANCE_H_
#define EDITDISTANCE_H_

#include "commonHeader.h"

	int getMin(int a, int b, int c){
		if (a<=b && a<=c) return a;
		if (b<=a && b<=c) return b;
		if (c<=a && c<=b) return c;
	}

	int minDistance(string word1, string word2) {
		int len1 = word1.size();
		int len2 = word2.size();
		if (word1.empty()) return len2;
		if (word2.empty()) return len1;
		vector<int> row(len1+1, 0);
		vector<vector<int> > v(len2+1, row);
		for(int i=0;i<=len1;i++) v[len2][i] = len1-i;
		for(int i=0;i<=len2;i++) v[i][len1] = len2-i;
		for(int i=len2-1;i>=0;i--){
			for(int j=len1-1;j>=0;j--){
				if (word1[j]==word2[i]) v[i][j] = v[i+1][j+1];
				else v[i][j] = getMin(v[i+1][j], v[i][j+1], v[i+1][j+1])+1;
			}
		}
		return v[0][0];
    }

#endif /* EDITDISTANCE_H_ */

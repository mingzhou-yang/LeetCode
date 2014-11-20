/*
 * ScrambleString.h
 *
 *  Created on: Nov 20, 2014
 *      Author: frye
 */

#ifndef SCRAMBLESTRING_H_
#define SCRAMBLESTRING_H_

#include "commonHeader.h"

    bool isScramble(string s1, string s2) {
    	if (s1.size()!=s2.size()) return false;
    	int size = s1.size();
    	vector<vector<vector<bool>>> v(size+1, vector<vector<bool>>
    			(size, vector<bool> (size, false)));
    	for(int i=0;i<size;i++)
    		for(int j=0;j<size;j++)
    			v[1][i][j] = s1[i]==s2[j];

    	for(int i=2;i<=size;i++)
    		for(int j=0;i+j<=size;j++)
    			for(int k=0;i+k<=size;k++)
    				for(int n=1;n<i;n++)
    					if ((v[n][j][k]&&v[i-n][j+n][k+n]) || (v[n][j][k+i-n]&&v[i-n][j+n][k]))
    						v[i][j][k] = true;

    	return v[size][0][0];
    }



#endif /* SCRAMBLESTRING_H_ */

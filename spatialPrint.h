/*
 * spatialPrint.h
 *
 *  Created on: 2014-05-01
 *      Author: frye
 */

#ifndef SPATIALPRINT_H_
#define SPATIALPRINT_H_

#include "commonHeader.h"

	vector<vector<int> > generateMatrix(int n) {
		int num=1, i;
		vector<int> row(n, 0);
		vector<vector<int> > v;
		for(i=0;i<n;i++) v.push_back(row);

		for(i=0;i<=n/2;i++){
			for(int j=i;j<n-i-1;j++) v[i][j] = (num++);
			for(int j=i;j<n-i-1;j++) v[j][n-i-1] = (num++);
			for(int j=i;j<n-i-1;j++) v[n-i-1][n-j-1] = (num++);
			for(int j=i;j<n-i-1;j++) v[n-j-1][i] = (num++);
		}

		if ((--i)*2!=n) v[i][i] = num;
		return v;
    }

#endif /* SPATIALPRINT_H_ */

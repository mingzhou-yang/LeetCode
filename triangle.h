/*
 * triangle.h
 *
 *  Created on: 2014-04-26
 *      Author: frye
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_

#include "commonHeader.h"

using namespace std;

	int minimumTotal(vector<vector<int> > &triangle) {
        int n = triangle.size();
        vector<int> sum(triangle[n-1]);
        for(int i=n-2;i>=0;i--)
            for(int j=0;j<i;j++)
                sum[j] = sum[j]<sum[j+1]?sum[j]+triangle[i][j]:sum[j+1]+triangle[i][j];
        return sum[0];
    }

	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> result;
		if (numRows==0) return result;
		vector<int> initial;
		initial.push_back(1);
		result.push_back(initial);
		for(int i=1;i<numRows;i++){
			vector<int> temp(result.back());
			vector<int> newline;
			newline.push_back(temp.front());
			for(int j=0;j<temp.size()-1;j++){
				newline.push_back(temp[j]+temp[j+1]);
			}
			newline.push_back(temp.back());
			result.push_back(newline);
		}
		return result;
    }

#endif /* TRIANGLE_H_ */

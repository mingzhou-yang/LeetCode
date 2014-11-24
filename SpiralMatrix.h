#ifndef _LARGEST_RECTANGLE
#define _LARGEST_RECTANGLE
#include "commonHeader.h"

    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ret;
		if (matrix.empty()) return ret;
		int up=0, down=(int)matrix.size()-1, left=0, right=matrix[0].size()-1;
		int i=0, j=0, total=(int)matrix.size()*matrix[0].size();
		while(up<=down && left<=right){
			for(;j<=right;j++) ret.push_back(matrix[i][j]);
			printVector(ret);
			if (ret.size()==total) break;
			i = ++up;
			j--;
			for(;i<=down;i++) ret.push_back(matrix[i][j]);
			if (ret.size()==total) break;
			printVector(ret);
			j = --right;
			i--;
			for(;j>=left;j--) ret.push_back(matrix[i][j]);
			if (ret.size()==total) break;
			printVector(ret);
			i = --down;
			j++;
			for(;i>=up;i--) ret.push_back(matrix[i][j]);
			if (ret.size()==total) break;
			printVector(ret);
			j = ++left;
			i++;
		}	
		return ret;
    }

#endif
/*
 * MaximalRectangle.h
 *
 *  Created on: Nov 23, 2014
 *      Author: frye
 */

#ifndef MAXIMALRECTANGLE_H_
#define MAXIMALRECTANGLE_H_

#include "commonHeader.h"

    int maximalRectangle(vector<vector<char> > &matrix) {
    	int n = matrix.size();
    	if (!n) return 0;
    	int m = matrix[0].size();
    	if (!m) return 0;
    	vector<int> height(m, 0);
    	int max = 0;
    	for(int i=0;i<n;i++){
    		for(int j=0;j<m;j++){
    			if (i==0 || !height[j]){
    				int count = 0;
    				while(count+i<n && matrix[count+i][j]=='1') count++;
    				height[j] = count;
    			}
    			else height[j]--;
    		}

//    		printVector(height);
    		stack<int> s;
    		for(int j=0;j<m;j++){
//    			cout<<j<<" ";
    			if (s.empty() || height[s.top()]<height[j]) s.push(j);
    			else{
    				while(!s.empty() && height[s.top()]>=height[j]){
    					int prev = s.top();
    					s.pop();
    					int area = (s.empty() ? j : (j-s.top()-1)) * height[prev];
    					max = area > max ? area : max;
    				}
    				s.push(j);
    			}
    		}

    		while(!s.empty()){
    			int prev = s.top();
    			s.pop();
    			int area = (s.empty() ? m : (m-s.top()-1)) * height[prev];
    			max = area > max ? area : max;
    		}
//    		cout<<max<<endl;
    	}
    	return max;
    }

#endif /* MAXIMALRECTANGLE_H_ */

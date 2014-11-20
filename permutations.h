/*
 * permutations.h
 *
 *  Created on: 2014-04-27
 *      Author: frye
 */

#ifndef PERMUTATIONS_H_
#define PERMUTATIONS_H_

#include "commonHeader.h"

	vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> v;
        if (num.size()==1){
            v.push_back(num);
            return v;
        }
        for(unsigned int i=0;i<num.size();i++){
            vector<int> temp(num);
            temp.erase(temp.begin()+i);
            vector<vector<int>> ret = permute(temp);
            for(unsigned int j=0;j<ret.size();j++){
            	ret[j].push_back(num[i]);
            	v.push_back(ret[j]);
            }
        }
        return v;
    }

	vector<vector<int> > permuteUniqueSorted(vector<int> &num) {
        vector<vector<int>> v;
        if (num.size()==1){
            v.push_back(num);
            return v;
        }
        for(unsigned int i=0;i<num.size();i++){
        	if (i>0&&num[i]==num[i-1]) continue;
            vector<int> temp(num);
            temp.erase(temp.begin()+i);
            vector<vector<int>> ret = permuteUniqueSorted(temp);
            for(unsigned int j=0;j<ret.size();j++){
            	ret[j].push_back(num[i]);
            	v.push_back(ret[j]);
            }
        }
        return v;
    }

	vector<vector<int> > permuteUnique(vector<int> &num) {
		sort(num.begin(), num.end());
		return permuteUniqueSorted(num);
	}



#endif /* PERMUTATIONS_H_ */

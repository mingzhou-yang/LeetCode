/*
 * combinationSum.h
 *
 *  Created on: 2014-05-15
 *      Author: frye
 */

#ifndef COMBINATIONSUM_H_
#define COMBINATIONSUM_H_

#include "commonHeader.h"

	vector<vector<int> > getCombinationSum(vector<int> &candidates, int target) {
		vector<vector<int> > ret;
		if (candidates.size()<1) return ret;
		if (candidates[0]>target) return ret;
		if (candidates[0]==target){
			vector<int> temp(1, target);
			ret.push_back(temp);
		}
		vector<vector<int> > result1 = getCombinationSum(candidates, target-candidates[0]);
		vector<int> newCanditates(candidates.begin()+1, candidates.end());
		vector<vector<int> > result2 = getCombinationSum(newCanditates, target);
		if (!result1.empty()){
			for(unsigned int i=0;i<result1.size();i++) result1[i].insert(result1[i].begin(), candidates[0]);
			ret.insert(ret.begin(), result1.begin(), result1.end());
		}
		if (!result2.empty()) ret.insert(ret.begin(), result2.begin(), result2.end());
		return ret;
    }

	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());
		return getCombinationSum(candidates, target);
	}

	vector<vector<int> > getCombinationSum2(vector<int> &candidates, int target) {
		vector<vector<int> > ret;
		if (candidates.size()<1) return ret;
		if (candidates[0]>target) return ret;
		if (candidates[0]==target){
			vector<int> temp(1, target);
			ret.push_back(temp);
		}
		vector<int> newCanditates(candidates.begin()+1, candidates.end());
		int j;
		for(j=1;j<candidates.size();j++)
			if (candidates[j]!=candidates[0]) break;
		vector<int> newCanditates2(candidates.begin()+j, candidates.end());
		vector<vector<int> > result1 = getCombinationSum2(newCanditates, target-candidates[0]);
		vector<vector<int> > result2 = getCombinationSum2(newCanditates2, target);
		if (!result1.empty()){
			for(unsigned int i=0;i<result1.size();i++) result1[i].insert(result1[i].begin(), candidates[0]);
			ret.insert(ret.begin(), result1.begin(), result1.end());
		}
		if (!result2.empty()) ret.insert(ret.begin(), result2.begin(), result2.end());
			return ret;
	    }

	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		return getCombinationSum2(num, target);
	}

#endif /* COMBINATIONSUM_H_ */

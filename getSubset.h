/*
 * getSubset.h
 *
 *  Created on: 2014-01-29
 *      Author: frye
 */

#ifndef GETSUBSET_H_
#define GETSUBSET_H_

#include "commonHeader.h"

using namespace std;

typedef set<int> numSet;
typedef set<numSet> setSet;

/*setSet getSubset(numSet s){
	setSet subsets;
	if (s.size() == 1){
		subsets.insert(s);
		return subsets;
	}
	numSet::iterator it = s.begin();
	int val = *it;
	numSet singleSet;
	singleSet.insert(val);
	subsets.insert(singleSet);
	s.erase(it);

	setSet subsetsWithoutFirst = getSubset(s);
	subsets.insert(subsetsWithoutFirst.begin(), subsetsWithoutFirst.end());

	for(setSet::iterator it = subsetsWithoutFirst.begin();
			it != subsetsWithoutFirst.end(); ++it){
		numSet temp = *it;
		temp.insert(val);
		subsets.insert(temp);
	}
//	subsets.insert(subsetsWithoutFirst.begin(), subsetsWithoutFirst.end());
	return subsets;
}*/

	void getSubsets(int level, vector<int> cur, vector<vector<int>> &ret, vector<int> &S){
		int pre = S[level];
		for(int i=level;i<S.size();i++){
			if (S[i]!=pre || i==level){
				cur.push_back(S[i]);
				ret.push_back(cur);
				getSubsets(i+1, cur, ret, S);
				cur.pop_back();
				pre = S[i];
			}
		}
	}

	vector<vector<int> > subsets(vector<int> &S) {
	    sort (S.begin(), S.end());
		vector<vector<int> > ret;
		vector<int> cur;
		ret.push_back(cur);
		getSubsets(0, cur, ret, S);
		return ret;
	}

void printSet(numSet s){
	cout << "<";
	for (numSet::iterator it = s.begin(); it != s.end();++it) cout<<(*it)<<" ";
	cout << ">"<<endl;
}

void printSubsets(setSet s){
	for(setSet::iterator it=s.begin(); it != s.end(); ++it) printSet(*it);
}


#endif /* GETSUBSET_H_ */

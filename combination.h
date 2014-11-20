/*
 * combination.h
 *
 *  Created on: 2014-05-02
 *      Author: frye
 */

#ifndef COMBINATION_H_
#define COMBINATION_H_

#include "commonHeader.h"
#include <algorithm>
#include <set>

/*	set<set<int> > makeCombine(int n, int k, set<int> &v){
		set<set<int> > ret;
		if (k==0){
			ret.insert(v);
		}
		for(int i=1;i<=n;i++){
			if (find(v.begin(), v.end(), i)==v.end()){
				set<int> temp(v);
				temp.insert(i);
				set<set<int> > tempset = makeCombine(n, k-1, temp);
				ret.insert(tempset.begin(), tempset.end());
			}
		}
		return ret;
	}

	vector<vector<int> > combine(int n, int k) {
		set<int> input;
		set<set<int> > ret = makeCombine(n, k, input);
		vector<vector<int> > v;
		for(set<set<int>>::iterator it=ret.begin();it!=ret.end();++it){
			vector<int> temp((*it).begin(),(*it).end());
			v.push_back(temp);
		}
		return v;
    }*/
/*	vector<vector<int> > combine(int n, int k){
		vector<set<set<int>>> v;
		set<set<int> > first;
		vector<vector<int> > ret;
		if(n<=0||k<=0) return ret;
		for(int i=1;i<=n;i++){
			set<int> temp;
			temp.insert(i);
			first.insert(temp);
		}
		v.push_back(first);
		for(int i=2;i<=k;i++){
			set<set<int> > setofSet;
			for(int j=1;j<=n;j++){
				for(set<set<int> >::iterator it=v[i-2].begin();it!=v[i-2].end();++it){
					if (find(it->begin(), it->end(), j)==it->end()){
						set<int> tempset(it->begin(), it->end());
						tempset.insert(j);
						setofSet.insert(tempset);
					}
				}
			}
			v.push_back(setofSet);
		}
		for(set<set<int>>::iterator it=v[k-1].begin();it!=v[k-1].end();++it){
			vector<int> temp(it->begin(),it->end());
			ret.push_back(temp);
		}
		return ret;
	}*/

	void getCombine(int n, int k, int level, vector<int> cur, vector<vector<int>> &ret){
		if (cur.size()==k){
			ret.push_back(cur);
			return;
		}
		for(int i=level;i<=n;i++){
			cur.push_back(i);
			getCombine(n, k, i+1, cur, ret);
			cur.pop_back();
		}
	}

	vector<vector<int> > combine(int n, int k){
		vector<vector<int> > ret;
		vector<int> cur;
		getCombine(n, k, 1, cur, ret);
		return ret;
	}

	void getSubsets(int level, vector<int> cur, vector<vector<int>> &ret, vector<int> &S){
			for(int i=level;i<S.size();i++){
				cur.push_back(S[i]);
				ret.push_back(cur);
				getSubsets(i+1, cur, ret, S);
				cur.pop_back();
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

#endif /* COMBINATION_H_ */

/*
 * Parentheses.h
 *
 *  Created on: 2014-02-06
 *      Author: frye
 */

#ifndef PARENTHESES_H_
#define PARENTHESES_H_

#include "commonHeader.h"
#include <set>

using namespace std;

typedef set<string> ParenSet;
ParenSet Parentheses(int num){
	ParenSet pSet[num+1];
	pSet[1].insert("()");
	if (num == 1){
		return pSet[1];
	}
	for(int i=2;i<num+1;i++){
		for(int j=1;j<=i/2;j++){
			for(set<string>::iterator it=pSet[j].begin();it!=pSet[j].end();++it){
				for(set<string>::iterator it2=pSet[i-j].begin();it2!=pSet[i-j].end();++it2){
					pSet[i].insert((*it)+(*it2));
					pSet[i].insert((*it2)+(*it));
				}
			}
		}
		for(set<string>::iterator it=pSet[i-1].begin();it!=pSet[i-1].end();++it){
			pSet[i].insert("("+(*it)+")");
		}
	}
	return pSet[num];
}

	vector<string> generateParenthesis(int n) {
		ParenSet p = Parentheses(n);
		vector<string> v;
		for(ParenSet::iterator it=p.begin();it!=p.end();++it){
			v.push_back(*it);
		}
		return v;
    }

#endif /* PARENTHESES_H_ */

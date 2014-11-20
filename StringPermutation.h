/*
 * StringPermutation.h
 *
 *  Created on: 2014-02-06
 *      Author: frye
 */
#include <iostream>
#include <set>

using namespace std;

typedef set<string> StringSet;

#ifndef STRINGPERMUTATION_H_
#define STRINGPERMUTATION_H_

StringSet StringPermutation(string s){
//	cout<<s<<endl;
	StringSet result;
	if (s.length()<2){
		result.insert(s);
		return result;
	}

	string rest(s.begin()+1, s.end());
	string first(s.begin(), s.begin()+1);
	StringSet prev = StringPermutation(rest);
	int i;
	StringSet::iterator it = prev.begin();
	int length = (*it).length();
	for (;it!=prev.end();++it){
		for (i=0;i<=length;i++){
			string temp(*it);
			temp.insert(i, first);
			result.insert(temp);
		}
	}
	return result;
}

void printSet(StringSet s){
	StringSet::iterator it;
	for(it=s.begin();it!=s.end();++it)
		cout<<(*it)<<endl;
}

#endif /* STRINGPERMUTATION_H_ */

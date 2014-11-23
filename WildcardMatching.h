/*
 * WildcardMatching.h
 *
 *  Created on: Nov 20, 2014
 *      Author: frye
 */

#ifndef WILDCARDMATCHING_H_
#define WILDCARDMATCHING_H_

#include "commonHeader.h"


//Space complexity O(N^2)
	bool isMatch2(const char *s, const char *p) {
    	int slen = strlen(s), plen = strlen(p);
    	vector<vector<bool>> isValid(slen+1, vector<bool>(plen+1,false));
    	isValid[slen][plen] = true;
    	for(int j=plen-1;j>=0;j--){
    		for(int i=slen-1;i>=0;i--){
//    			if (isValid[i][j]) continue;
    			if (p[j]=='?' || s[i]==p[j]) isValid[i][j] = isValid[i+1][j+1];
    			else if(p[j]=='*' && isValid[i+1][j+1]){
    				isValid[i][j] = true;
    				isValid[i+1][j] = true;
    				for(i=i-1;i>=0;i--)
    					if (s[i]==s[i+1]) isValid[i][j] = true;
    			}
    		}
    	}
//    	printVecVector(isValid);
    	return isValid[0][0];
    }

	bool isMatch(const char *s, const char *p){
		const char *lastStar = NULL, *lastS=s;
		while(*s){
			cout<<*s<<" "<<*p<<endl;
			if (*p=='?' || *s==*p) {s++; p++;}
			else if (*p=='*') {lastStar = p++; lastS = s;}
			else if (lastStar) {p = lastStar+1; s = ++lastS;}
			else return false;
		}
		cout<<*s<<endl;
		while (*p=='*') {p++;}
		return !*s && !*p;
	}

#endif /* WILDCARDMATCHING_H_ */

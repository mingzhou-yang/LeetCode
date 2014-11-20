/*
 * PalindromePartition.h
 *
 *  Created on: 2014-06-11
 *      Author: frye
 */

#ifndef PALINDROMEPARTITION_H_
#define PALINDROMEPARTITION_H_

#include "commonHeader.h"

	vector<vector<string>> partition(string s) {
		vector<vector<vector<string>>> v;
		vector<vector<string>> first;
		int len = s.length();
		if (len==0) return first;
		vector<string> firstChar;
		firstChar.push_back(s.substr(0, 1));
		first.push_back(firstChar);
		v.push_back(first);
		for(int i=1;i<len;i++){
			vector<vector<string>> temp;
			for(unsigned int j=0;j<v[i-1].size();j++){
				vector<string> tempVec1(v[i-1][j]);
				if (tempVec1.back()==s.substr(i, 1)){
					vector<string> tempVec2(v[i-1][j]);
					tempVec2.pop_back();
					string str = tempVec1.back()+s[i];
					tempVec2.push_back(str);
					temp.push_back(tempVec2);
				}
				if (tempVec1.size()>1 && tempVec1[tempVec1.size()-2]==s.substr(i, 1)){
					vector<string> tempVec2(v[i-1][j]);
					string str = tempVec1[tempVec1.size()-2] + tempVec1.back()+s[i];
					tempVec2.pop_back();
					tempVec2.pop_back();
					tempVec2.push_back(str);
					temp.push_back(tempVec2);
				}
				tempVec1.push_back(s.substr(i, 1));
				temp.push_back(tempVec1);

			}
/*			if (i==1 && s[i-1]==s[i]) {
				string str = s.substr(0,2);
				vector<string> tempVec;
				tempVec.push_back(str);
				temp.push_back(tempVec);
			}
			else if (s[i-1]==s[i]){
				string str = s.substr(i-1,2);
				for(unsigned int j=0;j<v[i-2].size();j++){
					vector<string> tempVec(v[i-2][j]);
					tempVec.push_back(str);
					temp.push_back(tempVec);
				}
			}
			if (i==2 && s[i-2]==s[i]){
				string str = s.substr(0,3);
				vector<string> tempVec;
				tempVec.push_back(str);
				temp.push_back(tempVec);
			}
			else if (s[i-2]==s[i]){
				string str = s.substr(i-2,3);
				for(unsigned int j=0;j<v[i-3].size();j++){
					vector<string> tempVec(v[i-3][j]);
					tempVec.push_back(str);
					temp.push_back(tempVec);
				}
			}*/
			v.push_back(temp);
		}
		return v[len-1];
    }

#endif /* PALINDROMEPARTITION_H_ */

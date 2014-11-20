/*
 * LetterCombination.h
 *
 *  Created on: 2014-05-18
 *      Author: frye
 */

#ifndef LETTERCOMBINATION_H_
#define LETTERCOMBINATION_H_

#include "commonHeader.h"
	void letterCombinations(string digits, vector<char> &v, int pos, map<int, string> m, vector<string> &ret) {
		if (pos==digits.size()){
			string str(v.begin(), v.end());
			ret.push_back(str);
		}
		int num = digits[pos] - '0';
		for(int i=0;i<m[num].size();i++){
			v.push_back(m[num][i]);
			letterCombinations(digits, v, pos+1, m, ret);
			v.pop_back();
		}
	}

	vector<string> letterCombinations(string digits) {
		vector<char> v;
		vector<string> ret;
		if (digits.size()==0) {
			string str = "";
			ret.push_back(str);
			return ret;
		}
		map<int, string> m;
		m[2] = "abc";
		m[3] = "def";
		m[4] = "ghi";
		m[5] = "jkl";
		m[6] = "mno";
		m[7] = "pqrs";
		m[8] = "tuv";
		m[9] = "wxyz";
		letterCombinations(digits, v, 0, m, ret);
		return ret;
    }

#endif /* LETTERCOMBINATION_H_ */

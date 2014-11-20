/*
 * Anagrams.h
 *
 *  Created on: Sep 30, 2014
 *      Author: frye
 */

#ifndef ANAGRAMS_H_
#define ANAGRAMS_H_

#include "commonHeader.h"

	vector<string> anagrams(vector<string> &strs) {
		map<string, vector<string>> m;
		vector<string> ret;
		for(unsigned int i=0;i<strs.size();i++){
			string temp = strs[i];
			sort(temp.begin(), temp.end());
			vector<string> v = m[temp];
			v.push_back(strs[i]);
			m[temp] = v;
		}
		for(map<string, vector<string>>::iterator it=m.begin();it!=m.end();++it){
			vector<string> v = it->second;
			if (v.size()>1)
				for(unsigned int i=0;i<v.size();i++) ret.push_back(v[i]);
		}
		return ret;
    }

	vector<string> anagrams2(vector<string> &strs) {
		map<vector<int>, vector<string>> m;
		vector<string> ret;
		for(unsigned int i=0;i<strs.size();i++){
			vector<int> freq(26, 0);
			for(int j=0;j<strs[i].size();j++){
				int index = strs[i][j] - 'a';
				freq[index]++;
			}
			vector<string> v = m[freq];
			v.push_back(strs[i]);
			m[freq] = v;
		}
		for(map<vector<int>, vector<string>>::iterator it=m.begin();it!=m.end();++it){
			vector<string> v = it->second;
			if (v.size()>1)
				for(unsigned int i=0;i<v.size();i++) ret.push_back(v[i]);
		}
		return ret;
	}


#endif /* ANAGRAMS_H_ */

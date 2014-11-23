/*
 * SubstringwithConcatenationofAllWords.h
 *
 *  Created on: Nov 23, 2014
 *      Author: frye
 */

#ifndef SUBSTRINGWITHCONCATENATIONOFALLWORDS_H_
#define SUBSTRINGWITHCONCATENATIONOFALLWORDS_H_

#include "commonHeader.h"

    vector<int> findSubstring(string S, vector<string> &L) {
    	vector<int> ret;
    	if (S.empty() || L.empty()) return ret;
    	int len = L[0].size(), size = L.size();
    	unordered_map<string,int> m;
    	for(int i=0;i<size;i++) m[L[i]]++;
    	for(int i=0;i<len;i++){
    		unordered_map<string, int> copy(m);
    		int prev = 0;
    		for(int j=0;(j+1)*len+i<=(int)S.size();j++){
    			string word = S.substr(i+j*len,len);
    			if (copy.find(word)!=copy.end() && copy[word]>0) copy[word]--;
    			else if (!copy[word]){
    				string temp = S.substr(i+prev*len, len);
    				while(temp!=word){
    					copy[temp]++;
    					prev++;
    					temp = S.substr(i+prev*len, len);
    				}
    				prev++;
    			}
    			else {
    				prev = j+1;
    				copy = m;
    			}
    			if (j-prev+1==size) ret.push_back(prev*len+i);
    		}
    	}
    	return ret;
    }

//TLE
    vector<int> findSubstringSlow(string S, vector<string> &L) {
    	vector<int> ret;
    	if (S.empty() || L.empty()) return ret;
    	int len = L[0].size(), size = L.size();
    	unordered_map<string,int> m;
    	for(int i=0;i<size;i++) m[L[i]]++;
    	for(int i=0;i<=(int)S.size()-len*size;i++){
    		unordered_map<string, int> copy(m);
    		int j;
    		for(j=0;j<size;j++){
    			string word = S.substr(i+j*len,len);
    			if (copy.find(word)!=copy.end() && copy[word]>0) copy[word]--;
    			else break;
    		}
    		if (j==size) ret.push_back(i);
    	}
    	return ret;
    }

#endif /* SUBSTRINGWITHCONCATENATIONOFALLWORDS_H_ */

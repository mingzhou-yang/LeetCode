/*
 * LongestPalindromic.h
 *
 *  Created on: Nov 14, 2014
 *      Author: frye
 */

#ifndef LONGESTPALINDROMIC_H_
#define LONGESTPALINDROMIC_H_

#include "commonHeader.h"

    string longestPalindrome2(string s) {
    	int len = s.size();
    	vector<int> num(len, 1);
    	for(int i=0;i<len;i++){
    		for(int j=1;i-j>=0&&i+j<len;j++){
    			if (s[i-j]==s[i+j]) num[i] += 2;
    			else break;
    		}
    	}
    	for(int i=0;i<len-1;i++){
    		int length = 0;
    		if (s[i]==s[i+1]) length=2;
    		else continue;
    		for(int j=1;i-j>=0&&i+j+1<len;j++){
    			if (s[i-j]==s[i+j+1]) length+= 2;
    			else break;
    		}
    		num[i] = num[i]>length?num[i]:length;
    		num[i+1] = num[i+1]>length?num[i+1]:length;
    	}
    	int maxLen=0, pos;
    	for(int i=0;i<len;i++){
    		if (num[i]>maxLen){
    			pos = i;
    			maxLen = num[i];
    		}
    	}
    	if (num[pos]%2) return s.substr(pos-maxLen/2, maxLen);
    	else return s.substr(pos-maxLen/2+1, maxLen);
    }

    string Manacher(string s){
    	string ext = "";
    	for(int i=0;i<(int)s.size();i++) ext = ext + "#" + s[i];
    	ext = ext + "#";

    	vector<int> lenVec(ext.size(), 0);

    	int R=1, C=0;
    	for(int i=1;i<(int)ext.size();i++){
    		int mirror = 2*C - i;
    		if (lenVec[mirror]+i >= (int)ext.size()) lenVec[i] = lenVec[mirror];
    		else if (mirror<0 || lenVec[mirror] + i >= R) {
    			lenVec[i] = R - i;
    			while(i>=lenVec[i]+1 && ext[i+lenVec[i]+1]==ext[i-lenVec[i]-1]) lenVec[i]++;
    			R = i + lenVec[i];
    			C = i;
    		}
    		else lenVec[i] = lenVec[mirror];
    	}
    	int maxLen=0, pos=0;
    	for(int i=0;i<(int)ext.size();i++){
    		if (lenVec[i]>maxLen){
    			pos = i;
    			maxLen = lenVec[i];
    		}
    	}
    	string str = ext.substr(pos-maxLen, 2*maxLen+1);
    	string ret = "";
    	for(int i=0;i<(int)str.size();i++)
    		if (str[i]!='#') ret.push_back(str[i]);
    	return ret;
    }

    bool isPalindromic(string s){
    	for(int i=0, j=s.size()-1;i<j;i++,j--)
    		if (s[i]!=s[j]) return false;
    	return true;
    }

    int minCut(string s) {
    	int size = s.size();
    	vector<int> cut(size+1, 0);
    	for(int i=0;i<=size;i++) cut[i] = i-1;
    	for(int i=0;i<size;i++){
    		printVector(cut);
    		for(int j=0;i-j>=0&&i+j<size&&s[i+j]==s[i-j];j++)
    			cut[i+j+1] = cut[i+j+1]<cut[i-j]+1?cut[i+j+1]:cut[i-j]+1;
    		for(int j=0;i-j>=0&&i+j+1<size&&s[i+j+1]==s[i-j];j++)
    			cut[i+j+2] = cut[i+j+2]<cut[i-j]+1?cut[i+j+2]:cut[i-j]+1;
    	}
    	return cut[size];
    }

/*    int minCut(string s) {
    	if (s.empty()) return 0;
    	vector<string> v;
        for(int i=0;i<(int)s.size();i++){
        	int size = v.size();
        	if (v.empty()) {
        		string temp(1,s[i]);
        		v.push_back(temp);
        	}
        	else if (size==1) {
        		if (isPalindromic(v[0]+s[i])) v[0] = v[0] + s[i];
        		else{
            		string temp(1,s[i]);
            		v.push_back(temp);
        		}
        	}
        	else{
        		string s2 = v[size-2];
        		string s1 = v[size-1];
        		if (isPalindromic(s2+s1+s[i])){
        			v.pop_back();
        			v[size-2] = s2+s1+s[i];
        		}
        		else if (isPalindromic(s1+s[i])) v[size-1] = s1 + s[i];
        		else if(isPalindromic(s2.substr(0, s2.size()-1)) && isPalindromic(s2.back()+s1+s[i])){
        			v[size-2] = s2.substr(0,s2.size()-1);
        			v[size-1] = s2.back()+s1+s[i];
        		}
        		else{
        			string temp(1,s[i]);
        			v.push_back(temp);
        		}
        	}
        	printVector(v);
        }

        return v.size()-1;
    }*/



#endif /* LONGESTPALINDROMIC_H_ */

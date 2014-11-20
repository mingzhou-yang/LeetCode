/*
 * validPalindrome.h
 *
 *  Created on: Nov 12, 2014
 *      Author: frye
 */

#ifndef VALIDPALINDROME_H_
#define VALIDPALINDROME_H_

#include "commonHeader.h"

	bool isAlphanumeric(char c){
		if (c>='a'&&c<='z') return true;
		if (c>='A'&&c<='Z') return true;
		if (c>='0'&&c<='9') return true;
		else return false;
	}

    bool isPalindrome(string s) {
    	for(int i=0, j=s.size()-1;i<j;i++,j--){
    		if (!isAlphanumeric(s[i])) {
    			j++;
    			continue;
    		}
    		if (!isAlphanumeric(s[j])) {
    			i--;
    			continue;
    		}
    		if (s[i]>='A' && s[i]<='Z') s[i] = s[i]-'A'+'a';
    		if (s[j]>='A' && s[j]<='Z') s[j] = s[j]-'A'+'a';
    		if (s[i]!=s[j]) return false;
    	}
    	return true;
    }

#endif /* VALIDPALINDROME_H_ */

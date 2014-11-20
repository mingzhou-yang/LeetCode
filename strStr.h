/*
 * strStr.h
 *
 *  Created on: Nov 12, 2014
 *      Author: frye
 */

#ifndef STRSTR_H_
#define STRSTR_H_
#include <string.h>
#include "commonHeader.h"

    int strStr(char *haystack, char *needle) {
    	int n = strlen(haystack);
    	int m = strlen(needle);
        if (!m) return 0;
    	if (!n) return -1;
    	for(int i=0;i<=n-m;i++){
    		bool flag = true;
    		for(int j=0;j<m;j++){
    			if (haystack[i+j]!=needle[j]){
    				flag = false;
    				break;
    			}
    		}
    		if (flag) return i;
    	}
    	return -1;
    }

    int KMP(char *haystack, char *needle) {
    	int lenH = strlen(haystack);
    	int lenN = strlen(needle);
    	vector<int> prev(lenN, -1);
    	int j=0, k=-1;
    	while(j<lenN){
    		if (k==-1 || needle[k]==needle[j]) prev[++j] = ++k;
    		else k = prev[k];
    	}
    	for(j=0,k=0;j<lenH&&k<lenN;){
    		if (k==-1 || haystack[j]==needle[k]){
    			j++;
    			k++;
    		}
    		else k = prev[k];
    	}
    	if (!strncmp(haystack+j-k, needle, k)) return j-k;
    	else return -1;
    }

#endif /* STRSTR_H_ */

/*
 * ReverseWordsinString.h
 *
 *  Created on: Oct 7, 2014
 *      Author: frye
 */

#ifndef REVERSEWORDSINSTRING_H_
#define REVERSEWORDSINSTRING_H_

#include "commonHeader.h"

    void reverseWords(string &s) {
    	stack<string> words;
    	for(unsigned int i=0;i<s.size();i++){
    		bool flag = false;
    		while(i<s.size() && s[i]==' ') i++;
    		unsigned int j = i;
    		while(j<s.size() && s[j]!=' ') {
    			j++;
    			flag = true;
    		}
    		if (flag){
        		string str(s.begin()+i, s.begin()+j);
        		words.push(str);
        		i = j;
    		}
    	}
    	s = "";
    	while(!words.empty()){
    		s = s + words.top() + " ";
    		words.pop();
    	}
    	s = s.substr(0, s.size()-1);
    }

#endif /* REVERSEWORDSINSTRING_H_ */

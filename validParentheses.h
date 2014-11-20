/*
 * validParentheses.h
 *
 *  Created on: 2014-05-08
 *      Author: frye
 */

#ifndef VALIDPARENTHESES_H_
#define VALIDPARENTHESES_H_

#include "commonHeader.h"
	bool isValid(string s) {
		stack<char> st;
		for(unsigned int i=0;i<s.size();i++){
			if (s[i]=='('||s[i]=='['||s[i]=='{') st.push(s[i]);
			else if (s[i]==')'){
				if (st.empty()) return false;
				char c = st.top();
				st.pop();
				if (c!='(') return false;
			}
			else if (s[i]==']'){
				if (st.empty()) return false;
				char c = st.top();
				st.pop();
				if (c!='[') return false;
			}
			else if (s[i]=='}'){
				if (st.empty()) return false;
				char c = st.top();
				st.pop();
				if (c!='{') return false;
			}
			else return false;
		}
		if (st.empty()) return true;
		else return false;
    }

#endif /* VALIDPARENTHESES_H_ */

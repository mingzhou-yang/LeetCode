/*
 * LongestValidParentheses.h
 *
 *  Created on: Nov 25, 2014
 *      Author: frye
 */

#ifndef LONGESTVALIDPARENTHESES_H_
#define LONGESTVALIDPARENTHESES_H_

#include "commonHeader.h"

/*    int longestValidParentheses(string s) {
    	int left = 0, max = 0, cur = 0, prev = 0;
    	for(int i=0;i<(int)s.size();i++){
    		if (s[i]=='(') left++;
    		else if (s[i]==')' && left>0){
    			left--;
    			cur += 2;
    			max = cur>max ? cur : max;
    		}
    		else if (s[i]==')' && left<=0){
    			cur = 0;
    			left = 0;
    			prev = 0;
    		}
    		if (!left) {
    			prev += cur;
    			cur = 0;
    			max = prev>max ? prev : max;
    		}
    	}
    	return max;
    }*/

	void shrink(stack<int> &st){
		int sum = 0;
		while(!st.empty() && st.top()!=-1){
			sum += st.top();
			st.pop();
		}
		st.push(sum);
	}

	int longestValidParentheses(string s){
		int max = 0;
		stack<int> st;
		for(int i=0;i<(int)s.size();i++){
			if (s[i]=='(') st.push(-1);
			else if(s[i]==')'){
				int prev = 0;
				if (st.empty()) continue;
				if (st.top()!=-1) {prev = st.top(); st.pop();}
				if (st.empty()) continue;
				st.pop();
				shrink(st);
				if (!st.empty() && st.top()!=-1) st.top() += (2+prev);
				else st.push(2+prev);
				max = st.top()>max ? st.top() : max;
			}
		}
		return max;
	}

#endif /* LONGESTVALIDPARENTHESES_H_ */

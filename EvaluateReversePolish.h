/*
 * EvaluateReversePolish.h
 *
 *  Created on: Nov 24, 2014
 *      Author: frye
 */

#ifndef EVALUATEREVERSEPOLISH_H_
#define EVALUATEREVERSEPOLISH_H_

#include "commonHeader.h"

	int toInt(string s){
		int sign = 1;
		int num=0;
		for(int i=0;i<(int)s.size();i++){
			if (s[i]=='-') sign = -1;
			else{
				num *= 10;
				num += (int)(s[i]-'0');
			}
		}
		return sign*num;
	}

    int evalRPN(vector<string> &tokens) {
    	if (tokens.empty()) return 0;
    	stack<int> s;
    	s.push(toInt(tokens[0]));
    	for(int i=1;i<(int)tokens.size();i++){
    		if (tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
    			int num1 = s.top();
    			s.pop();
    			int num2 = s.top();
    			s.pop();
    			if (tokens[i]=="+") s.push(num1+num2);
    			else if (tokens[i]=="-") s.push(num2-num1);
    			else if (tokens[i]=="*") s.push(num1*num2);
    			else if (tokens[i]=="/") s.push(num2/num1);
    		}
    		else s.push(toInt(tokens[i]));
    	}
    	return s.top();
    }



#endif /* EVALUATEREVERSEPOLISH_H_ */

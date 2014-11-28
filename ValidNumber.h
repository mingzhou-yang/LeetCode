/*
 * ValidNumber.h
 *
 *  Created on: Nov 27, 2014
 *      Author: frye
 */

#ifndef VALIDNUMBER_H_
#define VALIDNUMBER_H_

#include "commonHeader.h"

    bool isNumber(const char *s) {
    	int state = 0;
    	bool flag = false;
    	int len = strlen(s);
    	int begin, end;
    	for(begin=0;begin<len&&s[begin]==' ';begin++) {}
    	for(end=begin;end<len&&s[end]!=' ';end++) {}
    	string str(s+begin, s+end);
    	for(;end<len;end++)
    		if (s[end]!=' ') return false;

    	for(int i=0;i<(int)str.size();i++){
    		switch(state){
    		case 0:
    			if (str[i]>='0'&&str[i]<='9') state = 2;
    			else if (str[i]=='+'||str[i]=='-') state = 1;
    			else if (str[i]=='.') state = 6;
    			else return false;
    			break;
    		case 1:
    			if (str[i]>='0'&&str[i]<='9') state = 2;
    			else if (str[i]=='.') state = 6;
    			else return false;
    			break;
    		case 2:
    		    flag = true;
    			if (str[i]>='0'&&str[i]<='9') state = 2;
    			else if (str[i]=='.') state = 6;
    			else if (str[i]=='e') state = 3;
    			else return false;
    			break;
    		case 3:
    			if (str[i]>='0'&&str[i]<='9') state = 5;
    			else if (str[i]=='+'||str[i]=='-') state = 4;
    			else return false;
    			break;
    		case 4:
    			if (str[i]>='0'&&str[i]<='9') state = 5;
    			else return false;
    			break;
    		case 5:
    			if (str[i]>='0'&&str[i]<='9') state = 5;
    			else return false;
    			break;
    		case 6:
    			if (str[i]>='0'&&str[i]<='9') state = 7;
    			else if (str[i]=='e') state = 3;
    			else return false;
    			break;
    		case 7:
    			if (str[i]>='0'&&str[i]<='9') state = 7;
    			else if (str[i]=='e') state = 3;
    			else return false;
    			break;
    		default:
    			return false;
    		}
    	}
    	cout<<flag<<" "<<state<<endl;
    	return (state==2||state==5||(flag&&state==6)||state==7);
    }

#endif /* VALIDNUMBER_H_ */

/*
 * DecodeWays.h
 *
 *  Created on: Nov 26, 2014
 *      Author: frye
 */

#ifndef DECODEWAYS_H_
#define DECODEWAYS_H_

#include "commonHeader.h"

    int numDecodings(string s) {
    	if (s.empty() || s[0]=='0') return 0;
    	int size = (int)s.size();
    	vector<int> v(size+1, 1);
    	for(int i=0;i<size-1;i++) if (s[i+1]=='0' && (s[i]>'2'||s[i]<'1')) return 0;
    	for(int i=size-2;i>=0;i--){
    		if (s[i]=='0' || s[i+1]=='0' || (i==size-2?false:(s[i+2]=='0'))) {
    			v[i] = v[i+1];
    			continue;
    		}
    		if ((s[i]-'0')*10+s[i+1]-'0'<=26){
    			v[i] = v[i+2]+v[i+1];
    		}
    		else v[i] = v[i+1];
    	}
    	return v[0];
    }

#endif /* DECODEWAYS_H_ */

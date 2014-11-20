/*
 * SimplifyPath.h
 *
 *  Created on: Nov 19, 2014
 *      Author: frye
 */

#ifndef SIMPLIFYPATH_H_
#define SIMPLIFYPATH_H_

#include "commonHeader.h"

    string simplifyPath(string path) {
        vector<string> vec;
        string ret = "";
        if (path.empty()) return ret;
        int prev = 0;
        for(int i=0;i<=(int)path.size();i++){
        	if (i==(int)path.size() || path[i]=='/'){
        		string str(path.begin()+prev, path.begin()+i);
        		prev = i;
        		if (str=="/.." && !vec.empty()) vec.pop_back();
        		else if (str!="/" && str!="/." && str!="/..") vec.push_back(str);
//        		cout<<str<<endl;
        	}
        }
        for(int i=0;i<(int)vec.size();i++) ret = ret+vec[i];
        return ret==""?"/":ret;
    }

#endif /* SIMPLIFYPATH_H_ */

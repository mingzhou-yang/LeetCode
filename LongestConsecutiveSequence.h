/*
 * LongestConsecutiveSequence.h
 *
 *  Created on: 2014-05-10
 *      Author: frye
 */

#ifndef LONGESTCONSECUTIVESEQUENCE_H_
#define LONGESTCONSECUTIVESEQUENCE_H_

#include "commonHeader.h"
#define visited 2
#define unvisited 1

	int longestConsecutive(vector<int> &num) {
		map<int, int> m;
		for(int i=0;i<num.size();i++) m[num[i]] = unvisited;
		int longest = 0;
		for(int i=0;i<num.size();i++){
			if (m[num[i]]==visited) continue;
			m[num[i]] = visited;
			int before=num[i]-1, after=num[i]+1;
			int bef = m[before], aft = m[after];
			while(bef==unvisited||aft==unvisited){
				if (bef==unvisited){
					m[before] = visited;
					bef = m[--before];
				}
				if (aft==unvisited){
					m[after] = visited;
					aft = m[++after];
				}
			}
			int len = after - before - 1;
			if (len>longest) longest = len;
		}
		return longest;
    }

#endif /* LONGESTCONSECUTIVESEQUENCE_H_ */

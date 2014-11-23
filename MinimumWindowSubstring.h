/*
 * MinimumWindowSubstring.h
 *
 *  Created on: Nov 21, 2014
 *      Author: frye
 */

#ifndef MINIMUMWINDOWSUBSTRING_H_
#define MINIMUMWINDOWSUBSTRING_H_

#include "commonHeader.h"

/*    string minWindow(string S, string T) {
    	if (S.empty()&&T.empty()) return "";
    	if (S.size()<T.size()) return "";

//    	cout<<S<<endl;
//    	for(int i=0;i<S.size();i++) cout<<i;
//    	cout<<endl;
    	unordered_map<char, int> m;
    	for(int i=0;i<(int)T.size();i++) m[T[i]]++;
    	int min=(int)S.size()+1, count=0, prev=0, start;

    	for(int i=0;i<(int)S.size();i++){
    		if (i-prev>=min)
    			if (m.find(S[prev])!=m.end()&&m[S[prev++]]++ >= 0) count--;
    		while(m.find(S[prev])==m.end() || m[S[prev]]<0) {
    			if (m[S[prev]]<0) m[prev]++;
    			prev++;
    		}
//    		cout<<prev<<" "<<i<<" "<<min<<" "<<m['A']<<" "<<m['B']<<" "<<m['C']<<" "<<count<<endl;
    		if (m.find(S[i])!=m.end()) {
    			if (m[S[i]]<=0 && S[i]==S[prev]) prev++;
    			else if (m[S[i]]<=0) m[S[i]]--;
    			else {m[S[i]]--; count++;}
    		}
    		if (count==(int)T.size() && i+1-prev<min) {
    			start = prev;
    			min = i-prev+1;
    			if (m[S[prev++]]++ >= 0) count--;
    			cout<<prev<<endl;
    			while(m.find(S[prev])==m.end()) prev++;
    		}
    	}
    	if (min==(int)S.size()+1) return "";
    	else return S.substr(start, min);
    }*/

    string minWindow(string S, string T) {
    	if (S.empty()&&T.empty()) return "";
    	if (S.size()<T.size()) return "";

    	unordered_map<char, int> m;
    	for(int i=0;i<(int)T.size();i++) m[T[i]]++;
    	int min=(int)S.size()+1, count=0, prev=0, start;

    	for(int i=0;i<(int)S.size();i++){
    		if (m.find(S[i])!=m.end()) {
    			if (m[S[i]]<=0) m[S[i]]--;
    			else {m[S[i]]--; count++;}
    		}
    		cout<<prev<<" "<<i<<" "<<min<<" "<<m['A']<<" "<<m['B']<<" "<<m['C']<<" "<<count<<endl;
    		if (count==(int)T.size()) {
    			while(prev<i){
    				if (m.find(S[prev])==m.end()) prev++;
    				else if (m[S[prev]]<0) m[S[prev++]]++;
    				else break;
    			}
    			if(i+1-prev<min){
					start = prev;
					min = i-prev+1;
    			}
    			m[S[prev++]]++;
    			count--;
    		}
    	}
    	if (min==(int)S.size()+1) return "";
    	else return S.substr(start, min);
    }


#endif /* MINIMUMWINDOWSUBSTRING_H_ */

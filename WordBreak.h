/*
 * WordBreak.h
 *
 *  Created on: Oct 6, 2014
 *      Author: frye
 */

#ifndef WORDBREAK_H_
#define WORDBREAK_H_

#include "commonHeader.h"

/*	bool wordBreak(string s, unordered_set<string> &dict, vector<vector<bool>> &v, bool rec[], int start){
		cout<<start<<endl;
		int size = s.size();
		for(int i=size-1;i>=0;i--){
			string str(s.begin()+i, s.end());
			unordered_set<string>::iterator it= dict.find(str);
			if (it != dict.end()) rec[i+start] = true;
			for(int j=i+1;j<size;j++){
				if (rec[j+start]){
					if (v[i+start][j+start]){
						rec[i+start] = true;
						break;
					}
					string temp(s.begin()+i+start, s.begin()+j+start);
					if (wordBreak(temp, dict, v, rec, start+i)) {
						rec[i+start] = true;
						v[i+start][j+start] = true;
						break;
					}
				}
			}
		}
		return rec[0];
	}

	bool wordBreak(string s, unordered_set<string> &dict) {
		int size = s.size();
		vector<bool> row(size, false);
		vector<vector<bool>> v(size, row);
		bool *rec = new bool[size];
		for(int i=0;i<size;i++) rec[i] = false;
		return wordBreak(s, dict, v, rec, 0);
    }*/

	bool wordBreak2(string s, unordered_set<string> &dict) {
		int size = s.size();
		vector<bool> row(size+1, false);
		vector<vector<bool>> v(size, row);
		for(int i=0;i<size;i++){
			for(int j=i+1;j<=size;j++){
				string str(s.begin()+i, s.begin()+j);
				unordered_set<string>::iterator it= dict.find(str);
				if (it != dict.end()) v[i][j] = true;
			}
		}
		bool *rec = new bool[size+1];
		for(int i=1;i<size+1;i++) rec[i]=false;
		rec[0] = true;
		for(int i=0;i<size;i++){
			if (rec[i]){
				for(int j=i+1;j<=size;j++) if (v[i][j]) rec[j] = true;
			}
		}
		return rec[size];
	}

	vector<string> wordBreak(string s, unordered_set<string> &dict, vector<vector<bool>> &v, vector<vector<string>> &words, int start){
//		cout<<start<<endl;
		for(unsigned int i=start;i<=s.size();i++){
			if (v[start][i]){
				string str(s.begin()+start, s.begin()+i);
				if (i==s.size()) words[start].push_back(str);
				else if (words[i].empty()) wordBreak(s, dict, v, words, i);
				for(unsigned int j=0;j<words[i].size();j++) words[start].push_back(str+" "+words[i][j]);
			}
		}
		return words[start];
	}

	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		int size = s.size();
		vector<bool> row(size+1, false);
		vector<vector<bool>> v(size, row);
		for(int i=0;i<size;i++){
			for(int j=i+1;j<=size;j++){
				string str(s.begin()+i, s.begin()+j);
				unordered_set<string>::iterator it= dict.find(str);
				if (it != dict.end()) v[i][j] = true;
			}
		}
		vector<string> row2;
		vector<vector<string>> words(size+1, row2);
		wordBreak(s, dict, v, words, 0);
		return words[0];
	}


	//Solution from leetcode, fast in oj system but slow in my eclipse
	        bool wordBreakImpl(string s, unordered_set<string> &dict, vector<string> &path, unordered_map<string, bool> &memory, vector<string> &ret)
	        {
	            if(s.size() == 0)
	            {
	                string one;
	                for(int i = 0; i < path.size(); i++)
	                {
	                    if(i == 0)
	                        one = path[i];
	                    else
	                        one += " " + path[i];
	                }
	                ret.push_back(one);
	                return true;
	            }
	            else
	            {
	                if(memory.find(s) != memory.end() && memory[s] == false)
	                    return false;

	                int result = false;
	                for(int i = 0; i < s.size(); i++)
	                {
	                    string word = s.substr(0, i+1);
	                    if(dict.find(word) != dict.end())
	                    {
	                        path.push_back(word);

	                        if(wordBreakImpl(s.substr(i+1), dict, path, memory, ret))
	                            result = true;

	                        path.pop_back();
	                    }
	                }
	                memory[s] = result;
	                return memory[s];
	            }
	        }

	        vector<string> wordBreak1(string s, unordered_set<string> &dict) {

	            vector<string> ret;
	            vector<string> path;
	            unordered_map<string, bool> memory;
	            wordBreakImpl(s, dict, path, memory, ret);

	            return ret;
	        }


#endif /* WORDBREAK_H_ */

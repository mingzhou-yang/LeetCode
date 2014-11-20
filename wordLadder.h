/*
 * wordLadder.h
 *
 *  Created on: 2014-04-21
 *      Author: frye
 */

#ifndef WORDLADDER_H_
#define WORDLADDER_H_

#include "commonHeader.h"

using namespace std;

typedef struct node* pNode;
typedef map<string, pNode> Map;

struct node{
	string word;
	vector<pNode> neighbors;
	pNode pre;
};

int getDistance(string a, string b){
	int size = a.size();
	int dist = 0;
	for(int i=0;i<size;i++){
		if (a[i]!=b[i]) dist++;
	}
	return dist;
}

int ladderLength(string start, string end, unordered_set<string> &dict) {
	Map myMap;
	map<string, bool> record;
	for(unordered_set<string>::iterator it=dict.begin();it!=dict.end();++it)
	{
		node *n = new node;
		n->word = *it;
		myMap[*it] = n;
	}
	node *s = new node;
	s->word = start;
	node *e = new node;
	e->word = end;
	myMap[start] = s;
	myMap[end] = e;
	for(Map::iterator it=myMap.begin();it!=myMap.end();++it)
	{
		record[it->first] = false;
		for(Map::iterator it2=myMap.begin();it2!=it;++it2){
			if (getDistance(it->first, it2->first)==1) {
				it->second->neighbors.push_back(it2->second);
				it2->second->neighbors.push_back(it->second);
			}
		}
	}

	queue<string> q;
	q.push(start);
	while(!q.empty()){
		string s = q.front();
		q.pop();
		for(vector<pNode>::iterator it=myMap[s]->neighbors.begin();it!=myMap[s]->neighbors.end();++it){
			if (!record[(*it)->word]){
				record[(*it)->word] = true;
				q.push((*it)->word);
				myMap[(*it)->word]->pre = myMap[s];
			}
		}
	}
	if (myMap[end]->pre==NULL) return -1;
	int dist = 2;
	pNode p = myMap[end];
	while(true){
		if (p->pre!=myMap[start]){
			p = p->pre;
			dist++;
		}
		else break;
	}
	return dist;
}

//For word ladder II
	void findPath(string start, string end, vector<string> &v,
			unordered_map<string, vector<string>> &next, vector<vector<string>> &ret){
		v.push_back(start);
		if (start==end) ret.push_back(v);
		for(int i=0;i<(int)next[start].size();i++) findPath(next[start][i], end, v, next, ret);
		v.pop_back();
	}

	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		vector<vector<string>> ret;
		unordered_map<string, int> count;
		unordered_map<string, vector<string>> next;
		queue<string> q;
		dict.insert(end);
		q.push(start);
		count[start] = 0;
		while(!q.empty()){
			string s = q.front();
			q.pop();
			for(int i=0;i<(int)s.size();i++){
				string front(s.begin(),s.begin()+i);
				string back(s.begin()+i+1, s.end());
				for(char c='a';c<='z';c++){
					if (c==s[i]) continue;
					string word = front + c + back;
					if (dict.find(word)!=dict.end() && (count.find(word)==count.end()||count[word]==count[s]+1)){
						if (count.find(word)==count.end()) q.push(word);
						count[word] = count[s]+1;
						next[s].push_back(word);
					}
				}
			}
		}
//		printVector(next[start]);
		vector<string> v;
		findPath(start, end, v, next, ret);
		return ret;
	}

	    void getPath(string &start, string &end, unordered_set<string> &dict,
	            unordered_map<string, unordered_set<string>> &father, vector<vector<string>> &ret, vector<string> &path) {
	        path.push_back(start);
	        if (start == end) {
	            ret.push_back(vector<string>(path.rbegin(), path.rend()));
	        } else {
	            for (auto e : father[start]) {
	                getPath(e, end, dict, father, ret, path);
	            }
	        }
	        path.pop_back();
	    }

	    void bfs(string &start, string &end, unordered_set<string> &dict,
	            vector<vector<string>> &ret) {
	        size_t len = start.size();
	        if (len != end.size() || len == 0 || start == end) return; // invalid

	        unordered_set<string> used;
	        unordered_set<string> levelUsed;
	        unordered_map<string, unordered_set<string>> father; // use it to get path

	        queue<string> q;
	        q.push(start);
	        int levelSize = 1;
	        bool found = false;

	        while (!q.empty()) {
	            string cur = q.front();
	            string t(cur);
	            q.pop();
	            levelSize--;

	            for (size_t i = 0; i < len; i++) {
	                for (char c = 'a'; c <= 'z'; c++) {
	                    if (t[i] == c) continue; // itself

	                    t[i] = c;
	                    if (t == end) { // find it
	                        found = true;
	                        father[t].insert(cur);
	                        break;
	                    }

	                    // t is not used and is in the dict
	                    if (used.count(t) == 0 && dict.count(t) != 0) {
	                        //q.push(t);
	                        levelUsed.insert(t);
	                        father[t].insert(cur);
	                    }
	                }
	                t[i] = cur[i]; // reset t to cur
	            }

	            if (levelSize == 0) { // finish one level
	                if (found) break;
	                for (auto e : levelUsed) {used.insert(e); q.push(e);}
	                levelSize = q.size();
	                levelUsed.clear();
	            }
	        }

	        if (found) {
	            vector<string> path;
	            getPath(end, start, dict, father, ret, path);
	        }

	    }

	    vector<vector<string>> findLadders2(string &start, string &end, unordered_set<string> &dict) {
	        vector<vector<string>> ret;
	        bfs(start, end, dict, ret);
	        return ret;
	    }

#endif /* WORDLADDER_H_ */

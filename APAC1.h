/*
 * APAC1.h
 *
 *  Created on: Oct 28, 2014
 *      Author: frye
 */

#ifndef APAC1_H_
#define APAC1_H_

#include "commonHeader.h"
#include <fstream>

void storeCredit(){
	fstream input("A-large-practice.in");
	int testSize;
	input >> testSize;
	for (int i=0;i<testSize;i++){
		map<int, int> m;
		int credit, listSize;
		input >> credit >> listSize;
		for (int j=0;j<listSize;j++){
			int temp;
			input >> temp;
			if (m[credit-temp]){
				cout<<"Case #"<<i+1<<": "<<m[credit-temp]<<" "<<j+1<<endl;
			}
			else m[temp] = j+1;
		}
	}
	input.close();
}

vector<string> split(string s, char c){
	vector<string> ret;
	if (s.empty()) return ret;
	string temp;
	for(unsigned int i=0;i<s.length();i++){
		if (s[i]==c && !temp.empty()) {
			ret.push_back(temp);
			temp = "";
		}
		else if (s[i]!=c)
			temp = temp + s[i];
	}
	if (!temp.empty()) ret.push_back(temp);
	return ret;
}

vector<string> reverseSplit(string s, char c){
	vector<string> ret;
	if (s.empty()) return ret;
	string temp;
	for(unsigned int i=0;i<s.length();i++){
		if (s[i]==c && !temp.empty()) {
			ret.push_back(temp);
			temp = "";
		}
		else if (s[i]!=c)
			temp = temp + s[i];
	}
	if (!temp.empty()) ret.push_back(temp);
	return ret;
}

void reverseWord(){
	ifstream input("B-large-practice.in");
	int testSize;
	input >> testSize;
	string s;
	int i=1;
	while(getline(input, s)){
		if (!s.empty()){
			vector<string> words = split(s, ' ');
			cout<<"Case #"<<i++<<": ";
			for(int i=words.size()-1;i>0;i--) cout<<words[i]<<" ";
			cout<<words[0]<<endl;
		}
	}
}

void revealNeighbour(vector<vector<bool>> &mineMap, vector<vector<bool>> &safeMap, int j, int k){
	if (mineMap[j][k]) return;
	mineMap[j][k] = true;
	if (safeMap[j][k]){
		revealNeighbour(mineMap, safeMap, j-1, k-1);
		revealNeighbour(mineMap, safeMap, j-1, k);
		revealNeighbour(mineMap, safeMap, j-1, k+1);
		revealNeighbour(mineMap, safeMap, j, k-1);
		revealNeighbour(mineMap, safeMap, j, k+1);
		revealNeighbour(mineMap, safeMap, j+1, k-1);
		revealNeighbour(mineMap, safeMap, j+1, k);
		revealNeighbour(mineMap, safeMap, j+1, k+1);
	}
}

void Minesweeper(){
//	ifstream input("B-large-practice.in");
	ifstream input("A-large-practice.in");
	ofstream output("output.txt");
	int testSize;
	input >> testSize;
	for (int i=0;i<testSize;i++){
		int len;
		int counter=0;
		input >> len;
		vector<bool> row(len+2, false);
		vector<vector<bool>> mineMap(len+2, row);
		vector<vector<bool>> safeMap(len+2, row);
		for(int j=1;j<=len;j++){
			for(int k=1;k<=len;k++){
				char c;
				input >> c;
				if (c=='*') mineMap[j][k] = true;
			}
		}
//		printVecVector(mineMap);
//		cout<<"-------------------"<<endl;
		for(int j=1;j<=len;j++){
			for(int k=1;k<=len;k++){
				if (!mineMap[j-1][k-1] && !mineMap[j-1][k] && !mineMap[j-1][k+1] &&
						!mineMap[j][k-1] && !mineMap[j][k] && !mineMap[j][k+1] &&
						!mineMap[j+1][k-1] && !mineMap[j+1][k] && !mineMap[j+1][k+1])
					safeMap[j][k] = true;
			}
		}
//		printVecVector(safeMap);
//		cout<<"-------------------"<<endl;
		for(int j=1;j<=len;j++){
			for(int k=1;k<=len;k++){
				if (safeMap[j][k] && !mineMap[j][k]) {
					revealNeighbour(mineMap, safeMap, j, k);
					counter++;
				}
			}
		}
//		printVecVector(mineMap);
		for(int j=1;j<=len;j++){
			for(int k=1;k<=len;k++){
				if (!mineMap[j][k]) counter++;
			}
		}
		output<<"Case #"<<i+1<<": "<<counter<<endl;
	}
	input.close();
	output.close();
}



#endif /* APAC1_H_ */

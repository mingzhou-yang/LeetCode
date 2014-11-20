/*
 * NQueens.h
 *
 *  Created on: 2014-04-26
 *      Author: frye
 */

#ifndef NQUEENS_H_
#define NQUEENS_H_

#include "commonHeader.h"
typedef vector<vector<string> > vecStr;

	void NQueenSub(int cur, int n, int pos[], vecStr &v){
		bool *record = new bool[n];
		for(int j=0;j<cur;j++){
			int diff = cur - j;
			if (pos[j]-diff>=0) record[pos[j]-diff] = true;
			if (pos[j]+diff<n) record[pos[j]+diff] = true;
			record[pos[j]] = true;
		}
		for(int i=0;i<n;i++){
			pos[cur] = i;
			if (!record[i]){
				if (cur+1==n) {
					vector<string> temp;
					for(int k=0;k<n;k++){
						string front(pos[k], '.');
						string back(n-pos[k]-1, '.');
						string s = front+'Q'+back;
						temp.push_back(s);
					}
					v.push_back(temp);
					break;
				}

				NQueenSub(cur+1, n, pos, v);
			}
		}
	}


	vecStr solveNQueens(int n) {
        vector<vector<string> > v;
        int *pos = new int[n];
        NQueenSub(0, n, pos, v);
		return v;
    }


	int totalNQueenSub(int cur, int n, int pos[], int sum){
			int newsum = sum;
			bool *record = new bool[n];
			for(int j=0;j<cur;j++){
				int diff = cur - j;
				if (pos[j]-diff>=0) record[pos[j]-diff] = true;
				if (pos[j]+diff<n) record[pos[j]+diff] = true;
				record[pos[j]] = true;
			}
			for(int i=0;i<n;i++){
				pos[cur] = i;
				if (!record[i]){
					if (cur+1==n)
						return sum+1;
					newsum = totalNQueenSub(cur+1, n, pos, newsum);
				}
			}

			return newsum;
	}

	int totalNQueens(int n){
        int *pos = new int[n];
        return totalNQueenSub(0, n, pos, 0);
	}

#endif /* NQUEENS_H_ */

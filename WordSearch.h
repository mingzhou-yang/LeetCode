/*
 * WordSearch.h
 *
 *  Created on: Nov 26, 2014
 *      Author: frye
 */

#ifndef WORDSEARCH_H_
#define WORDSEARCH_H_

#include "commonHeader.h"

	bool wordSearch(vector<vector<char> > &board, vector<vector<bool>> &visited,
			int x, int y, string word, int pos){
		if (pos==(int)word.size()-1) return true;
		visited[x][y] = true;
		if (x>0 && board[x-1][y]==word[pos+1] && !visited[x-1][y] &&
				wordSearch(board, visited, x-1, y, word, pos+1)){
			visited[x][y] = false;
			return true;
		}
		if (x<(int)board.size()-1 && board[x+1][y]==word[pos+1] && !visited[x+1][y] &&
				wordSearch(board, visited, x+1, y, word, pos+1)){
			visited[x][y] = false;
			return true;
		}
		if (y>0 && board[x][y-1]==word[pos+1] && !visited[x][y-1] &&
				wordSearch(board, visited, x, y-1, word, pos+1)){
			visited[x][y] = false;
			return true;
		}
		if (y<(int)board[0].size()-1 && board[x][y+1]==word[pos+1] && !visited[x][y+1] &&
				wordSearch(board, visited, x, y+1, word, pos+1)){
			visited[x][y] = false;
			return true;
		}
		visited[x][y] = false;
		return false;
	}

    bool exist(vector<vector<char> > &board, string word) {
    	if (word.empty()) return true;
    	if (board.empty()) return false;
    	if (board[0].empty()) return false;
    	int h = board.size(), w = board[0].size();
    	vector<vector<bool>> visited(h, vector<bool>(w, false));
    	for(int i=0;i<h;i++)
    		for(int j=0;j<w;j++)
    			if (board[i][j]==word[0] && wordSearch(board, visited, i, j, word, 0))
    				return true;
    	return false;
    }

#endif /* WORDSEARCH_H_ */

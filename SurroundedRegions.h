/*
 * SurroundedRegions.h
 *
 *  Created on: Nov 19, 2014
 *      Author: frye
 */

#ifndef SURROUNDEDREGIONS_H_
#define SURROUNDEDREGIONS_H_

#include "commonHeader.h"

    void BoundaryCheck(int i, int j, vector<vector<char> > &board){
        int h = board.size();
        int w = board[0].size();
        queue<pair<int, int> > q;
        q.push(make_pair(i, j));
        board[i][j] = 'B';
        while(!q.empty()){
        	pair<int,int> p = q.front();
        	q.pop();
        	int x = p.first, y = p.second;
        	if (x+1<h&&board[x+1][y]=='O') {q.push(make_pair(x+1, y)); board[x+1][y]='B';}
        	if (x-1>=0&&board[x-1][y]=='O') {q.push(make_pair(x-1, y)); board[x-1][y]='B';}
        	if (y+1<w&&board[x][y+1]=='O') {q.push(make_pair(x, y+1)); board[x][y+1]='B';}
        	if (y-1>=0&&board[x][y-1]=='O') {q.push(make_pair(x, y-1)); board[x][y-1]='B';}
        }
    }


    void solve(vector<vector<char> > &board) {
        int h = board.size();
        if (!h) return;
        int w = board[0].size();
        if (!w) return;

        for(int i=0;i<h;i++){
        	if (board[i][0]=='O')  BoundaryCheck(i, 0, board);
        	if (board[i][w-1]=='O') BoundaryCheck(i, w-1, board);
        }
        for(int i=0;i<w;i++){
        	if (board[0][i]=='O') BoundaryCheck(0, i, board);
        	if (board[h-1][i]=='O') BoundaryCheck(h-1, i, board);
        }

        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if (board[i][j]=='O') board[i][j] = 'X';
                else if(board[i][j]=='B') board[i][j] = 'O';
            }
        }
    }

#endif /* SURROUNDEDREGIONS_H_ */

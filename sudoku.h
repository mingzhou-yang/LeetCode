/*
 * sudoku.h
 *
 *  Created on: Nov 16, 2014
 *      Author: frye
 */

#ifndef SUDOKU_H_
#define SUDOKU_H_

#include "commonHeader.h"
    bool solveSudokuHelper(vector<vector<int> > &board) {
    	int size = board.size();
    	for(int i=0;i<size;i++){
    		for(int j=0;j<size;j++){
    			if (board[i][j]==0){
    				vector<bool> rec(size+1, false);
    				for(int k=0;k<size;k++){
    					if (board[i][k]!=0) rec[board[i][k]] = true;
    					if (board[k][j]!=0) rec[board[k][j]] = true;
    				}
    				int boxSize = sqrt(size);
    				int rowNum = i/boxSize;
   					int colNum = j/boxSize;
   					for(int k=rowNum*boxSize;k<(rowNum+1)*boxSize;k++){
   						for(int n=colNum*boxSize;n<(colNum+1)*boxSize;n++){
   							if (board[k][n]!=0) rec[board[k][n]] = true;
   						}
   					}
   					for(int k=1;k<=size;k++){
   						if(rec[k]==false){
   							board[i][j] = k;
   							if (solveSudokuHelper(board)) return true;
   						}
   					}
   					board[i][j] = 0;
   					return false;
    			}
    		}
    	}
    	return true;
    }

    void solveSudoku(vector<vector<int> > &board) {
    	solveSudokuHelper(board);
    }

	void reader(){
		int size = 9;
		ifstream input("input.txt");
		if (!input.is_open()){
			cout<<"error open file"<<endl;
			return;
		}
		vector<vector<int>> sudo;
		for(int i=0;i<size;i++){
			vector<int> row;
			for(int j=0;j<size;j++){
				int c;
				input >> c;
				row.push_back(c);
			}
			sudo.push_back(row);
		}
		printVecVector(sudo);
		solveSudoku(sudo);
		printVecVector(sudo);
	}

/*    bool solveSudokuHelper(vector<vector<char> > &board) {
    	int size = board.size();
    	for(int i=0;i<size;i++){
    		for(int j=0;j<size;j++){
    			if (board[i][j]=='.'){
    				vector<bool> rec(size+1, false);
    				for(int k=0;k<size;k++){
    					if (board[i][k]!='.') rec[board[i][k]-'0'] = true;
    					if (board[k][j]!='.') rec[board[k][j]-'0'] = true;
    				}
    				int boxSize = sqrt(size);
    				int rowNum = i/boxSize;
   					int colNum = j/boxSize;
   					for(int k=rowNum*boxSize;k<(rowNum+1)*boxSize;k++){
   						for(int n=colNum*boxSize;n<(colNum+1)*boxSize;n++){
   							if (board[k][n]!='.') rec[board[k][n]-'0'] = true;
   						}
   					}
   					for(int k=1;k<=size;k++){
   						if(rec[k]==false){
   							board[i][j] = k + '0';
   							if (solveSudokuHelper(board)) return true;
   						}
   					}
   					board[i][j] = '.';
   					return false;
    			}
    		}
    	}
    	return true;
    }

    void solveSudoku(vector<vector<char> > &board) {
    	solveSudokuHelper(board);
    }

	void reader(int size){
		ifstream input("input.txt");
		if (!input.is_open()){
			cout<<"error open file"<<endl;
			return;
		}
		vector<vector<char>> sudo;
		for(int i=0;i<size;i++){
			vector<char> row;
			for(int j=0;j<size;j++){
				char c;
				input >> c;
				row.push_back(c);
			}
			sudo.push_back(row);
		}

		solveSudoku(sudo);
		printVecVector(sudo);
	}*/

#endif /* SUDOKU_H_ */

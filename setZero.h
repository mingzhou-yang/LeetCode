/*
 * setZero.h
 *
 *  Created on: 2014-04-30
 *      Author: frye
 */

#ifndef SETZERO_H_
#define SETZERO_H_
void setZeroes(vector<vector<int> > &matrix) {
        int height = matrix.size();
        int width = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;

        for(int i=0;i<height;i++){
            if (matrix[i][0]==0){
                firstColZero = true;
                break;
            }
        }

        for(int i=0;i<width;i++){
            if (matrix[0][i]==0){
                firstRowZero = true;
                break;
            }
        }
        for(int i=1;i<height;i++){
            for(int j=0;j<width;j++)
                if (matrix[i][j]==0){
                    matrix[i][0] = 0;
                }
        }

        for(int i=1;i<width;i++){
            for(int j=0;j<height;j++)
                if (matrix[j][i]==0){
                    matrix[0][i] = 0;
                }
        }
        for(int i=1;i<height;i++){
            if (matrix[i][0]==0)
                for(int j=1;j<width;j++)
                    matrix[i][j] = 0;
        }

        for(int i=1;i<width;i++){
            if (matrix[0][i]==0)
                for(int j=1;j<height;j++)
                    matrix[j][i] = 0;
        }

        if (firstRowZero)
            for(int i=0;i<width;i++) matrix[0][i] = 0;

        if (firstColZero)
            for(int i=0;i<height;i++) matrix[i][0] = 0;
    }

#endif /* SETZERO_H_ */

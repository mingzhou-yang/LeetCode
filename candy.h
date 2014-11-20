/*
 * candy.h
 *
 *  Created on: Nov 11, 2014
 *      Author: frye
 */

#ifndef CANDY_H_
#define CANDY_H_

#include "commonHeader.h"

/*    int candy(vector<int> &ratings) {
 		int size = (int)ratings.size();
    	if (size==0) return 0;
    	vector<int> num(size, 1);
    	int i;
 		for(i=0;i<size-1 && ratings[i]<ratings[i+1];i++) num[i+1] = num[i] + 1;
// 		printVector(num);
    	for(i=i+1;i<size;){
    		while (i<size && ratings[i]<ratings[i-1]) i++;
    		cout<<i<<endl;
    		if (ratings[i]>ratings[i-1]) i--;
    		int j;
    		for(j=i-1;j>=0 && num[j]==1;j--) num[j] = num[j+1] + 1;
    		num[j] = num[j]>=num[j+1]+1?num[j]:num[j+1]+1;
    		for(i=i+1;i<size && ratings[i]>ratings[i-1];i++) num[i] = num[i-1] + 1;
    	}
//    	printVector(num);
    	int sum = 0;
    	for(i=0;i<size;i++) sum+=num[i];
    	return sum;
    }
*/

    int candy(vector<int> &ratings) {
 		int size = (int)ratings.size();
    	if (size==0) return 0;
    	vector<int> num(size, 1);
    	for(int i=1;i<size;i++){
    		if (ratings[i]>ratings[i-1]) num[i] = num[i-1]+1;
    		else if(ratings[i]<ratings[i-1]){
    			while(i<size && ratings[i]<ratings[i-1]) i++;
    			int j = ratings[i]>=ratings[i-1]?i-2:i-1;
        		for(;j>=0 && num[j]==1 && ratings[j]!=ratings[j+1];j--) num[j] = num[j+1] + 1;
        		if (ratings[j]>ratings[j+1] && num[j] < num[j+1]+1) num[j] = num[j+1]+1;
        		if (ratings[i]>ratings[i-1]) i--;
    		}
    	}
    	printVector(num);
    	int sum = 0;
    	for(int i=0;i<size;i++) sum+=num[i];
    	return sum;
    }


#endif /* CANDY_H_ */

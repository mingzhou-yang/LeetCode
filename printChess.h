/*
 * printChess.h
 *
 *  Created on: 2014-02-13
 *      Author: frye
 */

#ifndef PRINTCHESS_H_
#define PRINTCHESS_H_

using namespace std;

void printLine(int *pos, int depth){
	int i;
	if (depth==8){
		for (i=0;i<8;i++) cout<<pos[i]<<",";
		cout<<endl;
		return;
	}
	for(i=0;i<8;i++)
		if (pos[i]==0){
			pos[i]=depth+1;
			printLine(pos, depth+1);
			pos[i]=0;
		}
}

void printChess(){
	int* pos = new int[8];
	printLine(pos, 0);
}

#endif /* PRINTCHESS_H_ */

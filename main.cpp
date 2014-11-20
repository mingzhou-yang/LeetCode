/*
 * main.cpp
 *
 *  Created on: 2014-01-24
 *      Author: frye
 */
#include "commonHeader.h"
#include "ScrambleString.h"


int main()
{

	struct timespec start, end;
	clock_gettime(CLOCK_MONOTONIC, &start);

	cout<<isScramble("great", "tgera")<<endl;

	clock_gettime(CLOCK_MONOTONIC, &end);
//	unsigned long long timeElapsed = timespecDiff(&end, &start);
//	cout<<timeElapsed<<endl;


    return 0;
}

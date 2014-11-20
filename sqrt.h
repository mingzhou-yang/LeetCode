/*
 * sqrt.h
 *
 *  Created on: Nov 19, 2014
 *      Author: frye
 */

#ifndef SQRT_H_
#define SQRT_H_

//Babylonian's Algorithm
    int Babylonian(int x){
        if (x < 0) return -1;
        double ret = 1.0;
        double prev = 0.0;
        double error = 0.00001;
        while(abs(prev-ret)>error){
            prev = ret;
            ret = (x/ret + ret)/2;
        }
        return ret;
    }

//bit operation
    int sqrt(int x){
        if (x<0) return -1;
        unsigned int ret = 0;
        for(int i=15;i>=0;i--){
            if ((ret+(1<<i))*(ret+(1<<i)) <= x) ret+=(1<<i);
        }
        return ret;
    }



#endif /* SQRT_H_ */

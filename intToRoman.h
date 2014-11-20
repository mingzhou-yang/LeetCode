/*
 * intToRoman.h
 *
 *  Created on: 2014-04-25
 *      Author: frye
 */

#ifndef INTTOROMAN_H_
#define INTTOROMAN_H_

#include <iostream>
using namespace std;

string intToRoman(int num) {
        string result = "";
        int remain = num % 1000;
        int k = num / 1000;
        for (int i=0;i<k;i++)
            result = result + "M";

        int h = remain / 100;
        remain = remain % 100;
        if (h==9) result = result + "CM";
        else if(h==4) result = result + "CD";
        else{
        	if(h>=5) {
        		result = result + "D";
        		h -= 5;
        	}
        	for (int i=0;i<h;i++)
        		result = result + "C";
        }

        int t = remain / 10;
        remain = remain % 10;
        if (t==9) result = result + "XC";
        else if(t==4) result = result + "XL";
        else{
        	if(t>=5) {
				result = result + "L";
				t -= 5;
			}
        	for (int i=0;i<t;i++)
        		result = result + "X";
        }

        if (remain==9) result = result + "IX";
        else if(remain==4) result = result + "IV";
        else{
        	if(remain>=5) {
				result = result + "V";
				remain -= 5;
			}
			for (int i=0;i<remain;i++)
				result = result + "I";
        }
        return result;
}

#endif /* INTTOROMAN_H_ */

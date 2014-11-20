/*
 * MaxPointsonLine.h
 *
 *  Created on: Oct 7, 2014
 *      Author: frye
 */

#ifndef MAXPOINTSONLINE_H_
#define MAXPOINTSONLINE_H_

#include "commonHeader.h"
    int maxPoints(vector<Point> &points) {
    	if (points.size()<2) return points.size();
    	int max = 2;
    	for(unsigned int i=0;i<points.size();i++){
    		int same = 0, vertical=0, localmax=1;
    		map<float,int> num;
    		for(unsigned int j=i+1;j<points.size();j++){
    			if (points[i].y==points[j].y && points[i].x==points[j].x)	same++;
    			else if (points[i].x==points[j].x) vertical++;
    			else{
        			float a = (points[i].y - points[j].y)*1.0 / (points[i].x - points[j].x);
        			if (num.find(a)!=num.end()) num[a]++;
        			else num[a]=2;
    			}
    		}
    		for(map<float, int>::iterator it=num.begin();it!=num.end();++it)
    			if (it->second > localmax) localmax = it->second;
    		if (vertical > localmax) localmax = vertical;
    		localmax += same;
    		if (localmax > max) max = localmax;
    	}
    	return max;
    }

    int maxPoints4(vector<Point> &points) {
    	if (points.size()<2) return points.size();
    	map<pair<float,float>,int> num;
//    	map<string, int> num;
    	int vertical = 0;
    	for(unsigned int i=0;i<points.size();i++){
    		int same = 0;
    		for(unsigned int j=i+1;j<points.size();j++){
    			if (points[i].y==points[j].y && points[i].x==points[j].x) {
    				same++;
    			}
    			else if (points[i].x==points[j].x) vertical++;
    			float a = (points[i].y - points[j].y)*1.0 / (points[i].x - points[j].x);
    			float b = points[i].y - a * points[i].x;
    			ostringstream strs;
    			strs <<a<<" "<<b;
    			string s = strs.str();
    			if (num.find(make_pair(a,b))!=num.end()) num[make_pair(a,b)] = num[make_pair(a,b)]+1+same;
//    			if (num.find(s)!=num.end()) num[s] = num[s]+1+same;
    			else num[make_pair(a,b)]=1;
    		}
    	}
    	int max=vertical;
    	for(map<pair<float,float>, int>::iterator it=num.begin();it!=num.end();++it)
//    	for(map<string, int>::iterator it=num.begin();it!=num.end();++it)
    		if (it->second > max) max = it->second;
    	return sqrt(max*2)+1;
    }

    int maxPoints2(vector<Point> &points) {
        if(points.size() <= 2) //size is less then or equal to 2 then just return size
            return points.size();

        unordered_map<string, int> dupMap;
        for(int i = 0; i < points.size(); i++){ // delete dubs and keep track of their count in dupMap
            string pt = to_string(points[i].x) + ' '+ to_string(points[i].y);
            if(dupMap.count(pt) == 0)
                dupMap[pt] = 0;
            else{
                dupMap[pt]++;
                points.erase(points.begin() + i--);
            }
        }


        if(points.size() == 1){ //if every item  was a dup
            string pt = to_string(points[0].x) + ' '+ to_string(points[0].y);
            return dupMap[pt] + 1;
        }

        int max = 2;
        for(int i = 0; i < points.size()-1; i++){//O(N^2) calclate every combination of points
            unordered_map<string, int> hashMap;
            string pt = to_string(points[i].x) +' '+ to_string(points[i].y);

            for(int j = i+1; j < points.size(); j++){
                string pt2 = to_string(points[j].x) +' '+ to_string(points[j].y);
                string eq = "";
                if(points[i].x == points[j].x)
                    eq = "x = " + to_string(points[i].x); //infinte slope
                else{
                    float m = (float)(points[j].y - points[i].y) / (float)(points[j].x - points[i].x);//slope
                    m = (m < 0.0005 && m > -0.0005)? 0: m; //rounding to 0 for floats
                    float b = (float)points[i].y - (float)(m * points[i].x);
                    eq = "y =" + to_string(m) + '+' + to_string(b); //form equation string
                }

                if(hashMap.count(eq) == 0){ //havent seen this eq before
                    hashMap[eq] = 2;
                    if(dupMap[pt] > 0) //pt has dupes
                        hashMap[eq] += dupMap[pt];
                    if(dupMap[pt2] > 0)//pt2 has dupes
                        hashMap[eq] += dupMap[pt2];
                }
                else
                    hashMap[eq] += (dupMap[pt2] > 0)? dupMap[pt2] + 1 : 1;
                max = (hashMap[eq] > max)? hashMap[eq] : max;
            }
        }
        return max; //return the max count
    }


    int GCD(int a, int b) {

        if(b==0) return a;
        else return GCD(b, a%b);
    }

    int maxPoints3(vector<Point> &points) {

        if(points.size()<2) return points.size();
        int result=0;
        for(int i=0; i<points.size(); i++) {

			map<pair<int, int>, int> lines;
			int localmax=0, overlap=0, vertical=0;

			for(int j=i+1; j<points.size(); j++) {

				if(points[j].x==points[i].x && points[j].y==points[i].y) {
					overlap++;
					continue;
				}
				else if(points[j].x==points[i].x) vertical++;
				else {

						int a=points[j].x-points[i].x, b=points[j].y-points[i].y;
						int gcd=GCD(a, b);

						a/=gcd;
						b/=gcd;

						lines[make_pair(a, b)]++;
						localmax=max(lines[make_pair(a, b)], localmax);
				}
				localmax=max(vertical, localmax);
			}
			result=max(result, localmax+overlap+1);
		}
        return result;
    }


#endif /* MAXPOINTSONLINE_H_ */

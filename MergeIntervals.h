/*
 * MergeIntervals.h
 *
 *  Created on: Nov 23, 2014
 *      Author: frye
 */

#ifndef MERGEINTERVALS_H_
#define MERGEINTERVALS_H_

#include "commonHeader.h"

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

void printVector(vector<Interval> v){
	for(int i=0;i<(int)v.size();i++) cout<<"["<<v[i].start<<" "<<v[i].end<<"] ";
	cout << endl;
}

bool mycomparison(Interval a, Interval b) {return a.start<b.start;}

    vector<Interval> merge(vector<Interval> &intervals) {
    	vector<Interval> ret;
    	if (intervals.empty()) return ret;
    	sort(intervals.begin(), intervals.end(), mycomparison);
    	printVector(intervals);
    	int farthest=intervals[0].end, pos=0;
    	ret.push_back(intervals[0]);
    	for(int i=0;i<(int)intervals.size();i++){
    		if (intervals[i].start > farthest){
    			ret.push_back(intervals[i]);
    			farthest = intervals[i].end;
    			pos++;
    		}
    		else if (intervals[i].start <= farthest && intervals[i].end > farthest){
    			ret[pos].end = intervals[i].end;
    			farthest = intervals[i].end;
    		}
    	}
    	return ret;
    }

    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    	vector<Interval> ret;
    	if (intervals.empty()){ret.push_back(newInterval); return ret;}
    	int size = (int)intervals.size();
    	for(int i=0;i<(int)intervals.size();i++)
    		if (intervals[i].start > newInterval.start){
    			intervals.insert(intervals.begin()+i, newInterval);
    			break;
    		}
    	if (size==intervals.size()) intervals.push_back(newInterval);

    	int farthest=intervals[0].end, pos=0;
    	ret.push_back(intervals[0]);
    	for(int i=0;i<(int)intervals.size();i++){
    		if (intervals[i].start > farthest){
    			ret.push_back(intervals[i]);
    			farthest = intervals[i].end;
    			pos++;
    		}
    		else if (intervals[i].start <= farthest && intervals[i].end > farthest){
    			ret[pos].end = intervals[i].end;
    			farthest = intervals[i].end;
    		}
    	}
    	return ret;
    }


#endif /* MERGEINTERVALS_H_ */

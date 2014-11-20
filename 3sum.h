/*
 * 3sum.h
 *
 *  Created on: Nov 10, 2014
 *      Author: frye
 */

#ifndef SUM3_H_
#define SUM3_H_

#include "commonHeader.h"

    vector<vector<int> > threeSum2(vector<int> &num) {
    	vector<vector<int>> ret;
    	unordered_map<int, int> m;
    	sort(num.begin(), num.end());
    	for(unsigned int i=0;i<num.size();i++) m[num[i]]++;
    	for(unsigned int i=0;i<num.size();i++){
    		for(unsigned int j=i+1;j<num.size();j++){
    			int sum = -num[i]-num[j];
    			if (sum<num[j]) continue;
    			vector<int> temp(3, sum);
    			if(sum==num[i]){
    				if (m[sum]>=3) ret.push_back(temp);
    			}
    			else if(sum==num[j]){
    				if (m[sum]>=2){
						temp[0] = num[i];
						temp[1] = num[j];
						ret.push_back(temp);
    				}
    			}
    			else if(m[sum]>=1){
					temp[0] = num[i];
					temp[1] = num[j];
    				ret.push_back(temp);
    			}
    			while(num[j]==num[j+1]) j++;
    		}
    		while(num[i]==num[i+1]) i++;
    	}
    	return ret;
    }

    vector<vector<int> > threeSum(vector<int> &num) {
    	vector<vector<int>> ret;
    	sort(num.begin(), num.end());
    	for(int i=0;i<(int)num.size()-2;i++){
    		int j=i+1, k=num.size()-1;
    		while(j<k){
				if (num[j]+num[k]==-num[i]){
					vector<int> temp(1,num[i]);
					temp.push_back(num[j]);
					temp.push_back(num[k]);
					ret.push_back(temp);
					while (num[j]==num[j+1]) j++;
					while (num[k]==num[k-1]) k--;
					j++;
					k--;
				}
				else if (num[j]+num[k]>-num[i]) k--;
				else if (num[j]+num[k]<-num[i]) j++;
    		}
    		while (num[i]==num[i+1]) i++;
    	}
    	return ret;
    }

    vector<vector<int> > threeSum(vector<int> &num, int target, int first) {
    	vector<vector<int>> ret;
    	sort(num.begin(), num.end());
    	for(int i=0;i<(int)num.size()-2;i++){
    		int j=i+1, k=num.size()-1;
    		while(j<k){
				if (num[j]+num[k]==target-num[i]){
					vector<int> temp(1,first);
					temp.push_back(num[i]);
					temp.push_back(num[j]);
					temp.push_back(num[k]);
					ret.push_back(temp);
					while (num[j]==num[j+1]) j++;
					while (num[k]==num[k-1]) k--;
					j++;
					k--;
				}
				else if (num[j]+num[k]>target-num[i]) k--;
				else if (num[j]+num[k]<target-num[i]) j++;
    		}
    		while (num[i]==num[i+1]) i++;
    	}
    	return ret;
    }

    vector<vector<int> > fourSum(vector<int> &num, int target) {
    	vector<vector<int>> ret;
    	sort(num.begin(), num.end());
    	for(int i=0;i<(int)num.size();i++){
    		vector<int> subvec(num.begin()+i+1, num.end());
    		vector<vector<int>> resultOfSum3 = threeSum(subvec, target-num[i], num[i]);
    		vector<vector<int>>::iterator it = ret.begin();
//    		ret.insert(it, resultOfSum3.begin(), resultOfSum3.end());
    		for(int j=0;j<(int)resultOfSum3.size();j++) ret.push_back(resultOfSum3[j]);
    		while (num[i]==num[i+1]) i++;
    	}
    	return ret;
    }

    vector<int> twoSum(vector<int> &numbers, int target) {
    	unordered_map<int, int> m;
    	vector<int> ret(2,0);
        for(int i=0;i<(int)numbers.size();i++){
        	if (m[target-numbers[i]]) {
        		ret[0] = m[target-numbers[i]];
        		ret[1] = i+1;
        		return ret;
        	}
        	if (m.find(numbers[i])==m.end() || m[numbers[i]]==0)
        		m[numbers[i]] = i+1;
        }
        return ret;
    }

#endif /* 3SUM_H_ */

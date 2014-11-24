#ifndef _LARGEST_RECTANGLE
#define _LARGEST_RECTANGLE
#include "commonHeader.h"

    int largestRectangleArea(vector<int> &height) {
		if (height.empty()) return 0;
        int max = 0;
		stack<int> s;
		for(int i=0;i<(int)height.size();i++){
			if (s.empty() || height[i]>height[s.top()]) s.push(i);
			else {
				while(!s.empty() && height[s.top()]>=height[i]){
					int pos = s.top();
					s.pop();
					int area;
					if (!s.empty()) area = height[pos] * (i-s.top()-1);
					else area = height[pos] * i;
					max = area>max ? area : max;
					cout<<i<<" "<<pos<<" "<<area<<" "<<max<<endl;
					if (!s.empty()) cout<<s.top()<<endl;
				}
				s.push(i);
			}
		}
		
		while(!s.empty()){
			int pos = s.top();
			s.pop();
			int area;
			if (!s.empty()) area = height[pos] * (height.size()-s.top()-1);
			else area = height[pos] * height.size();
			max = area>max ? area : max;
			cout<<pos<<" "<<max<<" "<<area<<endl;
			if (!s.empty()) cout<<s.top()<<endl;
		}
		return max;
    }

#endif
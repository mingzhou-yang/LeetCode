/*
 * minStack.h
 *
 *  Created on: Nov 12, 2014
 *      Author: frye
 */

#ifndef MINSTACK_H_
#define MINSTACK_H_

#include "commonHeader.h"

class MinStack {
public:
    void push(int x) {
    	if (s.empty() || minStack.top()>=x) minStack.push(x);
    	s.push(x);
    }

    void pop() {
    	if (s.empty()) return;
    	int num = s.top();
    	if (minStack.top() == num) minStack.pop();
    	s.pop();
    }

    int top() {
    	if (!s.empty())
    		return s.top();
    	else return 0;
    }

    int getMin() {
    	if (!minStack.empty())
    		return minStack.top();
    	else return 0;
    }
private:
    stack<int> s;
    stack<int> minStack;
};



#endif /* MINSTACK_H_ */

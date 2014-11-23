/*
 * MergeKSortedLists.h
 *
 *  Created on: Nov 23, 2014
 *      Author: frye
 */

#ifndef MERGEKSORTEDLISTS_H_
#define MERGEKSORTEDLISTS_H_

#include "commonHeader.h"

class mycomparison
{
public:
  mycomparison()
    {}
  bool operator() (const ListNode *lhs, const ListNode *rhs) const
  {
    return (lhs->val>rhs->val);
  }
};


    ListNode *mergeKLists(vector<ListNode *> &lists) {
    	vector<ListNode *> list;
    	for(int i=0;i<(int)lists.size();i++)
    		if (lists[i]) list.push_back(lists[i]);
    	if (lists.empty()) return NULL;
    	typedef std::priority_queue<ListNode*,std::vector<ListNode*>,mycomparison> ListHeap;
    	ListHeap myheap(list.begin(), list.end());
    	ListNode *head = myheap.top();
    	myheap.pop();
    	if (head->next) myheap.push(head->next);
    	ListNode* cur = head;
    	while(!myheap.empty()){
    		cur->next = myheap.top();
    		myheap.pop();
    		cur = cur->next;
    		if (cur->next) myheap.push(cur->next);
    	}
    	return head;
    }


#endif /* MERGEKSORTEDLISTS_H_ */

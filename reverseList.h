/*
 * reverseList.h
 *
 *  Created on: 2014-06-05
 *      Author: frye
 */

#ifndef REVERSELIST_H_
#define REVERSELIST_H_

#include "commonHeader.h"

	ListNode *reverseBetween(ListNode *head, int m, int n) {
		if (m==n) return head;
		ListNode *newhead = new ListNode(0);
		newhead->next = head;
		ListNode *preList = newhead;
		ListNode *cur = head;
		for(int i=1;i<m;i++) {
			preList = preList->next;
			cur = cur->next;
		}
		ListNode *tempTail = cur;
		ListNode *pre = cur;
		cur = cur->next;
		ListNode *next = cur->next;
		for(int i=m;i<n&&cur!=NULL;i++){
			cur->next = pre;
			pre = cur;
			cur = next;
			if (next!=NULL) next = next->next;
		}
		preList->next = pre;
		tempTail->next = cur;
		return newhead->next;
    }

	ListNode *reverseKGroup(ListNode *head, int k) {
		if (head==NULL) return NULL;
		ListNode *cur = head;
		for(int i=0;i<k;i++){
			if(cur==NULL) return head;
			cur = cur->next;
		}
		cur = head->next;
		ListNode *pre = head;
		for(int i=0;i<k-1;i++){
			ListNode *temp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = temp;
		}
		head->next = reverseKGroup(cur, k);
		return pre;
	}

#endif /* REVERSELIST_H_ */

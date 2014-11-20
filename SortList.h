/*
 * SortList.h
 *
 *  Created on: Oct 6, 2014
 *      Author: frye
 */

#ifndef SORTLIST_H_
#define SORTLIST_H_

#include "commonHeader.h"

	ListNode *sortList(ListNode *head, int len){
		if (len==0) return NULL;
		if (len==1) return head;
		int half = len/2;
		ListNode *right = head;
		for(int i=0;i<half-1;i++) right = right->next;
		ListNode *rhead = sortList(right->next, len-half);
		right->next = NULL;
		ListNode *lhead = sortList(head, half);

		ListNode *newhead, *lcur=lhead, *rcur=rhead;
		if (lhead->val < rhead->val){
			newhead = lhead;
			lcur = lcur->next;
		}
		else{
			newhead = rhead;
			rcur = rcur->next;
		}
		ListNode *cur = newhead;
		while(lcur!=NULL&&rcur!=NULL){
			if (lcur->val < rcur->val){
				cur->next = lcur;
				cur = cur->next;
				lcur = lcur->next;
			}
			else{
				cur->next = rcur;
				cur = cur->next;
				rcur = rcur->next;
			}
		}
		if (lcur!=NULL) cur->next = lcur;
		else cur->next = rcur;
		return newhead;
	}

    ListNode *sortList(ListNode *head) {
    	if (head==NULL) return NULL;
    	int len = 0;
    	for(ListNode *cur = head;cur!=NULL;cur=cur->next,len++) ;
    	return sortList(head, len);
    }

#endif /* SORTLIST_H_ */

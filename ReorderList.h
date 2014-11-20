/*
 * ReorderList.h
 *
 *  Created on: Oct 6, 2014
 *      Author: frye
 */

#ifndef REORDERLIST_H_
#define REORDERLIST_H_

#include "commonHeader.h"

    void reorderList(ListNode *head) {
    	if (head==NULL) return;
    	int len = 0;
    	for(ListNode *cur=head;cur!=NULL;cur=cur->next,len++) ;
    	if (len <= 2) return;
    	int half = len - len/2;
    	ListNode *right = head;
    	for(int i=0;i<half-1;i++) right = right->next;
    	cout<<right->val<<endl;
    	ListNode *pre = right->next, *cur = pre->next, *righthead = pre;
    	right->next = NULL;
    	pre->next = NULL;
    	while(cur!=NULL){
    		ListNode *temp = cur->next;
    		cur->next = pre;
    		righthead = cur;
    		pre = cur;
    		cur = temp;
    	}
    	printList(righthead);
    	ListNode *lcur = head->next, *rcur = righthead;
    	pre = head;
    	bool flag = true;
    	while(lcur!=NULL || rcur!=NULL){
    		if (flag) {
    			pre->next = rcur;
    			rcur = rcur->next;
    		}
    		else {
    			pre->next = lcur;
    			lcur = lcur->next;
    		}
    		flag = !flag;
    		pre = pre->next;
    	}
    	printList(head);
    }

#endif /* REORDERLIST_H_ */

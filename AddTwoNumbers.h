/*
 * AddTwoNumbers.h
 *
 *  Created on: Oct 7, 2014
 *      Author: frye
 */

#ifndef ADDTWONUMBERS_H_
#define ADDTWONUMBERS_H_

#include "commonHeader.h"

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    	if (l1==NULL) return l2;
    	if (l2==NULL) return l1;
    	int carry = 0;
    	ListNode *head=new ListNode(0), *cur=head, *cur1, *cur2;
    	for(cur1=l1,cur2=l2;cur1!=NULL||cur2!=NULL;){
    		int num = carry;
    		if (cur1!=NULL) {
    			num += cur1->val;
    			cur1 = cur1->next;
    		}
    		if (cur2!=NULL) {
    			num += cur2->val;
    			cur2 = cur2->next;
    		}
    		if (num>=10){
    			carry = 1;
    			num -= 10;
    		}
    		else carry = 0;
    		ListNode *node = new ListNode(num);
    		cur->next = node;
    		cur = cur->next;
    	}
    	if (carry==1){
    		ListNode *node = new ListNode(1);
    		cur->next = node;
    	}
    	return head->next;
    }



#endif /* ADDTWONUMBERS_H_ */

/*
 * LinkedListCycle.h
 *
 *  Created on: 2014-04-29
 *      Author: frye
 */

#ifndef LINKEDLISTCYCLE_H_
#define LINKEDLISTCYCLE_H_

#include "commonHeader.h"

	ListNode *detectCycle(ListNode *head) {
        if (head==NULL) return NULL;
        if (head->next==NULL) return NULL;
        ListNode* fast = head->next->next;
        ListNode* slow = head->next;
        while(slow!=NULL&&fast!=NULL){
        	if (fast==slow) break;
        	slow = slow->next;
        	if (fast->next==NULL) break;
        	fast = fast->next->next;
        }
        if (fast!=slow) return NULL;
        ListNode *p1 = fast, *p2 = head;
        while(p1!=p2){
        	p1 = p1->next;
        	p2 = p2->next;
        }
        return p1;
    }

#endif /* LINKEDLISTCYCLE_H_ */

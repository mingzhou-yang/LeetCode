/*
 * partitionList.h
 *
 *  Created on: 2014-05-15
 *      Author: frye
 */

#ifndef PARTITIONLIST_H_
#define PARTITIONLIST_H_

#include "commonHeader.h"

	ListNode *partition(ListNode *head, int x) {
		if (head==NULL) return NULL;
		ListNode *newhead = new ListNode(0), *pos, *cur=head;
		newhead->next = head;
		pos = newhead;

		while (cur->val < x) {
			pos = cur;
			cur = cur->next;
			if (cur==NULL) return head;
		}

		while(cur->next!=NULL){
			if (cur->next->val < x){
				ListNode *temp = pos->next;
				pos->next = cur->next;
				cur->next = cur->next->next;
				pos = pos->next;
				pos->next = temp;
			}
			else cur = cur->next;
		}
		return newhead->next;
    }

#endif /* PARTITIONLIST_H_ */

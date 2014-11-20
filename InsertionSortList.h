/*
 * InsertionSortList.h
 *
 *  Created on: 2014-06-21
 *      Author: frye
 */

#ifndef INSERTIONSORTLIST_H_
#define INSERTIONSORTLIST_H_

#include "commonHeader.h"

	ListNode *insertionSortList(ListNode *head) {
		if (head==NULL) return head;
		ListNode *pre = head, *cur = head->next, *newhead = head;
		bool inserted = false;
		while(cur!=NULL){
			cout<<cur->val<<endl;
			if (cur->val < newhead->val){
				pre->next = cur->next;
				cur->next = newhead;
				newhead = cur;
				cur = pre->next;
				continue;
			}
			ListNode *pretemp = newhead, *temp = newhead->next;
			for( ;temp!=cur; pretemp=temp, temp=temp->next){
				if (temp->val > cur->val){
					pre->next = cur->next;
					cur->next = temp;
					pretemp->next = cur;
					cur = pre->next;
					inserted = true;
					break;
				}
			}
			if (!inserted){
				cur = cur->next;
				pre = pre->next;
			}
			else inserted = false;
		}
		return newhead;
    }

#endif /* INSERTIONSORTLIST_H_ */

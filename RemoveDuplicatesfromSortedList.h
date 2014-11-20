/*
 * RemoveDuplicatesfromSortedList.h
 *
 *  Created on: Sep 25, 2014
 *      Author: frye
 */

#ifndef REMOVEDUPLICATESFROMSORTEDLIST_H_
#define REMOVEDUPLICATESFROMSORTEDLIST_H_

#include "commonHeader.h"

	ListNode *deleteDuplicates(ListNode *head) {
		if (head==NULL || head->next==NULL) return head;
		ListNode *newhead = new ListNode(0);
		newhead->next = head;
		ListNode *pre = newhead, *cur = head, *post = head->next;
		while(cur!=NULL&&post!=NULL){
			if (post->val!=cur->val){
				pre = pre->next;
				cur = cur->next;
				post = post->next;
			}
			else{
				while(post!=NULL&&post->val==cur->val) {
					ListNode *temp = post->next;
					delete post;
					post = temp;
				}
				delete cur;
				pre->next = post;
				cur = pre->next;
				if (cur!=NULL) post = cur->next;
			}
		}
		return newhead->next;
    }



#endif /* REMOVEDUPLICATESFROMSORTEDLIST_H_ */

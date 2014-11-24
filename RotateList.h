#ifndef _ROTATE_LIST
#define _ROTATE_LIST
#include "commonHeader.h"

    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) return head;
		int len=0;
		ListNode *cur = head;
		while(cur) {
			cur=cur->next;
			len++;
		}
		k = k%len;
		if (!k) return head;
		ListNode *prev = head;
		cur = head;
		int i=0;
		while(cur && i++<k) cur = cur->next;
		while(cur->next){
			cur = cur->next;
			prev = prev->next;
		}
		ListNode *temp = prev->next;
		prev->next = NULL;
		cur->next = head;
		return temp;
    }

#endif
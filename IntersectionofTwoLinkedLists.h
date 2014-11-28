/*
 * IntersectionofTwoLinkedLists.h
 *
 *  Created on: Nov 27, 2014
 *      Author: frye
 */

#ifndef INTERSECTIONOFTWOLINKEDLISTS_H_
#define INTERSECTIONOFTWOLINKEDLISTS_H_

#include "commonHeader.h"

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	if (!headA || !headB) return NULL;
    	int lenA = 0, lenB = 0;
    	ListNode *curA = headA, *curB = headB;
    	while(curA->next) {
    		curA = curA->next;
    		lenA++;
    	}
    	while(curB->next) {
    		curB = curB->next;
    		lenB++;
    	}
    	if (curA!=curB) return NULL;
    	int diff = max(lenA, lenB) - min(lenA, lenB);
    	curA = headA;
    	curB = headB;
    	for(int i=0;i<diff;i++){
    		if (lenA>lenB) curA = curA->next;
    		else curB = curB->next;
    	}
    	while(curA!=curB){
    		curA = curA->next;
    		curB = curB->next;
    	}
    	return curA;
    }

#endif /* INTERSECTIONOFTWOLINKEDLISTS_H_ */

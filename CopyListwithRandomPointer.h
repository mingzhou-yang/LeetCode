/*
 * CopyListwithRandomPointer.h
 *
 *  Created on: Oct 4, 2014
 *      Author: frye
 */

#ifndef COPYLISTWITHRANDOMPOINTER_H_
#define COPYLISTWITHRANDOMPOINTER_H_

#include "commonHeader.h"

	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head==NULL) return NULL;
        map<RandomListNode*, RandomListNode*> m;
        RandomListNode *newhead = new RandomListNode(head->label);
        m[head] = newhead;
        m[NULL] = NULL;
        for(RandomListNode *cur=head->next, *pre=newhead;cur!=NULL;cur=cur->next,pre=pre->next){
        	RandomListNode *temp = new RandomListNode(cur->label);
        	pre->next = temp;
        	m[cur] = temp;
        }
        for(RandomListNode *cur=head,*newcur=newhead;cur!=NULL;cur=cur->next,newcur=newcur->next){
        	RandomListNode *temp = m[cur->random];
        	newcur->random = temp;
        }
        return newhead;
    }



#endif /* COPYLISTWITHRANDOMPOINTER_H_ */

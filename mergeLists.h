/*
 * mergeLists.h
 *
 *  Created on: 2014-04-25
 *      Author: frye
 */

#ifndef MERGELISTS_H_
#define MERGELISTS_H_

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1==NULL&&l2==NULL) return NULL;
        if (l1==NULL) return l2;
        if (l2==NULL) return l1;
        ListNode *head;
        ListNode *p1 = l1, *p2 = l2;
        if (p1->val<p2->val){
            head = p1;
            p1 = p1->next;
        }
        else {
            head = p2;
            p2 = p2->next;
        }
        ListNode *cur = head;

        while(true){
            if (p1==NULL){
                cur->next = p2;
                break;
            }
            if (p2==NULL){
                cur->next = p1;
                break;
            }
            if (p1->val<p2->val){
                cur->next = p1;
                p1 = p1->next;
            }
            else {
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
        }
        return head;
    }

#endif /* MERGELISTS_H_ */

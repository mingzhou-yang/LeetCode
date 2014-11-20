/*
 * listToBTree.h
 *
 *  Created on: 2014-05-13
 *      Author: frye
 */

#ifndef LISTTOBTREE_H_
#define LISTTOBTREE_H_

#include "commonHeader.h"

	TreeNode *buildTree(ListNode *head, int len){
        if (len==0) return NULL;
        int half = len/2;
        ListNode *mid = head;
        for(int i=0;i<half;i++) mid = mid->next;
        TreeNode *root = new TreeNode(mid->val);
        root->left = buildTree(head, half);
        root->right = buildTree(mid->next, len-half-1);
        return root;
    }

    TreeNode *sortedListToBST(ListNode *head) {
        if (head==NULL) return NULL;
        ListNode *p = head;
        int len=0;
        while(p!=NULL){
            p = p->next;
            len++;
        }
        TreeNode * ret = buildTree(head, len);
        return ret;
    }

#endif /* LISTTOBTREE_H_ */

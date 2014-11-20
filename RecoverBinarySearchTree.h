/*
 * RecoverBinarySearchTree.h
 *
 *  Created on: Sep 30, 2014
 *      Author: frye
 */

#ifndef RECOVERBINARYSEARCHTREE_H_
#define RECOVERBINARYSEARCHTREE_H_

#include "commonHeader.h"

	void findMistake(TreeNode *root, TreeNode *&pre, TreeNode **mistake){
		if (root==NULL) return;
		findMistake(root->left, pre, mistake);
		if (pre->val > root->val){
			if (mistake[0]==NULL) mistake[0] = pre;
			mistake[1] = root;
			cout<<"here"<<endl;
		}
		pre = root;
		findMistake(root->right, pre, mistake);
	}

	void recoverTree(TreeNode *root) {
		TreeNode t = TreeNode(INT_MIN);
        TreeNode *pre = &t;
        TreeNode **mistake = (TreeNode**)malloc(sizeof(TreeNode*)*2);
        mistake[0] = NULL;
        findMistake(root, pre, mistake);
        if (mistake[0]&&mistake[1]) {
        	int temp = mistake[0]->val;
        	mistake[0]->val = mistake[1]->val;
        	mistake[1]->val = temp;
        }
    }



#endif /* RECOVERBINARYSEARCHTREE_H_ */

/*
 * ValidateBST.h
 *
 *  Created on: 2014-06-16
 *      Author: frye
 */

#ifndef VALIDATEBST_H_
#define VALIDATEBST_H_

#include "commonHeader.h"

	bool isValidBST(TreeNode *root, int arg[]){
		int value[2];
        if (root->left!=NULL){
            if (!isValidBST(root->left, value)) return false;
            if (value[1] >= root->val) return false;
            arg[0] = value[0];
        }
        else arg[0] = root->val;
        if (root->right!=NULL){
            if (!isValidBST(root->right, value)) return false;
            if (value[0] <= root->val) return false;
            arg[1] = value[1];
        }
        else arg[1] = root->val;
        return true;
	}

	bool isValidBST(TreeNode *root) {
        if (root==NULL) return true;
        int arg[2];
        return isValidBST(root, arg);
    }

#endif /* VALIDATEBST_H_ */

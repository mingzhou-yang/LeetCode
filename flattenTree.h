/*
 * flattenTree.h
 *
 *  Created on: 2014-05-10
 *      Author: frye
 */

#ifndef FLATTENTREE_H_
#define FLATTENTREE_H_

#include "commonHeader.h"

	TreeNode * setFlatten(TreeNode *root){
        if (root->left==NULL&&root->right==NULL) return root;
        if (root->left==NULL){
            TreeNode *rightTail = setFlatten(root->right);
            return rightTail;
        }
        if (root->right==NULL){
            TreeNode *leftTail = setFlatten(root->left);
            root->right = root->left;
            root->left = NULL;
            return leftTail;
        }
        else{
            TreeNode *leftTail = setFlatten(root->left);
            TreeNode *rightTail = setFlatten(root->right);
            TreeNode *rightChild = root->right;
            root->right = root->left;
            root->left = NULL;
            leftTail->right = rightChild;
            return rightTail;
        }
    }

    void flatten(TreeNode *root) {
        if (root==NULL) return;
        setFlatten(root);
    }

#endif /* FLATTENTREE_H_ */

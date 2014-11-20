/*
 * BinaryTreeMaximumPathSum.h
 *
 *  Created on: Oct 5, 2014
 *      Author: frye
 */

#ifndef BINARYTREEMAXIMUMPATHSUM_H_
#define BINARYTREEMAXIMUMPATHSUM_H_

#include "commonHeader.h"

	int maxSum(TreeNode *root, int *max){
		if (root==NULL) return 0;
		int maxleft = maxSum(root->left, max);
		int maxright = maxSum(root->right, max);
		int tempmax = getMax3(maxleft+root->val, maxright+root->val, maxleft+maxright+root->val);
		if (tempmax > *max) *max = tempmax;
		return getMax3(maxleft+root->val, maxright+root->val, root->val);
	}

    int maxPathSum(TreeNode *root) {
    	int *max=new int(root->val);
    	int max2 = maxSum(root, max);
    	cout<<*max<<" "<<max2<<endl;
    	return max2>*max?max2:*max;
    }



#endif /* BINARYTREEMAXIMUMPATHSUM_H_ */

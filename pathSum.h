/*
 * pathSum.h
 *
 *  Created on: 2014-04-30
 *      Author: frye
 */

#ifndef PATHSUM_H_
#define PATHSUM_H_

#include "commonHeader.h"

	bool hasPathSum(TreeNode *root, int sum) {
		if (root==NULL) return false;
		if (root->val==sum&&root->left==NULL&&root->right==NULL) return true;
		return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }


	vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int>> ret;
        if (root==NULL) return ret;
		if (root->val==sum&&root->left==NULL&&root->right==NULL){
			vector<int> temp;
			temp.push_back(root->val);
			ret.push_back(temp);
			return ret;
		}
		vector<vector<int>> left = pathSum(root->left, sum-root->val);
		vector<vector<int>> right = pathSum(root->right, sum-root->val);
		for(int i=0;i<left.size();i++) left[i].insert(left[i].begin(), root->val);
		for(int i=0;i<right.size();i++) right[i].insert(right[i].begin(), root->val);
		ret.insert(ret.begin(), left.begin(), left.end());
		ret.insert(ret.begin(), right.begin(), right.end());
		return ret;
    }
#endif /* PATHSUM_H_ */

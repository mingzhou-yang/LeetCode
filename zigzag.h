/*
 * zigzag.h
 *
 *  Created on: 2014-05-15
 *      Author: frye
 */

#ifndef ZIGZAG_H_
#define ZIGZAG_H_

#include "commonHeader.h"

	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int> > ret;
		if (root==NULL) return ret;
		stack<TreeNode *> s1, s2;
		s1.push(root);
		while(!s1.empty() || !s2.empty()){
			vector<int> level;
			while(!s1.empty()){
				TreeNode *temp = s1.top();
				level.push_back(temp->val);
				if (temp->left!=NULL) s2.push(temp->left);
				if (temp->right!=NULL) s2.push(temp->right);
				s1.pop();
			}
			if (!level.empty()) ret.push_back(level);
			level.clear();
			while(!s2.empty()){
				TreeNode *temp = s2.top();
				level.push_back(temp->val);
				if (temp->right!=NULL) s1.push(temp->right);
				if (temp->left!=NULL) s1.push(temp->left);
				s2.pop();
			}
			if (!level.empty()) ret.push_back(level);
		}
		return ret;
    }

	string convert(string s, int nRows) {
		string ret;
		if (nRows<=0) return ret;
		if (nRows==1) return s;
		int group = nRows * 2 - 2;
		for(int i=0;i<nRows;i++){
			for(int j=0;j*group+i<s.size();j++){
				ret = ret + s[j*group+i];
				if (i!=0&&i!=nRows-1&&(j+1)*group-i<s.size()){
					ret = ret + s[(j+1)*group-i];
				}
			}
		}
		return ret;
	}

#endif /* ZIGZAG_H_ */

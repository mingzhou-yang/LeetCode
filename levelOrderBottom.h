/*
 * levelOrderBottom.h
 *
 *  Created on: 2014-04-27
 *      Author: frye
 */

#ifndef LEVELORDERBOTTOM_H_
#define LEVELORDERBOTTOM_H_

#include "commonHeader.h"

	vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> v;
        if (root==NULL) return v;
        queue<TreeNode*> q;
        q.push(root);
        int count=1, nextCount=0;
        while(!q.empty()){
        	vector<int> level;
        	for(int i=0;i<count;i++){
        		pnode p = q.front();
        		q.pop();
        		level.push_back(p->val);
        		if (p->left!=NULL) {
        			q.push(p->left);
        			nextCount++;
        		}
        		if (p->right!=NULL) {
        			q.push(p->right);
        			nextCount++;
        		}
        	}
        	v.insert(v.begin(), level);
        	count = nextCount;
        	nextCount = 0;
        }
        return v;
    }

#endif /* LEVELORDERBOTTOM_H_ */

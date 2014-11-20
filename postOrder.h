/*
 * postOrder.h
 *
 *  Created on: 2014-04-29
 *      Author: frye
 */

#ifndef POSTORDER_H_
#define POSTORDER_H_

#include "commonHeader.h"

/*	vector<int> postorderTraversal(TreeNode *root) {
        vector<int> v;
        if (root==NULL) return v;
        vector<int> left = postorderTraversal(root->left);
        vector<int> right = postorderTraversal(root->right);
        for(int i=0;i<left.size();i++) v.push_back(left[i]);
        for(int i=0;i<right.size();i++) v.push_back(right[i]);
        v.push_back(root->val);
        return v;
    }*/

	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> v;
		if (root==NULL) return v;
		stack<pnode> st;
		map<pnode, bool> m;
		st.push(root);
		while(!st.empty()){
			pnode n = st.top();
			map<pnode, bool>::iterator it = m.find(n);
			if (it==m.end()){
				m[n] = true;
				if (n->right!=NULL) st.push(n->right);
				if (n->left!=NULL) st.push(n->left);
			}
			else {
				v.push_back(n->val);
				st.pop();
			}
		}
		return v;
	}

#endif /* POSTORDER_H_ */

/*
 * buildTreeFromTraversal.h
 *
 *  Created on: 2014-05-15
 *      Author: frye
 */

#ifndef BUILDTREEFROMTRAVERSAL_H_
#define BUILDTREEFROMTRAVERSAL_H_

#include "commonHeader.h"

	TreeNode *buildTree(vector<int> &inorder, int li, int ri, vector<int> &postorder, int lp, int rp){
		int size = li - ri;
		cout<<lp<<" "<<rp<<endl;
		if (size==0) return NULL;
		int rootValue = postorder[rp-1];
		TreeNode *node = new TreeNode(rootValue);
		vector<int>::iterator rootPos = find(inorder.begin()+li, inorder.begin()+ri, rootValue);

		int leftSize = rootPos-inorder.begin()-li;
		node->left = buildTree(inorder, li, li+leftSize, postorder, lp, lp+leftSize);
		node->right = buildTree(inorder, li+leftSize+1, ri, postorder, lp+leftSize, rp-1);

		return node;
	}

	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		int size = inorder.size();
		return buildTree(inorder, 0, size, postorder, 0, size);
    }

	TreeNode *buildTree2(vector<int> &preorder, int lp, int rp, vector<int> &inorder, int li, int ri) {
		if (lp>=rp) return NULL;
		int rootValue = preorder[lp];
		TreeNode *root = new TreeNode(rootValue);
		int rootPos = li;
		for(int i=li;i<ri;i++)
			if (inorder[i]==rootValue)
				rootPos = i;
		int leftSize = rootPos - li, rightSize = ri - rootPos - 1;
		root->left = buildTree2(preorder, lp+1, lp+leftSize+1, inorder, li, li+leftSize);
		root->right = buildTree2(preorder, rp-rightSize, rp, inorder, ri-rightSize, ri);
		return root;
	}

	TreeNode *buildTree2(vector<int> &preorder, vector<int> &inorder) {
		int size = preorder.size();
		return buildTree2(preorder, 0, size, inorder, 0, size);
	}
	/*
	  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		int size = inorder.size();
		if (size==0) return NULL;
		int rootValue = postorder[size-1];
		TreeNode *node = new TreeNode(rootValue);
		vector<int>::iterator rootPos = find(inorder.begin(), inorder.end(), rootValue);
		vector<int> inorder_left(inorder.begin(), rootPos);
		vector<int> inorder_right(rootPos+1, inorder.end());

		int leftSize = inorder_left.size();
		vector<int> postorder_left(postorder.begin(), postorder.begin()+leftSize);
		vector<int> postorder_right(postorder.begin()+leftSize, postorder.end()-1);

		node->left = buildTree(inorder_left, postorder_left);
		node->right = buildTree(inorder_right, postorder_right);

		return node;
    }
	 */

#endif /* BUILDTREEFROMTRAVERSAL_H_ */

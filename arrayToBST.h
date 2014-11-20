/*
 * arrayToBST.h
 *
 *  Created on: 2014-04-25
 *      Author: frye
 */

#ifndef ARRAYTOBST_H_
#define ARRAYTOBST_H_

#include <vector>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode *arrayToBST(vector<int> &num, int start, int end){
        if (start>end) return NULL;
        TreeNode * root = (TreeNode *)malloc(sizeof(TreeNode));
        int mid = (start+end)/2;
        root->val = num[mid];
        root->left = arrayToBST(num, start, mid-1);
        root->right = arrayToBST(num, mid+1, end);
        return root;
}

TreeNode *sortedArrayToBST(vector<int> &num) {
        return arrayToBST(num, 0, num.size()-1);
}


#endif /* ARRAYTOBST_H_ */

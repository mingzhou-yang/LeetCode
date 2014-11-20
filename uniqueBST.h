/*
 * uniqueBST.h
 *
 *  Created on: 2014-05-15
 *      Author: frye
 */

#ifndef UNIQUEBST_H_
#define UNIQUEBST_H_

#include "commonHeader.h"

	int numTrees(int n) {
        int *num = new int[n+1];
        for(int i=0;i<=n;i++) num[i]=0;
        num[0] = 1;
        num[1] = 1;
        for (int i=2;i<=n;i++){
            for (int j=0;j<i;j++){
                num[i] += (num[j]*num[i-j-1]);
            }
        }
        return num[n];
    }

	vector<TreeNode *> generateTrees(int n) {
		vector<TreeNode *> empty;
		vector<vector<TreeNode *>> empty2(n+2, empty);
		vector<vector<vector<TreeNode *>>> trees(n+2, empty2);

		for(int i=0;i<=n;i++) {
			TreeNode *temp = new TreeNode(i);
			trees[i][i].push_back(temp);
		}
		for(int i=0;i<=n;i++)
			trees[i][n+1].push_back(NULL);

		for(int i=0;i<n+2;i++){
			for(int j=0;j<i;j++){
				trees[i][j].push_back(NULL);
			}
		}
		for(int i=1;i<n;i++)
			for(int j=1;j+i<=n;j++)
				for(int k=j;k<=i+j;k++)
					for(unsigned int m=0;m<trees[j][k-1].size();m++)
						for(unsigned int n=0;n<trees[k+1][i+j].size();n++){
							TreeNode *temp = new TreeNode(k);
							temp->left = trees[j][k-1][m];
							temp->right = trees[k+1][i+j][n];
							trees[j][i+j].push_back(temp);
						}
		return trees[1][n];
	}

	vector<TreeNode *>* generate(int start, int end)
	{
		vector<TreeNode *> *subTree = new vector<TreeNode*>();
		if(start>end)
		{
				subTree->push_back(NULL);
				return subTree;
		}
		for(int i =start; i<=end; i++)
		{
			vector<TreeNode*> *leftSubs = generate(start, i-1);
			vector<TreeNode*> *rightSubs = generate(i+1, end);
			for(int j = 0; j< leftSubs->size(); j++)
			{
				for(int k=0; k<rightSubs->size(); k++)
				{
					TreeNode *node = new TreeNode(i);
					node->left = (*leftSubs)[j];
					node->right = (*rightSubs)[k];
					subTree->push_back(node);
				}
			}
		}
		return subTree;
	}


	vector<TreeNode *> generateTrees2(int n) {
		if(n ==0) return *generate(1,0);
		return *generate(1, n);
	}

#endif /* UNIQUEBST_H_ */

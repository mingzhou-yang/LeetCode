/*
 * CopyNode.h
 *
 *  Created on: 2014-02-12
 *      Author: frye
 */

#ifndef COPYNODE_H_
#define COPYNODE_H_

#include <unordered_map>
#include <iostream>
#include <map>

using namespace std;

struct Node{
	Node * left;
	Node * right;
};

typedef unordered_map<Node*,Node*> NodeMap;

Node* CopyNode(Node* n, NodeMap& m){
	if (n==NULL) return NULL;
	if (m.find(n)!=m.end()) return n;
	Node* newNode = new Node;
	m[n] = newNode;
	newNode->left = CopyNode(n->left, m);
	newNode->right = CopyNode(n->right, m);
	return newNode;
}

Node* CopyStructure(Node* n){
	NodeMap m;
	return CopyNode(n, m);
}

#endif /* COPYNODE_H_ */

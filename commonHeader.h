/*
 * commonHeader.h
 *
 *  Created on: 2014-04-26
 *      Author: frye
 */

#ifndef COMMONHEADER_H_
#define COMMONHEADER_H_

#include <algorithm>
#include <iostream>
#include <fstream>
#include <ctime>
#include <utility>
#include <sstream>

#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>

#define INT_MAX 2147483647
#define INT_MIN (-INT_MAX - 1)


using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
	void printNode(){
		cout<<label<<": ";
		for(int i=0;i<(int)neighbors.size();i++) cout<<neighbors[i]->label<<" ";
		cout<<endl;
	}
};

RandomListNode *buildRandomList(int arr[], int size){
	RandomListNode *head = new RandomListNode(arr[0]);
	RandomListNode *pre = head;
	for(int i=1;i<size;i++){
		RandomListNode *temp = new RandomListNode(arr[i]);
		pre->next = temp;
		pre->random = temp;
		pre = pre->next;
	}
	return head;
}

typedef struct TreeNode* pnode;

int64_t timespecDiff(struct timespec *timeA_p, struct timespec *timeB_p)
{
  return ((timeA_p->tv_sec * 1000000000) + timeA_p->tv_nsec) -
           ((timeB_p->tv_sec * 1000000000) + timeB_p->tv_nsec);
}

template <typename T>
void printVector(vector<T> v){
	for(unsigned int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
}

template <typename T>
void printVecVector(vector<vector<T> > v){
	for(unsigned int i=0;i<v.size();i++) printVector(v[i]);
}

pnode buildTree(int arr[], int size){
	if (size==0) return NULL;
	pnode root = new TreeNode(arr[0]);
	pnode cur = root;
	queue<pnode> q;
	for(int i=1;i<size;i++){
		if (arr[i]!=INT_MIN && i%2==1) {
			cur->left = new TreeNode(arr[i]);
			q.push(cur->left);
		}
		else if (arr[i]!=INT_MIN && i%2==0) {
			cur->right = new TreeNode(arr[i]);
			q.push(cur->right);
		}
		if (i%2==0){
			cur = q.front();
			q.pop();
		}
	}
	return root;
}



ListNode *buildList(int arr[], int n){
	if (n==0) return NULL;
	ListNode *head = new ListNode(arr[0]);
	ListNode *pre = head;
	for(int i=1;i<n;i++){
		ListNode *temp = new ListNode(arr[i]);
		pre->next = temp;
		pre = pre->next;
	}
	return head;
}

void printTree(pnode root){
	if (root==NULL) return;
	cout<<root->val<<" ";
	printTree(root->left);
	printTree(root->right);
}

void printList(ListNode *p){
	if (p==NULL) return;
	while(p!=NULL){
		cout<<p->val<<" ";
		p = p->next;
	}
	cout<<endl;
}

void printList(RandomListNode *p){
	if (p==NULL) return;
	while(p!=NULL){
		cout<<p->label<<" ";
		p = p->next;
	}
	cout<<endl;
}

void printVector(vector<TreeNode *> v){
	for(unsigned int i=0;i<v.size();i++){
		printTree(v[i]);
		cout<<endl;
	}
}

	int getMax3(int a, int b, int c){
		if (a>=b&&a>=c) return a;
		if (b>=a&&b>=c) return b;
		else return c;
	}

#endif /* COMMONHEADER_H_ */

/*
 * LRUCache.h
 *
 *  Created on: Nov 19, 2014
 *      Author: frye
 */

#ifndef LRUCACHE_H_
#define LRUCACHE_H_
#include "commonHeader.h";

typedef struct node MyNode;


struct node{
    struct node *prev;
    struct node *next;
    int val;
    node(MyNode* a, MyNode *b, int x):prev(a), next(b), val(x){}
};


class LRUCache{
public:
    LRUCache(int capacity) {
        MaxCap = capacity;
        head = NULL;
        tail = NULL;
        elementNum = 0;
    }

    void updateMap(int key){
        MyNode *n = nodeMap[key];
            if (n!=head && n==tail){
                n->prev->next = NULL;
                tail = n->prev;
                n->prev = NULL;
                n->next = head;
                head->prev = n;
                head = n;
            }
            else if (n!=head){
                n->prev->next = n->next;
                n->next->prev = n->prev;
                n->prev = NULL;
                n->next = head;
                head->prev = n;
                head = n;
            }
    }

    int get(int key) {
        if (valueMap.find(key)!=valueMap.end()) {
            updateMap(key);
            return valueMap[key];
        }
        else return -1;
    }

    void set(int key, int value) {
        if (valueMap.find(key)==valueMap.end()){
            elementNum++;
            if (!head){
                MyNode *n = new MyNode(NULL, NULL, key);
                head = n;
                tail = n;
                nodeMap[key] = n;
            }
            else{
                MyNode *n = new MyNode(NULL, head, key);
                head->prev = n;
                head = n;
                nodeMap[key] = n;
                if (elementNum > MaxCap){
                    elementNum--;
                    MyNode *n2 = tail->prev;
                    valueMap.erase(tail->val);
                    nodeMap.erase(tail->val);
                    delete tail;
                    n2->next = NULL;
                    tail = n2;
                }
            }
        }
        else{
            updateMap(key);
        }
        valueMap[key] = value;
    }
private:
    int MaxCap;
    int elementNum;
    map<int, int> valueMap;
    map<int, MyNode*> nodeMap;
    MyNode *head, *tail;
};


#endif /* LRUCACHE_H_ */

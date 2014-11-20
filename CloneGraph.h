/*
 * CloneGraph.h
 *
 *  Created on: Nov 6, 2014
 *      Author: frye
 */

#ifndef CLONEGRAPH_H_
#define CLONEGRAPH_H_

#include "commonHeader.h"

	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node, map<int, UndirectedGraphNode *> &nodemap) {
    	if (!node) return NULL;
    	UndirectedGraphNode *ret;
    	if (!nodemap[node->label]) {
    		ret = new UndirectedGraphNode(node->label);
    		nodemap[node->label] = ret;
    		for(unsigned int i=0;i<node->neighbors.size();i++){
    			if (!nodemap[node->neighbors[i]->label]) ret->neighbors.push_back(cloneGraph(node->neighbors[i], nodemap));
    			else ret->neighbors.push_back(nodemap[node->neighbors[i]->label]);
    		}
    	}
    	return ret;
    }

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    	if (!node) return NULL;
    	UndirectedGraphNode *ret;
    	map<int, UndirectedGraphNode *> nodemap;
    	if (!nodemap[node->label]) {
    		ret = new UndirectedGraphNode(node->label);
    		nodemap[node->label] = ret;
    		for(unsigned int i=0;i<node->neighbors.size();i++){
    			if (!nodemap[node->neighbors[i]->label]) ret->neighbors.push_back(cloneGraph(node->neighbors[i], nodemap));
    			else ret->neighbors.push_back(nodemap[node->neighbors[i]->label]);
    		}
    	}
    	return ret;
    }



#endif /* CLONEGRAPH_H_ */

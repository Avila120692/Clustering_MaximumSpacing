/*UnionFind class implementation*/

#include <stdio.h>
#include <stdlib.h>
#include "UFNode.h"
#include "UnionFind.h"

// Constructor [size must be positive]
UnionFind::UnionFind(int size) {

	this->count = size;
	this->numVertices = size;
	this->nodeHolder = (UFNode*)malloc(size*sizeof(UFNode));

	for (int i = 0; i < size; i++)
		nodeHolder[i] = UFNode(i, 1); // Default values, node points to itself and rank is 1
}

// Finds the parent of a given vertex, using recursion
int UnionFind::Find(int vertex){

	if (vertex < 0 || vertex >= sizeof(nodeHolder))
		nodeHolder[vertex].parent = Find(nodeHolder[vertex].parent);

	return nodeHolder[vertex].parent;
}

//  Unions of two cluster (two vertices)
void UnionFind::Union(int v1, int v2) {
	int i = Find(v1);
	int j = Find(v2);

	if (i == j)
		return;

	if (nodeHolder[i].rank < nodeHolder[j].rank) {
		nodeHolder[i].parent = j;
		nodeHolder[j].rank = nodeHolder[j].rank + nodeHolder[i].rank;
	}
	else {
		nodeHolder[j].parent = i;
		nodeHolder[i].rank = nodeHolder[i].rank + nodeHolder[j].rank;
	}

	count--;
}

// Returns cluster count
int UnionFind::getCount() {
	return count;
}

// Receive two vertices from some clusters. Return true if both vertex have same parent
bool UnionFind::isConnected(int v1, int v2) {
	return Find(v1) == Find(v2);
}

// Prints the clusters here
void UnionFind::printCluster(){
	printf("%s \n", "We are printing here");
}
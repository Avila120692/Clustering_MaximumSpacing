/*UnionFind class implementation*/
#include "UnionFind.h"

using namespace std;

// Constructor [size must be positive]
UnionFind::UnionFind(int size){

	this->count = size;
	this->numVertices = size;

	for (int i = 0; i < size; i++) 
		nodeHolder.insert(nodeHolder.end(), UFNode(i, 1)); // Default values, node points to itself and rank is 1

}

// Finds the parent of a given vertex, using recursion
int UnionFind::Find(int vertex){

	if (vertex < 0 || vertex >= sizeof(nodeHolder))
		nodeHolder.at(vertex).parent = Find(nodeHolder.at(vertex).parent);

	return nodeHolder.at(vertex).parent;
}

//  Unions of two cluster (two vertices)
void UnionFind::Union(int v1, int v2){
	int i = Find(v1);
	int j = Find(v2);

	if (i == j)
		return;

	if (nodeHolder.at(i).rank < nodeHolder.at(j).rank) {
		nodeHolder.at(i).parent = j;
		nodeHolder.at(j).rank = nodeHolder.at(j).rank + nodeHolder.at(i).rank;
	}
	else {
		nodeHolder.at(j).parent = i;
		nodeHolder.at(i).rank = nodeHolder.at(i).rank + nodeHolder.at(j).rank;
	}

	count--;
}

// Returns cluster count
int UnionFind::getCount(){
	return count;
}

// Receive two vertices from some clusters. Return true if both vertex have same parent
bool UnionFind::isConnected(int v1, int v2){
	return Find(v1) == Find(v2);
}

// Prints the clusters here
void UnionFind::printCluster(){
	printf("\n\nPrint clusters:");

	for (int i = 0; i < nodeHolder.size(); i++)
		printf("\nnodeHolder[%i] : parent[%i]", i, nodeHolder.at(i).parent);

}

// Destructor
UnionFind::~UnionFind(){}
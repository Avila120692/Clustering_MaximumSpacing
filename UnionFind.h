/* UnionFind class definition*/
using namespace std;
#include "UFNode.h"

#ifndef __UNIONFIND__

#define __UNIONFIND__

class UnionFind {

private:
	int numVertices; // Node Holder having UFNode
	UFNode* nodeHolder; // NodeHolder, having UFNode
	int count; // Number of node (Cluster count)

public:
	UnionFind(int size);
	~UnionFind();
	int Find(int vertex);
	void Union(int v1, int v2);
	int getCount();
	bool isConnected(int v1, int v2);
	void printCluster();
};

#endif
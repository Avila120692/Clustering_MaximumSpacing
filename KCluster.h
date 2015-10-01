/* KCluster class definition*/
#include <vector>
#include <algorithm>
#include "Edge.h"
#include "Generator.h"
#include "UnionFind.h"

using namespace std;

#ifndef __KCLUSTER__

#define __KCLUSTER__

class KCluster {

private:
	int mNumVertices;   // Number of vertices in the graph
	int mNumEdges;  // Number of edges in the graph
	vector<Edge> mEdgeList; // Collection of edges representing the graph

public:
	int maxClusterDistance; // for K cluster
	KCluster(int numVertices, int numEdges);
	~KCluster();
	int getMaxSpacing(int clusterCount);
	void addEdges(vector<Edge> e_collection);
	void printEdges();
	void execute();
};


#endif
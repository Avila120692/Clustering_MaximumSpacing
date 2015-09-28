/* KCluster class definition*/
#include <windows.h>
#include "Edge.h"

#ifndef __KCLUSTER__

#define __KCLUSTER__

class KCluster {

private:
	int mNumVertices;   // Number of vertices in the graph
	int mNumEdges;  // Number of edges in the graph
	Edge* mEdgeList;

public:
	int maxClusterDistance; // for K cluster
	KCluster(int numVertices, int numEdges);
	~KCluster();
	int getMaxSpacing(int clusterCount);
	void addEdges(Edge* edges);
	void print();
};


#endif
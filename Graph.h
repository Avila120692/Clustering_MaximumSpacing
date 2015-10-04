/* KCluster class definition*/
#include <vector>
#include <algorithm>
#include "Edge.h"
#include "Generator.h"
#include "UnionFind.h"

using namespace std;

#ifndef __GRAPH__

#define __GRAPH__

class Graph {

private:
	int mNumVertices;   // Number of vertices in the graph
	int mNumEdges;  // Number of edges in the graph
	vector<Edge> mEdgeList; // Collection of edges representing the Graph

public:
	int maxClusterDistance; // for K cluster
	Graph(int n);
	~Graph();
	void setProperties(int numVertices, int numEdges);
	int getMaxSpacing(int clusterCount);
	void addEdges(vector<Edge> e_collection);
	void printEdges();
	void executeClustering(int k);
	void drawGraph();
	void drawClusters();
};


#endif
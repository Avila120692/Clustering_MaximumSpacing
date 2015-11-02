/* KCluster class definition*/
#include <vector>
#include <algorithm>
#include "Edge.h"
#include "UnionFind.h"

using namespace std;

#ifndef __GRAPH__

#define __GRAPH__

class Graph {

private:
	vector<Vertex> vertices;
	vector<Edge> edges;
	vector<int> clusters;

public:
	float maxClusterDistance; 
	Graph(vector<Vertex> vertices, vector<Edge> edges);
	~Graph();
	
	void printData();
	float getMaxSpacing(int clusterCount);
	vector<int> executeClustering(int k);
	void drawVertices(float dist_color);
	void drawEdges();
	void drawClusters();
};


#endif
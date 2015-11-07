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
	

public:
	vector<Vertex> vertices;
	vector<Edge> edges;
	vector<int> clusters;
	vector<Edge> cluster_edges;

	float maxClusterDistance; 
	Graph(vector<Vertex> vertices, vector<Edge> edges);
	~Graph();

	GLfloat mat_ambient[4];
	GLfloat mat_diffuse[4];
	GLfloat mat_specular[4];
	GLfloat mat_shininess[1];
	GLfloat mat_emissive[4];
	GLfloat glow;
	
	void printData();
	float getMaxSpacing(int clusterCount);
	vector<int> executeClustering(int k);
	void drawVertices();
	void drawEdges();
	void drawClusterEdges();
	void drawClusters();
};


#endif
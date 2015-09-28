/* KCluster class dimplementation*/
using namespace std;
#include <algorithm>
#include "Edge.h"
#include "UnionFind.h"
#include "KCluster.h"

// Constructor 
KCluster::KCluster(int numVertices, int numEdges) {

	this->mNumVertices = numVertices;
	this->mNumEdges = numEdges;
	this->mEdgeList = (Edge*)malloc(mNumEdges*sizeof(Edge));
}

// Main method for getting the Max spacing
int KCluster::getMaxSpacing(int clusterCount) {

	//sort(mEdgeList, mEdgeList + (mNumEdges*sizeof(Edge)));

	UnionFind uf(mNumVertices);

	if (clusterCount > uf.getCount()){
		printf("%s \n", "Cluster counter is lesser than input");
	}
	else {
		for (int i = 0; i < mNumVertices; i++) {

			Edge edge = mEdgeList[i];

			// If parents do not match, consider edge list for MST and , union the two vertex
			if (!uf.isConnected(edge.src, edge.dest)) {

				if (uf.getCount() == clusterCount) {
					uf.printCluster();
					return maxClusterDistance = edge.weight;
				}

				int v1 = uf.Find(edge.src);  // Parent vertex for source
				int v2 = uf.Find(edge.dest); // Parent vertex for destinition
				uf.Union(v1, v2);
			}
		}
	}
	return -1;
}

void KCluster::addEdges(Edge* edges){

	for (int i = 0; i < mNumEdges; i++){
		printf("\nEdge [%i] : src[%i] - dest[%i] | weight[%i]", i, edges[i].src, edges[i].dest, edges[i].weight);
		//mEdgeList[i] = edges[i];
	}
}

void KCluster::print() {

	for (int i = 0; i < mNumEdges; i++){
		//printf("\nEdge [%i] : src[%i] - dest[%i] | weight[%i]", i, mEdgeList[i].src, mEdgeList[i].dest, mEdgeList[i].weight);
	}
}

// Destructor
KCluster::~KCluster(){}
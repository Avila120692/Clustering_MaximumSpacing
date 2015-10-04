/* KCluster class dimplementation*/
#include "Graph.h"

using namespace std;

// Constructor 
Graph::Graph(int n) {}

// Set properties fot the graph (numVertices, numEdges)
void Graph::setProperties(int numVertices, int numEdges){

	this->mNumVertices = numVertices;
	this->mNumEdges = numEdges;
}

// Main method for getting the Max spacing
int Graph::getMaxSpacing(int clusterCount) {

	// Sort the edges by their weight
	sort(mEdgeList.begin(), mEdgeList.end(), [](const Edge lhs, const Edge& rhs) {
		return lhs.weight < rhs.weight;
	});

	printf("Sorted edges"); /*
							for (int i = 0; i < mEdgeList.size(); i++)
							printf("\nEdge [%i] : src[%i] - dest[%i] | weight[%i]", i, mEdgeList.at(i).src, mEdgeList.at(i).dest, mEdgeList.at(i).weight); */


	// The data structure for the UNION and FIND operations
	UnionFind uf(mNumVertices);

	if (clusterCount > uf.getCount()){
		printf("%s \n", "Cluster counter is lesser than input");
	}
	else {
		for (int i = 0; i < mNumVertices; i++) {

			Edge edge = mEdgeList.at(i);

			// If parents do not match, consider edge list for MST and , union the two vertex
			if (!uf.isConnected(edge.src, edge.dest)) {

				// If we have finished forming the K clusters
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

// Once the random collection of edges is generated, add them to the graph
void Graph::addEdges(vector<Edge> e_collection){

	// Fill mEdgeList with random collection of edges in Generator.cpp	
	for (int i = 0; i < e_collection.size(); i++)
		mEdgeList.insert(mEdgeList.end(), e_collection.at(i));

}

// Verify the edges in console
void Graph::printEdges() {

	for (int i = 0; i < mEdgeList.size(); i++)
		printf("\nEdge [%i] : src[%i] - dest[%i] | weight[%i]", i, mEdgeList.at(i).src, mEdgeList.at(i).dest, mEdgeList.at(i).weight);
}

// Clustering execution {graph, edges, clusters}
void Graph::executeClustering(int k){

	// Call the main method for calculating the k clusters
	maxClusterDistance = getMaxSpacing(k);

	// Print result : maximum spacing
	if (maxClusterDistance != -1)
		printf("\n\nMaximum Cluster Spacing for %i clusters is %i", k, maxClusterDistance);
	else
		printf("\nSomething went wrong");
}

// Draw the original graph (all edges) in 3D
void Graph::draw(){ // <---------------------------------------------------------- HERE HERE HERE

	// You have a vector of edges, do what you need to do in order to call

	// new vertex(x, y, z)...  vertex.draw()  SPHERE

	// new edge( src, dest, weight)... edge.draw()   LINE

}

// Destructor
Graph::~Graph(){}
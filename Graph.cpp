/* KCluster class dimplementation*/
#include "Graph.h"

using namespace std;

// Constructor 
Graph::Graph(vector<Vertex> vertices, vector<Edge> edges) {
	// Attribute generated vertices and edges to the graph
	this->vertices = vertices;
	this->edges = edges;
}

// Print the graph data
void Graph::printData(){
	cout << "Graph:";

	// Vertices data
	cout << "\n-------------------- Vertices:";
	for (int i = 0; i < vertices.size(); i++)
		cout << "\nVertex[" << i << "]: (" << vertices.at(i).x << ", " << vertices.at(i).y << ", " << vertices.at(i).z << ")";

	// Edges data
	cout << "\n----------------------- Edges:";
	for (int i = 0; i < edges.size(); i++)
		cout << "\nEdge[" << i << "]: (" << edges.at(i).src << ", " << edges.at(i).dest << ", " << edges.at(i).weight << ")";
}

// Main method for getting the Max spacing
float Graph::getMaxSpacing(GLint clusterCount){
	// Sort the edges by their weight
	sort(edges.begin(), edges.end(), [](const Edge lhs, const Edge& rhs) {
		return lhs.weight < rhs.weight;
	});

	cout << "\n\n---------------------- Sorted:"; 
	for (int i = 0; i < edges.size(); i++)
		cout << "\nEdge[" << i << "]: (" << edges.at(i).src << ", " << edges.at(i).dest << ", " << edges.at(i).weight << ")";

	// The data structure for the UNION and FIND operations
	UnionFind uf(vertices.size());

	if (clusterCount > uf.getCount()){
		cout << "Cluster counter is lesser than input";
	}
	else {
		cout << "\n\n------------------- Clustering:";
		for (int i = 0; i < vertices.size(); i++) {
			Edge edge = edges.at(i);

			// If parents do not match, consider edge list for MST and , union the two vertex
			if (!uf.isConnected(edge.src, edge.dest)) {

				// If we have finished forming the K clusters
				if (uf.getCount() == clusterCount) {
					clusters = uf.getClusters();

					return maxClusterDistance = edge.weight; // Last edge to be added represents the maximum spacing
				}

				int v1 = uf.Find(edge.src);  // Parent vertex for source
				int v2 = uf.Find(edge.dest); // Parent vertex for destinition
				uf.Union(v1, v2);
			}
		
		}
	}

	return -1.0;
}

// Clustering execution {graph, edges, clusters}
vector<int> Graph::executeClustering(int k){
	// Call the main method for calculating the k clusters
	maxClusterDistance = getMaxSpacing(k);

	// Print result : maximum spacing
	if (maxClusterDistance != -1)
		cout << "\n\nMaximum Cluster Spacing for " << k << " clusters is " << maxClusterDistance << "\n";
	else
		cout << "\nSomething went wrong";

	return clusters;
}

// Draw the original graph (ALL vertices) in 3D
void Graph::drawVertices(float dist_color){
	// Draw each vertex
	for (int i = 0; i < vertices.size(); i++)
		vertices.at(i).draw(dist_color);

}

void Graph::drawEdges(){
	// Draw each edge
	for (int i = 0; i < edges.size(); i++)
		edges.at(i).draw(vertices);
}

// Destructor
Graph::~Graph(){}
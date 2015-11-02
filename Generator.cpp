/* Generator Class implementation */
#include "Generator.h"

using namespace std;

// Constructor
Generator::Generator(){}

// (LCG) : Linear Congruential Generator
int Generator::lcg(int m, int a, int c, int x0){

	return - 1.0;
}

// (MCG) : Multiplicative Congruential Generator
GLint Generator::mcg(int m, int a, int x0){

	return -1.0;
}

// Generate random position -> Must return float value in the range [1, 12]
int Generator::randomPosition_X(bool mult_generator){
	// Initialize random seed
	srand(time(NULL));
	GLint x0, posX;
	x0 = rand() % 6 + 1;

	// posX = mult_generator ? mcg( m, a, c, x0) : lcg( m, a, x0);
	posX = x0; // We temporally use the value of x0
	cout << "\nposition_X: " << posX;

	return posX; // We temporally return x0
}

// Generate random position -> Must return float value in the range [1, 4]
int Generator::randomPosition_Y(bool mult_generator){
	// Initialize random seed
	srand(time(NULL)*10);
	int x0, posY;
	x0 = rand() % 4 + 1;
	
	// posy = mult_generator ? mcg( m, a, c, x0) : lcg( m, a, x0);
	posY = x0; // We temporally use the value of x0
	cout << "\nposition_Y: " << posY;
	
	return posY; 
}

// Generate random position -> Must return float values in the range [1, 12]
int Generator::randomPosition_Z(bool mult_generator){
	// Initialize random seed
	srand(time(NULL) * 100);
	int x0, posZ;
	x0 = rand() % 6 + 1;

	// posz = mult_generator ? mcg( m, a, c, x0) : lcg( m, a, x0);
	posZ = x0; // We temporally use the value of x0
	cout << "\nposition_Z: " << posZ;

	return posZ;
}

// Generate random edge -> Must return integer value in the range [1, numEdges]
int Generator::randomEdge(bool mult_generator, int numEdges){
	// Initialize random seed
	srand(time(NULL) * 100);
	int x0, edge_key;
	x0 = rand() % numEdges + 1;

	// edge_key = mult_generator ? mcg( m, a, c, x0) : lcg( m, a, x0);
	edge_key = x0; // We temporally use the value of x0
	cout << "\nedge_key: " << edge_key;

	return edge_key;
}

// Generate the random vertices (x, y, z)
vector<Vertex> Generator::generateVertices(int numVertices, bool mult){

	vector<Vertex> vertexList;
	
	// Temporal vertices [testing purposses]
	vertexList.insert(vertexList.end(), Vertex(5.0, 1.0, 5.0));
	vertexList.insert(vertexList.end(), Vertex(4.0, 5.0, 3.0));
	vertexList.insert(vertexList.end(), Vertex(6.0, 2.0, 1.0));
	vertexList.insert(vertexList.end(), Vertex(1.0, 1.0, 5.0));
	vertexList.insert(vertexList.end(), Vertex(3.0, 3.0, 3.0));
	
	/* Others vertices
	for (int i = 0; i < numVertices; i++)
		vertexList.insert(vertexList.end(), Vertex(randomPosition_X(mult), randomPosition_Y(mult), randomPosition_Z(mult)));
	*/
	
	// Return full-filled collection of vertices
	return vertexList;
}

// Generate the random edges (src, dest, weight)
vector<Edge> Generator::generateEdges(vector<Vertex> vertices, int numEdges, bool mult){

	vector<Edge> edges;
	
	// Edges collection is BASE 1 !!!! <--- VERIFY THIS IN ALGORITHM
	// Temporal edges [testing purposses]
	edges.insert(edges.end(), Edge(0, 1, distance(vertices.at(0), vertices.at(1))));
	edges.insert(edges.end(), Edge(1, 2, distance(vertices.at(1), vertices.at(2))));
	edges.insert(edges.end(), Edge(2, 3, distance(vertices.at(2), vertices.at(3))));
	edges.insert(edges.end(), Edge(3, 4, distance(vertices.at(3), vertices.at(4))));

	/* Others edges
	//for (int i = 0; i < numEdges; i++){
		src = randomEdge(mult, numEdges);
		dst = randomEdge(mult, numEdges);

		while(edge1 == edge2) // We generate another edge, if source and destiny are the same 
			edge2 = randomEdge(mult);

		edgeList.insert(edgeList.end(), Edge(src, dst, distance(vertices.at(src-1), vertices.at(dest-1))));
	}
	*/

	return edges;
}

// Calculate the 'distance' function among the objects
float Generator::distance(Vertex v1, Vertex v2){
	// Calculate the euclidian distance between vertices
	return sqrt(pow(v2.x - v1.x, 2) + pow(v2.y - v1.y, 2) + pow(v2.z - v1.z, 2));
}

// Destructor
Generator::~Generator(){}
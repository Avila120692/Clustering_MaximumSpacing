/* Generator Class implementation */
#include "Generator.h"

using namespace std;

// Constructor
Generator::Generator(int random_factor){
	this->random_factor = random_factor;
}


// Here we would generate the random edges (src, dest, weight)
vector<Edge> Generator::generateEdges(int numEdges){

	vector<Edge> edgeList;
	
	// For the moment, we dont apply the random generator
	edgeList.insert(edgeList.begin(), Edge(1, 2, 4));
	edgeList.insert(edgeList.end(), Edge(2, 3, 8));
	edgeList.insert(edgeList.end(), Edge(3, 4, 7));
	edgeList.insert(edgeList.end(), Edge(4, 5, 9));
	edgeList.insert(edgeList.end(), Edge(5, 6, 10));
	edgeList.insert(edgeList.end(), Edge(6, 3, 4));
	edgeList.insert(edgeList.end(), Edge(6, 7, 2));
	edgeList.insert(edgeList.end(), Edge(7, 8, 1));
	edgeList.insert(edgeList.end(), Edge(8, 1, 8));
	edgeList.insert(edgeList.end(), Edge(8, 2, 11));
	edgeList.insert(edgeList.end(), Edge(8, 0, 7));
	edgeList.insert(edgeList.end(), Edge(0, 3, 2));
	edgeList.insert(edgeList.end(), Edge(0, 7, 6));

	return edgeList;
}

// Generate random edges (src, dest, weight)
vector<Edge> Generator::generateRandomEdges(int numEdges){

	vector<Edge> edgeList;

	// Here we would apply a randomness technique
	/*random_x = (GLfloat)(rand() % 250 + 1) / 100;
	random_y = (GLfloat)(rand() % 250 + 1) / 100;
	random_z = (GLfloat)(rand() % 250 + 1) / 100;*/

	return edgeList;
}

// Destructor
Generator::~Generator(){}
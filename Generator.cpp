/* Generator Class implementation */
#include "Generator.h"

using namespace std;

const GLfloat node_radius = 0.1;
const GLfloat node_surface = 0.8;

// Constructor
Generator::Generator(int random_factor){
	this->random_factor = random_factor;
}

void Generator::generateNodes(int n){
	// Random variables for nodes position and body messures
	GLfloat random_x = 0.0;
	GLfloat random_y = 0.0;
	GLfloat random_z = 0.0;
	Node node(node_radius, node_surface);

	// Initialize random seed
	srand(time(NULL));

	for (int i = 1; i <= n; i++) {
		// Here we would apply a randomness technique
		random_x = (GLfloat)(rand() % 250 + 1) / 100;
		random_y = (GLfloat)(rand() % 250 + 1) / 100;
		random_z = (GLfloat)(rand() % 250 + 1) / 100;
		
		// Set position for the node Point(x,y,z) is center of node body
		node.setPosition(random_x, random_y, random_z);

		// Set color for node surface
		node.setColor(5.0, 5.0, 0.0);

		// Draw node
		node.draw();
	}	
}


vector<Edge> Generator::generateEdges(int numEdges){

	vector<Edge> edgeList;
	
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

// Destructor
Generator::~Generator(){}
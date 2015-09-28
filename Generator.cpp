/* Generator Class implementation */
using namespace std;

#include <windows.h>
#include <GL/gl.h>
#include "glut.h"
#include <time.h>
#include "Generator.h"
#include "Node.h"

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

// Destructor
Generator::~Generator(){}
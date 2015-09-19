/* Generator Class implementation */

#include <windows.h>
#include <GL/gl.h>
#include "glut.h"
#include <time.h>
#include "Generator.h"
#include "Node.h"

const GLfloat node_radius = 1.2;

// Constructor
Generator::Generator(){}

void Generator::generateNodes(int n){

	// Random variables for nodes position
	GLfloat random_x = 0.0;
	GLfloat random_y = 0.0;
	GLfloat random_z = 0.0;
	Node node(node_radius);

	// Initialize random seed
	srand(time(NULL));

	for (int i = 1; i <= n; i++) {
		random_x = (GLfloat)(rand() % 250 + 1) / 100;
		random_y = (GLfloat)(rand() % 250 + 1) / 100;
		random_z = (GLfloat)(rand() % 250 + 1) / 100;

		// Set position for the node
		node.setPosition(random_x, random_y, random_z);

		// Set material for the node
		node.setMaterial(255.0, 255.0, 0.0, 0.0);

		// Draws the node
		node.drawBody();
	}
}

// Destructor
Generator::~Generator(){}
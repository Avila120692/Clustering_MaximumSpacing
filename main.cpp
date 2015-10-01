#include <windows.h>
#include <iostream>
#include <stdlib.h> 
#include <GL/gl.h>
#include "glut.h"
//#include "glui.h"

#include "Helper.h"
#include "Generator.h"
#include "KCluster.h"

using namespace std;

// Instantiate Helper object (graphic enviroment utility)
static Helper helper(1);

// Instantiate generator
static Generator random_generator(1);

// Declare graph properties (numVertices, numEdges, numClusters[k])
int numVertices, numEdges, k;

// Instantiate the Graph
KCluster graph(1);

void init(void){

	// Initialize graph properties
	numVertices = 9;
	numEdges = 13;
	k = 4;

	// Instantiate the graph
	graph.setProperties(numVertices, numEdges);

	// Add edges to the graph
	graph.addEdges(random_generator.generateEdges(numEdges));
	random_generator.generateNodes(20); // INTEGRATE THESE BOTH
 
	// Set clear (background) color
	glClearColor(0.0, 0.0, 0.0, 0.0);
}



void display(void){
	// Clear the buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(255.0, 255.0, 0.0);

	// Draw enviroment (axis, reference frame, background texture, parallax effect)
	helper.drawGraphicEnviroment();

	// Draw original graph (all edges)
	graph.draw();

	// Execute clustering algorithm
	graph.executeClustering(k);

	// Draw representation of clusters (k-1 edges)
	//graph.drawClusters(); <- PERHAPS IT WONT BE HERE

	// Force execution of GL commands in finite time
	glFlush();
}

void reshape(int w, int h){
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 60.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Set the "look at" point
	gluLookAt(3.0, 3.0, 4.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

// We will have some sort of cotnrol with the keyboard
void keyboard(unsigned char key, int x, int y){
	switch (key) {
	case 27:
		exit(0);
		break;
	}
}

// We will have some sort of cotnrol with the mouse as well
void mouse(int btn, int state, int x, int y) {
}

// We need to have a GUI for controlling : amount of nodes, randomness level, amount of clusters, color for thr clusters...
// Also, we need to display the time it took the algortihm to calculate the clusters


int main(int argc, char** argv){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1340, 680);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Clustering of Maxmimum Spacing");

	// Register callback functions
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);

	init();
	glutMainLoop();

	system("pause");
	return 0;
}

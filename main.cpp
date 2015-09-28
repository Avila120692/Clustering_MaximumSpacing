#include <windows.h>
#include <iostream>
#include <stdlib.h> 
#include <GL/gl.h>
#include "glut.h"
#include "Generator.h"
#include "Edge.h"
#include "KCluster.h"
using namespace std;

/*

// Create generator
Generator random_generator(1);

void init(void){
	// Set clear (background) color
	glClearColor(0.0, 0.0, 0.0, 0.0);
}

// Draw an axis with a cone at the end : From CG using OpenGL - Hill and Kelley
void drawAxis(double length) {
	glPushMatrix();

	// Draw line
	glBegin(GL_LINES);
	glVertex3d(0.0, 0.0, 0.0);
	glVertex3d(0.0, 0.0, length);
	glEnd();

	// Draw cone
	glTranslated(0.0, 0.0, length - 0.2);
	glutSolidCone(0.04, 0.2, 12, 9);
	
	glPopMatrix();
}

void display(void){
	// Clear the buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(255.0, 255.0, 0.0);

	// ----------------------------------------------------
	// Draw reference frame
	glLineWidth(1.0);

	// Z axis
	glColor3f(1.0, 0.0, 0.0);
	drawAxis(3.0);

	// X axis
	glColor3f(0.0, 1.0, 0.0);
	glPushMatrix();
	glRotated(90.0, 0.0, 1.0, 0.0);
	drawAxis(3.0);
	glPopMatrix();

	// Y axis
	glColor3f(0.0, 0.0, 1.0);
	glPushMatrix();
	glRotated(-90.0, 1.0, 0.0, 0.0);
	drawAxis(2.5);
	glPopMatrix();
	// -----------------------------------------------------

	// Generate nodes
	random_generator.generateNodes(20);

	// -----------------------------------------------------

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

	return 0;
}

*/

Edge* generateEdges(){

	Edge* edges[13];

	edges[0] = new Edge(1, 2, 4);
	edges[1] = new Edge(2, 3, 8);
	edges[2] = new Edge(3, 4, 7);
	edges[3] = new Edge(4, 5, 9);
	edges[4] = new Edge(5, 6, 10);
	edges[5] = new Edge(6, 3, 4);
	edges[6] = new Edge(6, 7, 2);
	edges[7] = new Edge(7, 8, 1);
	edges[8] = new Edge(8, 1, 8);
	edges[9] = new Edge(8, 2, 11);
	edges[10] = new Edge(8, 0, 7);
	edges[11] = new Edge(0, 3, 2);
	edges[12] = new Edge(0, 7, 6);

	return *edges;
}

int main(void)
{
	
	Edge* edges = generateEdges();

	KCluster graph(9, 13);
	int k = 4;
	graph.addEdges(edges);
	graph.print();

	/*
	graph.maxClusterDistance = graph.getMaxSpacing(k);

	if (graph.maxClusterDistance != -1)
	printf("\nMaximum Cluster Spacing for %i clusters is %i", k, graph.maxClusterDistance);
	else
	printf("\n %s", "Something went Wrong
	*/

	system("pause");
	return 0;
}
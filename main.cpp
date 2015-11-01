#include <iostream>
#include <stdlib.h> 
#include <windows.h>
#include "glui.h"
#include "Helper.h"
#include "Generator.h"
#include "Graph.h"

using namespace std;

// Angle of rotation for the camera orientation
GLfloat camAngle_horizontal = 0.0;
GLfloat camAngle_vertical = 0.0;

// Position of camera
GLfloat camPosition_X = 9.0;
GLfloat camPosition_Y = 2.0;
GLfloat camPosition_Z = 9.0;
GLfloat camInc_X = 0.08;
GLfloat camInc_Z = 0.1;

// Target point(center) of camera
GLfloat camTarget_X = 0.0;
GLfloat camTarget_Y = 0.0;
GLfloat camTarget_Z = -1.0;

// KEY states. These variables will be zero when no key is being pressed
GLint camOrigin_X = -1;
GLint camOrigin_Y = -1;
GLfloat camAngle_inc_X = 0.0;
GLfloat camAngle_inc_Y = 0.0;

// Instantiate Helper object (graphic enviroment utility)
Helper* helper = new Helper();

// Instantiate generator
GLboolean mult_generator;
Generator* generator = new Generator();

// Declare graph properties (numVertices, numEdges, numClusters[k])
int numVertices, numEdges, k;
vector<Vertex> vertices;
vector<Edge> edges;

// Instantiate the Graph
Graph graph(1);

void init(void){
	// Define default material properties
	GLfloat mat_specular[] = { 3.0, 3.0, 3.0, 3.0 };
	GLfloat mat_shininess[] = { 5.0 };
	GLfloat mat_surface[] = { 0.0, 0.0, 0.0, 0.0 };

	// Set material properties, as defined above
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_surface);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_surface);

	// Set light properties
	GLfloat main_light[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat light_position0[] = { 0.0, 4.0, 0.0, 1.0 };

	// Finish setting up the two lights (position, and component values (specular and diffuse))
	glLightfv(GL_LIGHT0, GL_POSITION, light_position0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, main_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, main_light);

	// Set shading model to use
	glShadeModel(GL_SMOOTH);

	// Enable lighting
	//glEnable(GL_LIGHTING);
	// Activate (enable) lights
	glEnable(GL_LIGHT0);
	// Enable depth testing (for hidden surface removal)
	glEnable(GL_DEPTH_TEST);

	/********************* GRAPH *************************************************************/
	// Initialize graph properties
	numVertices = 5; // Valid range : [2, 50]
	numEdges = 2; // Valid range : [1, 49]
	k = 2; // Valid range : [1, 10]
	mult_generator = false;

	// Vertices and edges collections
	vertices = generator->generateVertices(numVertices, mult_generator);
	edges = generator->generateEdges(numEdges, vertices, numEdges);

	// Instantiate the graph
	graph.setProperties(numVertices, numEdges);

	// Add edges to the graph
	graph.addEdges(edges);

	// Set clear (background) color
	glClearColor(0.0, 0.0, 0.0, 0.0);
	/******************************************************************************************/
}

void display(void){
	// Clear the buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Set the MatrixMode to MODELVIEW
	glMatrixMode(GL_MODELVIEW);

	// Reset transformations
	glLoadIdentity();
	
	// Set the camera's lookAt vector
	gluLookAt(camPosition_X, camPosition_Y, camPosition_Z, (camPosition_X + camTarget_X), (camPosition_Y + camTarget_Y), (camPosition_Z+camTarget_Z), 0.0, 1.0, 0.0);

	/********************************** ENVIROMENT ******************************************/
	// Draw enviroment (axis, reference frame, background texture, parallax effect)
	helper->drawGraphicEnviroment();

	/********************************** GRAPH *******************************************/
	// Draw original graph (all edges)
	graph.drawVertices(vertices);
	graph.drawEdges(vertices, edges);
	
	// Execute clustering algorithm
	//graph.executeClustering(k);

	// Draw representation of clusters (k-1 edges)
	//graph.drawClusters(); <- PERHAPS IT WONT BE HERE
	/************************************************************************************/



	// Swaps the buffers of the current window if double buffered
	glFlush();
	glutSwapBuffers();
}

void reshape(int w, int h){
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 60.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// We will have some sort of cotnrol with the keyboard
void keyboard(unsigned char key, int x, int y){
	switch (key) {
	case 0x1B:case 'q':case 'Q':
		exit(0);
		break;
	default:
		break;
	}
	glutPostRedisplay();
}


// Special keys for controlling the camera
void processSpecialKeys(int key, int x, int y) {

	switch (key) {
		case GLUT_KEY_LEFT:
			glMatrixMode(GL_PROJECTION);
			glTranslatef(camInc_X, 0.0, 0.0);
		break;
		case GLUT_KEY_RIGHT:
			glMatrixMode(GL_PROJECTION);
			glTranslatef(-camInc_X, 0.0, 0.0);
			break;
		case GLUT_KEY_UP:
			glMatrixMode(GL_PROJECTION);
			glTranslatef(0.0, 0.0, camInc_Z);
			break;
		case GLUT_KEY_DOWN:
			glMatrixMode(GL_PROJECTION);
			glTranslatef(0.0, 0.0, -camInc_Z);
		break;
	}

	glutPostRedisplay();
}


void mouse(int btn, int state, int x, int y) {

	// Only start motion if the left button is pressed
	if (btn == GLUT_LEFT_BUTTON) {

		// Button is released
		if (state == GLUT_UP) {
			// Horizontal camera rotation
			camAngle_horizontal += camAngle_inc_X;
			camOrigin_X = -1;

			// Vertical camera rotation
			camAngle_vertical += camAngle_inc_Y;
			camOrigin_Y = -1;
		}
		else { // state = GLUT_DOWN
			camOrigin_X = x;
			camOrigin_Y = y;
		}
	}
}

void mouseMove(int x, int y) {

	// This will only be true when the left button is down
	if (camOrigin_X >= 0) {

		// Update angle increment for both rotations
		camAngle_inc_X = (x - camOrigin_X) * 0.001; // [Horizontal]
		camAngle_inc_Y = (y - camOrigin_Y) * 0.001; // [Vertical]

		// Update camera's orientation [Horizontal]
		camTarget_X = -cos(camAngle_horizontal + camAngle_inc_X);
		camTarget_Z = sin(camAngle_horizontal + camAngle_inc_X);

		// Update camera's orientation [Vertical]
		camTarget_Y = sin(camAngle_vertical + camAngle_inc_Y);
	}
}

int main(int argc, char** argv){

	/****************************** GLUT ******************************************/
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1340, 680);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Clustering of Maxmimum Spacing");

	/******************************  GRAPH *****************************************/
	numVertices = 0;
	numEdges = 0;
	k = 0;

	/******************************* GLUI ******************************************/
	/*
	GLUI *glui = GLUI_Master.create_glui("Controls");
	GLUI_Panel *collection_panel = glui->add_panel("Collection properties");
	
	// GLUI lements for OBJECTS
	glui->add_edittext_to_panel(collection_panel, "Objects :");
	glui->add_edittext_to_panel(collection_panel, "Edges   :");
	glui->add_edittext_to_panel(collection_panel, "Clusters:");

	// GLUI lements for RANDOMNESS
	GLUI_Panel *random_panel = glui->add_panel("Randomness");
	glui->add_listbox_to_panel(random_panel, "Random");
	
	// GLUI lements for EXECUTION;
	glui->add_separator();
	glui->add_statictext("   Running time: ");
	glui->add_separator();
	glui->add_button("  Run  ");
	glui->add_separator();
	*/
	/*******************************************************************************/


	// Register callback functions
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMove);
	glutSpecialFunc(processSpecialKeys);
	glutIdleFunc(display);

	init();
	glutMainLoop();

	system("pause");
	return 0;
}

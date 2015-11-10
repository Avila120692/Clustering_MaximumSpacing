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
GLfloat camInc_Y = 0.08;
GLfloat camInc_Z = 0.1;

// Target point(center) of camera
GLfloat camTarget_X = 0.0;
GLfloat camTarget_Y = 0.0;
GLfloat camTarget_Z = -1.0;

// KEY states.
GLint camOrigin_X = -1;
GLint camOrigin_Y = -1;
GLfloat camAngle_inc_X = 0.0;
GLfloat camAngle_inc_Y = 0.0;

// Instantiate Helper
Helper* helper = new Helper();

// Instantiate generator
GLboolean mult_generator;
Generator* generator = new Generator();

// Declare graph properties 
int numVertices, numEdges, k;
boolean show_edges, clustering_executed;
Graph* graph;
vector<Vertex> vertices;
vector<Edge> edges;
vector<int> clusters;

// Light, shadows
GLfloat glow_intensity = 0.0;
bool glow_limit = false;

void init(void){

	// Set light properties
	GLfloat main_light[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat light_position0[] = { 4.0, 1.0, 10.0, 0.0 };

	// Finish setting up the two lights (position, and component values (specular and diffuse))
	glLightfv(GL_LIGHT0, GL_POSITION, light_position0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, main_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, main_light);

	// Set shading model to use
	glShadeModel(GL_SMOOTH);

	// Enable lighting
	glEnable(GL_LIGHTING);
	// Activate (enable) lights
	glEnable(GL_LIGHT0);
	// Enable depth testing (for hidden surface removal)
	glEnable(GL_DEPTH_TEST);

	/********************* GRAPH *************************************************************/
	// Initialize graph properties
	numVertices = 0; // Valid range : [2, 50]
	numEdges = 0; // Valid range : [1, 49]
	k = 3; // Valid range : [1, 10]
	mult_generator = false;
	show_edges = false;
	clustering_executed = false;

	// Vertices and edges collections
	vertices = generator->generateVertices(numVertices, mult_generator);
	edges = generator->generateEdges(vertices, numEdges, mult_generator);

	// Instantiate the graph with vertices and edges
	graph = new Graph(vertices, edges);
	graph->printData();

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
	gluLookAt(camPosition_X, camPosition_Y, camPosition_Z, (camPosition_X+camTarget_X), (camPosition_Y+camTarget_Y), (camPosition_Z+camTarget_Z), 0.0, 1.0, 0.0);

	/********************************** ENVIROMENT ******************************************/
	// Draw enviroment (axis, reference frame)
	helper->drawGraphicEnviroment();

	/********************************** EMISSIVE LIGHT *******************************************/
	if (glow_limit)
		glow_intensity += 0.001;
	else
		glow_intensity -= 0.001;


	if (glow_intensity <= 0)
		glow_limit = true;
	else if (glow_intensity >= 1)
		glow_limit = false;
	/********************************** GRAPH *******************************************/

	// Draw graph
	graph->drawVertices();
	
	for (int i = 0; i < graph->vertices.size(); i++)
		graph->vertices.at(i).setEmission(glow_intensity, 0.0, 0.0);

	if (show_edges)
		graph->drawEdges();

	if (clustering_executed)
		graph->drawClusterEdges();
	
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
	case 'e': case 'E':
		// For drawing all the edges again (not just the cluster_edges)
		show_edges = !show_edges;
		clustering_executed = !clustering_executed;

		// Return the vertices to its original material color
		for (int i = 0; i < graph->vertices.size(); i++)
			graph->vertices.at(i).setMaterial(0.1745, 0.01175, 0.01175);

		break;
	case 'r': case 'R' :
		// Execute clustering algorithm
		clusters = graph->executeClustering(k);	
		clustering_executed =  !clustering_executed;
		
		// Modify material for each vertex in function of its resulting cluster's belongness
		for (int i = 0; i < graph->vertices.size(); i++){
			cout << "\nVertex[" << i << "] belongs to cluster: " << clusters.at(i);
			graph->vertices.at(i).setMaterial(1.0, clusters.at(i), 0.4);
			graph->vertices.at(i).setEmission(0.0, 0.0, glow_intensity);
		}

		break;
	case 'h': case	'H':
		graph->vertices.at(0).setPosition(0.0, 0.0, 0.0);
		break;
	case 'o' : case 'O':
		if (camPosition_Y <= 12.0)
			camPosition_Y += camInc_Y;
			break;
	case 'p': case 'P':
		if (camPosition_Y >= 2.0)
			camPosition_Y -= camInc_Y;
		break;
	case 'y': case 'Y':
		graph->vertices.at(0).setPosition(graph->vertices.at(0).getPosition_X() + 0.02, 0.0, 0.0);
		break;
	case 'u': case 'U':
		graph->vertices.at(0).setPosition(graph->vertices.at(0).getPosition_X() - 0.02, 0.0, 0.0);
		break;
	case 0x1B:case 'q':case 'Q':
		exit(0);
		break;
	default:
		break;
	}
	glutPostRedisplay();
}


// Special keys for controlling the camera traslations
void processSpecialKeys(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:
		if (camPosition_X >= 2.0){
			camPosition_Z += camInc_Z;
			camPosition_X -= camInc_X;
		}
		break;
	case GLUT_KEY_RIGHT:
		if (camPosition_Z >= 2.0){
			camPosition_Z -= camInc_Z;
			camPosition_X += camInc_X;
		}
		break;
	case GLUT_KEY_UP:
		if (camPosition_X >= 2.0 && camPosition_Z >= 2){
			camPosition_X -= camInc_X;
			camPosition_Z -= camInc_Z;
		}
		break;
	case GLUT_KEY_DOWN:
		if (camPosition_X <= 16.0 && camPosition_Z <= 16.0){
			camPosition_X += camInc_X;
			camPosition_Z += camInc_Z;
		}
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

			// Vertical camera rotation
			camAngle_vertical += camAngle_inc_Y;
		}
		else {
			// if (state = GLUT_DOWN) 
			camOrigin_X = x;
			camOrigin_Y = y;
		}
	}
}

void mouseMove(int x, int y) {
	// Update angle increment for both rotations
	camAngle_inc_X = (x - camOrigin_X) * 0.001; // [Horizontal]
	camAngle_inc_Y = (y - camOrigin_Y) * 0.001; // [Vertical]

	// Update camera's orientation [Horizontal]
	camTarget_X = sin(camAngle_horizontal + camAngle_inc_X);
	camTarget_Z = -cos(camAngle_horizontal + camAngle_inc_X);

	// Update camera's orientation [Vertical]
	camTarget_Y = -sin(camAngle_vertical + camAngle_inc_Y);
}

void joystick(unsigned int buttonmask, int x, int y, int z) {
	// Update angle increment for both rotations
	camAngle_inc_X = (x - camOrigin_X) * 0.001; // [Horizontal]
	camAngle_inc_Y = (y - camOrigin_Y) * 0.001; // [Vertical]

	// Update camera's orientation [Horizontal]
	camTarget_X = sin(camAngle_horizontal + camAngle_inc_X);
	camTarget_Z = -cos(camAngle_horizontal + camAngle_inc_X);

	// Update camera's orientation [Vertical]
	camTarget_Y = -sin(camAngle_vertical + camAngle_inc_Y);

	if (buttonmask & 0x01) {
		glMatrixMode(GL_PROJECTION);
		glTranslatef(0.0, 0.0, camInc_Z);
		glTranslatef(camInc_X, 0.0, 0.0);
	}

	if (buttonmask & 0x02) {
		glMatrixMode(GL_PROJECTION);
		glTranslatef(0.0, 0.0, -camInc_Z);
		glTranslatef(-camInc_X, 0.0, 0.0);
	}

	if (buttonmask & 0x04){
		glMatrixMode(GL_PROJECTION);
		glTranslatef(0.0, 0.0, -camInc_Z);
		glTranslatef(camInc_X, 0.0, 0.0);
	
	}

	if (buttonmask & 0x08) {
		glMatrixMode(GL_PROJECTION);
		glTranslatef(0.0, 0.0, camInc_Z);
		glTranslatef(-camInc_X, 0.0, 0.0);
	}

	if (buttonmask & 0x10) {
		glMatrixMode(GL_PROJECTION);
		glRotatef(0.5, 0.0, 1.0, 0.0);
	}

	if (buttonmask & 0x20) {
		
	}

	if (buttonmask & 0x40) {

	}


	if (buttonmask & 0x80) {
		glMatrixMode(GL_PROJECTION);
		glRotatef(-0.5, 0.0, 1.0, 0.0);
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
	/*******************************************************************************/

	// Register callback functions
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMove);
	glutSpecialFunc(processSpecialKeys);
	glutJoystickFunc(joystick, 25);
	glutIdleFunc(display);

	init();
	glutMainLoop();

	system("pause");
	return 0;
}

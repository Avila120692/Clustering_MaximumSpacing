#include <windows.h>
#include <iostream>
#include <stdlib.h> 
#include <GL/gl.h>
#include "glut.h"
#include "Generator.h"
using namespace std;

// Create generator
Generator generator();

generator.generateNodes(10);

void init(void){
	// Set clear (background) color
	glClearColor(0.0, 0.0, 0.0, 0.0);

	// Define material properties
	GLfloat mat_specular[] = { 3.0, 3.0, 3.0, 3.0 };
	GLfloat mat_shininess[] = { 30.0 };
	GLfloat mat_surface[] = { 1.0, 1.0, 0.0, 0.0 };

	// Set material properties, as defined above
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_surface);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_surface);

	// Set light properties ... What ?
	GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position0[] = { 0.0, 0.0, 0.0, 1.0 };

	// Finish setting up the two lights (position, and component values (specular and diffuse))
	glLightfv(GL_LIGHT0, GL_POSITION, light_position0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
	glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);

	// Set shading model to use
	glShadeModel(GL_SMOOTH);

	// Enable lighting
	glEnable(GL_LIGHTING);
	// Activate (enable) lights
	glEnable(GL_LIGHT0);
	// Enable depth testing (for hidden surface removal)
	glEnable(GL_DEPTH_TEST);
}

void display(void){
	// Clear the buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	random_generator.

	// glFlush — Force execution of GL commands in finite time
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
	gluLookAt(0.0, 5.0, 20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

void keyboard(unsigned char key, int x, int y){
	switch (key) {
	case 27:
		exit(0);
		break;
	}
}

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

	init();
	glutMainLoop();

	return 0;
}
/* Node Class definition*/
#include <windows.h>
#include <GL/gl.h>
#include "glut.h"

#ifndef __VERTEX__

#define __VERTEX__

class Vertex{

public:
	GLfloat x;
	GLfloat y;
	GLfloat z;
	GLfloat radius;
	GLfloat color_surface[3];
	Vertex(GLfloat x, GLfloat y, GLfloat z);
	~Vertex();
	void setPosition(GLfloat x, GLfloat y, GLfloat z);
	void setColor(GLfloat R, GLfloat G, GLfloat B);
	void draw(void);
};

#endif
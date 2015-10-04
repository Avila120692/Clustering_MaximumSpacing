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
	GLfloat surface;
	GLfloat demi_radius;
	GLfloat color_surface[3];
	Vertex(GLfloat radius, GLfloat surface);
	~Vertex();
	void setPosition(GLfloat x, GLfloat y, GLfloat z);
	void setColor(GLfloat R, GLfloat G, GLfloat B);
	void draw(void);
	void drawBody(void);
};

#endif
/* Generator Class definition*/

#include <windows.h>
#include <GL/gl.h>
#include "glut.h"

#ifndef __GENERATOR__

#define __GENERATOR__

class Generator {

public:
	int random_factor;
	Generator(int random_factor);
	~Generator();
	void generateNodes(int n);
};

#endif
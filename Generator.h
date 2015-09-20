/* Generator Class definition*/

#include <windows.h>
#include <GL/gl.h>
#include "glut.h"

#ifndef __GENERATOR__

#define __GENERATOR__

class Generator {

public:
	Generator();
	~Generator();
	void generateNodes(int n);
};

#endif
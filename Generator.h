/* Generator Class definition*/
using namespace std;

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
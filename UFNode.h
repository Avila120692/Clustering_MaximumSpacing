/* UFnode class definition*/

#ifndef __UFNode__

#define __UFNode__

class UFNode {

public:
	int parent;
	int rank;
	UFNode(int parent, int rank);
	~UFNode();
};

#endif